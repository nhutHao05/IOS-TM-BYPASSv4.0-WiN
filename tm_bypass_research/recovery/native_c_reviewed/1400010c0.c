/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * native_1400010c0(char *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  char *pcVar2;
  char cVar3;
  longlong lVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lStackX_10;
  longlong alStackX_18 [2];
  
  alStackX_18[0] = param_3;
  alStackX_18[1] = param_4;
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  lVar9 = -1;
  do {
    lVar9 = lVar9 + 1;
  } while (param_1[lVar9] != '\0');
  plVar10 = &lStackX_10;
  iVar8 = (int)lVar9 + 1;
  lVar9 = param_2;
  if (param_2 != 0) {
    do {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (*(char *)(lVar9 + lVar4) != '\0');
      plVar1 = plVar10 + 1;
      plVar10 = plVar10 + 1;
      iVar8 = iVar8 + 1 + (int)lVar4;
      lVar9 = *plVar1;
    } while (*plVar1 != 0);
  }
  iVar7 = 0;
  lStackX_10 = param_2;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  pcVar5 = (char *)api_malloc_1401b5c0d((longlong)iVar8);
  pcVar6 = pcVar5;
  do {
    cVar3 = *param_1;
    param_1 = param_1 + 1;
    *pcVar6 = cVar3;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  plVar10 = &lStackX_10;
  while (lStackX_10 != 0) {
    pcVar6 = pcVar5 + -1;
    do {
      pcVar2 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar2 != '\0');
    *(undefined2 *)pcVar6 = _DAT_140007610;
    pcVar6 = pcVar5 + -1;
    do {
      pcVar2 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar2 != '\0');
    lVar9 = 0;
    do {
      cVar3 = *(char *)(lStackX_10 + lVar9);
      pcVar6[lVar9] = cVar3;
      lVar9 = lVar9 + 1;
    } while (cVar3 != '\0');
    lVar9 = -1;
    do {
      lVar9 = lVar9 + 1;
    } while (pcVar5[lVar9] != '\0');
    lVar4 = (longlong)iVar7;
    iVar7 = (int)lVar9;
    if (lVar4 < iVar7) {
      pcVar6 = pcVar5 + lVar4;
      lVar4 = iVar7 - lVar4;
      do {
        if (*pcVar6 == '/') {
          *pcVar6 = '\\';
        }
        pcVar6 = pcVar6 + 1;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
    }
    plVar1 = plVar10 + 1;
    plVar10 = plVar10 + 1;
    lStackX_10 = *plVar1;
  }
  return pcVar5;
}

