/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void sbservices_client_start_service_Recovered(void)

{
                    /* 0x19720  254  sbservices_client_start_service */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return;
}

