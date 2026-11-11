/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_reboot_Recovered(void)

{
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
                    /* 0x19570  248  restored_reboot */
  return;
}

