/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_send_Recovered(byte param_1,undefined2 param_2)

{
  undefined1 *unaff_RSI;
  undefined1 in_CF;
  char in_SF;
  char in_OF;
  
  func_0x000180d8cdd6();
  if (!(bool)in_CF) {
    out(*unaff_RSI,CONCAT11((char)((ushort)param_2 >> 8),(byte)param_2 >> (param_1 & 0x1f)));
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (in_OF != in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

