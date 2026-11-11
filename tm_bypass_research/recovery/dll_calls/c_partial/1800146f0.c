/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobilesync_get_all_records_from_device_Recovered(void)

{
                    /* 0x146f0  207  mobilesync_get_all_records_from_device */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  return 0xffffffff94a589cc;
}

