/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_anchors_new_Recovered(void)

{
                    /* 0x154b0  200  mobilesync_anchors_new */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return;
}

