/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_ready_to_send_changes_from_computer_Recovered(void)

{
  func_0x000180d8cdd6();
  LOCK();
  UNLOCK();
                    /* 0x14d20  209  mobilesync_ready_to_send_changes_from_computer */
  return;
}

