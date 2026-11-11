/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001805003b9) overlaps instruction at (ram,0x0001805003b8)
    */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debug_info_real_Recovered(byte *param_1,undefined8 param_2)

{
  byte bVar1;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  byte bVar8;
  int iVar9;
  byte unaff_BL;
  undefined7 unaff_00000019;
  longlong unaff_RBP;
  char *pcVar10;
  uint uVar11;
  undefined1 *unaff_RDI;
  char cVar12;
  bool bVar13;
  char cVar14;
  byte bVar2;
  
                    /* 0x11c0  26  debug_info_real */
  uVar5 = func_0x000180cef54a();
  iVar9 = (int)((ulonglong)param_2 >> 8);
  out((short)param_2,uVar5);
  pcVar10 = (char *)(ulonglong)*(uint *)(CONCAT71(unaff_00000019,unaff_BL ^ (byte)param_1) + 0x46);
  uVar11 = (uint)unaff_RDI;
  cVar12 = CARRY4(uVar5,uVar11);
  cVar14 = SCARRY4(uVar5,uVar11);
  bVar13 = (int)(uVar5 + uVar11) < 0;
  pcVar4 = (code *)swi(199);
  uVar7 = (*pcVar4)();
  if ((bool)cVar14 == bVar13) {
    pcVar10[0x2f918e05] = pcVar10[0x2f918e05] << ((byte)param_1 & 0x1f);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (bVar13) {
    bVar8 = (byte)((uint)iVar9 >> 8);
    *pcVar10 = *pcVar10 + bVar8 + cVar12;
    if ((POPCOUNT(*pcVar10) & 1U) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ('\b' < (char)uVar7) {
      halt_baddata();
    }
    bVar1 = *param_1;
    bVar2 = *param_1;
    *param_1 = *param_1 - bVar8;
    if ((char)*param_1 < '\0') {
      iVar6 = (int)CONCAT71((int7)((ulonglong)uVar7 >> 8),*unaff_RDI);
      iVar3 = iVar6 + iVar9;
      if ((SCARRY4(iVar6,iVar9) != SCARRY4(iVar3,(uint)(bVar1 < bVar8))) !=
          (int)(iVar3 + (uint)(bVar1 < bVar8)) < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (SBORROW1(bVar2,bVar8)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    pcVar10 = *(undefined1 **)(unaff_RBP + 8) + 1;
    out(**(undefined1 **)(unaff_RBP + 8),(short)iVar9);
  }
  out(*pcVar10,(short)iVar9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

