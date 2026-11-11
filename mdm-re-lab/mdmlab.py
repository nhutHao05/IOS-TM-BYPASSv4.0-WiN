"""MDM RE Lab: USB observations, explicit protocol experiments, offline backup RE.

The legacy restore profile reproduces the observed TM-BYPASS request. Its MDM
effect is unsupported on iOS 27. An acknowledged request is never reported as
proof that MDM enrollment was removed.
"""
from __future__ import annotations
import argparse
import asyncio
import base64
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import plistlib
import sqlite3
import struct
import sys

RE_PROFILE = {
    "RestoreSystemFiles": False,
    "RestoreDontCopyBackup": True,
    "RestorePreserveSettings": True,
}
PATCH_KEYS = {
    "CloudConfigurationUIComplete", "ConfigurationWasApplied", "IsSupervised",
    "IsMDMUnremovable", "PostSetupProfileWasInstalled", "AwaitDeviceConfigured",
}


def json_value(value):
    if isinstance(value, bytes):
        return {"base64": base64.b64encode(value).decode()}
    if isinstance(value, datetime):
        return value.isoformat()
    raise TypeError(type(value).__name__)


def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_text(json.dumps(value, ensure_ascii=False, indent=2, default=json_value) + "\n", encoding="utf-8")
    temporary.replace(path)


def compatibility(version):
    try:
        major = int(str(version).split(".", 1)[0])
    except (ValueError, TypeError):
        major = None
    return {
        "ios_major": major,
        "legacy_mdm_restore": "unsupported_by_documented_ios_policy" if major is not None and major >= 27 else "not_validated_on_this_device",
        "mcinstall_state_experiment": "unverified",
    }


def validate_patch(patch):
    if not isinstance(patch, dict) or not patch:
        raise ValueError("Payload must be a nonempty JSON object")
    unknown = set(patch) - PATCH_KEYS
    if unknown:
        raise ValueError("Unsupported experiment keys: " + ", ".join(sorted(unknown)))
    if any(type(v) not in (bool, int) or v not in (False, True, 0, 1) for v in patch.values()):
        raise ValueError("Experiment values must be booleans or 0/1")
    return patch


def restore_message(target, source, password):
    return {"MessageName": "Restore", "TargetIdentifier": target,
            "SourceIdentifier": source, "Options": {**RE_PROFILE, "Password": password}}


class ProtocolRejected(RuntimeError):
    def __init__(self, response):
        self.response = response
        super().__init__("MCInstall rejected the request")


class Trace:
    def __init__(self, connection):
        self.connection = connection
        self.events = []

    async def request(self, kind, **fields):
        request = {"RequestType": kind, **fields}
        self.events.append({"request": request})
        try:
            response = await asyncio.wait_for(self.connection.send_recv_plist(request), timeout=30)
        except Exception as error:
            self.events[-1]["transport_error"] = {"type": type(error).__name__, "message": str(error)}
            raise
        self.events[-1]["response"] = response
        if not isinstance(response, dict) or response.get("Status") != "Acknowledged":
            raise ProtocolRejected(response)
        return response

    async def observe(self):
        result = {}
        for name in ("GetCloudConfiguration", "GetProfileList"):
            try:
                result[name] = await self.request(name)
            except ProtocolRejected as error:
                result[name] = {"rejected": error.response}
        return result

    async def apply(self, patch):
        validate_patch(patch)
        before = await self.observe()
        old = before.get("GetCloudConfiguration", {})
        if "rejected" in old:
            raise ProtocolRejected(old["rejected"])
        current = old.get("CloudConfiguration") or {}
        if not isinstance(current, dict):
            raise ValueError("CloudConfiguration is not a dictionary")
        report = {"before": before, "request_acknowledged": False,
                  "readback_matches": None, "mdm_enrollment_removed": "not_established"}
        try:
            await self.request("SetCloudConfiguration", CloudConfiguration={**current, **patch})
            report["request_acknowledged"] = True
        except ProtocolRejected as error:
            report["rejection"] = error.response
        report["after"] = await self.observe()
        after = report["after"].get("GetCloudConfiguration", {})
        cfg = after.get("CloudConfiguration")
        if isinstance(cfg, dict):
            report["readback_matches"] = all(k in cfg and cfg[k] == v for k, v in patch.items())
        report["result"] = ("rejected" if not report["request_acknowledged"] else
                            "local_flags_observed" if report["readback_matches"] is True else
                            "acknowledged_but_not_observed")
        return report


def inspect_backup(folder):
    folder = Path(folder).resolve()
    plists = {}
    for name in ("Info.plist", "Manifest.plist", "Status.plist"):
        try:
            value = plistlib.loads((folder / name).read_bytes())
        except (OSError, ValueError, plistlib.InvalidFileException) as error:
            raise ValueError(f"Cannot read {name}: {error}") from error
        if not isinstance(value, dict):
            raise ValueError(f"{name} must contain a dictionary")
        plists[name] = value
    if plists["Status.plist"].get("SnapshotState") != "finished":
        raise ValueError("Backup SnapshotState must be 'finished'")
    index = next((folder / n for n in ("Manifest.db", "Manifest.mbdb") if (folder / n).is_file()), None)
    if index is None:
        raise ValueError("Missing Manifest.db/Manifest.mbdb")
    manifest = plists["Manifest.plist"]
    if manifest.get("IsEncrypted") and not manifest.get("BackupKeyBag"):
        raise ValueError("Encrypted backup is missing BackupKeyBag")
    if manifest.get("IsEncrypted") and index.name == "Manifest.db" and not manifest.get("ManifestKey"):
        raise ValueError("Encrypted Manifest.db is missing ManifestKey")
    return {"folder": str(folder), "source": folder.name, "root": str(folder.parent),
            "encrypted": bool(manifest.get("IsEncrypted")), "index": index.name,
            "snapshot": "finished", "mdm_effect": "not_established"}


class Keybag:
    def __init__(self, data, password):
        from cryptography.hazmat.primitives.keywrap import aes_key_unwrap, InvalidUnwrap
        attrs, classes = {}, {}
        current = None
        offset = 0
        while offset < len(data):
            if offset + 8 > len(data):
                raise ValueError("Truncated keybag")
            tag, size = struct.unpack_from(">4sI", data, offset)
            offset += 8
            value = data[offset:offset+size]
            if len(value) != size:
                raise ValueError("Truncated keybag value")
            offset += size
            if tag == b"UUID":
                current = None
            elif tag == b"CLAS":
                current = {}
                classes[int.from_bytes(value, "big")] = current
            elif current is None:
                attrs[tag] = value
            else:
                current[tag] = value
        secret = password.encode("utf-8")
        if b"DPSL" in attrs:
            secret = hashlib.pbkdf2_hmac("sha256", secret, attrs[b"DPSL"], int.from_bytes(attrs[b"DPIC"], "big"), 32)
        secret = hashlib.pbkdf2_hmac("sha1", secret, attrs[b"SALT"], int.from_bytes(attrs[b"ITER"], "big"), 32)
        self.keys = {}
        for number, record in classes.items():
            if int.from_bytes(record.get(b"WRAP", b"\0"), "big") & 2:
                try:
                    self.keys[number] = aes_key_unwrap(secret, record[b"WPKY"])
                except InvalidUnwrap:
                    continue
        if not self.keys:
            raise ValueError("Password cannot unlock this backup keybag")

    def unwrap(self, value, protection=None):
        from cryptography.hazmat.primitives.keywrap import aes_key_unwrap
        if len(value) == 44:
            protection = struct.unpack_from("<I", value)[0]
            value = value[4:]
        if protection not in self.keys:
            raise ValueError(f"Protection class {protection} is unavailable")
        return aes_key_unwrap(self.keys[protection], value)


def decrypt_cbc(data, key):
    from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
    if len(data) % 16:
        raise ValueError("Encrypted data length is not a multiple of 16")
    ctx = Cipher(algorithms.AES(key), modes.CBC(bytes(16))).decryptor()
    return ctx.update(data) + ctx.finalize()


def keyed_value(value, objects):
    if isinstance(value, plistlib.UID):
        return keyed_value(objects[value.data], objects)
    if isinstance(value, dict) and "NS.data" in value:
        return keyed_value(value["NS.data"], objects)
    return value


def decrypt_record(folder, output, bag, file_id, raw):
    archive = plistlib.loads(raw)
    objects = archive["$objects"]
    root = keyed_value(archive["$top"]["root"], objects)
    wrapped = keyed_value(root["EncryptionKey"], objects)
    protection = keyed_value(root.get("ProtectionClass"), objects)
    size = keyed_value(root.get("Size"), objects)
    source = folder / file_id[:2] / file_id
    if not source.is_file():
        source = folder / file_id
    data = decrypt_cbc(source.read_bytes(), bag.unwrap(wrapped, protection))
    if not isinstance(size, int) or not 0 <= size <= len(data):
        raise ValueError("Invalid decrypted file size")
    destination = output / (file_id + ".decrypted")
    destination.write_bytes(data[:size])
    return {"bytes": size, "output": str(destination)}


def decrypt_backup(folder, output, password):
    folder, output = Path(folder).resolve(), Path(output).resolve()
    metadata = inspect_backup(folder)
    manifest = plistlib.loads((folder / "Manifest.plist").read_bytes())
    if not metadata["encrypted"] or metadata["index"] != "Manifest.db":
        raise ValueError("This decoder expects an encrypted Manifest.db backup")
    bag = Keybag(manifest["BackupKeyBag"], password)
    clear = decrypt_cbc((folder / "Manifest.db").read_bytes(), bag.unwrap(manifest["ManifestKey"]))
    if not clear.startswith(b"SQLite format 3\0"):
        raise ValueError("Decrypted index has no SQLite header; manifest does not match")
    page_size = int.from_bytes(clear[16:18], "big")
    page_size = 65536 if page_size == 1 else page_size
    page_count = int.from_bytes(clear[28:32], "big")
    if not page_size or not page_count or page_size * page_count > len(clear):
        raise ValueError("Invalid decrypted SQLite file size")
    output.mkdir(parents=True, exist_ok=True)
    db = output / "Manifest.decrypted.db"
    if db.resolve() == (folder / "Manifest.db").resolve():
        raise ValueError("Output must not overwrite the encrypted source")
    db.write_bytes(clear[:page_size * page_count])
    rows, undecoded = [], []
    with sqlite3.connect(db.as_uri() + "?mode=ro&immutable=1", uri=True) as conn:
        if conn.execute("PRAGMA quick_check").fetchone()[0] != "ok":
            raise ValueError("Decrypted SQLite integrity check failed")
        query = "SELECT fileID,domain,relativePath,file FROM Files WHERE flags=1 AND (lower(relativePath) LIKE '%configurationprofiles%' OR lower(relativePath) LIKE '%purplebuddy%')"
        for file_id, domain, relative, raw in conn.execute(query):
            if not isinstance(file_id, str) or len(file_id) != 40 or any(c not in "0123456789abcdef" for c in file_id.lower()):
                raise ValueError("Invalid backup fileID")
            identity = {"fileID": file_id, "domain": domain, "path": relative}
            try:
                rows.append({**identity, **decrypt_record(folder, output, bag, file_id, raw)})
            except Exception as error:
                undecoded.append({**identity, "error": {"type": type(error).__name__, "message": str(error)}})
    return {"index": str(db), "management_files": rows, "undecoded_files": undecoded,
            "complete": not undecoded}


async def connected(args):
    from pymobiledevice3.lockdown import create_using_usbmux
    return await create_using_usbmux(serial=args.udid, connection_type="USB", pair_timeout=45, label="MDM-RE-Lab")


async def devices():
    from pymobiledevice3.usbmux import list_devices
    found = await list_devices()
    return {"devices": [{"udid": d.serial, "connection": d.connection_type} for d in found
                        if d.connection_type == "USB"]}


async def device_action(args):
    from pymobiledevice3.services.mobile_config import MobileConfigService
    report = {"captured_at_utc": datetime.now(timezone.utc).isoformat(), "command": args.command,
              "mdm_enrollment_removed": "not_established"}
    async with await connected(args) as lockdown:
        values = await lockdown.get_value()
        report["device"] = {k: values.get(k) for k in ("ProductType", "ProductVersion", "BuildVersion", "UniqueDeviceID", "SerialNumber", "ActivationState", "IsSupervised")}
        report["compatibility"] = compatibility(values.get("ProductVersion"))
        try:
            if args.command == "restore":
                report.update(await restore_action(lockdown, args))
            else:
                async with MobileConfigService(lockdown) as config:
                    trace = Trace(config.service)
                    try:
                        if args.command == "apply-cloud":
                            patch = json.loads(Path(args.payload).read_text(encoding="utf-8"))
                            report["experiment"] = await trace.apply(patch)
                        else:
                            report["observations"] = await trace.observe()
                    finally:
                        report["protocol"] = trace.events
        except Exception as error:
            report["error"] = {"type": type(error).__name__, "message": str(error)}
    return report


async def restore_action(lockdown, args):
    from pymobiledevice3.services.mobilebackup2 import Mobilebackup2Service
    from pymobiledevice3.services.afc import AfcService
    from pymobiledevice3.services.notification_proxy import NotificationProxyService
    metadata = inspect_backup(args.backup)
    password = os.environ.get("MDMLAB_BACKUP_PASSWORD", "mdm")
    if not password:
        raise ValueError("MDMLAB_BACKUP_PASSWORD is empty")
    root, source = Path(metadata["root"]), metadata["source"]
    request = restore_message(lockdown.udid, source, password)
    progress = []
    async with Mobilebackup2Service(lockdown) as backup:
        backup._assert_backup_exists(root, source)
        async with (backup.device_link(root) as dl,
                    NotificationProxyService(lockdown) as notify,
                    AfcService(lockdown) as afc,
                    backup._backup_lock(afc, notify)):
            await dl.send_process_message(request)
            await dl.dl_loop(lambda value: progress.append(value))
    return {"backup": metadata, "restore_service_completed": True,
            "restore_options": {**RE_PROFILE, "Password": "<provided>"},
            "progress": progress, "mdm_enrollment_removed": "not_established"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("devices")
    for command in ("inspect", "apply-cloud", "restore"):
        p = sub.add_parser(command)
        p.add_argument("--udid", required=True, help="Explicit target UDID")
        p.add_argument("--out", default=f"runs/{command}.json")
        if command == "apply-cloud":
            p.add_argument("--payload", required=True, help="JSON state experiment; no MDM-removal guarantee")
        if command == "restore":
            p.add_argument("--backup", required=True, help="Device backup directory containing Info.plist")
    p = sub.add_parser("inspect-backup")
    p.add_argument("backup")
    p = sub.add_parser("decrypt-backup")
    p.add_argument("backup")
    p.add_argument("--out", required=True)
    args = parser.parse_args()
    try:
        if args.command == "devices":
            report = asyncio.run(devices())
        elif args.command == "inspect-backup":
            report = inspect_backup(args.backup)
        elif args.command == "decrypt-backup":
            report = decrypt_backup(args.backup, args.out, os.environ.get("MDMLAB_BACKUP_PASSWORD", "mdm"))
            save(Path(args.out) / "decryption-report.json", report)
        else:
            try:
                report = asyncio.run(device_action(args))
            except Exception as error:
                report = {"command": args.command, "mdm_enrollment_removed": "not_established",
                          "error": {"type": type(error).__name__, "message": str(error)}}
            save(args.out, report)
        print(json.dumps(report, ensure_ascii=False, indent=2, default=json_value))
        if "error" in report or report.get("experiment", {}).get("rejection"):
            return 1
        if report.get("experiment", {}).get("result") == "acknowledged_but_not_observed":
            return 2
        if report.get("complete") is False:
            return 2
        return 0
    except Exception as error:
        print(json.dumps({"error": {"type": type(error).__name__, "message": str(error)}}), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
