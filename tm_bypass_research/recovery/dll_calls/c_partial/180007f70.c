/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 diagnostics_relay_query_mobilegestalt_Recovered(void)

{
  func_0x000180cd8a6f();
                    /* 0x7f70  48  diagnostics_relay_query_mobilegestalt */
  LOCK();
  UNLOCK();
  return 0xf5765a;
}

