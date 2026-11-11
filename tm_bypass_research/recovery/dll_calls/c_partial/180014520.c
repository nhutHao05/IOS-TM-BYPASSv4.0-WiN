/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_finish_Recovered(void)

{
                    /* 0x14520  206  mobilesync_finish */
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
  return;
}

