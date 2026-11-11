/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c0e0(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  if ((param_1 == _DAT_18002c008) && ((short)((ulonglong)param_1 >> 0x30) == 0)) {
    return;
  }
  puVar3 = auStack_38;
  iVar2 = api_IsProcessorFeaturePresent_1800d1c34(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(2);
    puVar3 = auStack_30;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18001c163;
  native_18001c32c(0x18002c3e0);
  _DAT_18002c350 = *(undefined8 *)(puVar3 + 0x38);
  _DAT_18002c478 = puVar3 + 0x40;
  _DAT_18002c460 = *(undefined8 *)(puVar3 + 0x40);
  _DAT_18002c340 = 0xc0000409;
  _DAT_18002c344 = 1;
  _DAT_18002c358 = 1;
  uRam000000018002c360 = 2;
  *(longlong *)(puVar3 + 0x20) = _DAT_18002c008;
  *(undefined8 *)(puVar3 + 0x28) = _DAT_18002c000;
  *(undefined8 *)(puVar3 + -8) = 0x18001c205;
  _DAT_18002c4d8 = _DAT_18002c350;
  native_18001c104(&UNK_18001e5e0);
  return;
}

