/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_receive_Recovered(void)

{
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
                    /* 0x17820  230  preboard_receive */
  return;
}

