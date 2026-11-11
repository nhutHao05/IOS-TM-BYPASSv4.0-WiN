/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_get_value_Recovered(void)

{
  func_0x000180de3bb5();
                    /* 0xdcf0  131  lockdownd_get_value */
  LOCK();
  UNLOCK();
  return;
}

