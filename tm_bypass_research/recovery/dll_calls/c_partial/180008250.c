/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: This function may have set the stack pointer */
/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_query_ioregistry_plane_Recovered(void)

{
  code *pcVar1;
  
                    /* 0x8250  47  diagnostics_relay_query_ioregistry_plane */
  uRam94e3d39b80f92f13 = func_0x000180dbfef6();
  in(0x9d);
  pcVar1 = (code *)swi(3);
  (*pcVar1)(0x452b0e4);
  return;
}

