/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void np_client_start_service_Recovered(void)

{
                    /* 0x16600  218  np_client_start_service */
  func_0x000180cd8a6f();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

