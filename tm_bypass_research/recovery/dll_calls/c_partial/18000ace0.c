/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_get_tcp_endpoint_Recovered(void)

{
  func_0x000180d15cec();
                    /* 0xace0  88  idevice_get_tcp_endpoint */
  LOCK();
  UNLOCK();
  return;
}

