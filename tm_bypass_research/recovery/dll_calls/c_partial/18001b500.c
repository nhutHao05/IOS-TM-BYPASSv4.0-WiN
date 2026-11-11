/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_start_capture_Recovered(void)

{
                    /* 0x1b500  279  syslog_relay_start_capture */
  func_0x000180db85e3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

