/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_status_get_name_Recovered(void)

{
                    /* 0xcc00  116  instproxy_status_get_name */
  func_0x000180db85e3();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

