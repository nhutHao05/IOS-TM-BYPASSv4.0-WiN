/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_connection_receive_Recovered(void)

{
                    /* 0xa3d0  75  idevice_connection_receive */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  return;
}

