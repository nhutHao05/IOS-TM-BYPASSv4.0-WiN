/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_activate_Recovered(undefined8 param_1,byte *param_2)

{
  uint uVar1;
  char *unaff_RDI;
  
                    /* 0x10080  120  lockdownd_activate */
  uVar1 = func_0x000180dbfef6();
  *unaff_RDI = (char)uVar1;
  *param_2 = *param_2 >> 1 | (0xffffffde < uVar1) << 7;
  cRam0000000124107cd4 = cRam0000000124107cd4 + (char)uVar1 + '!';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

