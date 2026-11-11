#!/usr/bin/env python3
"""Install the verified Linux x86-64 REA stack into an isolated directory."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import stat
import subprocess
import sys
import tarfile
import tempfile
import urllib.request
import zipfile

REA_COMMIT = "0909d89c966c30955fd0906b622ff25f3700789f"
REA_VERSION = "6.8.0"
GHIDRA = {
    "directory": "ghidra_12.1.4_PUBLIC",
    "url": "https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.1.4_build/ghidra_12.1.4_PUBLIC_20260921.zip",
    "sha256": "ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db",
    "kind": "zip",
}
JDK = {
    "directory": "jdk-21.0.13+9",
    "url": "https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.13%2B9/OpenJDK21U-jdk_x64_linux_hotspot_21.0.13_9.tar.gz",
    "sha256": "d7f5d5cf865a2902b70ff549b97586a7d3f234e016f041ab447ea740c7d66d1c",
    "kind": "tar",
}


def run(*args):
    subprocess.run([str(a) for a in args], check=True)


def capture(*args):
    return subprocess.check_output([str(a) for a in args], text=True).strip()


def install_archive(root, spec):
    target = root / spec["directory"]
    if target.exists():
        print(f"Keeping existing installation: {target}", flush=True)
        return
    with tempfile.TemporaryDirectory(prefix="download-", dir=root) as tmp:
        tmp = Path(tmp)
        archive = tmp / "archive"
        digest = hashlib.sha256()
        print(f"Downloading {spec['url']}", flush=True)
        with urllib.request.urlopen(spec["url"], timeout=60) as response, archive.open("wb") as out:
            while chunk := response.read(1024 * 1024):
                digest.update(chunk)
                out.write(chunk)
        if digest.hexdigest() != spec["sha256"]:
            raise RuntimeError("Publisher archive SHA-256 mismatch")
        extracted = tmp / "extracted"
        extracted.mkdir()
        if spec["kind"] == "zip":
            with zipfile.ZipFile(archive) as z:
                for member in z.infolist():
                    dest = (extracted / member.filename).resolve()
                    if not dest.is_relative_to(extracted):
                        raise RuntimeError("Archive path escapes extraction directory")
                    z.extract(member, extracted)
                    mode = member.external_attr >> 16
                    if mode:
                        dest.chmod(stat.S_IMODE(mode))
        else:
            with tarfile.open(archive) as t:
                t.extractall(extracted, filter="data")
        (extracted / spec["directory"]).rename(target)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parent / "installed")
    args = parser.parse_args()
    if platform.system() != "Linux" or platform.machine() not in ("x86_64", "amd64"):
        parser.error("These pinned native archives support Linux x86-64 only.")
    if sys.version_info < (3, 12):
        parser.error("Python 3.12+ is required for filtered tar extraction.")
    for command in ("git", "node", "npm", "ps"):
        if not shutil.which(command):
            parser.error(f"Missing host prerequisite: {command}")
    node = tuple(map(int, capture("node", "--version").lstrip("v").split(".")))
    if not ((node[0] == 22 and node >= (22, 23, 4)) or
            (node[0] == 24 and node >= (24, 22, 1)) or node >= (26, 12, 1)):
        parser.error("REA 6.8.0 requires Node ^22.23.4 || ^24.22.1 || >=26.12.1.")
    root = args.root.resolve()
    root.mkdir(parents=True, exist_ok=True)
    source = root / "rea-source"
    if not source.exists():
        run("git", "init", source)
        run("git", "-C", source, "remote", "add", "origin", "https://github.com/morluto/rea.git")
        run("git", "-C", source, "fetch", "--depth", "1", "origin", REA_COMMIT)
        run("git", "-C", source, "checkout", "--detach", "FETCH_HEAD")
    if capture("git", "-C", source, "rev-parse", "HEAD") != REA_COMMIT:
        raise RuntimeError("REA source is at a different commit; existing checkout was preserved")
    prefix = root / "rea-cli"
    package = prefix / "node_modules/rea-agents/package.json"
    if not package.exists() or json.loads(package.read_text()).get("version") != REA_VERSION:
        run("npm", "install", "--prefix", prefix, "--omit=optional", "--no-audit", "--no-fund", f"rea-agents@{REA_VERSION}")
    install_archive(root, GHIDRA)
    install_archive(root, JDK)
    venv = root / "symbolic-venv"
    if shutil.which("uv"):
        if not (venv / "bin/python").exists():
            run("uv", "venv", venv, "--python", sys.executable)
        run("uv", "pip", "install", "--python", venv / "bin/python", "--only-binary=:all:",
            "triton-library==1.0.0rc4", "z3-solver==5.4.1.0")
    else:
        if not (venv / "bin/python").exists():
            run(sys.executable, "-m", "venv", venv)
        run(venv / "bin/python", "-m", "pip", "install", "--only-binary=:all:",
            "triton-library==1.0.0rc4", "z3-solver==5.4.1.0")
    manifest = {"rea_repository": "https://github.com/morluto/rea.git", "rea_source_commit": REA_COMMIT,
                "rea_cli_version": REA_VERSION, "ghidra": GHIDRA, "jdk": JDK,
                "triton_library": "1.0.0rc4", "z3_solver": "5.4.1.0"}
    (root / "installation.json").write_text(json.dumps(manifest, indent=2) + "\n")
    env = dict(os.environ, GHIDRA_INSTALL_DIR=str(root / GHIDRA["directory"]),
               JAVA_HOME=str(root / JDK["directory"]))
    doctor = subprocess.run([str(prefix / "node_modules/.bin/rea"), "doctor", "--provider", "ghidra", "--format", "json"],
                            env=env, stdout=subprocess.PIPE, text=True)
    (root / "doctor-ghidra.json").write_text(doctor.stdout)
    doctor.check_returncode()
    print(f"Installed. Doctor report: {root / 'doctor-ghidra.json'}")


if __name__ == "__main__":
    main()
