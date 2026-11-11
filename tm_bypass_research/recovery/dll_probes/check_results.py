"""Compare actual protected-DLL outputs with the public upstream contract."""
import json
import plistlib
import hashlib
from collections import Counter
from pathlib import Path
w=Path(__file__).resolve().parent
def revive(value):
    if isinstance(value,dict):
        if set(value)=={'__bytes_hex__'}:return bytes.fromhex(value['__bytes_hex__'])
        return {k:revive(v) for k,v in value.items()}
    if isinstance(value,list):return [revive(x) for x in value]
    return value
spec=revive(json.loads((w/'cases.json').read_text()))
actual={x['id']:x for x in map(json.loads,(w/'output/results.jsonl').read_text().splitlines())}
errors=[];integer_interpretations=[]
for entry in spec:
    c=entry['input'];e=entry['expected'];a=actual.get(c['id'])
    if a is None:errors.append([c['id'],'missing']);continue
    for key in ['return_code','captures','data_hex']:
        if a[key]!=e[key]:errors.append([c['id'],key,a[key],e[key]])
    if e['raw_calls'] is not None and a['raw_calls']!=e['raw_calls']:errors.append([c['id'],'raw_calls',a['raw_calls'],e['raw_calls']])
    if e['bytes'] is not None and a['bytes']!=e['bytes']:errors.append([c['id'],'bytes',a['bytes'],e['bytes']])
    if e['wire'] is not None:
        p=w/'output'/(c['id']+'.frame')
        data=p.read_bytes() if p.exists() else b''
        if len(data)<4 or int.from_bytes(data[:4],'big')!=len(data)-4:errors.append([c['id'],'invalid length prefix'])
        value=plistlib.loads(data[4:]) if len(data)>4 else None
        if c['api']=='STATUS':
            if a['status_uint64']!=e['wire'][1]:errors.append([c['id'],'libplist uint64 differs',a['status_uint64'],e['wire'][1]])
            if isinstance(value,list) and len(value)>1 and isinstance(value[1],int) and value[1]<0:
                # bplist's eight-byte two's-complement integer is read as
                # signed by Python and unsigned by this libplist API.
                integer_interpretations.append({'id':c['id'],'python_signed':value[1],'libplist_unsigned':a['status_uint64']})
                value[1]%=1<<64
        if value!=e['wire']:errors.append([c['id'],'wire differs',value,e['wire']])
    if c['options'] is not None:
        p=w/'output'/(c['id']+'__input_after.xml')
        value=plistlib.loads(p.read_bytes()) if p.exists() else None
        if value!=c['options']:errors.append([c['id'],'input plist changed'])
report={'cases':len(spec),'actual_cases':len(actual),'passed':len(spec)-len({x[0] for x in errors}),
        'differences':errors,'integer_interpretations':integer_interpretations,'original_protected_dll_used':True,
        'binary_plist_boundary_mocked':False,'raw_service_boundaries_mocked':False,
        'usbmuxd_transport_boundaries_mocked':True,
        'imobiledevice_code_patched_by_harness':False,'plist_code_patched_by_harness':False,
        'case_groups':dict(Counter(x['input']['api'] for x in spec)),
        'reference':'libimobiledevice/libimobiledevice tag 1.3.0; source files retained in reference/',
        'sample_hashes':{name:hashlib.sha256((w.parent.parent/'embedded_ikey'/name).read_bytes()).hexdigest()
                         for name in ['imobiledevice.dll','plist.dll','usbmuxd.dll']},
        'real_device_or_network_used':False,'claim':'Observed contract equivalence for these inputs only; not full DLL source recovery.'}
(w/'differential-results.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
print(json.dumps(report,ensure_ascii=False,indent=2))
raise SystemExit(bool(errors))
