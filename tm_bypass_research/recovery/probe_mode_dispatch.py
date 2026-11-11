"""Verify actual helper mode initialization and switch dispatch, offline."""
from pathlib import Path
import json
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parent.parent/'deps'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_64
from capstone.x86_const import X86_OP_REG
from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE
from unicorn.x86_const import *

w=Path(__file__).resolve().parent.parent
image=(w/'native_runtime/wine/MDM_SETUP.exe.memory_ready.bin').read_bytes()
BASE=0x140000000;STACK=0x700000000;SP=STACK+0x10000
def machine():
    u=Uc(UC_ARCH_X86,UC_MODE_64)
    u.mem_map(BASE,(len(image)+4095)&~4095);u.mem_write(BASE,image)
    u.mem_map(STACK,0x20000);u.reg_write(UC_X86_REG_RSP,SP)
    u.reg_write(UC_X86_REG_RBP,SP+0x1000)
    return u

u=machine()
# Execute the exact instructions up to, but not including, the memset call.
u.emu_start(BASE+0x40de,BASE+0x40f9,count=20)
initial=u.reg_read(UC_X86_REG_R12)&0xffffffff
stored=struct.unpack('<I',u.mem_read(SP+0x38,4))[0]
assert initial==stored==1

names=['Backup','Restore','Info','List','Unback','ChangePassword','Leave','Cloud']
entries=[BASE+struct.unpack_from('<I',image,0x5d6c+4*i)[0] for i in range(8)]
assert entries[1]==BASE+0x4dea
targets=set(entries)|{BASE+0x4d5d}
results=[]
for mode in range(9):
    state={};u=machine();u.reg_write(UC_X86_REG_R12,mode)
    def code(uc,address,size,_):
        if address in targets:state['target']=address;uc.emu_stop()
    u.hook_add(UC_HOOK_CODE,code)
    u.emu_start(BASE+0x474e,0,count=50)
    expected=entries[mode] if mode<8 else BASE+0x4d5d
    assert state.get('target')==expected
    results.append({'mode':mode,'meaning':names[mode] if mode<8 else 'out_of_range',
                    'target':hex(state['target']),'dispatch_matches_table':True})

md=Cs(CS_ARCH_X86,CS_MODE_64);md.detail=True;md.skipdata=True
writes=[]
for i in md.disasm(image[0x4070:0x474e],BASE+0x4070):
    if i.id==0 or not i.operands:continue
    first=i.operands[0]
    _,changed=i.regs_access()
    if any(i.reg_name(reg) in ('r12','r12d') for reg in changed):
        writes.append({'address':hex(i.address),'instruction':i.mnemonic+' '+i.op_str})
report={'scope':'Actual mode-initialization slice and switch block; not full device execution',
        'initialization_address':hex(BASE+0x40de),'initial_mode':initial,
        'mode_stored_in_stack':stored,'default_mode_name':'Restore',
        'restore_entry':hex(entries[1]),'dispatch_cases_verified':len(results),
        'writes_to_mode_register_before_dispatch':writes,'switch_cases':results}
(w/'recovery/file_sender/mode-dispatch-evidence.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k not in ('writes_to_mode_register_before_dispatch','switch_cases')},indent=2))
