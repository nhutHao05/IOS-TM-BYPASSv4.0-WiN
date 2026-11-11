/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void webinspector_client_start_service_Recovered(byte param_1,longlong param_2)

{
  uint *puVar1;
  int *unaff_RSI;
  int *unaff_RDI;
  
  func_0x000180de4640();
  if (*unaff_RSI != *unaff_RDI) {
    in(0xac);
    puVar1 = (uint *)(param_2 + -0x2c7d2f7f);
    *puVar1 = *puVar1 >> (param_1 & 0x1f) | *puVar1 << 0x20 - (param_1 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

