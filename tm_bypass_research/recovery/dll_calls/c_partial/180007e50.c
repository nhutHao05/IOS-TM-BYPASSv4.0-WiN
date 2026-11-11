/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_request_diagnostics_Recovered(void)

{
  func_0x000180cef54a();
                    /* 0x7e50  49  diagnostics_relay_request_diagnostics */
  LOCK();
  UNLOCK();
  return;
}

