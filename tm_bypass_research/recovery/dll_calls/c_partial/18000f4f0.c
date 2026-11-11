/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_enter_recovery_Recovered(void)

{
                    /* 0xf4f0  127  lockdownd_enter_recovery */
  func_0x000180d8cdd6();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

