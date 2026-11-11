/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 idevice_event_unsubscribe_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180d8cdd6();
                    /* 0x96f0  82  idevice_event_unsubscribe */
  LOCK();
  UNLOCK();
  return uVar1;
}

