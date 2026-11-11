/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_archive_Recovered(void)

{
                    /* 0xc750  96  instproxy_archive */
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
  return;
}

