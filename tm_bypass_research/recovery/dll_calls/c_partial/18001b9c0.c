/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void webinspector_client_free_Recovered(void)

{
  undefined1 uVar1;
  
                    /* 0x1b9c0  282  webinspector_client_free */
  uVar1 = func_0x000180db85e3();
  out(0x41,uVar1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

