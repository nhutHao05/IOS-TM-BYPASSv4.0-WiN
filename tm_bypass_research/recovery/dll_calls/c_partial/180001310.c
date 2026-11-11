/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180001310(longlong param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [80];
  ulonglong uStack_28;
  
  uStack_28 = _DAT_18002c008 ^ (ulonglong)auStack_98;
  if (1 < _DAT_18002c934) {
    iVar7 = 0;
    if (0 < param_2) {
      do {
        iVar2 = native_180001060(auStack_78,"%04x: ",iVar7);
        lVar8 = 0;
        iVar6 = iVar7;
        do {
          if (iVar6 < param_2) {
            iVar3 = native_180001060(auStack_78 + iVar2,"%02x ",*(undefined1 *)(param_1 + lVar8));
          }
          else {
            iVar3 = native_180001060(auStack_78 + iVar2,&UNK_18001e644);
          }
          iVar2 = iVar2 + iVar3;
          iVar6 = iVar6 + 1;
          lVar8 = lVar8 + 1;
        } while (lVar8 < 0x10);
        iVar3 = native_180001060(auStack_78 + iVar2,"  | ");
        iVar2 = iVar2 + iVar3;
        lVar8 = 0;
        do {
          if (param_2 <= iVar7) break;
          if ((byte)(*(char *)(param_1 + lVar8) - 0x20U) < 0x60) {
            iVar3 = native_180001060(auStack_78 + iVar2,&UNK_18001e65c,*(char *)(param_1 + lVar8));
          }
          else {
            iVar3 = native_180001060(auStack_78 + iVar2,&UNK_18001e658);
          }
          iVar2 = iVar2 + iVar3;
          iVar7 = iVar7 + 1;
          lVar8 = lVar8 + 1;
        } while (lVar8 < 0x10);
        iVar7 = native_180001060(auStack_78 + iVar2,&UNK_18001e660);
        for (uVar4 = (ulonglong)(iVar7 + iVar2); (longlong)uVar4 < 0x50; uVar4 = uVar4 + 1) {
          if (0x4f < uVar4) {
            native_18001c20c();
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          auStack_78[uVar4] = 0;
        }
        if (_DAT_18002c938 == (code *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
          uVar5 = api___acrt_iob_func_180ab2514(2);
          native_180001010(uVar5,&UNK_18001e664,auStack_78);
        }
        else {
          (*_DAT_18002c938)(auStack_78);
        }
        param_1 = param_1 + 0x10;
        iVar7 = iVar6;
      } while (iVar6 < param_2);
    }
    if (_DAT_18002c938 == (code *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
      uVar5 = api___acrt_iob_func_180a8a8e6(2);
      native_180001010(uVar5,&UNK_18001e660);
    }
  }
  native_18001c0e0(uStack_28 ^ (ulonglong)auStack_98);
  return;
}

