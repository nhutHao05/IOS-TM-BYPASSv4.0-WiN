/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_command_get_name_Recovered(void)

{
  func_0x000180d915bb();
                    /* 0xcdb0  108  instproxy_command_get_name */
  LOCK();
  UNLOCK();
  return;
}

