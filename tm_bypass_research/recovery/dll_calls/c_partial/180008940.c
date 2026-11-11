/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void heartbeat_client_new_Recovered(void)

{
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
                    /* 0x8940  59  heartbeat_client_new */
  return;
}

