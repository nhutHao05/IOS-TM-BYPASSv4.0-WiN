/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void np_client_free_Recovered(void)

{
  func_0x000180cfc54a();
                    /* 0x16730  216  np_client_free */
  LOCK();
  UNLOCK();
  return;
}

