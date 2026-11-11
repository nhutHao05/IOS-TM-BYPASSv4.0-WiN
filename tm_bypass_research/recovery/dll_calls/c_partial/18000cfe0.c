/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_client_get_path_for_bundle_identifier_Recovered(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  undefined3 uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 unaff_RBX;
  ulonglong *puVar12;
  ulonglong *puVar13;
  undefined8 *puVar14;
  longlong unaff_RBP;
  longlong unaff_RSI;
  uint uVar15;
  uint uVar16;
  byte *unaff_RDI;
  byte *pbVar17;
  ulonglong in_R11;
  longlong unaff_R14;
  bool bVar18;
  ulonglong auStack_18 [3];
  uint *puVar9;
  
  auStack_18[2] = 0xffffffffc5213d57;
  uVar8 = func_0x000180de4640();
  uVar3 = auStack_18[2] & 0x400;
  LOCK();
  uVar2 = *(undefined1 *)(unaff_RBP + 0x4b);
  *(undefined1 *)(unaff_RBP + 0x4b) = (char)unaff_RBX;
  auStack_18[2] = CONCAT71((int7)((ulonglong)unaff_RBX >> 8),uVar2);
  UNLOCK();
  puVar13 = auStack_18 + 2;
  pbVar17 = unaff_RDI + (ulonglong)(uVar3 != 0) * -2 + 1;
  if (SBORROW1((byte)uVar8,*unaff_RDI)) {
    uVar6 = *(uint *)(unaff_RSI + -0x7b);
    *(uint *)(unaff_RSI + -0x7b) =
         uVar6 << 9 | (uint)(ushort)(CONCAT14((byte)uVar8 < *unaff_RDI,uVar6) >> 0x18);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  while( true ) {
    uVar16 = (uint)uVar8;
    bVar18 = uVar16 < 0x934bff89;
    uVar6 = uVar16 + 0x6cb40077;
    lVar10 = param_1 + -1;
    if (lVar10 == 0 || uVar6 != 0) break;
    uVar4 = (undefined3)(uVar6 >> 8);
    uVar8 = (ulonglong)
            (uint)(int)(short)CONCAT31(uVar4,*(undefined1 *)
                                              (auStack_18[2] +
                                              ((ulonglong)
                                               CONCAT31(uVar4,((char)uVar6 + -0x38) - bVar18) & 0xff
                                              )));
    puVar12 = puVar13 + -1;
    puVar13 = puVar13 + -1;
    *puVar12 = uVar8;
    puVar9 = (uint *)(param_2 + -0x45 + uVar8);
    *puVar9 = *puVar9 ^ (uint)param_2;
    *(int *)(uVar8 - 0x67) = *(int *)(uVar8 - 0x67) + (int)auStack_18[2];
    param_1 = lVar10;
  }
  if (bVar18) {
    piVar1 = (int *)(unaff_RSI + 0x41cf3ff1 + (ulonglong)uVar6 * 8);
    *piVar1 = *piVar1 << 0x1d;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  out((short)param_2,uVar6);
  piVar1 = (int *)((ulonglong)((uVar16 + 0x501c9488) - (uint)bVar18) + 0x77847f0f);
  *piVar1 = *piVar1 + (int)unaff_RBP +
            (uint)(uVar6 < 0x1c976bef || uVar16 + 0x501c9488 < (uint)bVar18);
  uVar6 = (int)unaff_RBP + 0x50;
  *(int *)(param_1 + 0x67887b1b) = *(int *)(param_1 + 0x67887b1b) >> 0x17;
  uVar11 = *puVar13;
  puVar14 = puVar13 + 1;
  puVar9 = (uint *)(auStack_18[2] + -0x298b9f84);
  *puVar9 = *puVar9 | uVar6;
  if (lVar10 != 0) {
    return;
  }
  param_1 = param_1 + -2;
  if (param_1 == 0 || *puVar9 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  while( true ) {
    uVar16 = (int)pbVar17 >> 1;
    cVar5 = ((char)*puVar14 + '?') - (((ulonglong)pbVar17 & 1) != 0);
    param_1 = param_1 + -1;
    if (param_1 == 0 || cVar5 == '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar7 = (uint)CONCAT71((int7)((ulonglong)*puVar14 >> 8),cVar5);
    uVar3 = (ulonglong)(uVar7 < 0xb3401ec1);
    bVar18 = CARRY8(in_R11,*(ulonglong *)(unaff_R14 + -0x47));
    uVar8 = in_R11 + *(ulonglong *)(unaff_R14 + -0x47);
    in_R11 = uVar8 + uVar3;
    param_1 = CONCAT71((int7)((ulonglong)param_1 >> 8),
                       ((char)param_1 - cRam0000000155a98ca8) - (bVar18 || CARRY8(uVar8,uVar3))) +
              -1;
    if (param_1 == 0) break;
    uVar7 = uVar7 | 0xd007f39;
    puVar9 = (uint *)(ulonglong)uVar7;
    uVar15 = uVar16 - *puVar9;
    pbVar17 = (byte *)(ulonglong)uVar15;
    if (uVar16 < *puVar9 || uVar15 == 0) {
      *(int *)(auStack_18[2] + 0x5787a90a) = *(int *)(auStack_18[2] + 0x5787a90a) + (int)param_1;
      puVar9 = (uint *)((longlong)puVar9 + 0x789b6a67);
      *puVar9 = *puVar9 << 0x10 | *puVar9 >> 0x10;
      *pbVar17 = *pbVar17 ^ (byte)((ulonglong)param_1 >> 8);
      out((short)uVar11,
          CONCAT22((short)(uVar7 >> 0x10),
                   CONCAT11((byte)(uVar7 >> 8) | *(byte *)((ulonglong)uVar6 + 0x68912335),
                            (char)uVar7)));
      pbVar17[-0x44] = pbVar17[-0x44] | (byte)param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar11 = puVar14[1];
    puVar14 = puVar14 + 2;
  }
  return;
}

