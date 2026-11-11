"""Emulate only the recovered request-construction block with mocked plist APIs.
No device, network, filesystem, or real Windows API is exposed to the block.
"""
import json
from pathlib import Path
import struct
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
from unicorn.x86_const import *

w = Path(__file__).resolve().parent/'native_runtime'
data = (w/'wine/MDM_SETUP.exe.memory_ready.bin').read_bytes()
symbols = json.loads((w/'all_export_symbols.json').read_text())
needed = ['plist_new_dict','plist_new_bool','plist_new_string','plist_dict_set_item',
          'mobilebackup2_send_request']
api = {}
for address,names in symbols.items():
    for n in names:
        if n.split('!')[-1] in needed:
            api[int(address)] = n.split('!')[-1]
base, stack, heap = 0x140000000, 0x700000000, 0x500000000
uc = Uc(UC_ARCH_X86, UC_MODE_64)
uc.mem_map(base,(len(data)+0xfff)&~0xfff)
uc.mem_write(base,data)
uc.mem_map(stack,0x20000)
uc.mem_map(heap,0x10000)
for page in {address&~0xfff for address in api}:
    uc.mem_map(page,0x1000)
    uc.mem_write(page,b'\x90'*0x1000)
sp = stack+0x10000
udid = heap+0x8000
uc.mem_write(udid,b'OFFLINE-LAB-UDID\0')
uc.reg_write(UC_X86_REG_RSP,sp)
uc.reg_write(UC_X86_REG_RBP,sp+0x1000)
uc.reg_write(UC_X86_REG_R14,udid)
uc.mem_write(sp+0x58,struct.pack('<Q',udid))
uc.mem_write(sp+0x48,struct.pack('<Q',0xc0ffee))
objects = {}
events = []

def string(address):
    b = bytearray()
    for i in range(4096):
        v=uc.mem_read(address+i,1)
        if v==b'\0':return b.decode('utf8')
        b.extend(v)
    raise ValueError('unterminated string')

def allocate(value):
    address=heap+0x100+len(objects)*0x100
    objects[address]=value
    return address

def hook(uc,address,size,user):
    if address not in api:return
    name=api[address]
    rcx=uc.reg_read(UC_X86_REG_RCX)
    rdx=uc.reg_read(UC_X86_REG_RDX)
    r8=uc.reg_read(UC_X86_REG_R8)
    r9=uc.reg_read(UC_X86_REG_R9)
    rsp=uc.reg_read(UC_X86_REG_RSP)
    if name=='plist_new_dict':
        result=allocate({})
    elif name=='plist_new_bool':
        result=allocate(bool(rcx&0xff))
    elif name=='plist_new_string':
        result=allocate(string(rcx))
    elif name=='plist_dict_set_item':
        key=string(rdx)
        objects[rcx][key]=objects[r8]
        events.append({'api':name,'key':key,'value':objects[r8]})
        result=0
    elif name=='mobilebackup2_send_request':
        opts=struct.unpack('<Q',uc.mem_read(rsp+0x28,8))[0]
        events.append({'api':name,'request':string(rdx),'target':string(r8),
                       'source':string(r9),'options':objects[opts]})
        uc.emu_stop()
        return
    ret=struct.unpack('<Q',uc.mem_read(rsp,8))[0]
    uc.reg_write(UC_X86_REG_RAX,result)
    uc.reg_write(UC_X86_REG_RSP,rsp+8)
    uc.reg_write(UC_X86_REG_RIP,ret)

uc.hook_add(UC_HOOK_CODE,hook)
uc.emu_start(base+0x4e0b,base+0x4ea4,count=100000,timeout=1000000)
assert events and events[-1]['api']=='mobilebackup2_send_request'
assert events[-1]['request']=='Restore'
assert events[-1]['options']=={'RestoreSystemFiles':False,'RestoreDontCopyBackup':True,
                               'RestorePreserveSettings':True,'Password':'mdm'}
(w/'verified_restore_request.json').write_text(json.dumps({'scope':'isolated block emulation; all external APIs mocked','events':events},indent=2))
print(json.dumps(events[-1],indent=2))
