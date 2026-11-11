/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup2_send_message_Recovered(void)

{
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
                    /* 0x13220  178  mobilebackup2_send_message */
  return;
}

