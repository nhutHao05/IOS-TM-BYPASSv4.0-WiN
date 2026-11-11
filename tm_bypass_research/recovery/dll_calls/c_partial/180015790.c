/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 mobile_image_mounter_start_service_Recovered(void)

{
  undefined8 unaff_retaddr;
  
  func_0x000180cfc54a();
  LOCK();
  UNLOCK();
                    /* 0x15790  161  mobile_image_mounter_start_service */
  LOCK();
  UNLOCK();
  return unaff_retaddr;
}

