/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_client_free_Recovered(void)

{
                    /* 0x1b150  274  syslog_relay_client_free */
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
  return;
}

