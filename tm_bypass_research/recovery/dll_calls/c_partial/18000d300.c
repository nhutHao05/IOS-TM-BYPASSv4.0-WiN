/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 native_18000d300(longlong param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar5 = 0;
  pcVar3 = _DAT_18002c040;
  uVar6 = uVar5;
  if (_DAT_18002c040 != (char *)0x0) {
    do {
      lVar4 = param_1 - (longlong)pcVar3;
      do {
        cVar1 = *pcVar3;
        cVar2 = pcVar3[lVar4];
        if (cVar1 != cVar2) break;
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
      if (cVar1 == cVar2) {
        return *(undefined4 *)((longlong)(int)uVar6 * 0x18 + 0x18002c050);
      }
      uVar5 = uVar5 + 1;
      pcVar3 = *(char **)(&DAT_18002c040 + uVar5 * 0x18);
      uVar6 = (ulonglong)((int)uVar6 + 1);
    } while (*(char **)(&DAT_18002c040 + uVar5 * 0x18) != (char *)0x0);
  }
  return 0xffffff00;
}

