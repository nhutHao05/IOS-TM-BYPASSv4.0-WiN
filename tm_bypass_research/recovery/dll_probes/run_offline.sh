#!/usr/bin/env bash
set -euo pipefail
RE_PROBE_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
RE_RESEARCH_DIR="$(cd -- "$RE_PROBE_DIR/../.." && pwd)"
python "$RE_PROBE_DIR/generate_cases.py"
mkdir -p "$RE_PROBE_DIR/output"
chmod 755 "$RE_PROBE_DIR/src"
chmod 644 "$RE_PROBE_DIR/src/"*
chmod 777 "$RE_PROBE_DIR/output"
python - "$RE_PROBE_DIR" <<'PY'
import shutil,sys
free=shutil.disk_usage(sys.argv[1]).free
if free<3*1024**3:
    raise SystemExit('The VFS Docker driver needs about 3 GiB free for this Wine image; release old analysis containers first.')
PY
env -u DOCKER_HOST -u DOCKER_CONTEXT -u DOCKER_TLS -u DOCKER_TLS_VERIFY -u DOCKER_CERT_PATH \
  docker --host=unix:///var/run/docker.sock run --rm --pull=never \
  --name tm-mdm-contract-probe --label codex.research=tm-mdm \
  --network none --cap-drop ALL --security-opt no-new-privileges \
  --pids-limit 256 --memory 2g --cpus 2 --read-only \
  --tmpfs /tmp:rw,exec,nosuid,size=1g --tmpfs /run:rw,nosuid,size=16m \
  --mount "type=bind,src=$RE_RESEARCH_DIR/embedded_ikey,dst=/input,readonly" \
  --mount "type=bind,src=$RE_PROBE_DIR/src,dst=/runner,readonly" \
  --mount "type=bind,src=$RE_PROBE_DIR/output,dst=/output" \
  -e HTTP_PROXY= -e HTTPS_PROXY= -e ALL_PROXY= -e http_proxy= -e https_proxy= -e all_proxy= \
  -e XDG_CACHE_HOME=/tmp/cache -e WINEDLLOVERRIDES=winemenubuilder.exe=d \
  tm-mdm-analysis:local sh -c '
    mkdir -p /tmp/bin /tmp/compiler
    ln -sf /usr/bin/gcc /tmp/bin/g++
    export PATH=/tmp/bin:$PATH TMPDIR=/tmp/compiler
    cd /tmp
    winegcc-stable -m64 -o /tmp/probe.exe /runner/probe_matrix.c -lkernel32 > /output/compile.log 2>&1 || exit 50
    WINELOADER=/usr/lib/wine/wine64 timeout 100 /tmp/probe.exe > /output/run.log 2>&1
    result=$?
    echo "$result" > /output/run.exit
    exit "$result"
  '
python "$RE_PROBE_DIR/check_results.py"
