/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_client_free_Recovered(void)

{
                    /* 0x11ec0  173  mobilebackup2_client_free
                       0x11ec0  183  mobilebackup_client_free */
  func_0x000180cef54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

