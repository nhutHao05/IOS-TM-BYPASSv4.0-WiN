/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_send_restore_complete_Recovered(undefined8 param_1,undefined2 param_2)

{
  undefined1 *unaff_RSI;
  
                    /* 0x12aa0  194  mobilebackup_send_restore_complete */
  func_0x000180d915bb();
  out(*unaff_RSI,param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

