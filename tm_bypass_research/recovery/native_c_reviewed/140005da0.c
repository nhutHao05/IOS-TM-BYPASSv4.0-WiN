/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: This is an inlined function */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CheckSecurityCookieRecovered(ulonglong cookie)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  if ((cookie == _DAT_14000b008) && ((short)(cookie >> 0x30) == 0)) {
    return;
  }
  puVar3 = auStack_38;
  iVar2 = func_0x000140006b22(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x140005e22;
  native_140005fec(0x14000b0f0);
  _DAT_14000b060 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_14000b188 = puVar3 + 0x40;
  _DAT_14000b170 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_14000b050 = 0xc0000409;
  _DAT_14000b054 = 1;
  _DAT_14000b068 = 1;
  uRam000000014000b070 = 2;
  *(ulonglong *)(puVar3 + 0x20) = _DAT_14000b008;
  *(undefined8 *)(puVar3 + 0x28) = _DAT_14000b000;
  *(undefined8 *)(puVar3 + -8) = 0x140005ec4;
  _DAT_14000b1e8 = _DAT_14000b060;
  native_140005dc4(&UNK_1400075f0);
  return;
}

