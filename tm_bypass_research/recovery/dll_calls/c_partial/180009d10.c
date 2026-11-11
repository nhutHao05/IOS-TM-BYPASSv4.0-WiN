/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_free_Recovered(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *unaff_RDI;
  
                    /* 0x9d10  83  idevice_free */
  func_0x000180dbfef6();
  pcVar1 = (code *)swi(0xd4);
  uVar2 = (*pcVar1)();
  *unaff_RDI = uVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

