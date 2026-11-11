"""Check that literal recovery preserves every other managed method byte.

Read-only structural validation, not a claim that device operations succeed.
Run with PYTHONPATH=../deps from this task's research directory.
"""
import hashlib
import json
import logging
from collections import defaultdict
from pathlib import Path
import dnfile
from dncil.cil.body.reader import read_method_body_from_bytes

logging.disable(logging.CRITICAL)
w = Path(__file__).resolve().parent.parent
r = w / 'recovery'
before = dnfile.dnPE(str(w / 'TM-BYPASS.section_decrypted.exe'))
after = dnfile.dnPE(str(r / 'TM-BYPASS.analysis-only.exe'))
resolved = json.loads((w / 'resolved_constants.json').read_text())
by_method = defaultdict(list)
for item in resolved:
    by_method[item['method']].append(item)

assert len(before.net.mdtables.MethodDef.rows) == len(after.net.mdtables.MethodDef.rows) == 362
body_count = 0
literal_count = 0
for rid, old in enumerate(before.net.mdtables.MethodDef.rows, 1):
    new = after.net.mdtables.MethodDef.rows[rid - 1]
    assert old.Rva == new.Rva, ('RVA changed', rid)
    if not old.Rva:
        continue
    body_count += 1
    original = read_method_body_from_bytes(before.get_data(old.Rva, 500000))
    recovered = read_method_body_from_bytes(after.get_data(new.Rva, 500000))
    assert original.size == recovered.size
    expected = bytearray(before.get_data(old.Rva, original.size))
    actual = after.get_data(new.Rva, recovered.size)
    instructions = original.instructions
    indexes = {i.offset: n for n, i in enumerate(instructions)}
    after_instructions = {i.offset: i for i in recovered.instructions}
    for item in by_method[rid]:
        offset = int(item['il'], 16)
        pos = indexes[offset] - 1
        while str(instructions[pos].opcode) in ('br', 'br.s', 'nop'):
            pos -= 1
        arg = instructions[pos]
        replacement = after_instructions[offset]
        assert str(replacement.opcode) == 'ldstr', (rid, offset)
        token = replacement.operand.value
        assert token >> 24 == 0x70
        value = after.net.user_strings.get(token & 0xffffff).value
        assert value == item['value'], ('literal differs', rid, offset)
        assert actual[arg.offset:arg.offset + arg.size] == bytes(arg.size)
        expected[arg.offset:arg.offset + arg.size] = bytes(arg.size)
        expected[offset:offset + 5] = actual[offset:offset + 5]
        literal_count += 1
    assert bytes(expected) == actual, ('unexpected method byte change', rid)

assert literal_count == 1444
per_token = list((r / 'csharp_by_token').glob('*.cs'))
assert len(per_token) == 362
assert not list((r / 'csharp_by_token').glob('*.error'))
warnings = [p.name for p in per_token if any(s in p.read_text() for s in (
    'Unknown result type', 'Error decompiling', 'Expected O, but got Unknown', 'Invalid IL code'))]
compile_log = (r / 'compile_app.log').read_text()
assert 'error CS' not in compile_log
result = {
    'method_definitions': 362,
    'method_bodies_verified_byte_for_byte_except_literal_recovery': body_count,
    'literal_calls_verified': literal_count,
    'distinct_literals_in_calls': len({x['value'] for x in resolved}),
    'per_token_csharp_exports': len(per_token),
    'per_token_decompiler_warning_files': warnings,
    'application_compile_errors': 0,
    'application_compile_warnings': compile_log.count('warning CS'),
    'analysis_pe_sha256': hashlib.sha256((r / 'TM-BYPASS.analysis-only.exe').read_bytes()).hexdigest(),
    'original_application_executed': False,
    'real_device_tested': False,
}
(r / 'verification.json').write_text(json.dumps(result, indent=2))
print(json.dumps(result, indent=2))
