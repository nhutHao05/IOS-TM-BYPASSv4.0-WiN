/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_get_handle_Recovered(void)

{
  func_0x000180de3bb5();
                    /* 0xa5a0  86  idevice_get_handle */
  LOCK();
  UNLOCK();
  return;
}

