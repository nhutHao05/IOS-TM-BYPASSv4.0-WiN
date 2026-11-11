/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_14000663c(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 auStack_4d8 [1232];
  
  puVar3 = auStack_5c8;
  iVar2 = func_0x000140006b22(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_5c0;
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000666f;
  func_0x000140006634(3);
  *(undefined8 *)(puVar3 + -8) = 0x140006680;
  func_0x000140006a92(auStack_4d8,0,0x4d0);
  *(undefined8 *)(puVar3 + -8) = 0x140006689;
  func_0x0001401dec20(auStack_4d8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

