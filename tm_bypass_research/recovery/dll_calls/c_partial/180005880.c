/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Instruction at (ram,0x000180411bc5) overlaps instruction at (ram,0x000180411bc4)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_client_receive_with_timeout_Recovered(undefined8 param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined7 uVar4;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  uVar4 = (undefined7)((ulonglong)param_1 >> 8);
                    /* 0x5880  31  debugserver_client_receive_with_timeout */
  uVar3 = (undefined1)param_1;
  lVar2 = func_0x000180cd8a6f();
  if ((bool)in_CF || (bool)in_ZF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (CONCAT71(uVar4,uVar3) == 0) {
    piVar1 = (int *)(lVar2 + -0x73);
    *piVar1 = *piVar1 + -1;
    if ((bool)in_CF || *piVar1 == 0) {
      return;
    }
  }
  LOCK();
  UNLOCK();
  return;
}

