/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_restore_Recovered(void)

{
                    /* 0xc820  113  instproxy_restore */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

