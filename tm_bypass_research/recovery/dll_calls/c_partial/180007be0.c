/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 diagnostics_relay_sleep_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180d15cec();
                    /* 0x7be0  52  diagnostics_relay_sleep */
  LOCK();
  UNLOCK();
  return uVar1;
}

