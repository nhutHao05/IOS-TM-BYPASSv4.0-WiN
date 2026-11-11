"""Verify the measured import-call changes and check decompiler output coverage."""
from pathlib import Path
import hashlib
import json

r=Path(__file__).resolve().parent
original=(r/'vmp_input/MDM_SETUP.exe.unpacked').read_bytes()
patched=(r/'MDM_SETUP.analysis-only.exe').read_bytes()
assert len(original)==len(patched)
semantics=json.loads((r/'native-call-semantics.json').read_text())
assert len(semantics)==542
expected=set()
prefix=0x140000000
for item in semantics:
    assert item['padding_patch_verified']
    assert item['api_target_matches_prior_emulation']
    assert item['argument_registers_preserved']
    assert item['return_value_preserved']
    assert item['nonvolatile_preserved']
    # The input is reconstructed with section raw offsets equal to their RVAs.
    for patch in item['remove_pushes']+[item['remove_return_padding']]:
        offset=int(patch['address'],16)-prefix
        expected.update(range(offset,offset+patch['size']))
actual={i for i,(a,b) in enumerate(zip(original,patched)) if a!=b}
assert actual==expected
assert len(actual)==542
assert all(patched[i]==0x90 for i in actual)
coverage=(r/'native_c_reviewed/coverage.tsv').read_text().splitlines()
assert len(coverage)==64 and all('\tOK\t' in x for x in coverage)
assert not list((r/'native_c_reviewed').glob('*.error'))
main=(r/'native_c_reviewed/140004070.c').read_text()
assert all(x in main for x in ['"RestoreSystemFiles"','"RestoreDontCopyBackup"',
                              '"RestorePreserveSettings"','"Password"','"mdm"',
                              '"ErrorCode"','IKEY MDM Successful.'])
assert 'swi(3)' not in main
result={
    'native_import_call_sites_measured':542,
    'removed_dummy_register_pushes':sum(bool(x['remove_pushes']) for x in semantics),
    'removed_return_traps':sum(bool(x['remove_return_padding']['size']) for x in semantics),
    'changed_bytes_verified':len(actual),
    'native_core_functions_exported':len(coverage),
    'native_main_pseudocode_lines':len(main.splitlines()),
    'native_analysis_pe_sha256':hashlib.sha256(patched).hexdigest(),
    'native_pseudocode_compiled_or_device_tested':False,
    'protected_dll_fully_devirtualized':False,
}
(r/'native-verification.json').write_text(json.dumps(result,indent=2))
print(json.dumps(result,indent=2))
