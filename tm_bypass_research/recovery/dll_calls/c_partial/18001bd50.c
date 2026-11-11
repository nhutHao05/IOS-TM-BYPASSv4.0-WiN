/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 webinspector_receive_Recovered(void)

{
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
                    /* 0x1bd50  285  webinspector_receive */
  return 0xffffffff995bcdf4;
}

