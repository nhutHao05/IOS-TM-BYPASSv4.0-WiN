/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140006128(undefined8 param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  undefined1 auStack_28 [16];
  undefined8 auStack_18 [2];
  
  func_0x0001400067e4();
  func_0x0001400065d0();
  cVar4 = SCARRY8((longlong)auStack_28,0x28);
  cVar3 = (longlong)&stack0x00000000 < 0;
  uVar2 = &stack0x00000000 == (undefined1 *)0x0;
  puVar1 = &stack0xfffffffffffffff8;
  do {
    *(undefined1 **)(puVar1 + -8) = &SUB_140006b04;
    func_0x0001400d6f44();
    *(undefined8 *)(puVar1 + -8) = 0x140006b09;
    func_0x0001400af287();
    *(undefined8 *)(puVar1 + -8) = param_2;
    *(undefined1 **)(puVar1 + -0x10) = &SUB_140006b10;
    func_0x000140113afe();
    *(undefined8 *)(puVar1 + -0x10) = 0x140006b15;
    func_0x00014011464b();
    puVar1 = puVar1 + -8;
  } while ((bool)uVar2 || cVar4 != cVar3);
  return;
}

