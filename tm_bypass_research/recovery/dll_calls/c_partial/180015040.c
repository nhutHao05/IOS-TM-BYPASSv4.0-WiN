/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_send_changes_Recovered(void)

{
                    /* 0x15040  214  mobilesync_send_changes */
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
  return;
}

