/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_set_tcp_endpoint_Recovered(void)

{
                    /* 0xacc0  95  idevice_set_tcp_endpoint */
  func_0x000180cfc54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

