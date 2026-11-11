/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void service_receive_with_timeout_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
                    /* 0x1ac80  272  service_receive_with_timeout */
  return;
}

