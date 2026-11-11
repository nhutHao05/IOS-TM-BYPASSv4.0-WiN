/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_query_ioregistry_entry_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
                    /* 0x80d0  46  diagnostics_relay_query_ioregistry_entry */
  return;
}

