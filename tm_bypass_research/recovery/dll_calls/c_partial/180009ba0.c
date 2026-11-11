/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_set_debug_callback_Recovered(void)

{
  func_0x000180cef54a();
                    /* 0x9ba0  92  idevice_set_debug_callback */
  LOCK();
  UNLOCK();
  return;
}

