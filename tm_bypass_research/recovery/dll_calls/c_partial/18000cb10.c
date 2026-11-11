/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_status_get_error_Recovered(void)

{
  undefined1 in_ZF;
  
  func_0x000180cfc54a();
  if (!(bool)in_ZF) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

