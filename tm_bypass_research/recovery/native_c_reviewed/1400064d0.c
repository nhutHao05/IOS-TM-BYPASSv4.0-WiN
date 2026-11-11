/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_1400064d0(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (_DAT_14000b5d8 == -1) {
    iVar1 = func_0x000140006b16();
  }
  else {
    iVar1 = func_0x000140006b10(&DAT_14000b5d8,param_1);
  }
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = param_1;
  }
  return uVar2;
}

