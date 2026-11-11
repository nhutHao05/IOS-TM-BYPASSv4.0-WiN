/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_client_options_set_return_attributes_Recovered(void)

{
  func_0x000180dbfef6();
                    /* 0xcf20  106  instproxy_client_options_set_return_attributes */
  LOCK();
  UNLOCK();
  return;
}

