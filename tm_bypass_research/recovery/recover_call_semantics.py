"""Measure protected import calls and remove only proven padding in an analysis copy.

No foreign API is executed. A single mock return is supplied at the first export.
"""
from pathlib import Path
import collections
import json
import struct
import sys
sys.path.insert(0, str(Path(__file__).resolve().parent.parent/'deps'))
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED
from unicorn.x86_const import *

w=Path(__file__).resolve().parent.parent
r=w/'recovery'
dll=len(sys.argv)>1 and sys.argv[1]=='--dll'
if len(sys.argv)>1 and not dll:raise SystemExit('Usage: recover_call_semantics.py [--dll]')
name='imobiledevice.dll' if dll else 'MDM_SETUP.exe'
source=r/'vmp_input'/(name+'.unpacked')
pe=pefile.PE(str(source))
base=pe.OPTIONAL_HEADER.ImageBase
text_start=pe.sections[0].VirtualAddress
text_end=text_start+pe.sections[0].Misc_VirtualSize
mem=(w/'native_runtime/wine'/(name+'.memory_ready.bin')).read_bytes()
output=r/'dll_calls' if dll else r
output.mkdir(exist_ok=True)
calls_file=output/'calls-named.json' if dll else w/'native_runtime/resolved_native_calls.json'
calls=json.loads(calls_file.read_text())
md=Cs(CS_ARCH_X86,CS_MODE_64);md.detail=True;md.skipdata=True
instructions=list(md.disasm(mem[text_start:text_end],base+text_start))
indexes={i.address:n for n,i in enumerate(instructions)}
stack=0x700000000;sp=stack+0x10000
reg_names=['rax','rbx','rcx','rdx','rsi','rdi','rbp','r8','r9','r10','r11','r12','r13','r14','r15']
regs={name:globals()['UC_X86_REG_'+name.upper()] for name in reg_names}
values={name:0x1234000000000000+i*0x11111111 for i,name in enumerate(reg_names,1)}
return_value=0x1122334455667788
caller_return=0x600000000
uc=Uc(UC_ARCH_X86,UC_MODE_64)
uc.mem_map(base,(len(mem)+0xfff)&~0xfff);uc.mem_write(base,mem)
uc.mem_map(stack,0x20000)
state={}
def code(uc,address,size,_):
    if not base<=address<base+len(mem) or base+text_start<=address<base+text_end:
        state['stop']=address;uc.emu_stop()
def unmapped(uc,access,address,size,value,_):
    state['stop']=address;state['unmapped']=access;uc.emu_stop();return False
uc.hook_add(UC_HOOK_CODE,code);uc.hook_add(UC_HOOK_MEM_UNMAPPED,unmapped)
results=[]
for item in calls:
    site=int(item['callsite'],16);ins=instructions[indexes[site]]
    if ins.mnemonic!='call':
        results.append({**item,'kind':ins.mnemonic,'padding_patch':'VM entry jump is outside import-call recovery'})
        continue
    state.clear()
    for name,reg in regs.items():uc.reg_write(reg,values[name])
    uc.reg_write(UC_X86_REG_RSP,sp);uc.reg_write(UC_X86_REG_EFLAGS,0x202)
    uc.mem_write(sp-0x1000,bytes(0x3000))
    uc.mem_write(sp,struct.pack('<Q',site+ins.size))
    preceding=[]
    pos=indexes[site]-1
    while pos>=0 and instructions[pos].mnemonic=='push' and len(preceding)<4:
        preceding.append(instructions[pos]);pos-=1
    # Some tail-import wrappers are adjacent to deliberately invalid bytes.
    # Decode their last instruction from a known boundary rather than relying
    # solely on a linear sweep through the preceding padding.
    push_candidates=[]
    for length in (1,2):
        candidates=list(md.disasm(mem[site-base-length:site-base],site-length))
        if len(candidates)==1 and candidates[0].mnemonic=='push' and candidates[0].size==length:
            if candidates[0].op_str.lower() in values:push_candidates.append(candidates[0])
    if dll and not preceding and push_candidates:
        candidate=max(push_candidates,key=lambda p:p.size)
        preceding=[candidate]
    # The nearest push is at the lowest address above the return slot.
    for j,push in enumerate(preceding):
        operand=push.op_str.lower()
        value=values.get(operand,0)
        uc.mem_write(sp+8*(j+1),struct.pack('<Q',value))
    uc.mem_write(sp+8*(len(preceding)+1),struct.pack('<Q',caller_return))
    error=None
    try:uc.emu_start(int(item['stub'],16),0,timeout=100000,count=10000)
    except UcError as ex:error=str(ex)
    api_sp=uc.reg_read(UC_X86_REG_RSP)
    stop=state.get('stop')
    row={'callsite':item['callsite'],'stub':item['stub'],'symbol':item['symbol'][0],
         'api_target_matches_prior_emulation':stop==item.get('destination'),
         'stack_delta_at_api':api_sp-sp,
         'argument_registers_preserved':all(uc.reg_read(regs[k])==values[k] for k in ['rcx','rdx','r8','r9'])}
    if stop!=item.get('destination'):
        row['error']='Stub target differed';results.append(row);continue
    ret=struct.unpack('<Q',uc.mem_read(api_sp,8))[0]
    row['api_return_address']=hex(ret)
    state.clear()
    uc.reg_write(UC_X86_REG_RAX,return_value)
    uc.reg_write(UC_X86_REG_RSP,api_sp+8)
    try:uc.emu_start(ret,0,timeout=100000,count=10000)
    except UcError as ex:error=str(ex)
    resume=state.get('stop')
    row.update({'resume':hex(resume) if resume is not None else None,
                'final_stack_delta':uc.reg_read(UC_X86_REG_RSP)-(sp+8),
                'return_value_preserved':uc.reg_read(UC_X86_REG_RAX)==return_value,
                'nonvolatile_preserved':all(uc.reg_read(regs[k])==values[k] for k in ['rbx','rsi','rdi','rbp','r12','r13','r14','r15'])})
    delta=row['final_stack_delta']
    skip=(resume-(site+ins.size)) if resume is not None else -1
    is_tail=(resume==caller_return and ret==caller_return and delta==8*(len(preceding)+1))
    before=[]
    pushes_to_remove=delta//8-int(is_tail)
    if delta>=0 and delta%8==0 and 0<=pushes_to_remove<=len(preceding):before=preceding[:pushes_to_remove]
    if is_tail:skip=0
    skip_bytes=mem[site+ins.size-base:site+ins.size-base+max(skip,0)]
    valid=(row['argument_registers_preserved'] and row['return_value_preserved'] and row['nonvolatile_preserved']
           and 0<=delta<=40 and delta%8==0 and len(before)==pushes_to_remove
           and 0<=skip<=8 and all(x in (0x90,0xcc) for x in skip_bytes))
    row['padding_patch_verified']=valid
    row['tail_import_wrapper']=is_tail
    row['remove_pushes']=[{'address':hex(p.address),'size':p.size,'asm':p.mnemonic+' '+p.op_str} for p in before] if valid else []
    row['remove_return_padding']={'address':hex(site+ins.size),'size':skip} if valid else None
    if valid and is_tail:
        opcode_address=site+ins.size-5  # Preserve any x64 instruction prefixes.
        row['call_to_jump_patch']={'address':hex(opcode_address),'before':0xe8,'after':0xe9}
    results.append(row)

(output/'native-call-semantics.json').write_text(json.dumps(results,indent=2))
patched=bytearray(source.read_bytes());changes={}
for row in results:
    if not row.get('padding_patch_verified'):continue
    for patch in row['remove_pushes']+[row['remove_return_padding']]:
        offset=pe.get_offset_from_rva(int(patch['address'],16)-base)
        for i in range(patch['size']):
            changes[offset+i]=patched[offset+i];patched[offset+i]=0x90
    if row.get('call_to_jump_patch'):
        p=row['call_to_jump_patch'];offset=pe.get_offset_from_rva(int(p['address'],16)-base)
        assert patched[offset]==p['before']
        changes[offset]=patched[offset];patched[offset]=p['after']
(output/('imobiledevice.analysis-only.dll' if dll else 'MDM_SETUP.analysis-only.exe')).write_bytes(patched)
report={'sites':len(results),'call_sites':sum(x.get('kind')!='jmp' for x in results),
        'verified_call_sites':sum(x.get('padding_patch_verified',False) for x in results),
        'patched_bytes':len(changes),
        'tail_import_wrappers':sum(x.get('tail_import_wrapper',False) for x in results),
        'stack_deltas':dict(collections.Counter(x.get('final_stack_delta') for x in results)),
        'unverified':[x['callsite'] for x in results if x.get('kind')!='jmp' and not x.get('padding_patch_verified')]}
(output/'native-call-summary.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2))
