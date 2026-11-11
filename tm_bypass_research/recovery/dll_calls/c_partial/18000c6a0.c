/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_lookup_archives_Recovered(void)

{
                    /* 0xc6a0  111  instproxy_lookup_archives */
  func_0x000180de3bb5();
  LOCK();
  UNLOCK();
  return;
}

