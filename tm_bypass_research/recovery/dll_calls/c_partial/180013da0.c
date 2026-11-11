/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_client_new_Recovered(void)

{
                    /* 0x13da0  204  mobilesync_client_new */
  func_0x000180cfc54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

