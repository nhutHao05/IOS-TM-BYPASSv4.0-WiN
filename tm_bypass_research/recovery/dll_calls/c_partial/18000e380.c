/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_get_device_udid_Recovered(void)

{
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
                    /* 0xe380  129  lockdownd_get_device_udid */
  return;
}

