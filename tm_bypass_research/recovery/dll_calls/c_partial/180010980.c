/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_install_Recovered(void)

{
                    /* 0x10980  154  misagent_install */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

