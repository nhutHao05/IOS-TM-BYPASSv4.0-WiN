/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c220(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
                    /* Recovered VMProtect thunk: kernel32.dll!IsProcessorFeaturePresent; offline
                       emulation evidence. */
  iVar2 = api_IsProcessorFeaturePresent_18099ef88(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar3 = auStack_20;
  }
  *(undefined8 *)(puVar3 + -8) = 0x18001c24b;
  native_18001c2bc(0x18002c3e0);
  _DAT_18002c350 = *(undefined8 *)(puVar3 + 0x28);
  _DAT_18002c478 = puVar3 + 0x30;
  _DAT_18002c340 = 0xc0000409;
  _DAT_18002c344 = 1;
  _DAT_18002c358 = 1;
  uRam000000018002c360 = (ulonglong)*(uint *)(puVar3 + 0x30);
  *(undefined8 *)(puVar3 + -8) = 0x18001c2b7;
  _DAT_18002c4d8 = _DAT_18002c350;
  native_18001c104(&UNK_18001e5e0);
  return;
}

