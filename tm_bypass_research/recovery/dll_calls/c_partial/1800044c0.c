/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_file_lock_Recovered(void)

{
                    /* 0x44c0  8  afc_file_lock */
  func_0x000180de4640();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

