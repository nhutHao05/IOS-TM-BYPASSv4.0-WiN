/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_goodbye_Recovered(void)

{
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* 0x7ad0  45  diagnostics_relay_goodbye */
  return;
}

