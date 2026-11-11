/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 debugserver_client_set_argv_Recovered(void)

{
                    /* 0x68f0  35  debugserver_client_set_argv */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return 0x713d9563;
}

