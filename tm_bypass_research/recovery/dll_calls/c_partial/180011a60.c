/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_activate_with_session_Recovered(void)

{
  uint uVar1;
  
                    /* 0x11a60  164  mobileactivation_activate_with_session */
  uVar1 = func_0x000180db85e3();
  uRam00000001d4938b08 = uRam00000001d4938b08 & uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

