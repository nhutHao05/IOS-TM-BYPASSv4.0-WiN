/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_set_debug_level_Recovered(void)

{
  func_0x000180d15cec();
                    /* 0x9bb0  93  idevice_set_debug_level */
  LOCK();
  UNLOCK();
  return;
}

