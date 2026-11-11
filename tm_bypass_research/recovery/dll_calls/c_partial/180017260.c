/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void screenshotr_screenshot_free_Recovered(void)

{
                    /* 0x17260  223  pinvoke_free_string
                       0x17260  263  screenshotr_screenshot_free */
  func_0x000180cd8a6f();
  return;
}

