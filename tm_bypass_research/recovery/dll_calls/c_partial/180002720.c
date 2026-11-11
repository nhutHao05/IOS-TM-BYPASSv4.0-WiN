/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_client_free_Recovered(void)

{
                    /* 0x2720  1  afc_client_free */
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
  return;
}

