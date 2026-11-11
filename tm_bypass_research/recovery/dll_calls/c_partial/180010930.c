/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 misagent_client_free_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180d15cec();
                    /* 0x10930  148  misagent_client_free */
  LOCK();
  UNLOCK();
  return uVar1;
}

