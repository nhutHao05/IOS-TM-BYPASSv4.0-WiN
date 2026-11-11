/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void house_arrest_client_start_service_Recovered(void)

{
  func_0x000180de3bb5();
                    /* 0x90d0  66  house_arrest_client_start_service */
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  return;
}

