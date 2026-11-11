/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 webinspector_client_new_Recovered(void)

{
                    /* 0x1b710  283  webinspector_client_new */
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
  return 0x1ad915f3;
}

