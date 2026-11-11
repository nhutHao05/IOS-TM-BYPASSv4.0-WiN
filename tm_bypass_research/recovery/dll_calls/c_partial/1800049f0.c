/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_truncate_Recovered(void)

{
  code *pcVar1;
  byte bVar2;
  
                    /* 0x49f0  25  afc_truncate */
  bVar2 = func_0x000180de3bb5();
  if (bVar2 < 0x75) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

