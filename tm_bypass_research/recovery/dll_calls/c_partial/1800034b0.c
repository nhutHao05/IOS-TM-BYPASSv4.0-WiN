/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_remove_path_Recovered(void)

{
  func_0x000180cd8a6f();
                    /* 0x34b0  21  afc_remove_path */
  LOCK();
  UNLOCK();
  return;
}

