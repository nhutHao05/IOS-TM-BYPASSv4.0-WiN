"""Run the sample only inside the disposable offline analysis container."""
import hashlib
import json
import os
from pathlib import Path
import signal
import socket
import subprocess
import threading
import time

OUT = Path('/output')
OUT.mkdir(exist_ok=True)
events = []
layouts = json.loads(Path('/runner/image_layouts.json').read_text())


def log(kind, **kwargs):
    row = {'event': kind, 'time': round(time.monotonic(), 3), **kwargs}
    events.append(row)
    print(json.dumps(row), flush=True)


def hold_device_connections():
    sock = socket.socket()
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('127.0.0.1', 27015))
    sock.listen()
    while True:
        conn, _ = sock.accept()
        log('local_device_service_connection')
        def hold(c):
            c.settimeout(20)
            try:
                data = c.recv(16384)
                log('local_device_service_request', bytes=len(data))
                time.sleep(20)
            except OSError:
                pass
            finally:
                c.close()
        threading.Thread(target=hold, args=(conn,), daemon=True).start()


def snapshot(fd, layout, number):
    result = bytearray(layout['size'])
    ok = 0
    for offset in range(0, layout['size'], 4096):
        try:
            page = os.pread(fd, min(4096, layout['size'] - offset), layout['base'] + offset)
            result[offset:offset+len(page)] = page
            ok += len(page)
        except OSError:
            pass
    path = OUT / (layout['name'] + f'.memory{number}.bin')
    path.write_bytes(result)
    log('snapshot', image=layout['name'], bytes_read=ok, size=len(result),
        sha256=hashlib.sha256(result).hexdigest(), filename=path.name)


wine = '/usr/lib/wine/wine64'
env = os.environ.copy()
env['WINEDLLOVERRIDES'] = 'winemenubuilder.exe=d;mscoree,mshtml='
env['WINEDEBUG'] = '-all'
with (OUT / 'wine_init.log').open('wb') as log_file:
    try:
        r = subprocess.run([wine, 'cmd.exe', '/c', 'exit'], env=env,
                           stdout=log_file, stderr=subprocess.STDOUT, timeout=35)
        log('wine_initialized', returncode=r.returncode)
    except subprocess.TimeoutExpired:
        log('wine_init_timeout')

threading.Thread(target=hold_device_connections, daemon=True).start()
env['WINEDEBUG'] = '+loaddll,+seh'
seen = {}
counts = {}
last_dump = {}
fd = None
with (OUT / 'wine_sample.log').open('wb') as log_file:
    p = subprocess.Popen([wine, '/input/MDM_SETUP.exe'], cwd='/input', env=env,
                         stdout=log_file, stderr=subprocess.STDOUT)
    log('sample_started', pid=p.pid)
    start = time.monotonic()
    permission_logged = False
    final_snapshot_done = False
    while time.monotonic() - start < 9:
        if p.poll() is not None:
            log('sample_exited', returncode=p.returncode)
            break
        if fd is not None:
            os.close(fd)
            fd = None
        if fd is None:
            try:
                fd = os.open(f'/proc/{p.pid}/mem', os.O_RDONLY)
            except OSError as e:
                if not permission_logged:
                    log('memory_open_error', error=str(e))
                    permission_logged = True
                time.sleep(.01)
                continue
        for layout in layouts:
            try:
                text = os.pread(fd, 4096, layout['base'] + layout['text_rva'])
            except OSError:
                continue
            if not text or not any(text):
                continue
            digest = hashlib.sha256(text).hexdigest()
            name = layout['name']
            now = time.monotonic()
            count = counts.get(name, 0)
            if (digest != seen.get(name) and count < 3) or (count == 1 and now-last_dump[name] > .75):
                log('text_observed', image=name, text_hash=digest)
                snapshot(fd, layout, count)
                seen[name] = digest
                counts[name] = count + 1
                last_dump[name] = now
        if not final_snapshot_done and time.monotonic()-start >= 4 and all(counts.get(x['name'],0) for x in layouts):
            for layout in layouts:
                snapshot(fd, layout, '_ready')
            final_snapshot_done = True
        time.sleep(.005)
    else:
        log('sample_observation_timeout')
    if p.poll() is None:
        p.terminate()
        try:
            p.wait(timeout=3)
        except subprocess.TimeoutExpired:
            p.kill()
    if fd is not None:
        os.close(fd)
(OUT / 'events.json').write_text(json.dumps(events, indent=2))
