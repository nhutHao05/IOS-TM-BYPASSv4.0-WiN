/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_start_capture_raw_Recovered(void)

{
                    /* 0x1b5e0  280  syslog_relay_start_capture_raw */
  func_0x000180cef54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

