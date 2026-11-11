/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_client_options_add_Recovered(void)

{
                    /* 0xce00  103  instproxy_client_options_add */
  func_0x000180d915bb();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

