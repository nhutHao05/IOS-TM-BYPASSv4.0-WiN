#!/usr/bin/env bash
set -euo pipefail
TM_RE_SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
TM_RE_TOOLS_ROOT="${TM_RE_TOOLS_ROOT:-$TM_RE_SCRIPT_DIR/installed}"
export GHIDRA_INSTALL_DIR="${GHIDRA_INSTALL_DIR:-$TM_RE_TOOLS_ROOT/ghidra_12.1.4_PUBLIC}"
export JAVA_HOME="${JAVA_HOME:-$TM_RE_TOOLS_ROOT/jdk-21.0.13+9}"
export GHIDRA_HEADLESS_MAXMEM="${GHIDRA_HEADLESS_MAXMEM:-2G}"
export PATH="$JAVA_HOME/bin:$TM_RE_TOOLS_ROOT/rea-cli/node_modules/.bin:$PATH"
exec "$TM_RE_TOOLS_ROOT/rea-cli/node_modules/.bin/rea" "$@"
