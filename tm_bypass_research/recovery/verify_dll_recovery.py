"""Audit the DLL analysis copy; virtualized function bodies remain unresolved."""
from pathlib import Path
import hashlib
import json

r=Path(__file__).resolve().parent/'dll_calls'
old=(r.parent/'vmp_input/imobiledevice.dll.unpacked').read_bytes()
new=(r/'imobiledevice.analysis-only.dll').read_bytes()
assert len(old)==len(new)
rows=json.loads((r/'native-call-semantics.json').read_text())
calls=[x for x in rows if x.get('kind')!='jmp']
assert len(calls)==480 and all(x['padding_patch_verified'] for x in calls)
wanted={}
for row in calls:
    assert all(row[k] for k in ['api_target_matches_prior_emulation','argument_registers_preserved',
                                'return_value_preserved','nonvolatile_preserved'])
    for patch in row['remove_pushes']+[row['remove_return_padding']]:
        offset=int(patch['address'],16)-0x180000000
        for i in range(patch['size']):wanted[offset+i]=0x90
    if row.get('call_to_jump_patch'):
        p=row['call_to_jump_patch'];offset=int(p['address'],16)-0x180000000
        assert old[offset]==p['before']==0xe8
        wanted[offset]=p['after']
changed={i for i,(a,b) in enumerate(zip(old,new)) if a!=b}
assert changed==set(wanted) and all(new[i]==value for i,value in wanted.items())
exports=json.loads((r/'export-entry-audit.json').read_text())
assert len(exports)==287
for entry in exports:
    offset=int(entry['address'],16)-0x180000000
    assert old[offset:offset+5]==new[offset:offset+5]
files=list((r/'c_partial').glob('*.c'))
warnings=[p.name for p in files if 'WARNING' in p.read_text()]
result={
    'named_import_call_sites':len(calls),'verified_import_call_sites':len(calls),
    'tail_import_wrappers':sum(x.get('tail_import_wrapper',False) for x in calls),
    'analysis_copy_changed_bytes':len(changed),
    'exports':len(exports),'exports_entering_vm':sum(x['virtualized_entry'] for x in exports),
    'linear_sweep_vm_entry_jumps':len(rows)-len(calls),
    'pseudocode_fragments_exported':len(files),'fragments_with_explicit_warnings':len(warnings),
    'complete_dll_source_recovered':False,
    'analysis_copy_sha256':hashlib.sha256(new).hexdigest(),
    'scope':'Import-call ABI and analysis-copy changes only; not complete VM devirtualization.'
}
(r/'verification.json').write_text(json.dumps(result,indent=2))
print(json.dumps(result,indent=2))
