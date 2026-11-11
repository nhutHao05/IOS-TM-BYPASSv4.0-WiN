/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_goodbye_Recovered(void)

{
                    /* 0x19180  245  restored_goodbye */
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
  return;
}

