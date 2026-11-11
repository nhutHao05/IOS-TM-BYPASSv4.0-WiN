/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_decode_string_Recovered(undefined8 param_1,undefined2 param_2)

{
  int iVar1;
  int unaff_EBX;
  
                    /* 0x5d30  40  debugserver_decode_string */
  iVar1 = func_0x000180db85e3();
  uRam000000007e38d734 = (ulonglong)(uint)(unaff_EBX - (iVar1 + 0x2715bef1));
  out(param_2,(char)(iVar1 + 0x2715bef1));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

