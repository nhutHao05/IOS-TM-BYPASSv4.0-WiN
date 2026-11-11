/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_uninstall_Recovered(void)

{
  func_0x000180de3bb5();
                    /* 0xc5d0  118  instproxy_uninstall */
  LOCK();
  UNLOCK();
  return;
}

