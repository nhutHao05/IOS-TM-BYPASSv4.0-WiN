/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_create_activation_info_with_session_Recovered(void)

{
                    /* 0x11870  169  mobileactivation_create_activation_info_with_session */
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
  return;
}

