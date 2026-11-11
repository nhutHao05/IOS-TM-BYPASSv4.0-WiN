/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 afc_file_seek_Recovered(void)

{
  func_0x000180d15cec();
                    /* 0x4640  11  afc_file_seek */
  LOCK();
  UNLOCK();
  return 0xffffffff946182dc;
}

