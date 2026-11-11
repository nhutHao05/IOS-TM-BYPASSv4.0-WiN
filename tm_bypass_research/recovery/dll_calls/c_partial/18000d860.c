/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_client_set_label_Recovered(void)

{
  func_0x000180db85e3();
  LOCK();
  UNLOCK();
                    /* 0xd860  124  lockdownd_client_set_label */
  return;
}

