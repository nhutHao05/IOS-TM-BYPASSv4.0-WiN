/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_command_free_Recovered(longlong param_1,longlong param_2)

{
  byte in_CF;
  
                    /* 0x5ad0  38  debugserver_command_free */
  func_0x000180de4640();
  *(uint *)(param_1 + param_2) = *(uint *)(param_1 + param_2) >> 1 | (uint)in_CF << 0x1f;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

