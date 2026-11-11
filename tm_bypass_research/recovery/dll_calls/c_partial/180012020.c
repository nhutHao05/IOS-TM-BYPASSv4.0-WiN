/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_send_Recovered(void)

{
                    /* 0x12020  191  mobilebackup_send
                       0x12020  213  mobilesync_send */
  func_0x000180cef54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

