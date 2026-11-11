/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_18001c3f0(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  longlong *plVar6;
  undefined8 uVar7;
  
  cVar3 = native_18001c950(0);
  if (cVar3 != '\0') {
    uVar4 = native_18001c7e4();
    bVar2 = true;
    if (_DAT_18002c8d0 != 0) {
      native_18001cb20(7);
      pcVar1 = (code *)swi(3);
      uVar7 = (*pcVar1)();
      return uVar7;
    }
    _DAT_18002c8d0 = 1;
    cVar3 = native_18001c854();
    if (cVar3 != '\0') {
      native_18001cc6c();
      func_0x00018001c7ac();
      native_18001c7c8();
      iVar5 = func_0x00018001ceb8(&UNK_18001e5a8,&UNK_18001e5b0);
      if ((iVar5 == 0) && (cVar3 = native_18001c820(), cVar3 != '\0')) {
        func_0x00018001ceb2(&UNK_18001e598,&UNK_18001e5a0);
        _DAT_18002c8d0 = 2;
        bVar2 = false;
      }
    }
    native_18001cac0(uVar4);
    if (!bVar2) {
      plVar6 = (longlong *)func_0x00018001cb10();
      if ((*plVar6 != 0) && (cVar3 = native_18001ca28(plVar6), cVar3 != '\0')) {
        (*(code *)PTR__guard_dispatch_icall_18001e580)(param_1,2,param_2);
      }
      _DAT_18002c8b0 = _DAT_18002c8b0 + 1;
      return 1;
    }
  }
  return 0;
}

