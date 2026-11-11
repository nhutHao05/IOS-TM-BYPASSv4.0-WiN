/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_client_start_service_Recovered(void)

{
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
                    /* 0x25f0  5  afc_client_start_service */
  return;
}

