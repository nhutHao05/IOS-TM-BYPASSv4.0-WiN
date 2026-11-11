/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_receive_Recovered(void)

{
                    /* 0x188e0  249  restored_receive */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

