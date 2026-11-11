/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_start_service_with_escrow_bag_Recovered(void)

{
  longlong lVar1;
  undefined4 *unaff_RBX;
  undefined4 unaff_ESI;
  float10 in_ST0;
  
                    /* 0x10070  142  lockdownd_start_service_with_escrow_bag */
  lVar1 = func_0x000180d15cec();
  LOCK();
  *unaff_RBX = unaff_ESI;
  UNLOCK();
  *(longlong *)(lVar1 + 0x6f) = (longlong)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

