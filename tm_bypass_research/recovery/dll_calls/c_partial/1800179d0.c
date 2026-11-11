/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_create_stashbag_Recovered(void)

{
                    /* 0x179d0  229  preboard_create_stashbag */
  func_0x000180d8cdd6();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

