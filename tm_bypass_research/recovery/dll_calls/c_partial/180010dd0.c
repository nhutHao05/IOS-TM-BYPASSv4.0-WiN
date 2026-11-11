/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000180a27ef0) */
/* WARNING: Removing unreachable block (ram,0x000180a27f37) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_copy_all_Recovered(longlong param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined6 uVar4;
  uint unaff_EDI;
  uint unaff_R14D;
  char in_AF;
  
  uVar4 = (undefined6)((ulonglong)param_2 >> 0x10);
                    /* 0x10dd0  152  misagent_copy_all */
  uVar3 = (undefined2)param_2;
  uVar2 = func_0x000180de4640();
  puVar1 = (uint *)(CONCAT62(uVar4,uVar3) + 0x422cd11b);
  *puVar1 = *puVar1 ^ unaff_EDI;
  puVar1 = (uint *)(param_1 + -0x3e);
  *puVar1 = *puVar1 | unaff_R14D;
  out(2,(uint)CONCAT62((int6)((ulonglong)uVar2 >> 0x10),
                       CONCAT11(((int)*puVar1 < 0) << 7 | (*puVar1 == 0) << 6 | in_AF << 4 |
                                ((POPCOUNT(*puVar1 & 0xff) & 1U) == 0) << 2,(char)uVar2)) |
        0x3e2072c3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

