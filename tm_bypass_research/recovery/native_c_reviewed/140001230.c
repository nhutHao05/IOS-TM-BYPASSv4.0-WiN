/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FormatByteCountRecovered(ulonglong param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [48];
  undefined8 uStack_90;
  ulonglong auStack_88 [4];
  undefined1 auStack_68 [80];
  ulonglong uStack_18;
  
  uStack_18 = _DAT_14000b008 ^ (ulonglong)auStack_88;
  if (param_1 < 1000000000000) {
    if (param_1 < 1000000000) {
      if (param_1 < 1000000) {
        if (param_1 < 1000) {
          uStack_90 = 0x14000139a;
          native_140001060(auStack_68,"%d Bytes",param_1 & 0xffffffff);
        }
        else {
          uStack_90 = 0x140001384;
          native_140001060(auStack_68,"%0.1f KB",(double)param_1 / _DAT_140008cb0);
        }
      }
      else {
        uStack_90 = 0x140001337;
        native_140001060(auStack_68,"%0.1f MB",(double)param_1 / _DAT_140008cb8);
      }
    }
    else {
      uStack_90 = 0x1400012e7;
      native_140001060(auStack_68,"%0.1f GB",(double)param_1 / _DAT_140008cc0);
    }
  }
  else {
    uStack_90 = 0x140001297;
    native_140001060(auStack_68,"%0.1f TB",(double)param_1 / _DAT_140008cc8);
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
  uStack_90 = 0x1400013a4;
  api__mbsdup_1401cf943(auStack_68);
  auStack_88[0] = uStack_18 ^ (ulonglong)auStack_88;
  uStack_90 = 0x1400013b2;
  if ((auStack_88[0] != _DAT_14000b008) || ((short)(auStack_88[0] >> 0x30) != 0)) {
    puVar3 = auStack_c8;
    iVar2 = func_0x000140006b22(0x17);
    if (iVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(2);
      puVar3 = auStack_c0;
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
  }
  return;
}

