/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void sbservices_client_free_Recovered(void)

{
                    /* 0x19850  252  sbservices_client_free */
  func_0x000180db85e3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

