/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Instruction at (ram,0x000180ad0430) overlaps instruction at (ram,0x000180ad042f)
    */
/* Only the VM entry is recovered here; the VM body remains protected. */

ulonglong lockdownd_stop_session_Recovered(undefined8 param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  byte bVar4;
  uint *puVar6;
  code *pcVar7;
  byte bVar8;
  char cVar9;
  undefined8 uVar10;
  ulonglong uVar12;
  byte bVar13;
  undefined7 uVar14;
  undefined1 unaff_BL;
  char unaff_BH;
  undefined6 unaff_0000001a;
  longlong unaff_RBP;
  uint *unaff_RDI;
  char in_CF;
  bool bVar15;
  byte bVar5;
  byte *pbVar11;
  
  uVar14 = (undefined7)((ulonglong)param_1 >> 8);
  bVar13 = (byte)param_1;
                    /* 0xd5d0  144  lockdownd_stop_session */
  do {
    uVar10 = func_0x000180d15cec();
    bVar8 = (char)uVar10 + '\r' + in_CF & UNK_180af1da1;
    pbVar11 = (byte *)CONCAT71((int7)((ulonglong)uVar10 >> 8),bVar8);
    bVar4 = *pbVar11;
    bVar5 = *pbVar11;
    *pbVar11 = *pbVar11 + bVar8;
    uVar10 = param_2;
    if (!SCARRY1(bVar5,bVar8)) {
code_r0x000180ad0412:
      cVar9 = (char)pbVar11;
      *(char *)CONCAT71(uVar14,bVar13) = *(char *)CONCAT71(uVar14,bVar13) + cVar9;
      *pbVar11 = *pbVar11 + cVar9;
      pbVar11[0x33] = pbVar11[0x33] + bVar13;
      *(char *)((longlong)pbVar11 * 2) = *(char *)((longlong)pbVar11 * 2) + cVar9;
      *pbVar11 = *pbVar11 + cVar9;
      *(byte *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) =
           *(byte *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) ^ 0x55;
      *pbVar11 = *pbVar11 + (char)((ulonglong)uVar10 >> 8);
      *pbVar11 = *pbVar11 + cVar9;
      *pbVar11 = *pbVar11 + cVar9;
      *pbVar11 = *pbVar11 + cVar9;
      *(char *)CONCAT71(uVar14,bVar13) = *(char *)CONCAT71(uVar14,bVar13) + cVar9;
      *pbVar11 = *pbVar11 + cVar9;
      *(char *)((longlong)unaff_RDI + 0x3f58b336) =
           *(char *)((longlong)unaff_RDI + 0x3f58b336) + unaff_BH;
      puVar1 = (undefined1 *)(CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) + -0x4b);
      *puVar1 = *puVar1;
      return (ulonglong)pbVar11 ^ 0xf0;
    }
    out(0xbe,bVar8);
    pcVar2 = (char *)(CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) + -0x7c588c67);
    *pcVar2 = *pcVar2 + '\x04' + CARRY1(bVar4,bVar8);
    out(0xd8,4);
    puVar6 = unaff_RDI + 1;
    uVar10 = 0x97701404;
    unaff_BH = (unaff_BH - (char)*puVar6) - (uRam000000005890d29d < *unaff_RDI);
    if ((POPCOUNT(unaff_BH) & 1U) == 0) {
      uRambedcdb1358a1a267 = (undefined4)param_2;
      unaff_BH = unaff_BH + *(char *)(unaff_RBP + 0x3aea58ba);
      pbVar11 = (byte *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL));
      bVar15 = 0xef < (bVar13 ^ 0xbc) ||
               CARRY1((bVar13 ^ 0xbc) + 0x10,uRam000000005890d2a1 < *puVar6);
      pbVar3 = (byte *)(CONCAT71(uVar14,bVar13) + 0x2c779458);
      bVar4 = *pbVar3;
      bVar5 = *pbVar3;
      bVar8 = *pbVar3 - 0x14;
      *pbVar3 = bVar8 - bVar15;
      out(0x1404,unaff_BL);
      if ((SBORROW1(bVar5,'\x14') != SBORROW1(bVar8,bVar15)) == (char)*pbVar3 < '\0') {
        iRam0000000091297a03 =
             iRam0000000091297a03 + -0x2a588b3f + (uint)(bVar4 < 0x14 || bVar8 < bVar15);
        pcVar7 = (code *)swi(3);
        uVar12 = (*pcVar7)();
        return uVar12;
      }
      unaff_RDI = (uint *)0x3f58b336;
      goto code_r0x000180ad0412;
    }
    in_CF = '\0';
    param_2 = uVar10;
    unaff_RDI = puVar6;
  } while( true );
}

