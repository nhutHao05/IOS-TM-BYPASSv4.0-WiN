/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_get_device_list_Recovered(void)

{
                    /* 0x99c0  84  idevice_get_device_list */
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
  return;
}

