/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_client_free_Recovered(void)

{
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
                    /* 0x14090  203  mobilesync_client_free */
  return;
}

