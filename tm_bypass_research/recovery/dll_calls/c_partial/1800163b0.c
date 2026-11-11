/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobile_image_mounter_hangup_Recovered(void)

{
                    /* 0x163b0  157  mobile_image_mounter_hangup */
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
  return;
}

