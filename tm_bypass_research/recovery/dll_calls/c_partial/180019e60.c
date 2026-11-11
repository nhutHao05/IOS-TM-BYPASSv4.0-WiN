/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void sbservices_get_interface_orientation_Recovered(void)

{
  func_0x000180d915bb();
                    /* 0x19e60  258  sbservices_get_interface_orientation */
  LOCK();
  UNLOCK();
  return;
}

