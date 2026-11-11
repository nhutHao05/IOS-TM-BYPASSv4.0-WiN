import hashlib
import json
from pathlib import Path
import plistlib
import shutil
import struct
import subprocess
import sys
import tempfile
import time
import unittest

from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.keywrap import aes_key_wrap

import capture_manifest


def fixture():
    def tlv(tag, value):
        if isinstance(value, int):
            value = struct.pack(">I", value)
        return tag + struct.pack(">I", len(value)) + value
    salt, class_key, index_key = bytes(range(20)), b"c" * 32, b"i" * 32
    passkey = hashlib.pbkdf2_hmac("sha1", b"mdm", salt, 23, 32)
    bag = b"".join(tlv(tag, value) for tag, value in [
        (b"VERS", 3), (b"TYPE", 1), (b"UUID", b"u" * 16), (b"SALT", salt),
        (b"ITER", 23), (b"UUID", b"v" * 16), (b"CLAS", 4), (b"WRAP", 2),
        (b"WPKY", aes_key_wrap(passkey, class_key))])
    manifest = {"IsEncrypted": True, "BackupKeyBag": bag,
                "ManifestKey": struct.pack("<I", 4) + aes_key_wrap(class_key, index_key)}
    cipher = Cipher(algorithms.AES(index_key), modes.CBC(bytes(16))).encryptor()
    return manifest, cipher.update(b"SQLite format 3\0") + cipher.finalize()


class CaptureTests(unittest.TestCase):
    def test_keys_must_decrypt_the_selected_index(self):
        with tempfile.TemporaryDirectory() as tmp:
            index = Path(tmp) / "Manifest.db"
            manifest, ciphertext = fixture()
            index.write_bytes(ciphertext)
            self.assertTrue(capture_manifest.verify_index(manifest, index, "mdm")["matching_decryption_key"])
            self.assertFalse(capture_manifest.verify_index(manifest, index, "wrong")["matching_decryption_key"])
            corrupted = dict(manifest, ManifestKey=manifest["ManifestKey"][:-1] + bytes([manifest["ManifestKey"][-1] ^ 1]))
            self.assertFalse(capture_manifest.verify_index(corrupted, index, "mdm")["matching_decryption_key"])
            index.write_bytes(b"x" * 16)
            self.assertFalse(capture_manifest.verify_index(manifest, index, "mdm")["matching_decryption_key"])

    def test_partial_write_then_directory_cleanup_preserves_manifest(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            watch, out = root / "ikey", root / "private-captures"
            manifest, ciphertext = fixture()
            index = root / "Manifest.db"
            index.write_bytes(ciphertext)
            proc = subprocess.Popen([sys.executable, str(Path(capture_manifest.__file__)),
                                     "--watch-root", str(watch), "--out", str(out),
                                     "--seconds", "3", "--index", str(index)],
                                    stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            try:
                work = watch / "LAB-UDID"
                work.mkdir(parents=True)
                raw = plistlib.dumps(manifest)
                path = work / "Manifest.plist"
                path.write_bytes(raw[:40])
                time.sleep(0.1)
                path.write_bytes(raw)
                receipt = out / "capture-report.json"
                deadline = time.monotonic() + 2
                while not receipt.exists() and time.monotonic() < deadline:
                    time.sleep(0.02)
                self.assertTrue(receipt.exists(), "Watcher did not capture completed plist")
                shutil.rmtree(watch)
                stdout, stderr = proc.communicate(timeout=5)
                self.assertEqual(proc.returncode, 0, stderr)
                report = json.loads(receipt.read_text())
                self.assertEqual(len(report["captures"]), 1)
                self.assertTrue(report["captures"][0]["matching_decryption_key"])
                self.assertEqual((out / report["captures"][0]["capture_file"]).read_bytes(), raw)
                self.assertNotIn("BackupKeyBag", stdout)
            finally:
                if proc.poll() is None:
                    proc.terminate()
                    proc.communicate(timeout=5)


if __name__ == "__main__":
    unittest.main()
