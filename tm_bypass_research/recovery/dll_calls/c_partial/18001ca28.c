/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

ulonglong native_18001ca28(longlong param_1)

{
  ulonglong uVar1;
  uint7 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar1 = 0x5a4d;
  if (((IMAGE_DOS_HEADER_180000000.e_magic == (char  [2])0x5a4d) &&
      (lVar3 = (longlong)(int)IMAGE_DOS_HEADER_180000000.e_lfanew,
      *(int *)(lVar3 + 0x180000000) == 0x4550)) &&
     (uVar1 = 0x20b, *(short *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -4) == 0x20b
     )) {
    lVar4 = lVar3 + 0x180000018 +
            (ulonglong)*(ushort *)((longlong)IMAGE_DOS_HEADER_180000000.e_res_4_ + lVar3 + -8);
    uVar1 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_180000000.e_magic + lVar3 + 6);
    lVar3 = lVar4 + uVar1 * 0x28;
    for (; lVar4 != lVar3; lVar4 = lVar4 + 0x28) {
      if (((ulonglong)*(uint *)(lVar4 + 0xc) <= param_1 - 0x180000000U) &&
         (uVar1 = (ulonglong)(*(int *)(lVar4 + 8) + *(uint *)(lVar4 + 0xc)),
         param_1 - 0x180000000U < uVar1)) goto LAB_18001ca9e;
    }
    lVar4 = 0;
LAB_18001ca9e:
    if (lVar4 == 0) {
      uVar1 = uVar1 & 0xffffffffffffff00;
    }
    else {
      uVar2 = (uint7)(uVar1 >> 8);
      if (*(int *)(lVar4 + 0x24) < 0) {
        uVar1 = (ulonglong)uVar2 << 8;
      }
      else {
        uVar1 = CONCAT71(uVar2,1);
      }
    }
  }
  else {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}

