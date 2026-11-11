/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_cancel_Recovered(void)

{
                    /* 0x153e0  201  mobilesync_cancel */
  func_0x000180d8cdd6();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

