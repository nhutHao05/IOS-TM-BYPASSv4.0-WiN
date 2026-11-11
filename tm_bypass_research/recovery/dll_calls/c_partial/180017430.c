/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_client_start_service_Recovered(void)

{
  func_0x000180de4640();
  LOCK();
  UNLOCK();
                    /* 0x17430  227  preboard_client_start_service */
  return;
}

