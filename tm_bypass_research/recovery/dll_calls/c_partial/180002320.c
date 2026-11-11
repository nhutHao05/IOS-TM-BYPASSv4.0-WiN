/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180002320(void *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char **ppcVar1;
  char cVar2;
  longlong lVar3;
  void *pvVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  ulonglong arg1;
  char **ppcVar8;
  char *pcStackX_10;
  char *apcStackX_18 [2];
  undefined1 auStack_38 [32];
  undefined8 uStack_18;
  ulonglong uStack_10;
  
  apcStackX_18[0] = (char *)param_3;
  apcStackX_18[1] = (char *)param_4;
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_38;
  lVar7 = 0;
  if (param_1 != (void *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (*(char *)((longlong)param_1 + lVar7) != '\0');
  }
  ppcVar8 = &pcStackX_10;
  arg1 = lVar7 + 1;
  pcVar6 = param_2;
  if (param_2 != (char *)0x0) {
    do {
      lVar3 = -1;
      do {
        lVar3 = lVar3 + 1;
      } while (pcVar6[lVar3] != '\0');
      pcVar6 = ppcVar8[1];
      ppcVar8 = ppcVar8 + 1;
      arg1 = arg1 + lVar3;
    } while (pcVar6 != (char *)0x0);
  }
  uStack_18 = 0;
  pcStackX_10 = param_2;
                    /* Recovered VMProtect thunk: ucrtbase.dll!realloc; offline emulation evidence.
                        */
  pvVar4 = api_realloc_1801bbc43(param_1,arg1);
  if (pvVar4 != (void *)0x0) {
    ppcVar8 = &pcStackX_10;
    lVar7 = (longlong)pvVar4 + lVar7;
    pcVar6 = pcStackX_10;
    while (pcVar6 != (char *)0x0) {
      if ((lVar7 == 0) || (pcVar6 == (char *)0x0)) {
        lVar7 = 0;
      }
      else {
        pcVar5 = pcVar6;
        do {
          cVar2 = *pcVar5;
          pcVar5[lVar7 - (longlong)pcVar6] = cVar2;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        lVar3 = -1;
        do {
          lVar3 = lVar3 + 1;
        } while (pcVar6[lVar3] != '\0');
        lVar7 = lVar7 + lVar3;
      }
      ppcVar1 = ppcVar8 + 1;
      ppcVar8 = ppcVar8 + 1;
      pcVar6 = *ppcVar1;
    }
    native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
    return;
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

