/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 afc_file_read_Recovered(void)

{
                    /* 0x3f80  10  afc_file_read */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return 0x453a8730;
}

