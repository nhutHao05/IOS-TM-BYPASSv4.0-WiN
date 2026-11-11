/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

void property_list_service_receive_plist_Recovered(void)

{
  func_0x000180cef54a();
  LOCK();
  UNLOCK();
                    /* 0x185b0  237  property_list_service_receive_plist */
  LOCK();
  UNLOCK();
  return;
}

