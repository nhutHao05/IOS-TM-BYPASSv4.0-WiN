/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_get_file_info_Recovered(void)

{
                    /* 0x3aa0  17  afc_get_file_info */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return;
}

