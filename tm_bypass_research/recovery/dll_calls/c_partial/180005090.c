/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_remove_path_and_contents_Recovered(void)

{
                    /* 0x5090  22  afc_remove_path_and_contents */
  func_0x000180cfc54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

