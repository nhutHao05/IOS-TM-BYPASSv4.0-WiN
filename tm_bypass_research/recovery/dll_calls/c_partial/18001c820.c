/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined4 native_18001c820(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x00018001ce8c();
  if (iVar1 == 0) {
    uVar2 = func_0x00018000a600();
    iVar1 = func_0x00018001cec4(uVar2);
    if (iVar1 != 0) {
      return 0;
    }
    func_0x00018001ceca();
  }
  else {
    native_18001cce8();
  }
  return 1;
}

