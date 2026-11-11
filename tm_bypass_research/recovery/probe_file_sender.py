"""Execute the original helper's file-sender machine code in Unicorn.

All external APIs are mocked. Files are read by this harness only from the
explicit embedded-backup corpus. No USB, network or vendor server is used.
"""
from pathlib import Path
import hashlib
import json
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parent.parent/'deps'))
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
from unicorn.x86_const import *

w=Path(__file__).resolve().parent.parent
out=w/'recovery/file_sender'
out.mkdir(exist_ok=True)
image=(w/'native_runtime/wine/MDM_SETUP.exe.memory_ready.bin').read_bytes()
calls=json.loads((w/'native_runtime/resolved_native_calls.json').read_text())
apis={}
for row in calls:
    aliases=[s.split('!',1)[1] for s in row['symbol']]
    apis[row['destination']]=next((s for s in aliases if not s.startswith('_o_')),aliases[0])
for address,names in json.loads((w/'native_runtime/all_export_symbols.json').read_text()).items():
    for name in names:
        short=name.split('!',1)[1]
        if short in ('memcpy','memmove','memset','strcmp'):apis[int(address)]=short

BASE=0x140000000
STACK=0x700000000
HEAP=0x500000000
TEB=0x600010000
RETURN=0x600000000
SP=STACK+0x300000-8
MASK=(1<<64)-1

class Probe:
    def __init__(self,payload,filename,missing=False,read_error=False,short_write=False,status_document=None):
        self.payload=payload;self.filename=filename
        self.missing=missing;self.read_error=read_error;self.short_write=short_write
        self.status_document=status_document
        self.cursor=0;self.heap_next=HEAP+0x1000;self.objects={}
        self.events=[];self.parts=[];self.done=False;self.unexpected=None
        self.uc=Uc(UC_ARCH_X86,UC_MODE_64)
        self.uc.mem_map(BASE,(len(image)+4095)&~4095);self.uc.mem_write(BASE,image)
        self.uc.mem_map(STACK,0x400000);self.uc.mem_map(HEAP,0x200000)
        self.uc.mem_map(TEB,0x1000);self.uc.mem_map(RETURN,0x1000)
        self.uc.mem_write(TEB+0x10,struct.pack('<Q',STACK+0x1000))
        self.uc.reg_write(UC_X86_REG_GS_BASE,TEB)
        for page in {address&~4095 for address in apis}:
            if not BASE<=page<BASE+len(image):self.uc.mem_map(page,4096)
        self.errno=self.allocate(struct.pack('<I',2 if missing else 5))
        self.errdict=self.allocate(bytes(8))
        root=self.string('LAB-BACKUP')
        relative=self.string(filename)
        self.uc.reg_write(UC_X86_REG_RCX,0xc0ffee)
        self.uc.reg_write(UC_X86_REG_RDX,root)
        self.uc.reg_write(UC_X86_REG_R8,relative)
        self.uc.reg_write(UC_X86_REG_R9,self.errdict)
        self.uc.reg_write(UC_X86_REG_RSP,SP)
        self.uc.reg_write(UC_X86_REG_EFLAGS,0x202)
        self.uc.mem_write(SP,struct.pack('<Q',RETURN))
        self.uc.hook_add(UC_HOOK_CODE,self.hook)

    def allocate(self,data):
        ptr=self.heap_next;self.heap_next+=(len(data)+15)&~15
        self.uc.mem_write(ptr,data);return ptr
    def string(self,value):return self.allocate(value.encode()+b'\0')
    def cstring(self,address):
        buf=bytes(self.uc.mem_read(address,4096));return buf.split(b'\0',1)[0].decode()
    def object(self,value):
        p=self.allocate(bytes(16));self.objects[p]=value;return p
    def ret(self,value):
        sp=self.uc.reg_read(UC_X86_REG_RSP)
        address=struct.unpack('<Q',self.uc.mem_read(sp,8))[0]
        self.uc.reg_write(UC_X86_REG_RAX,value&MASK)
        self.uc.reg_write(UC_X86_REG_RSP,sp+8)
        self.uc.reg_write(UC_X86_REG_RIP,address)
    def hook(self,uc,address,size,_):
        if address==RETURN:self.done=True;uc.emu_stop();return
        if not BASE<=address<BASE+len(image) and address not in apis:
            self.unexpected={'unresolved_foreign_address':hex(address),'events':self.events[-6:]}
            uc.emu_stop();return
        if address not in apis and address not in (BASE+0x10c0,BASE+0x1230,BASE+0x13c0,BASE+0x1500):return
        args=[uc.reg_read(r) for r in [UC_X86_REG_RCX,UC_X86_REG_RDX,UC_X86_REG_R8,UC_X86_REG_R9]]
        a,b,c,d=args
        if address==BASE+0x10c0:
            path=self.cstring(a)+'/'+self.cstring(b)
            if c:path+='/'+self.cstring(c)
            result=self.string(path)
            name='mock_string_build_path'
        elif address==BASE+0x13c0:
            name='mock_load_plist'
            result=0 if self.status_document is None else self.object(self.status_document)
            uc.mem_write(a,struct.pack('<Q',result))
            self.events.append({'api':name,'path':self.cstring(b),'loaded':bool(result)})
            result=0
        elif address==BASE+0x1230:
            result=self.string(str(a)+' bytes');name='mock_format_size'
        elif address==BASE+0x1500:
            name='mock_printf';result=0
            self.events.append({'api':name,'format':self.cstring(a)})
        else:
            name=apis[address]
            if name=='mobilebackup2_send_raw':
                data=bytes(uc.mem_read(b,c));sent=c
                if self.short_write and len(self.parts)==3:sent=max(0,c-1)
                uc.mem_write(d,struct.pack('<I',sent))
                self.parts.append(data[:sent]);result=0
                self.events.append({'api':name,'requested':c,'sent':sent})
            elif name=='_stat64':
                self.events.append({'api':name,'path':self.cstring(a)})
                if self.missing:result=-1
                else:
                    # Windows _stat64: st_size is at byte offset 0x18.
                    record=bytearray(0x38);struct.pack_into('<Q',record,0x18,len(self.payload))
                    uc.mem_write(b,bytes(record));result=0
            elif name=='fopen':
                self.events.append({'api':name,'path':self.cstring(a),'mode':self.cstring(b)})
                assert self.cstring(b)=='rb';result=HEAP+0x180000
            elif name=='fread':
                assert b==1 and c==0x8000
                data=b'' if self.read_error else self.payload[self.cursor:self.cursor+c]
                if data:uc.mem_write(a,data)
                self.cursor+=len(data);result=len(data)
                self.events.append({'api':name,'returned':result})
            elif name in ('fclose','free','plist_free'):result=0
            elif name in ('memcpy','memmove'):
                uc.mem_write(a,bytes(uc.mem_read(b,c)));result=a
            elif name=='memset':uc.mem_write(a,bytes([b&255])*c);result=a
            elif name=='strcmp':result=(self.cstring(a)>self.cstring(b))-(self.cstring(a)<self.cstring(b))
            elif name=='_errno':result=self.errno
            elif name=='strerror':result=self.string('No such file' if a==2 else 'Synthetic read error')
            elif name=='plist_new_dict':result=self.object({})
            elif name=='plist_new_string':result=self.object(self.cstring(a))
            elif name=='plist_new_uint':result=self.object(a)
            elif name=='plist_dict_get_item':
                value=self.objects[a]
                key=self.cstring(b)
                result=self.object(value[key]) if isinstance(value,dict) and key in value else 0
            elif name=='plist_get_node_type':
                value=self.objects[a]
                result=0 if isinstance(value,bool) else 1 if isinstance(value,int) else 3 if isinstance(value,str) else 4 if isinstance(value,list) else 5 if isinstance(value,dict) else 6
            elif name=='plist_get_string_val':
                value=self.objects[a];ptr=self.string(value) if isinstance(value,str) else 0
                uc.mem_write(b,struct.pack('<Q',ptr));result=0
            elif name=='plist_dict_set_item':
                self.objects[a][self.cstring(b)]=self.objects[c];result=0
            else:
                self.unexpected={'address':hex(address),'api':name}
                uc.emu_stop();return
        self.ret(result)

    def run(self,start=0x2dc0):
        try:self.uc.emu_start(BASE+start,RETURN+1,count=2_000_000,timeout=5_000_000)
        except UcError as error:
            raise RuntimeError(f'Emulation failed at {self.uc.reg_read(UC_X86_REG_RIP):x}: {error}') from error
        if self.unexpected or not self.done:raise RuntimeError(f'Incomplete execution for {self.filename}: {self.unexpected}')
        stream=b''.join(self.parts)
        result=self.uc.reg_read(UC_X86_REG_RAX)&0xffffffff
        return result,stream

def decode(stream):
    assert len(stream)>=4
    size=int.from_bytes(stream[:4],'big')
    name=stream[4:4+size].decode()
    pos=4+size;chunks=[];statuses=[];payload=bytearray()
    while pos<len(stream):
        assert pos+5<=len(stream)
        size=int.from_bytes(stream[pos:pos+4],'big');assert size>=1
        code=stream[pos+4];data=stream[pos+5:pos+4+size]
        assert len(data)==size-1
        if code==0x0c:payload.extend(data);chunks.append(len(data))
        else:statuses.append({'code':code,'data_hex':data.hex()})
        pos+=4+size
    return name,bytes(payload),chunks,statuses

cases=[]
for size in [0,1,32767,32768,32769,65536,65553]:
    cases.append((f'synthetic-{size}',bytes((n*37+11)&255 for n in range(size)),'LAB-UDID/aa/opaque.bin',None))
inventory=json.loads((w/'backup_candidate_matches.json').read_text())
if isinstance(inventory,dict):inventory=list(inventory.values())
for item in inventory:
    fileid=item['fileID'];path=w/'embedded_nego'/fileid[:2]/fileid
    if path.exists():cases.append((fileid,path.read_bytes(),'LAB-UDID/'+fileid[:2]+'/'+fileid,str(path.relative_to(w))))
manifest=w/'embedded_nego/Manifest.db'
cases.append(('manifest-db',manifest.read_bytes(),'LAB-UDID/Manifest.db',str(manifest.relative_to(w))))
results=[]
for name,payload,path,source in cases:
    probe=Probe(payload,path);rc,stream=probe.run()
    decoded_name,decoded,chunks,statuses=decode(stream)
    assert rc==0 and decoded==payload and decoded_name==path
    assert all(0<n<=0x8000 for n in chunks)
    assert statuses==[{'code':0,'data_hex':''}]
    results.append({'case':name,'source':source,'bytes':len(payload),
                    'input_sha256':hashlib.sha256(payload).hexdigest(),
                    'sent_payload_sha256':hashlib.sha256(decoded).hexdigest(),
                    'data_chunk_sizes':chunks,'terminal_status':0,'helper_return':rc,
                    'mocked_api_events':probe.events})
    if name=='manifest-db':(out/'manifest-db.device-link-stream.bin').write_bytes(stream)

for label,kwargs in [('missing-file',{'missing':True}),('read-error',{'read_error':True}),('short-write',{'short_write':True})]:
    probe=Probe(b'LAB-ERROR-CONTROL','LAB-UDID/aa/opaque.bin',**kwargs);rc,stream=probe.run()
    errors_ptr=struct.unpack('<Q',probe.uc.mem_read(probe.errdict,8))[0]
    errors=probe.objects.get(errors_ptr)
    assert rc==0xffffffff
    if label=='short-write':
        assert errors is None
        assert any(e.get('requested',0)>e.get('sent',0) for e in probe.events if e['api']=='mobilebackup2_send_raw')
    else:
        assert probe.parts[-1][4]==6
        assert int.from_bytes(probe.parts[-1][:4],'big')==len(probe.parts[-1])-4
        code=errors[probe.filename]['DLFileErrorCode']
        assert code==((-6 if label=='missing-file' else -5)&MASK)
    results.append({'case':label,'helper_return':rc,'wire_bytes':len(stream),
                    'helper_return_signed':-1,'errors':errors,'control_assertions_passed':True,
                    'mocked_api_events':probe.events})

report={'scope':'Original x64 file-sender routine 0x140002dc0 with external APIs mocked',
        'success_cases':len(cases),'error_control_cases':3,
        'all_success_payloads_byte_identical':True,
        'all_error_controls_passed':True,
        'maximum_data_chunk':32768,
        'file_data_code':12,'success_code':0,'local_error_code':6,
        'no_real_device_or_network':True,'results':results}
(out/'file-sender-evidence.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k!='results'},indent=2))

import plistlib
embedded_status=plistlib.loads((w/'embedded_nego/Status.plist').read_bytes())
status_cases=[
    ('embedded-status',embedded_status,True),
    ('minimal-finished',{'SnapshotState':'finished'},True),
    ('other-fields-invalid',{'SnapshotState':'finished','Version':999,'BackupState':'arbitrary','IsFullBackup':False},True),
    ('unfinished',{'SnapshotState':'unfinished'},False),
    ('case-sensitive',{'SnapshotState':'Finished'},False),
    ('wrong-type',{'SnapshotState':True},False),
    ('missing-key',{},False),
    ('missing-plist',None,False),
]
status_results=[]
for label,document,expected in status_cases:
    p=Probe(b'','unused',status_document=document)
    p.uc.reg_write(UC_X86_REG_RCX,p.string('LAB-BACKUP'))
    p.uc.reg_write(UC_X86_REG_RDX,p.string('LAB-UDID'))
    actual,_=p.run(start=0x2b10);actual=bool(actual&255)
    assert actual==expected
    status_results.append({'case':label,'accepted_by_helper':actual,'expected':expected,'events':p.events})
status_report={'scope':'Original helper Status.plist gate with plist-load and plist APIs mocked',
               'cases_passed':len(status_results),'results':status_results,
               'device_acceptance_or_mdm_removal_not_tested':True}
(out/'status-gate-evidence.json').write_text(json.dumps(status_report,indent=2))
print(json.dumps({k:v for k,v in status_report.items() if k!='results'},indent=2))
