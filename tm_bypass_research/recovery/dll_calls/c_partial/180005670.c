/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_client_free_Recovered(void)

{
                    /* 0x5670  27  debugserver_client_free */
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
  return;
}

