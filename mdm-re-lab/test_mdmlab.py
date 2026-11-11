import asyncio
import hashlib
import json
import os
from pathlib import Path
import plistlib
import sqlite3
import struct
import tempfile
import unittest

import mdmlab
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.keywrap import aes_key_wrap
from pymobiledevice3.exceptions import PyMobileDevice3Exception
from pymobiledevice3.services.mobilebackup2 import DeviceLink


class FakeMCInstall:
    def __init__(self, reject=False, apply=True):
        self.config = {"OrganizationName": "LAB", "IsSupervised": True}
        self.reject = reject
        self.apply_change = apply

    async def send_recv_plist(self, request):
        kind = request["RequestType"]
        if kind == "GetCloudConfiguration":
            return {"Status": "Acknowledged", "CloudConfiguration": dict(self.config)}
        if kind == "GetProfileList":
            return {"Status": "Acknowledged", "ProfileMetadata": {"lab.mdm": {"PayloadType": "com.apple.mdm"}}}
        if kind == "SetCloudConfiguration":
            if self.reject:
                return {"Status": "Error", "ErrorChain": [{"ErrorCode": 14002}]}
            if self.apply_change:
                self.config = dict(request["CloudConfiguration"])
            return {"Status": "Acknowledged"}
        raise AssertionError(kind)


class ProtocolTests(unittest.IsolatedAsyncioTestCase):
    async def test_local_flags_do_not_prove_mdm_removed(self):
        trace = mdmlab.Trace(FakeMCInstall())
        report = await trace.apply({"IsSupervised": False})
        self.assertTrue(report["request_acknowledged"])
        self.assertTrue(report["readback_matches"])
        self.assertEqual(report["mdm_enrollment_removed"], "not_established")
        self.assertIn("lab.mdm", report["after"]["GetProfileList"]["ProfileMetadata"])
        self.assertEqual(report["after"]["GetCloudConfiguration"]["CloudConfiguration"]["OrganizationName"], "LAB")

    async def test_rejection_preserves_raw_protocol_error(self):
        trace = mdmlab.Trace(FakeMCInstall(reject=True))
        report = await trace.apply({"IsSupervised": False})
        self.assertFalse(report["request_acknowledged"])
        self.assertEqual(report["result"], "rejected")
        self.assertEqual(report["rejection"]["ErrorChain"][0]["ErrorCode"], 14002)

    async def test_acknowledged_but_ignored_write_is_visible(self):
        report = await mdmlab.Trace(FakeMCInstall(apply=False)).apply({"IsSupervised": False})
        self.assertTrue(report["request_acknowledged"])
        self.assertFalse(report["readback_matches"])
        self.assertEqual(report["result"], "acknowledged_but_not_observed")

    async def test_actual_device_link_rejects_error_status(self):
        class Peer:
            async def recv_plist(self):
                return ["DLMessageProcessMessage", {"ErrorCode": 12345, "ErrorDescription": "lab rejection"}]
        with self.assertRaises(PyMobileDevice3Exception):
            await DeviceLink(Peer(), Path(".")).dl_loop()

    async def test_actual_device_link_accepts_zero_status(self):
        class Peer:
            async def recv_plist(self):
                return ["DLMessageProcessMessage", {"ErrorCode": 0, "Content": "finished"}]
        self.assertEqual(await DeviceLink(Peer(), Path(".")).dl_loop(), "finished")


class FixtureTests(unittest.TestCase):
    def setUp(self):
        scratch = Path(__file__).parent / ".testwork"
        scratch.mkdir(exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=scratch)
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)

    def test_restore_profile_matches_captured_native_request(self):
        captured = json.loads((Path(__file__).parent / "protocol/restore-reference.json").read_text())["request"]
        report = mdmlab.restore_message(captured["TargetIdentifier"], captured["SourceIdentifier"], captured["Options"]["Password"])
        self.assertEqual(report, captured)

    def test_ios27_compatibility_is_not_assumed(self):
        self.assertEqual(mdmlab.compatibility("27.0.1")["legacy_mdm_restore"], "unsupported_by_documented_ios_policy")
        self.assertEqual(mdmlab.compatibility("27.0.1")["mcinstall_state_experiment"], "unverified")

    def test_real_tm_payload_missing_manifest_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "Info.plist"):
            mdmlab.inspect_backup(self.root)

    def test_payload_scope_validation(self):
        with self.assertRaises(ValueError):
            mdmlab.validate_patch({"EraseDevice": True})

    def test_encrypted_backup_round_trip(self):
        backup, output = self.root / "SOURCE", self.root / "decrypted"
        backup.mkdir()
        password = "lab-password"
        salt, dpsl = os.urandom(20), os.urandom(20)
        passkey = hashlib.pbkdf2_hmac("sha256", password.encode(), dpsl, 19, 32)
        passkey = hashlib.pbkdf2_hmac("sha1", passkey, salt, 23, 32)
        class_key, index_key, file_key = os.urandom(32), os.urandom(32), os.urandom(32)

        def tlv(tag, value):
            if isinstance(value, int):
                value = struct.pack(">I", value)
            return tag + struct.pack(">I", len(value)) + value

        keybag = b"".join(tlv(tag, value) for tag, value in [
            (b"VERS", 3), (b"UUID", os.urandom(16)), (b"SALT", salt), (b"ITER", 23),
            (b"DPSL", dpsl), (b"DPIC", 19), (b"UUID", os.urandom(16)), (b"CLAS", 4),
            (b"WRAP", 2), (b"WPKY", aes_key_wrap(passkey, class_key))])
        manifest = {"IsEncrypted": True, "BackupKeyBag": keybag,
                    "ManifestKey": struct.pack("<I", 4) + aes_key_wrap(class_key, index_key)}
        for name, value in [("Info.plist", {"ProductType": "iPhone12,8"}),
                            ("Manifest.plist", manifest),
                            ("Status.plist", {"SnapshotState": "finished"})]:
            (backup / name).write_bytes(plistlib.dumps(value))

        def encrypt(data, key):
            padding = 16 - len(data) % 16
            ctx = Cipher(algorithms.AES(key), modes.CBC(bytes(16))).encryptor()
            return ctx.update(data + bytes([padding]) * padding) + ctx.finalize()

        domain = "SysSharedContainerDomain-systemgroup.com.apple.configurationprofiles"
        path = "Library/ConfigurationProfiles/CloudConfigurationDetails.plist"
        file_id = hashlib.sha1((domain + "-" + path).encode()).hexdigest()
        plain = plistlib.dumps({"CloudConfigurationUIComplete": True, "IsSupervised": False})
        archive = {"$objects": ["$null", {"EncryptionKey": plistlib.UID(2), "ProtectionClass": 4, "Size": len(plain)},
                                  struct.pack("<I", 4) + aes_key_wrap(class_key, file_key)],
                   "$top": {"root": plistlib.UID(1)}}
        db = self.root / "plain.db"
        with sqlite3.connect(db) as conn:
            conn.execute("CREATE TABLE Files (fileID TEXT,domain TEXT,relativePath TEXT,flags INTEGER,file BLOB)")
            conn.execute("INSERT INTO Files VALUES (?,?,?,?,?)", (file_id, domain, path, 1, plistlib.dumps(archive, fmt=plistlib.FMT_BINARY)))
        (backup / "Manifest.db").write_bytes(encrypt(db.read_bytes(), index_key))
        (backup / file_id[:2]).mkdir()
        (backup / file_id[:2] / file_id).write_bytes(encrypt(plain, file_key))
        result = mdmlab.decrypt_backup(backup, output, password)
        self.assertEqual(Path(result["index"]).read_bytes(), db.read_bytes())
        self.assertEqual(Path(result["management_files"][0]["output"]).read_bytes(), plain)
        with self.assertRaises(ValueError):
            mdmlab.decrypt_backup(backup, self.root / "wrong-password", "incorrect")


if __name__ == "__main__":
    unittest.main()
