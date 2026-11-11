/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 lockdownd_pair_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180cfc54a();
  LOCK();
  UNLOCK();
                    /* 0xf3f0  133  lockdownd_pair */
  return uVar1;
}

