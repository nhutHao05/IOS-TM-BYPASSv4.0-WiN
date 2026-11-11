/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_start_restore_Recovered(void)

{
                    /* 0x19420  251  restored_start_restore */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return;
}

