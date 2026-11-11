/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140006060(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  
  func_0x000140006a9e(1);
  uVar4 = func_0x0001400065dc();
  func_0x000140006ad4(uVar4);
  uVar4 = func_0x0001400065d0();
  puVar2 = (undefined4 *)func_0x000140006b04();
  *puVar2 = uVar4;
  cVar3 = native_14000635c(1);
  if (cVar3 != '\0') {
    native_140006850();
    native_14000650c(native_14000688c);
    uVar4 = func_0x0001400065d4();
    iVar5 = func_0x000140006aaa(uVar4);
    if (iVar5 == 0) {
      func_0x0001400065e4();
      iVar5 = func_0x000140006618();
      if (iVar5 != 0) {
        func_0x000140006aa4(&SUB_1400065d0);
      }
      func_0x0001400065f8();
      func_0x0001400065f8();
      uVar4 = func_0x0001400065d0();
      func_0x000140006af8(uVar4);
      cVar3 = func_0x0001400065f4();
      if (cVar3 != '\0') {
        func_0x000140006ab0();
      }
      func_0x0001400065d0();
      iVar5 = func_0x000140006788();
      if (iVar5 == 0) {
        return;
      }
    }
  }
  native_14000663c(7);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

