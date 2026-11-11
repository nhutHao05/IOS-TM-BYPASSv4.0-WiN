/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_activate_Recovered(void)

{
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
                    /* 0x119a0  163  mobileactivation_activate */
  LOCK();
  UNLOCK();
  return;
}

