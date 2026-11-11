/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_anchors_free_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
                    /* 0x15530  199  mobilesync_anchors_free */
  return;
}

