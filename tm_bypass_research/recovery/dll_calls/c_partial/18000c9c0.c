/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_check_capabilities_match_Recovered(char *param_1)

{
  char extraout_AH;
  char in_CF;
  
                    /* 0xc9c0  99  instproxy_check_capabilities_match */
  func_0x000180cef54a();
  *param_1 = (*param_1 - extraout_AH) - in_CF;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

