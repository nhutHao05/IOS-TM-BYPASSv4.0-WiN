/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup2_receive_raw_Recovered(void)

{
                    /* 0x136e0  177  mobilebackup2_receive_raw */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return;
}

