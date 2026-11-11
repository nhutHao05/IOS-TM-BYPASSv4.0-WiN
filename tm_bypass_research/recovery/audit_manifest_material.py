"""Bounded offline search for manifest/keybag material in supplied artifacts.

No target code or network requests are executed. Results contain locations and
structure, never candidate key bytes or unrelated credential strings.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import io
import json
import logging
import lzma
from pathlib import Path
import plistlib
import struct
import tarfile
import zipfile
from xml.parsers.expat import ExpatError

MARKERS = ("BackupKeyBag", "ManifestKey", "BackupManifestKey", "Manifest.plist",
           "DPSL", "DPIC")
TAGS = {b"VERS", b"TYPE", b"UUID", b"HMCK", b"WRAP", b"SALT", b"ITER",
        b"DPSL", b"DPIC", b"CLAS", b"KTYP", b"WPKY", b"PBKY"}
MAX_BLOB = 256 * 1024 * 1024
MAX_TOTAL = 2 * 1024 * 1024 * 1024


def keybags(data: bytes) -> list[dict]:
    """Recognize complete-looking TLV sequences; do not assert matching keys."""
    found, start = [], 0
    while (start := data.find(b"VERS\0\0\0\x04", start)) >= 0:
        pos, tags = start, []
        while pos + 8 <= len(data) and len(tags) < 256:
            tag = data[pos:pos + 4]
            length = struct.unpack_from(">I", data, pos + 4)[0]
            if tag not in TAGS or length > 4096 or pos + 8 + length > len(data):
                break
            tags.append({"tag": tag.decode(), "length": length})
            pos += 8 + length
        names = Counter(x["tag"] for x in tags)
        if all(names[k] for k in ("VERS", "TYPE", "UUID", "CLAS", "WPKY")):
            found.append({"offset": start, "length": pos - start, "tags": tags,
                          "sha256": hashlib.sha256(data[start:pos]).hexdigest()})
        start += 8
    return found


class Audit:
    def __init__(self):
        self.seen = {}
        self.records, self.hits, self.omissions = [], [], []
        self.total = 0

    def visit(self, name: str, data: bytes, depth: int = 0):
        if len(data) > MAX_BLOB or self.total + len(data) > MAX_TOTAL or depth > 8:
            self.omissions.append({"path": name, "reason": "bounded traversal limit"})
            return
        digest = hashlib.sha256(data).hexdigest()
        record = {"path": name, "bytes": len(data), "sha256": digest}
        if digest in self.seen:
            record["same_content_as"] = self.seen[digest]
            self.records.append(record)
            return
        self.seen[digest] = name
        self.records.append(record)
        self.total += len(data)
        for marker in MARKERS:
            for encoding in ("ascii", "utf-16le"):
                needle = marker.encode(encoding)
                positions, pos = [], 0
                while (pos := data.find(needle, pos)) >= 0:
                    positions.append(pos)
                    pos += len(needle)
                if positions:
                    self.hits.append({"path": name, "kind": "marker", "marker": marker,
                                      "encoding": encoding, "count": len(positions),
                                      "offsets": positions[:32]})
        for bag in keybags(data):
            self.hits.append({"path": name, "kind": "keybag-tlv-candidate", **bag})

        # Inspect complete resource payloads and XML plist fragments.
        candidates = [(0, data)]
        pos = 0
        while (pos := data.find(b"<?xml", pos)) >= 0:
            end = data.find(b"</plist>", pos)
            if end < 0:
                break
            candidates.append((pos, data[pos:end + 8]))
            pos = end + 8
        for offset, candidate in candidates:
            try:
                obj = plistlib.loads(candidate)
            except (ValueError, TypeError, OverflowError, plistlib.InvalidFileException, ExpatError):
                continue
            if isinstance(obj, dict) and any(k in obj for k in ("BackupKeyBag", "ManifestKey")):
                self.hits.append({"path": name, "offset": offset, "kind": "manifest-plist-candidate",
                                  "fields": {k: {"type": type(obj[k]).__name__,
                                                  "bytes": len(obj[k]) if isinstance(obj[k], bytes) else None}
                                             for k in ("BackupKeyBag", "ManifestKey") if k in obj},
                                  "is_encrypted": obj.get("IsEncrypted")})
                for k in ("BackupKeyBag", "ManifestKey"):
                    if isinstance(obj.get(k), bytes):
                        self.visit(name + "!plist-field:" + k, obj[k], depth + 1)

        if len(data) >= 4 and struct.unpack_from("<I", data)[0] == len(data) - 4:
            self.visit(name + "!dotnet-bytearray", data[4:], depth + 1)
        if data.startswith(b"PK\x03\x04"):
            try:
                with zipfile.ZipFile(io.BytesIO(data)) as z:
                    for entry in z.infolist():
                        if entry.is_dir():
                            continue
                        if entry.flag_bits & 1 or entry.file_size > MAX_BLOB or self.total + entry.file_size > MAX_TOTAL:
                            self.omissions.append({"path": name + "!" + entry.filename,
                                                   "reason": "encrypted ZIP member or traversal limit"})
                            continue
                        self.visit(name + "!" + entry.filename, z.read(entry), depth + 1)
            except (zipfile.BadZipFile, RuntimeError) as exc:
                self.omissions.append({"path": name, "reason": type(exc).__name__})
        elif data.startswith((b"\x1f\x8b", b"\xfd7zXZ")) or data[:5] == b"\x5d\x00\x00\x80\x00" or data[257:262] == b"ustar":
            try:
                with tarfile.open(fileobj=io.BytesIO(data), mode="r:*") as archive:
                    for entry in archive:
                        if not entry.isfile():
                            continue
                        if entry.size > MAX_BLOB or self.total + entry.size > MAX_TOTAL:
                            self.omissions.append({"path": name + "!" + entry.name, "reason": "traversal limit"})
                            continue
                        self.visit(name + "!" + entry.name, archive.extractfile(entry).read(), depth + 1)
            except tarfile.ReadError:
                try:
                    decoder = lzma.LZMADecompressor(memlimit=MAX_BLOB)
                    unpacked = decoder.decompress(data, max_length=MAX_BLOB + 1)
                    if not decoder.eof or len(unpacked) > MAX_BLOB:
                        raise ValueError("LZMA decoding exceeded limit or did not reach EOF")
                    self.visit(name + "!lzma", unpacked, depth + 1)
                except (lzma.LZMAError, ValueError) as exc:
                    self.omissions.append({"path": name, "reason": type(exc).__name__})


def run(root: Path):
    import dnfile
    logging.disable(logging.CRITICAL)
    audit = Audit()
    inputs = [root / "TM-BYPASSv4.0 WiN.zip", root / "TM-BYPASS.section_decrypted.exe",
              root / "resource_assembly.dll", root / "constants.bin",
              root / "native_runtime/wine/MDM_SETUP.exe.memory_ready.bin",
              root / "native_runtime/wine/imobiledevice.dll.memory_ready.bin"]
    for path in inputs:
        if not path.exists():
            audit.omissions.append({"path": str(path.relative_to(root)), "reason": "input absent"})
            continue
        audit.visit(path.relative_to(root).as_posix(), path.read_bytes())
    dn = dnfile.dnPE(str(root / "resource_assembly.dll"))
    for index, resource in enumerate(dn.net.resources):
        if isinstance(resource.data, bytes):
            audit.visit(f"managed-resource:{index}", resource.data)
        elif hasattr(resource.data, "entries"):
            for entry in resource.data.entries:
                if isinstance(entry.data, bytes):
                    audit.visit(f"managed-resource:{index}:{entry.name}", entry.data)
    return {"scope": "Supplied Windows ZIP, decrypted managed resources/constants and two unpacked native snapshots",
            "network_requests": 0, "target_processes_executed": 0,
            "unique_blobs": len(audit.seen), "unique_bytes_scanned": audit.total,
            "records": audit.records, "hits": audit.hits, "omissions": audit.omissions,
            "limitations": ["Marker absence does not rule out encrypted, encoded, split or runtime-generated material.",
                            "Generic resource payloads with no byte representation in dnfile are not traversed separately.",
                            "TLV recognition does not prove a candidate matches the embedded encrypted backup.",
                            "The external manifest candidate from a different backup is excluded from the target search.",
                            "Only inputs and archive/resource forms described in this report were searched."]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = run(args.root)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({k: result[k] for k in ("unique_blobs", "unique_bytes_scanned", "omissions")}, indent=2))
    print(json.dumps({"manifest_candidates": sum(h["kind"] == "manifest-plist-candidate" for h in result["hits"]),
                      "keybag_candidates": sum(h["kind"] == "keybag-tlv-candidate" for h in result["hits"])}))
