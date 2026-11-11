/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_request_restore_Recovered(undefined8 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  undefined4 *unaff_RDI;
  
                    /* 0x12820  190  mobilebackup_request_restore */
  func_0x000180cfc54a();
  uVar1 = in(param_2);
  *unaff_RDI = uVar1;
  *(int *)((longlong)unaff_RDI + -0x29) = *(int *)((longlong)unaff_RDI + -0x29) + -0x5b4cefa;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

