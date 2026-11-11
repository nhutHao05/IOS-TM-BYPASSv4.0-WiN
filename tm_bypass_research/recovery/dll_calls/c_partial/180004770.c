/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_file_tell_Recovered(void)

{
                    /* 0x4770  12  afc_file_tell */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  return;
}

