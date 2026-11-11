/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

int file_relay_request_sources_Recovered(undefined8 param_1,undefined8 param_2)

{
  undefined1 *unaff_RSI;
  undefined1 *unaff_RDI;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  func_0x000180d915bb();
  if (!(bool)in_CF && !(bool)in_ZF) {
    out(*unaff_RSI,(short)CONCAT71((int7)((ulonglong)param_2 >> 8),0xa1));
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_RDI = 0xb7;
  return iRam000000002f2860f8 * 0x2f2860b7;
}

