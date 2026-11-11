/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_get_socket_type_Recovered(void)

{
                    /* 0xaca0  87  idevice_get_socket_type */
  uRam295c0ebcbf358674 = func_0x000180de4640();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

