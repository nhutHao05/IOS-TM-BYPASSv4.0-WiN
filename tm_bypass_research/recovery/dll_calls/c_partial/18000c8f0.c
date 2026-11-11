/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_remove_archive_Recovered(void)

{
                    /* 0xc8f0  112  instproxy_remove_archive */
  func_0x000180d8cdd6();
  in(0x2a);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

