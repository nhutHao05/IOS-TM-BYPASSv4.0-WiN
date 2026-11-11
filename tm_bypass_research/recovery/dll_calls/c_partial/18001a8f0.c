/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void service_client_new_Recovered(void)

{
                    /* 0x1a8f0  267  service_client_new */
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
  return;
}

