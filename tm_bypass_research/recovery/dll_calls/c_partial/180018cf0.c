/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 restored_query_value_Recovered(void)

{
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
                    /* 0x18cf0  247  restored_query_value */
  LOCK();
  UNLOCK();
  return 0x1210b36;
}

