/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_receive_Recovered(longlong param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  undefined8 uVar4;
  char cVar7;
  longlong lVar6;
  uint unaff_EBX;
  undefined4 unaff_0000001c;
  uint unaff_EBP;
  undefined1 *unaff_RSI;
  undefined1 *unaff_RDI;
  char in_CF;
  bool bVar8;
  undefined8 uStack_18;
  undefined7 uVar5;
  
  uVar4 = func_0x000180d915bb();
  uVar5 = (undefined7)((ulonglong)uVar4 >> 8);
  in_CF = (char)uVar4 + -0x78 + in_CF;
  uStack_18 = 0x3e;
  *unaff_RDI = *unaff_RSI;
  lVar6 = param_1 + -1;
  if (lVar6 == 0 || (unaff_EBP & unaff_EBX) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar8 = *(uint *)(CONCAT71(uVar5,in_CF) + -0x9f38c36 + lVar6) < (uint)&uStack_18;
  pcVar1 = (char *)(CONCAT44(unaff_0000001c,CONCAT31((int3)(unaff_EBX >> 8),uRam0000000198cf9478)) +
                   0x56f39c04);
  cVar2 = *pcVar1;
  cVar7 = (char)((ulonglong)lVar6 >> 8);
  cVar3 = *pcVar1 - cVar7;
  *pcVar1 = cVar3 - bVar8;
  if ((SBORROW1(cVar2,cVar7) != SBORROW1(cVar3,bVar8)) == *pcVar1 < '\0') {
    if (param_1 == 2 || *pcVar1 != '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Could not recover jumptable at 0x000180ba24c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(ulonglong)*(uint *)(CONCAT71(uVar5,in_CF) + 0x18))();
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

