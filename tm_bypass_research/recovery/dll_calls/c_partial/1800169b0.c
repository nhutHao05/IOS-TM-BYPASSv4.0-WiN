/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void np_post_notification_Recovered(void)

{
                    /* 0x169b0  221  np_post_notification */
  func_0x000180d915bb();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

