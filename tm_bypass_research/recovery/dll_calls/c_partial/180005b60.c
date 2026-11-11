/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

int native_180005b60(longlong param_1,uint param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined6 uVar3;
  undefined1 auVar4 [12];
  undefined1 auVar5 [12];
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ulonglong uVar12;
  short sVar13;
  undefined1 auVar14 [16];
  undefined1 auVar17 [16];
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 uVar20;
  undefined2 uVar21;
  
  iVar9 = 0;
  iVar8 = 0;
  iVar22 = 0;
  uVar6 = 0;
  if (7 < param_2) {
    iVar26 = 0;
    iVar27 = 0;
    iVar28 = 0;
    iVar29 = 0;
    iVar22 = 0;
    iVar23 = 0;
    iVar24 = 0;
    iVar25 = 0;
    do {
      iVar10 = (int)uVar6;
      uVar1 = *(undefined4 *)(uVar6 + param_1);
      uVar20 = (undefined1)((uint)uVar1 >> 0x18);
      uVar21 = CONCAT11(uVar20,uVar20);
      uVar20 = (undefined1)((uint)uVar1 >> 0x10);
      uVar2 = CONCAT35(CONCAT21(uVar21,uVar20),CONCAT14(uVar20,uVar1));
      uVar20 = (undefined1)((uint)uVar1 >> 8);
      uVar3 = CONCAT51(CONCAT41((int)((ulonglong)uVar2 >> 0x20),uVar20),uVar20);
      sVar13 = CONCAT11((char)uVar1,(char)uVar1);
      uVar12 = CONCAT62(uVar3,sVar13);
      uVar11 = iVar10 + 8;
      uVar6 = (ulonglong)uVar11;
      auVar16._8_4_ = 0;
      auVar16._0_8_ = uVar12;
      auVar16._12_2_ = uVar21;
      auVar16._14_2_ = uVar21;
      uVar21 = (undefined2)((ulonglong)uVar2 >> 0x20);
      auVar15._12_4_ = auVar16._12_4_;
      auVar15._8_2_ = 0;
      auVar15._0_8_ = uVar12;
      auVar15._10_2_ = uVar21;
      auVar14._10_6_ = auVar15._10_6_;
      auVar14._8_2_ = uVar21;
      auVar14._0_8_ = uVar12;
      uVar21 = (undefined2)uVar3;
      auVar4._4_8_ = auVar14._8_8_;
      auVar4._2_2_ = uVar21;
      auVar4._0_2_ = uVar21;
      iVar26 = iVar26 + ((int)sVar13 >> 8);
      iVar27 = iVar27 + (auVar4._0_4_ >> 0x18);
      iVar28 = iVar28 + (auVar14._8_4_ >> 0x18);
      iVar29 = iVar29 + (auVar15._12_4_ >> 0x18);
      uVar1 = *(undefined4 *)((ulonglong)(iVar10 + 4) + param_1);
      uVar20 = (undefined1)((uint)uVar1 >> 0x18);
      uVar21 = CONCAT11(uVar20,uVar20);
      uVar20 = (undefined1)((uint)uVar1 >> 0x10);
      uVar2 = CONCAT35(CONCAT21(uVar21,uVar20),CONCAT14(uVar20,uVar1));
      uVar20 = (undefined1)((uint)uVar1 >> 8);
      uVar3 = CONCAT51(CONCAT41((int)((ulonglong)uVar2 >> 0x20),uVar20),uVar20);
      sVar13 = CONCAT11((char)uVar1,(char)uVar1);
      uVar12 = CONCAT62(uVar3,sVar13);
      auVar19._8_4_ = 0;
      auVar19._0_8_ = uVar12;
      auVar19._12_2_ = uVar21;
      auVar19._14_2_ = uVar21;
      uVar21 = (undefined2)((ulonglong)uVar2 >> 0x20);
      auVar18._12_4_ = auVar19._12_4_;
      auVar18._8_2_ = 0;
      auVar18._0_8_ = uVar12;
      auVar18._10_2_ = uVar21;
      auVar17._10_6_ = auVar18._10_6_;
      auVar17._8_2_ = uVar21;
      auVar17._0_8_ = uVar12;
      uVar21 = (undefined2)uVar3;
      auVar5._4_8_ = auVar17._8_8_;
      auVar5._2_2_ = uVar21;
      auVar5._0_2_ = uVar21;
      iVar22 = iVar22 + ((int)sVar13 >> 8);
      iVar23 = iVar23 + (auVar5._0_4_ >> 0x18);
      iVar24 = iVar24 + (auVar17._8_4_ >> 0x18);
      iVar25 = iVar25 + (auVar18._12_4_ >> 0x18);
    } while (uVar11 < (param_2 & 0xfffffff8));
    iVar22 = iVar22 + iVar26 + iVar24 + iVar28 + iVar23 + iVar27 + iVar25 + iVar29;
  }
  uVar11 = (uint)uVar6;
  if (param_2 <= uVar11) {
    return iVar22;
  }
  if (1 < param_2 - uVar11) {
    uVar7 = ((param_2 - uVar11) - 2 >> 1) + 1;
    uVar12 = (ulonglong)uVar7;
    do {
      iVar9 = iVar9 + *(char *)(uVar6 + param_1);
      iVar8 = iVar8 + *(char *)(uVar6 + 1 + param_1);
      uVar6 = uVar6 + 2;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
    if (param_2 <= uVar11 + uVar7 * 2) goto LAB_180005c46;
  }
  iVar22 = iVar22 + *(char *)(uVar6 + param_1);
LAB_180005c46:
  return iVar8 + iVar9 + iVar22;
}

