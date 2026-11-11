/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 lockdownd_remove_value_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180cef54a();
                    /* 0xe180  137  lockdownd_remove_value */
  LOCK();
  UNLOCK();
  return uVar1;
}

