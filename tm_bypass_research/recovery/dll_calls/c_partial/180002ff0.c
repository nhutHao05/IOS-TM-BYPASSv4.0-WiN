/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_read_directory_Recovered(void)

{
                    /* 0x2ff0  20  afc_read_directory */
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
  return;
}

