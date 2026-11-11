/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobilebackup2_version_exchange_Recovered(void)

{
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* 0x137a0  182  mobilebackup2_version_exchange */
  return 0xffffffffd800ccce;
}

