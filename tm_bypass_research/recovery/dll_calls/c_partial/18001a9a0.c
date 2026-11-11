/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void service_client_factory_start_service_Recovered(void)

{
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
                    /* 0x1a9a0  265  service_client_factory_start_service */
  return;
}

