/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 afc_get_device_info_key_Recovered(void)

{
                    /* 0x33d0  16  afc_get_device_info_key */
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
  return 0x64f925e;
}

