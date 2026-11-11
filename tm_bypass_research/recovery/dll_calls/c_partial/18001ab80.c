/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void service_send_Recovered(void)

{
  func_0x000180cd8a6f();
                    /* 0x1ab80  273  service_send */
  LOCK();
  UNLOCK();
  return;
}

