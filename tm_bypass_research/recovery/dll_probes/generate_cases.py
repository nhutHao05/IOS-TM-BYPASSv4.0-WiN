"""Generate inputs and an independent upstream-contract oracle for DLL probes."""
import copy
import json
import plistlib
from pathlib import Path

w=Path(__file__).resolve().parent
cases=[]
def add(case_id,api,**kwargs):
    row={'id':case_id,'api':api,'client':2,'name':None,'target':None,'source':None,
         'options':None,'status':0,'status_text':None,'raw_mode':0,
         'null_data':False,'zero_length':False,'null_bytes':False}
    row.update(kwargs);cases.append(row)

restore={'RestoreSystemFiles':False,'RestoreDontCopyBackup':True,
         'RestorePreserveSettings':True,'Password':'mdm'}
add('restore_full','REQUEST',name='Restore',target='LAB-TARGET',source='LAB-SOURCE',options=restore)
add('restore_minimal','REQUEST',name='Restore',target='LAB-TARGET')
add('backup','REQUEST',name='Backup',target='LAB-TARGET',source='LAB-SOURCE',options={'ForceFullBackup':True})
add('unback_password','REQUEST',name='Unback',target='LAB-TARGET',options={'Password':'lab-secret'})
add('unback_empty','REQUEST',name='Unback',target='LAB-TARGET',options={})
add('cloud_true','REQUEST',name='EnableCloudBackup',target='LAB-TARGET',options={'CloudBackupState':True})
add('cloud_false','REQUEST',name='EnableCloudBackup',target='LAB-TARGET',options={'CloudBackupState':False})
add('request_unknown','REQUEST',name='LabUnknownRequest',target='LAB-TARGET',options={'Item':['x',3], 'Data':b'\0\xff'})
add('request_null_name','REQUEST',target='LAB-TARGET')
add('request_null_target','REQUEST',name='Restore')
add('request_null_client','REQUEST',client=0,name='Restore',target='LAB-TARGET')
add('request_null_parent','REQUEST',client=1,name='Restore',target='LAB-TARGET')
add('request_empty_name','REQUEST',name='',target='LAB-TARGET')
add('request_empty_target','REQUEST',name='Restore',target='')
add('request_empty_source','REQUEST',name='Restore',target='LAB-TARGET',source='')
add('request_options_array','REQUEST',name='Restore',target='LAB-TARGET',options=['value',2])
add('request_nested_name','REQUEST',name='Restore',target='LAB-TARGET',options={'MessageName':'NestedOnly'})
add('request_utf8','REQUEST',name='Info',target='LAB-TARGET',options={'Label':'Nghiên cứu'})
add('message_simple','MESSAGE',name='Info')
add('message_options','MESSAGE',name='Restore',options=restore)
add('message_overwrite','MESSAGE',name='Info',options={'MessageName':'Original','Value':5})
add('message_passthrough','MESSAGE',options={'MessageName':'Existing','Value':5})
add('message_no_name_key','MESSAGE',options={'Value':5})
add('message_both_null','MESSAGE')
add('message_array','MESSAGE',name='Info',options=[])
add('message_string','MESSAGE',name='Info',options='test')
add('message_null_client','MESSAGE',client=0,name='Info')
add('message_null_parent','MESSAGE',client=1,name='Info')
add('message_empty_name','MESSAGE',name='',options={})
add('status_success','STATUS')
add('status_error','STATUS',status=6,status_text='Lab error',options={'Detail':'synthetic'})
add('status_negative','STATUS',status=-6,status_text='',options=['synthetic'])
add('status_null_client','STATUS',client=0)
add('status_null_parent','STATUS',client=1)
for api in ['SEND_RAW','RECEIVE_RAW']:
    prefix='send' if api=='SEND_RAW' else 'recv'
    for mode in range(4):add(f'{prefix}_mode{mode}',api,raw_mode=mode)
    add(f'{prefix}_null_client',api,client=0)
    add(f'{prefix}_null_parent',api,client=1)
    add(f'{prefix}_null_data',api,null_data=True)
    add(f'{prefix}_zero_length',api,zero_length=True)
    add(f'{prefix}_null_bytes',api,null_bytes=True)

def expected(c):
    rc=0;wire=None;count=None;raw_calls=0;hex_data=''
    invalid=c['client']!=2
    o=copy.deepcopy(c['options'])
    if c['api']=='REQUEST':
        invalid|=c['name'] is None or c['target'] is None
        if not invalid:
            d={'TargetIdentifier':c['target']}
            if c['source'] is not None:d['SourceIdentifier']=c['source']
            if o is not None:d['Options']=o
            if c['name']=='Unback' and isinstance(o,dict) and 'Password' in o:d['Password']=o['Password']
            if c['name']=='EnableCloudBackup' and isinstance(o,dict) and 'CloudBackupState' in o:d['CloudBackupState']=o['CloudBackupState']
            d['MessageName']=c['name'];wire=['DLMessageProcessMessage',d]
    elif c['api']=='MESSAGE':
        invalid|=(c['name'] is None and o is None) or (o is not None and not isinstance(o,dict))
        if not invalid:
            d=o if o is not None else {}
            if c['name'] is not None:d['MessageName']=c['name']
            wire=['DLMessageProcessMessage',d]
    elif c['api']=='STATUS':
        if not invalid:
            wire=['DLMessageStatusResponse',c['status']%(1<<64),
                  c['status_text'] if c['status_text'] is not None else '___EmptyParameterString___',
                  o if o is not None else '___EmptyParameterString___']
    else:
        count=0xa5a5a5a5
        invalid|=c['null_data'] or c['zero_length'] or c['null_bytes']
        if not invalid:
            mode=c['raw_mode'];count=0 if mode==1 else 2 if mode==2 else 7
            raw_calls=1 if mode==1 else 2 if mode==2 else 4
            hex_data=b'ABCDEFG'[:count].hex()
            if c['api']=='SEND_RAW' and count==0:rc=-3
            # The hooks sit below service.c, in usbmuxd. Model the public
            # idevice.c/service.c error propagation, not an ideal service mock.
            if mode==2 and c['api']=='SEND_RAW':count=0;rc=-3
            if mode==3:
                raw_calls=1;count=0;hex_data=b'AB'.hex()
                if c['api']=='SEND_RAW':rc=-3
    if invalid:rc=-1
    if wire is not None:raw_calls=None  # Framing write segmentation is not part of this contract.
    return {'return_code':rc,'captures':int(wire is not None),'wire':wire,'bytes':count,
            'raw_calls':raw_calls,'data_hex':hex_data}

def cstr(value):return 'NULL' if value is None else json.dumps(value,ensure_ascii=True)
lines=['static const struct probe_case cases[]={']
for c in cases:
    opts=None if c['options'] is None else plistlib.dumps(c['options'],fmt=plistlib.FMT_XML,sort_keys=False).decode()
    fields=[cstr(c['id']),c['api'],str(c['client']),cstr(c['name']),cstr(c['target']),cstr(c['source']),
            cstr(opts),str(c['status']),cstr(c['status_text']),str(c['raw_mode']),
            str(int(c['null_data'])),str(int(c['zero_length'])),str(int(c['null_bytes']))]
    lines.append('{'+','.join(fields)+'},')
lines.append('};')
(w/'src/cases.generated.h').write_text('\n'.join(lines)+'\n')
spec=[{'input':c,'expected':expected(c)} for c in cases]
# Encode bytes in the reference JSON without losing their plist type.
(w/'cases.json').write_text(json.dumps(spec,ensure_ascii=False,indent=2,
    default=lambda x:{'__bytes_hex__':x.hex()}))
print('Generated',len(cases),'offline differential cases')
