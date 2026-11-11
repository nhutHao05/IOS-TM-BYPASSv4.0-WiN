/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_send_Recovered(void)

{
  func_0x000180de4640();
  LOCK();
  UNLOCK();
                    /* 0xd960  138  lockdownd_send */
  return;
}

