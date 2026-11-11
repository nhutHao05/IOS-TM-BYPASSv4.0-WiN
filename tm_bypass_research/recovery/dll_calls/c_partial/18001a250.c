/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 screenshotr_client_new_Recovered(void)

{
                    /* 0x1a250  261  screenshotr_client_new */
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
  return 0xffffffffb8061432;
}

