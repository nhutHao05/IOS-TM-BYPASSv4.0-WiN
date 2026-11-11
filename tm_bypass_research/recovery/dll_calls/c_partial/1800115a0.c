/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_get_activation_state_Recovered(void)

{
                    /* 0x115a0  172  mobileactivation_get_activation_state */
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
  return;
}

