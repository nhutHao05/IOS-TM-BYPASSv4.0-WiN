/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void file_relay_client_start_service_Recovered(void)

{
  undefined4 *unaff_RSI;
  undefined4 *unaff_RDI;
  
                    /* 0x83a0  55  file_relay_client_start_service */
  func_0x000180cd8a6f();
  *unaff_RDI = *unaff_RSI;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

