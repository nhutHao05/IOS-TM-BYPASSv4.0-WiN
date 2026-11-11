/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_client_start_service_Recovered(void)

{
                    /* 0xb660  107  instproxy_client_start_service */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

