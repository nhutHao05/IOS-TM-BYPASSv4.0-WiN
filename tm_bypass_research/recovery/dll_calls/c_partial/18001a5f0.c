/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void screenshotr_take_screenshot_Recovered(void)

{
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
                    /* 0x1a5f0  264  screenshotr_take_screenshot */
  return;
}

