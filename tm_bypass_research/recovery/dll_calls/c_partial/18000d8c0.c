/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 lockdownd_receive_Recovered(void)

{
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
                    /* 0xd8c0  136  lockdownd_receive */
  LOCK();
  UNLOCK();
  return 0xffffffffb8028045;
}

