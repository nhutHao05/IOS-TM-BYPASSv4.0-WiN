/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup2_receive_message_Recovered(void)

{
                    /* 0x13410  176  mobilebackup2_receive_message */
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
  return;
}

