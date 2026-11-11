/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_client_start_service_Recovered(void)

{
  func_0x000180de4640();
  LOCK();
  UNLOCK();
                    /* 0x11220  167  mobileactivation_client_start_service */
  return;
}

