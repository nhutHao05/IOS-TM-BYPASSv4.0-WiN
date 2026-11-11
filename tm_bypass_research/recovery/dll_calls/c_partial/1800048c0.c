/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_file_truncate_Recovered(void)

{
                    /* 0x48c0  13  afc_file_truncate */
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
  return;
}

