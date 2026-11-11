/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_remove_Recovered(void)

{
                    /* 0x10ff0  155  misagent_remove */
  func_0x000180d915bb();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

