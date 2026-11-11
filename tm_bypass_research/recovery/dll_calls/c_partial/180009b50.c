/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 idevice_device_list_free_Recovered(void)

{
                    /* 0x9b50  79  idevice_device_list_free */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return 0xffffffff8532c1d0;
}

