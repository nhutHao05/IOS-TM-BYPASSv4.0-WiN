/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong native_18001c3a0(undefined8 param_1,int param_2,longlong param_3)

{
  code *pcVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  undefined7 uVar10;
  
  if (param_2 == 0) {
    uVar10 = (undefined7)((ulonglong)param_1 >> 8);
    if (_DAT_18002c8b0 < 1) {
      uVar7 = 0;
    }
    else {
      _DAT_18002c8b0 = _DAT_18002c8b0 + -1;
      uVar5 = native_18001c7e4();
      if (_DAT_18002c8d0 != 2) {
        native_18001cb20(7);
        pcVar1 = (code *)swi(3);
        uVar9 = (*pcVar1)();
        return uVar9;
      }
      native_18001c90c();
      func_0x00018001c7bc();
      native_18001cca8();
      _DAT_18002c8d0 = 0;
      native_18001cac0(CONCAT71(uVar10,uVar5));
      cVar4 = native_18001cae4(param_3 != 0,0);
      uVar7 = -(uint)(cVar4 != '\0') & 1;
      native_18001c93c();
    }
    return (ulonglong)uVar7;
  }
  if (param_2 != 1) {
    if (param_2 == 2) {
      bVar3 = native_18001c86c();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      bVar3 = native_18001c894();
    }
    return (ulonglong)bVar3;
  }
  cVar4 = native_18001c950(0);
  if (cVar4 != '\0') {
    uVar5 = native_18001c7e4();
    bVar2 = true;
    if (_DAT_18002c8d0 != 0) {
      native_18001cb20(7);
      pcVar1 = (code *)swi(3);
      uVar9 = (*pcVar1)();
      return uVar9;
    }
    _DAT_18002c8d0 = 1;
    cVar4 = native_18001c854();
    if (cVar4 != '\0') {
      native_18001cc6c();
      func_0x00018001c7ac();
      native_18001c7c8();
      iVar6 = func_0x00018001ceb8(&UNK_18001e5a8,&UNK_18001e5b0);
      if ((iVar6 == 0) && (cVar4 = native_18001c820(), cVar4 != '\0')) {
        func_0x00018001ceb2(&UNK_18001e598,&UNK_18001e5a0);
        _DAT_18002c8d0 = 2;
        bVar2 = false;
      }
    }
    native_18001cac0(uVar5);
    if (!bVar2) {
      plVar8 = (longlong *)func_0x00018001cb10();
      if ((*plVar8 != 0) && (cVar4 = native_18001ca28(plVar8), cVar4 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_18001e580)(param_1,2,param_3);
      }
      _DAT_18002c8b0 = _DAT_18002c8b0 + 1;
      return 1;
    }
  }
  return 0;
}

