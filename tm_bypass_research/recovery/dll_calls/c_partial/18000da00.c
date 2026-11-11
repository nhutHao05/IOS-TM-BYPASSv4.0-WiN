/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_query_type_Recovered(void)

{
  byte bVar1;
  byte *unaff_RBX;
  undefined1 *unaff_RDI;
  
                    /* 0xda00  135  lockdownd_query_type */
  bVar1 = func_0x000180dbfef6();
  *unaff_RBX = *unaff_RBX ^ bVar1;
  *unaff_RDI = 0xef;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

