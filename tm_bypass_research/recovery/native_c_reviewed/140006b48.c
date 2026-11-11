/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140006b48(ulonglong param_1,longlong param_2,uint *param_3)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  uVar5 = param_1;
  if ((*param_3 & 4) != 0) {
    uVar5 = (longlong)(int)param_3[1] + param_1 & (longlong)(int)-param_3[2];
  }
  uVar3 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8);
  if ((*(byte *)(uVar3 + 3 + *(longlong *)(param_2 + 8)) & 0xf) != 0) {
    param_1 = param_1 + (*(byte *)(uVar3 + 3 + *(longlong *)(param_2 + 8)) & 0xfffffff0);
  }
  param_1 = param_1 ^ *(ulonglong *)((longlong)(int)(*param_3 & 0xfffffff8) + uVar5);
  if ((param_1 == _DAT_14000b008) && ((short)(param_1 >> 0x30) == 0)) {
    return;
  }
  puVar4 = auStack_38;
  iVar2 = func_0x000140006b22(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar4 = auStack_30;
  }
  *(undefined8 *)(puVar4 + -8) = 0x140005e22;
  native_140005fec(0x14000b0f0);
  _DAT_14000b060 = *(undefined8 *)(puVar4 + 0x38);
  _DAT_14000b188 = puVar4 + 0x40;
  _DAT_14000b170 = *(undefined8 *)(puVar4 + 0x40);
  _DAT_14000b050 = 0xc0000409;
  _DAT_14000b054 = 1;
  _DAT_14000b068 = 1;
  uRam000000014000b070 = 2;
  *(ulonglong *)(puVar4 + 0x20) = _DAT_14000b008;
  *(undefined8 *)(puVar4 + 0x28) = _DAT_14000b000;
  *(undefined8 *)(puVar4 + -8) = 0x140005ec4;
  _DAT_14000b1e8 = _DAT_14000b060;
  native_140005dc4(&UNK_1400075f0);
  return;
}

