/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140005ee0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  iVar2 = func_0x000140006b22(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x140005f0a;
  native_140005f7c(0x14000b0f0);
  _DAT_14000b060 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_14000b188 = puVar3 + 0x30;
  _DAT_14000b050 = 0xc0000409;
  _DAT_14000b054 = 1;
  _DAT_14000b068 = 1;
  uRam000000014000b070 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x140005f76;
  _DAT_14000b1e8 = _DAT_14000b060;
  native_140005dc4(&UNK_1400075f0);
  return;
}

