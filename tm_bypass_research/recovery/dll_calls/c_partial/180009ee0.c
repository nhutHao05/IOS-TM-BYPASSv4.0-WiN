/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 idevice_connection_send_Recovered(void)

{
                    /* 0x9ee0  77  idevice_connection_send */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return 0xffffffff94ae481c;
}

