/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

uint debugserver_client_receive_response_Recovered(undefined8 param_1,undefined8 param_2)

{
  undefined2 uVar1;
  undefined6 uVar2;
  uint unaff_EBP;
  undefined4 *unaff_RSI;
  undefined1 *unaff_RDI;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 in_SF;
  char in_OF;
  
  uVar2 = (undefined6)((ulonglong)param_2 >> 0x10);
                    /* 0x5e60  30  debugserver_client_receive_response */
  uVar1 = (undefined2)param_2;
  func_0x000180d15cec();
  if (in_OF == in_SF) {
    *unaff_RDI = 0x1c;
    *(uint *)CONCAT62(uVar2,uVar1) = *(uint *)CONCAT62(uVar2,uVar1) | unaff_EBP;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(0xff);
  if (!(bool)in_SF) {
    out(*unaff_RSI,uVar1);
    return unaff_EBP;
  }
  if (!(bool)in_CF && !(bool)in_ZF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

