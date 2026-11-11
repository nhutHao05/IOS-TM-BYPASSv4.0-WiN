#!/usr/bin/env bash
set -euo pipefail
RE_TASK_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
exec java -Xmx2G -Xshare:off \
  -Djava.system.class.loader=ghidra.GhidraClassLoader \
  -Djava.awt.headless=true \
  -Duser.home="$RE_TASK_DIR/ghidra_home" \
  -cp "$RE_TASK_DIR/ghidra/ghidra_11.3.2_PUBLIC/Ghidra/Framework/Utility/lib/Utility.jar" \
  ghidra.Ghidra ghidra.app.util.headless.AnalyzeHeadless "$@"
