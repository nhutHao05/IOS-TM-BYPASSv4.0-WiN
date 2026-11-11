/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_client_new_Recovered(void)

{
                    /* 0xe420  122  lockdownd_client_new */
  func_0x000180d15cec();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

