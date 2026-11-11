/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void misagent_client_new_Recovered(undefined8 param_1,undefined2 param_2)

{
  uint unaff_EBX;
  longlong unaff_RDI;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  
                    /* 0x9000  65  house_arrest_client_new
                       0x9000  149  misagent_client_new */
  func_0x000180cfc54a();
  if (!(bool)in_ZF && in_OF == in_SF) {
    in(param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(uint *)(unaff_RDI + -0x345f63a6) = *(uint *)(unaff_RDI + -0x345f63a6) | unaff_EBX;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

