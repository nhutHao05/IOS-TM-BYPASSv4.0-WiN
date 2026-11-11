/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0001807f1aae) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_copy_Recovered(longlong param_1)

{
  uint *puVar1;
  int *piVar2;
  uint unaff_EBP;
  uint *unaff_RSI;
  longlong unaff_RDI;
  byte in_CF;
  
  piVar2 = (int *)func_0x000180db85e3();
  *(int *)((longlong)unaff_RSI + 0x7f) =
       *(int *)((longlong)unaff_RSI + 0x7f) + unaff_EBP + (uint)in_CF;
  puVar1 = (uint *)(param_1 + unaff_RDI * 8);
  *puVar1 = *puVar1 & unaff_EBP;
  if ((int)param_1 != *piVar2) {
    *unaff_RSI = *unaff_RSI >> 2 | *unaff_RSI << 0x1e;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (-1 < (char)((char)unaff_RDI -
                 *(char *)(CONCAT71((int7)((ulonglong)piVar2 >> 8),0xa2) & 0xffffffff))) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

