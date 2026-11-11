/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_actions_free_Recovered(void)

{
                    /* 0xcfd0  104  instproxy_client_options_free
                       0xcfd0  197  mobilesync_actions_free */
  func_0x000180dbfef6();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

