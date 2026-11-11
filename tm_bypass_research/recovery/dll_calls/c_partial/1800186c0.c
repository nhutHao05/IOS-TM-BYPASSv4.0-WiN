/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void property_list_service_disable_ssl_Recovered(undefined8 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  undefined4 *unaff_RDI;
  
                    /* 0x186c0  235  property_list_service_disable_ssl */
  func_0x000180de3bb5();
  uVar1 = in(param_2);
  *unaff_RDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

