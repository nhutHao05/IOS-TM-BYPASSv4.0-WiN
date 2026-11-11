/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 property_list_service_send_binary_plist_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180de4640();
                    /* 0x18040  239  property_list_service_send_binary_plist */
  LOCK();
  UNLOCK();
  return uVar1;
}

