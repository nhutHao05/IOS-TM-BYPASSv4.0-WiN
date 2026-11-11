#!/usr/bin/env python3
"""Preserve Manifest.plist from a selected lab directory before tool cleanup.

This reads local files only. It does not start TM-BYPASS, call its servers,
perform a restore, or open a device. Captured manifests remain private locally.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import plistlib
import sys
import time
from xml.parsers.expat import ExpatError


def verify_index(manifest: dict, index: Path, password: str) -> dict:
    """Require real key unwrap and a decrypted SQLite header for a key match."""
    from cryptography.hazmat.primitives.keywrap import InvalidUnwrap
    sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "mdm-re-lab"))
    from mdmlab import Keybag, decrypt_cbc
    raw = index.read_bytes()
    result = {"index_sha256": hashlib.sha256(raw).hexdigest(),
              "matching_decryption_key": False, "full_database_validated": False}
    if len(raw) < 16 or len(raw) % 16:
        return {**result, "reason": "invalid_encrypted_index_length"}
    try:
        bag = Keybag(manifest["BackupKeyBag"], password)
        key = bag.unwrap(manifest["ManifestKey"])
        clear = decrypt_cbc(raw[:16], key)
    except (ValueError, KeyError, InvalidUnwrap, OverflowError) as exc:
        return {**result, "reason": "key_material_or_password_rejected",
                "error_type": type(exc).__name__}
    return {**result, "matching_decryption_key": clear == b"SQLite format 3\0",
            "reason": "sqlite_header_matches" if clear == b"SQLite format 3\0" else "sqlite_header_mismatch"}


def capture(watch_root: Path, output: Path, seconds: float, index: Path | None = None,
            password: str = "mdm", interval: float = 0.025) -> dict:
    watch_root, output = watch_root.resolve(), output.resolve()
    if output.is_relative_to(watch_root):
        raise ValueError("Output must be outside the watched input directory")
    output.mkdir(parents=True, exist_ok=True)
    seen, captures = set(), []
    report = {"watch_root": str(watch_root), "network_requests": 0,
              "device_actions": 0, "captures": captures,
              "scope": "Local file polling; only complete parseable manifests with both key fields are retained.",
              "limitations": ["Polling may miss a file deleted between polls.",
                              "A structural candidate is not a matching backup until its keys are verified.",
                              "A decrypted SQLite header verifies key compatibility, not the full database or MDM effect."]}
    deadline = time.monotonic() + seconds
    try:
        while time.monotonic() < deadline:
            try:
                paths = list(watch_root.rglob("Manifest.plist"))
            except OSError:
                paths = []
            for path in paths:
                try:
                    if path.is_symlink() or path.stat().st_size > 8 * 1024 * 1024:
                        continue
                    raw = path.read_bytes()
                    digest = hashlib.sha256(raw).hexdigest()
                    if digest in seen:
                        continue
                    manifest = plistlib.loads(raw)
                    if not isinstance(manifest, dict) or not all(
                            isinstance(manifest.get(k), bytes) and manifest[k]
                            for k in ("BackupKeyBag", "ManifestKey")):
                        continue
                except (OSError, ValueError, OverflowError, ExpatError):
                    continue
                destination = output / (digest + ".Manifest.plist")
                try:
                    with destination.open("xb") as stream:
                        stream.write(raw)
                    try:
                        destination.chmod(0o600)
                    except OSError:
                        pass
                except FileExistsError:
                    if destination.read_bytes() != raw:
                        raise ValueError("Existing capture does not match its content hash")
                item = {"sha256": digest, "capture_file": destination.name,
                        "source_relative_path": str(path.relative_to(watch_root)),
                        "captured_at": datetime.now(timezone.utc).isoformat(),
                        "backup_keybag_bytes": len(manifest["BackupKeyBag"]),
                        "manifest_key_bytes": len(manifest["ManifestKey"]),
                        "matching_decryption_key": None}
                if index is not None:
                    item["index_check"] = verify_index(manifest, index, password)
                    item["matching_decryption_key"] = item["index_check"]["matching_decryption_key"]
                seen.add(digest)
                captures.append(item)
                temporary = output / "capture-report.json.tmp"
                temporary.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
                temporary.replace(output / "capture-report.json")
                print(json.dumps({"captured_sha256": digest,
                                  "matching_decryption_key": item["matching_decryption_key"]}), flush=True)
            time.sleep(min(interval, max(0, deadline - time.monotonic())))
    finally:
        (output / "capture-report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--watch-root", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--seconds", type=float, default=600)
    parser.add_argument("--index", type=Path, help="Optional encrypted Manifest.db to verify captured keys")
    args = parser.parse_args()
    if args.seconds <= 0:
        parser.error("--seconds must be positive")
    capture(args.watch_root, args.out, args.seconds, args.index,
            os.environ.get("MDMLAB_BACKUP_PASSWORD", "mdm"))


if __name__ == "__main__":
    main()
