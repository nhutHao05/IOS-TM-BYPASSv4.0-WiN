/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_18001c99c(uint param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (DAT_18002c8e1 == '\0') {
    if (1 < param_1) {
      native_18001cb20(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    iVar2 = func_0x00018001ce8c();
    if ((iVar2 == 0) || (param_1 != 0)) {
      _DAT_18002c8e8 = _DAT_18001e600;
      uRam000000018002c8f0 = _UNK_18001e608;
      _DAT_18002c8f8 = 0xffffffffffffffff;
      _DAT_18002c900 = _DAT_18001e600;
      uRam000000018002c908 = _UNK_18001e608;
      _DAT_18002c910 = 0xffffffffffffffff;
    }
    else {
      iVar2 = func_0x00018001ced0(&DAT_18002c8e8);
      if ((iVar2 != 0) || (iVar2 = func_0x00018001ced0(&DAT_18002c900), iVar2 != 0)) {
        return 0;
      }
    }
    DAT_18002c8e1 = '\x01';
  }
  return 1;
}

