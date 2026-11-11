/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_14000635c(uint param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (DAT_14000b5d1 == '\0') {
    if (1 < param_1) {
      native_14000663c(5);
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    iVar2 = func_0x000140006a6c();
    if ((iVar2 == 0) || (param_1 != 0)) {
      _DAT_14000b5d8 = _DAT_140007600;
      uRam000000014000b5e0 = _UNK_140007608;
      _DAT_14000b5e8 = 0xffffffffffffffff;
      _DAT_14000b5f0 = _DAT_140007600;
      uRam000000014000b5f8 = _UNK_140007608;
      _DAT_14000b600 = 0xffffffffffffffff;
    }
    else {
      iVar2 = func_0x000140006b0a(&DAT_14000b5d8);
      if ((iVar2 != 0) || (iVar2 = func_0x000140006b0a(&DAT_14000b5f0), iVar2 != 0)) {
        return 0;
      }
    }
    DAT_14000b5d1 = '\x01';
  }
  return 1;
}

