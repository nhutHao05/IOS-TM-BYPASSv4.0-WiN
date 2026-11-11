/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 np_observe_notification_Recovered(void)

{
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
                    /* 0x16bf0  219  np_observe_notification */
  return 0xffffffffff636ae1;
}

