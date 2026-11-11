/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_rename_path_Recovered(undefined8 param_1,undefined2 param_2)

{
  char *pcVar1;
  uint uVar2;
  char unaff_BL;
  undefined7 unaff_00000019;
  longlong unaff_RBP;
  byte in_CF;
  
                    /* 0x36a0  23  afc_rename_path */
  uVar2 = func_0x000180d8cdd6();
  uRamff3be4a2ed8c5a8f = in(param_2);
  uRamb2ba45d034526bb0 = uRamff3be4a2ed8c5a8f;
  *(char *)(unaff_RBP + 0x2b) =
       *(char *)(unaff_RBP + 0x2b) + unaff_BL +
       (uVar2 < 0x4ca2eda8 || uVar2 + 0xb35d1258 < (uint)in_CF);
  pcVar1 = (char *)(CONCAT71(unaff_00000019,unaff_BL) + -0x20);
  *pcVar1 = *pcVar1 + -0x80;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

