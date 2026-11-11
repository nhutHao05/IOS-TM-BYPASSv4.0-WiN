/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void np_set_notify_callback_Recovered(void)

{
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
                    /* 0x170f0  222  np_set_notify_callback */
  return;
}

