/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_get_changes_from_device_Recovered(void)

{
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* 0x14780  208  mobilesync_get_changes_from_device */
  return;
}

