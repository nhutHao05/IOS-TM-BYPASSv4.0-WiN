/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void heartbeat_send_Recovered(void)

{
                    /* 0x8ca0  63  heartbeat_send */
  func_0x000180db85e3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

