/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_status_get_percent_complete_Recovered(void)

{
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
                    /* 0xcc40  117  instproxy_status_get_percent_complete */
  return;
}

