/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 debugserver_client_start_service_Recovered(void)

{
  undefined8 unaff_retaddr;
  
                    /* 0x5540  37  debugserver_client_start_service */
  func_0x000180d15cec();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  return unaff_retaddr;
}

