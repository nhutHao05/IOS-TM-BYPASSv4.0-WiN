/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void diagnostics_relay_restart_Recovered(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  undefined1 uVar2;
  undefined7 uVar3;
  byte unaff_BL;
  uint unaff_EBP;
  undefined4 unaff_0000002c;
  longlong unaff_RSI;
  uint unaff_EDI;
  
  uVar3 = (undefined7)((ulonglong)param_2 >> 8);
                    /* 0x7e30  50  diagnostics_relay_restart */
  uVar2 = (undefined1)param_2;
  func_0x000180cef54a();
  *(undefined8 *)(CONCAT71(uVar3,uVar2) + 0x76525358) = 0xffffffffe11157f3;
  if (CARRY4(unaff_EDI,unaff_EDI) || unaff_EDI * 2 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((POPCOUNT(*(uint *)((ulonglong)(unaff_EDI * 2) + 0x5660828f) & unaff_EBP & 0xff) & 1U) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *(undefined1 *)(unaff_RSI + -0x71a54314) = uVar2;
  *(byte *)CONCAT71(uVar3,uVar2) = *(byte *)CONCAT71(uVar3,uVar2) ^ unaff_BL;
  piVar1 = (int *)(CONCAT44(unaff_0000002c,unaff_EBP) + 0x4b);
  *piVar1 = *piVar1 + unaff_EDI * -2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

