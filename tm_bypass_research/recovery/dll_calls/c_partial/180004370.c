/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_file_close_Recovered(undefined8 param_1,undefined4 param_2)

{
  longlong unaff_RBP;
  
                    /* 0x4370  7  afc_file_close */
  func_0x000180cd8a6f();
  LOCK();
  *(undefined4 *)(unaff_RBP + 0x36) = param_2;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

