/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 debugserver_client_set_ack_mode_Recovered(void)

{
                    /* 0x5e00  34  debugserver_client_set_ack_mode */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return 0x45279edb;
}

