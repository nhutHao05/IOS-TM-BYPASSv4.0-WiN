/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_set_value_Recovered(void)

{
                    /* 0xdf50  140  lockdownd_set_value */
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
  return;
}

