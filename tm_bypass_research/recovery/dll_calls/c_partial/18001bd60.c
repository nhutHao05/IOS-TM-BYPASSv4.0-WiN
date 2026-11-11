/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 webinspector_receive_with_timeout_Recovered(void)

{
  func_0x000180de4640();
  LOCK();
  UNLOCK();
                    /* 0x1bd60  286  webinspector_receive_with_timeout */
  return 0xffffffffc534f3b1;
}

