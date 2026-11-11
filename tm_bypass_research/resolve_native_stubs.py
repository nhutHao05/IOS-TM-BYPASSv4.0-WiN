"""Resolve import-protection trampolines in a captured image, using CPU emulation.
Stops at the first address outside the captured EXE; never invokes Windows APIs.
"""
from pathlib import Path
import json
import struct
import sys
sys.path.insert(0, str(Path(__file__).resolve().parent/'deps'))
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
from capstone.x86_const import X86_OP_IMM
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_MEM_UNMAPPED, UC_MEM_FETCH_UNMAPPED, UC_HOOK_CODE, UcError
from unicorn.x86_const import *

w = Path(__file__).resolve().parent/'native_runtime'
name = sys.argv[1] if len(sys.argv) > 1 else 'MDM_SETUP.exe'
if name not in ('MDM_SETUP.exe', 'imobiledevice.dll'):
    raise SystemExit('Unsupported sample image')
orig = pefile.PE(str(w.parent/'embedded_ikey'/name), fast_load=True)
ready = w/'wine'/(name+'.memory_ready.bin')
mem = (ready if ready.exists() else w/'wine'/(name+'.memory1.bin')).read_bytes()
symbols = json.loads((w/'all_export_symbols.json').read_text())
base = orig.OPTIONAL_HEADER.ImageBase
text_start = orig.sections[0].VirtualAddress
text_end = text_start + orig.sections[0].Misc_VirtualSize
stack = 0x700000000
sp = stack + 0x10000
uc = Uc(UC_ARCH_X86, UC_MODE_64)
uc.mem_map(base, (len(mem)+0xfff)&~0xfff)
uc.mem_write(base, mem)
uc.mem_map(stack, 0x20000)
state = {}

def unmapped(uc, access, address, size, value, _):
    state['destination' if access == UC_MEM_FETCH_UNMAPPED else 'bad_read'] = address
    uc.emu_stop()
    return False

def code(uc, address, size, _):
    if not base <= address < base + len(mem) or base+text_start <= address < base+text_end:
        state['destination'] = address
        uc.emu_stop()

uc.hook_add(UC_HOOK_MEM_UNMAPPED, unmapped)
uc.hook_add(UC_HOOK_CODE, code)
md = Cs(CS_ARCH_X86, CS_MODE_64)
md.detail = True
md.skipdata = True
regs = [UC_X86_REG_RAX, UC_X86_REG_RBX, UC_X86_REG_RCX, UC_X86_REG_RDX,
        UC_X86_REG_RSI, UC_X86_REG_RDI, UC_X86_REG_RBP, UC_X86_REG_R8,
        UC_X86_REG_R9, UC_X86_REG_R10, UC_X86_REG_R11, UC_X86_REG_R12,
        UC_X86_REG_R13, UC_X86_REG_R14, UC_X86_REG_R15]
results = []
for ins in md.disasm(mem[text_start:text_end], base+text_start):
    if ins.id == 0 or ins.mnemonic not in ('call','jmp') or not ins.operands or ins.operands[0].type != X86_OP_IMM:
        continue
    target = ins.operands[0].imm
    if not base+text_end <= target < base+len(mem):
        continue
    state.clear()
    for reg in regs:
        uc.reg_write(reg, 0)
    uc.reg_write(UC_X86_REG_RSP, sp)
    uc.reg_write(UC_X86_REG_EFLAGS, 0x202)
    uc.mem_write(sp-0x1000, bytes(0x3000))
    uc.mem_write(sp, struct.pack('<Q', ins.address+ins.size))
    try:
        uc.emu_start(target, 0, timeout=100000, count=3000)
    except UcError as error:
        state['exception'] = str(error)
    row = {'callsite': hex(ins.address), 'stub': hex(target), **state.copy()}
    if 'destination' in state:
        row['symbol'] = symbols.get(str(state['destination']), [])
    results.append(row)
(w/(name+'.resolved_calls.json')).write_text(json.dumps(results, indent=2))
print(json.dumps({'calls':len(results), 'resolved_destinations':sum('destination' in x for x in results),
                  'named_exports':sum(bool(x.get('symbol')) for x in results)}))
for row in results:
    if 0x140004e00 <= int(row['callsite'],16) < 0x140004ec0:
        print(json.dumps(row))
