/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 idevice_get_udid_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180db85e3();
  LOCK();
  UNLOCK();
                    /* 0xa5c0  89  idevice_get_udid */
  return uVar1;
}

