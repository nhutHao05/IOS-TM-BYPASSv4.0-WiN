/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup2_send_status_response_Recovered(void)

{
  func_0x000180d8cdd6();
                    /* 0x13c40  181  mobilebackup2_send_status_response */
  LOCK();
  UNLOCK();
  return;
}

