/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_receive_with_timeout_Recovered(void)

{
  func_0x000180d15cec();
                    /* 0x1b250  278  syslog_relay_receive_with_timeout */
  LOCK();
  UNLOCK();
  return;
}

