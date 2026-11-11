/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_client_free_Recovered(longlong param_1)

{
  undefined4 uVar1;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  uVar1 = func_0x000180dbfef6();
  LOCK();
  *(undefined4 *)(param_1 + -0x2f) = uVar1;
  UNLOCK();
  if (!(bool)in_CF && !(bool)in_ZF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

