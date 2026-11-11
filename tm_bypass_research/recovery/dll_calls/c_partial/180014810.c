/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobilesync_receive_changes_Recovered(void)

{
  undefined8 uVar1;
  
                    /* 0x14810  211  mobilesync_receive_changes */
  uVar1 = func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return uVar1;
}

