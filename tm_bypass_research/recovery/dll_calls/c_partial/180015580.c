/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobilesync_actions_add_Recovered(void)

{
  func_0x000180d915bb();
  LOCK();
  UNLOCK();
                    /* 0x15580  196  mobilesync_actions_add */
  return 0xffffffffb11dcfd3;
}

