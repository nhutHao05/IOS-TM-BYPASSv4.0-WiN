/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void np_client_new_Recovered(void)

{
                    /* 0xb580  102  instproxy_client_new
                       0xb580  217  np_client_new */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return;
}

