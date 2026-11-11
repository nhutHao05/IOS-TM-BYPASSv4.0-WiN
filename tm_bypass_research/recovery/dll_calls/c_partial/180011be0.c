/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_client_new_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
                    /* 0x11be0  184  mobilebackup_client_new */
  return;
}

