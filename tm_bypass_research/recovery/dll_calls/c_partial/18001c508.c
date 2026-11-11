/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong native_18001c508(undefined1 param_1,undefined8 param_2,undefined8 param_3,
                          undefined8 param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  
  if (_DAT_18002c8b0 < 1) {
    uVar4 = 0;
  }
  else {
    _DAT_18002c8b0 = _DAT_18002c8b0 + -1;
    uVar2 = native_18001c7e4();
    if (_DAT_18002c8d0 != 2) {
      native_18001cb20(7);
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    uVar6 = uVar2;
    native_18001c90c();
    func_0x00018001c7bc();
    native_18001cca8();
    _DAT_18002c8d0 = 0;
    native_18001cac0(uVar2);
    cVar3 = native_18001cae4(param_1,0,param_3,param_4,uVar6);
    uVar4 = -(uint)(cVar3 != '\0') & 1;
    native_18001c93c();
  }
  return (ulonglong)uVar4;
}

