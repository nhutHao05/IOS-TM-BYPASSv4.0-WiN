/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_receive_with_timeout_Recovered(void)

{
  undefined1 uVar1;
  undefined1 *unaff_RDI;
  undefined1 in_PF;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  
  uVar1 = func_0x000180cef54a();
  if ((bool)in_PF) {
    *unaff_RDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!(bool)in_ZF && in_OF == in_SF) {
    in(0xba);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_RDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

