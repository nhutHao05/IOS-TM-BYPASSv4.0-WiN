/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_client_new_with_service_client_Recovered(byte param_1)

{
  uint uVar1;
  longlong unaff_RBP;
  undefined1 in_CF;
  
                    /* 0x2450  4  afc_client_new_with_service_client */
  func_0x000180cfc54a();
  uVar1 = *(uint *)(unaff_RBP + -0x23);
  *(uint *)(unaff_RBP + -0x23) =
       (uint)(CONCAT14(in_CF,uVar1) >> (param_1 & 0x1f)) | uVar1 << 0x21 - (param_1 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

