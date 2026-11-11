/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_client_start_service_Recovered(void)

{
                    /* 0x7960  44  diagnostics_relay_client_start_service */
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
  return;
}

