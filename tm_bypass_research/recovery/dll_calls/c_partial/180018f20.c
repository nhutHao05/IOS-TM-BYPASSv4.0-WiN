/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_get_value_Recovered(void)

{
                    /* 0x18f20  244  restored_get_value */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

