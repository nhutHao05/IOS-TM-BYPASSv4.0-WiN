/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void heartbeat_receive_Recovered(undefined8 param_1)

{
  undefined8 *unaff_RBP;
  undefined1 in_CF;
  undefined1 in_SF;
  
  func_0x000180cd8a6f();
  if ((bool)in_SF) {
    *unaff_RBP = param_1;
  }
  else if ((bool)in_CF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(0x18);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

