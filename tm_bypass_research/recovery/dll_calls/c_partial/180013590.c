/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobilebackup2_send_raw_Recovered(void)

{
  func_0x000180cef54a();
                    /* 0x13590  179  mobilebackup2_send_raw */
  LOCK();
  UNLOCK();
  return 0x53794bf3;
}

