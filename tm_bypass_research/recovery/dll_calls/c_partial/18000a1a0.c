/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_connection_receive_timeout_Recovered(void)

{
                    /* 0xa1a0  76  idevice_connection_receive_timeout */
  func_0x000180cfc54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

