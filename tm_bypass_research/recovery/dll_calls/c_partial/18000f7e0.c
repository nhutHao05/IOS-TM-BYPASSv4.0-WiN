/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_start_session_Recovered(void)

{
  uint *puVar1;
  undefined1 in_SF;
  char in_OF;
  
                    /* 0xf7e0  143  lockdownd_start_session */
  puVar1 = (uint *)func_0x000180d915bb();
  if ((bool)in_SF) {
                    /* WARNING: Could not recover jumptable at 0x0001807bd06e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(ulonglong)*puVar1)();
    return;
  }
  if (in_OF == in_SF) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

