/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

longlong * native_180002ef0(char *param_1,uint param_2)

{
  char cVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  char *pcVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  
  uVar11 = 0;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    uVar9 = 0;
    if (param_2 != 0) {
      uVar6 = (ulonglong)param_2;
      pcVar8 = param_1;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        uVar3 = uVar9 + 1;
        if (cVar1 != '\0') {
          uVar3 = uVar9;
        }
        uVar9 = uVar3;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    auVar2 = ZEXT816(8) * ZEXT416(uVar9 + 1);
    uVar6 = auVar2._0_8_;
    if (auVar2._8_8_ != 0) {
      uVar6 = 0xffffffffffffffff;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    plVar4 = (longlong *)api_malloc_180c4641b(uVar6);
    uVar6 = 0;
    if (uVar9 != 0) {
      uVar6 = (ulonglong)uVar9;
      uVar10 = (ulonglong)uVar9;
      plVar12 = plVar4;
      do {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
        lVar5 = api__mbsdup_1802b132c(param_1 + uVar11);
        *plVar12 = lVar5;
        lVar7 = -1;
        do {
          lVar7 = lVar7 + 1;
        } while (*(char *)(lVar5 + lVar7) != '\0');
        plVar12 = plVar12 + 1;
        uVar11 = (ulonglong)(uint)((int)uVar11 + 1 + (int)lVar7);
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    plVar4[uVar6] = 0;
    return plVar4;
  }
  return (longlong *)0x0;
}

