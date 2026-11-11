/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobile_image_mounter_lookup_image_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
                    /* 0x15910  158  mobile_image_mounter_lookup_image */
  return;
}

