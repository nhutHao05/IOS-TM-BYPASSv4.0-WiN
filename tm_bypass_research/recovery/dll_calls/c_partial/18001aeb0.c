/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_client_new_Recovered(void)

{
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* 0x1aeb0  275  syslog_relay_client_new */
  return;
}

