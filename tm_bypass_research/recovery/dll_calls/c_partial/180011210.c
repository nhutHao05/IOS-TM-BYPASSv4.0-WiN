/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_get_status_code_Recovered(void)

{
                    /* 0x11210  153  misagent_get_status_code */
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
  return;
}

