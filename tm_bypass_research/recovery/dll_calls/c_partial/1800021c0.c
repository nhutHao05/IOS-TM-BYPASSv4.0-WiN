/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800021c0(char *param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  char **ppcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong arg0;
  char *pcVar7;
  char **ppcVar8;
  char *pcStackX_10;
  char *apcStackX_18 [2];
  undefined1 auStack_38 [32];
  undefined8 uStack_18;
  ulonglong uStack_10;
  longlong lVar6;
  
  apcStackX_18[0] = (char *)param_3;
  apcStackX_18[1] = (char *)param_4;
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_38;
  pcStackX_10 = param_2;
  if (param_1 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_1[lVar5] != '\0');
    ppcVar8 = &pcStackX_10;
    arg0 = lVar6 + 2;
    if (param_2 != (char *)0x0) {
      do {
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (param_2[lVar5] != '\0');
        param_2 = ppcVar8[1];
        ppcVar8 = ppcVar8 + 1;
        arg0 = arg0 + lVar5;
      } while (param_2 != (char *)0x0);
    }
    uStack_18 = 0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    pcVar3 = (char *)api_malloc_180a78973(arg0);
    if (pcVar3 != (char *)0x0) {
      pcVar7 = pcVar3;
      pcVar4 = param_1;
      if (param_1 == (char *)0x0) {
        pcVar3 = (char *)0x0;
      }
      else {
        do {
          cVar2 = *pcVar4;
          *pcVar7 = cVar2;
          pcVar7 = pcVar7 + 1;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
        } while (param_1[lVar5] != '\0');
        pcVar3 = pcVar3 + lVar5;
      }
      ppcVar8 = &pcStackX_10;
      pcVar7 = pcStackX_10;
      while (pcVar7 != (char *)0x0) {
        if ((pcVar3 == (char *)0x0) || (pcVar7 == (char *)0x0)) {
          pcVar3 = (char *)0x0;
        }
        else {
          pcVar4 = pcVar7;
          do {
            cVar2 = *pcVar4;
            pcVar4[(longlong)pcVar3 - (longlong)pcVar7] = cVar2;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          lVar5 = -1;
          do {
            lVar5 = lVar5 + 1;
          } while (pcVar7[lVar5] != '\0');
          pcVar3 = pcVar3 + lVar5;
        }
        ppcVar1 = ppcVar8 + 1;
        ppcVar8 = ppcVar8 + 1;
        pcVar7 = *ppcVar1;
      }
      native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
      return;
    }
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

