#!/usr/bin/env python3
"""Check a real helper branch offline; never load or execute the PE as a process."""
import argparse
import hashlib
import json
from pathlib import Path

import triton
import z3


def probe(snapshot: Path) -> dict:
    memory = snapshot.read_bytes()
    base = 0x140000000
    # These anchors were measured in MDM_SETUP.exe.memory_ready.bin.
    expected = [(0x4751, bytes.fromhex("4183fc07")),
                (0x4755, bytes.fromhex("0f8702060000"))]
    ctx = triton.TritonContext(triton.ARCH.X86_64)
    ctx.setConcreteRegisterValue(ctx.registers.r12, 1)
    mode = ctx.symbolizeRegister(ctx.registers.r12, "mode")
    instructions = []
    for offset, opcode in expected:
        actual = memory[offset:offset + len(opcode)]
        assert actual == opcode, (hex(offset), actual.hex(), opcode.hex())
        insn = triton.Instruction(base + offset, actual)
        assert ctx.processing(insn) == triton.EXCEPTION.NO_FAULT
        instructions.append({"address": hex(base + offset), "bytes": actual.hex(),
                             "disassembly": insn.getDisassembly()})
    paths = ctx.getPathConstraints()
    assert len(paths) == 1
    alternatives = [b for b in paths[0].getBranchConstraints() if not b["isTaken"]]
    assert len(alternatives) == 1
    branch = alternatives[0]
    model = ctx.getModel(branch["constraint"])
    candidate = model[mode.getId()].getValue()
    assert (candidate & 0xFFFFFFFF) > 7
    assert branch["dstAddr"] == 0x140004D5D

    # Cross-check unsigned 32-bit comparison independently of Triton's AST.
    value = z3.BitVec("mode32", 32)
    solver = z3.Solver()
    solver.add(value == 1, z3.UGT(value, 7))
    assert solver.check() == z3.unsat
    solver = z3.Solver()
    solver.add(value == (candidate & 0xFFFFFFFF), z3.UGT(value, 7))
    assert solver.check() == z3.sat
    assert ctx.getConcreteRegisterValue(ctx.registers.rip) == 0x14000475B
    return {
        "snapshot_sha256": hashlib.sha256(memory).hexdigest(),
        "image_base": hex(base), "instructions": instructions,
        "concrete_mode": 1, "concrete_next_address": "0x14000475b",
        "alternate_branch_address": hex(branch["dstAddr"]),
        "alternate_mode_model": candidate,
        "z3_version": z3.get_version_string(),
        "mode_1_cannot_take_unsigned_above_branch": True,
        "alternate_model_can_take_unsigned_above_branch": True,
        "scope": "Two original x86-64 instructions, emulated by Triton; branch checked by Z3.",
        "limitations": ["No Windows process, USB connection, restore, or device was executed.",
                        "This validates analysis tooling, not MDM removal or VMProtect recovery."],
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("snapshot", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = json.dumps(probe(args.snapshot), indent=2) + "\n"
    if args.output:
        args.output.write_text(result)
    print(result, end="")
