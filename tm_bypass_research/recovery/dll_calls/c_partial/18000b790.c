/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_client_free_Recovered(void)

{
  uint uVar1;
  longlong unaff_RBP;
  undefined1 in_CF;
  
                    /* 0xb790  100  instproxy_client_free */
  func_0x000180db85e3();
  uVar1 = *(uint *)(unaff_RBP + -0x70);
  *(uint *)(unaff_RBP + -0x70) = uVar1 << 0x18 | (uint)(CONCAT14(in_CF,uVar1) >> 9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

