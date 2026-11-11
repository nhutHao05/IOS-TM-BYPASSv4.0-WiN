/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 instproxy_upgrade_Recovered(void)

{
                    /* 0xc500  119  instproxy_upgrade */
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
  return 0x4245a9;
}

