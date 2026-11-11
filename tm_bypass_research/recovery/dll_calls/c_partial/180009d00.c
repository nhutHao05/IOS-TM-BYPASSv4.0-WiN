/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_new_Recovered(void)

{
  func_0x000180de3bb5();
                    /* 0x9d00  90  idevice_new */
  LOCK();
  UNLOCK();
  return;
}

