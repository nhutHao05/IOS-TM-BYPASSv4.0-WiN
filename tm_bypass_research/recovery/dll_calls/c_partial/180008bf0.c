/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void heartbeat_client_free_Recovered(void)

{
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
                    /* 0x8bf0  58  heartbeat_client_free */
  return;
}

