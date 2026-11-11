/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140003e70(longlong param_1,longlong param_2)

{
  char *pcVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  void *arg0;
  void *arg0_00;
  undefined1 *puVar10;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [48];
  undefined8 uStack_80;
  ulonglong auStack_78 [4];
  undefined1 auStack_58 [6];
  ushort uStack_52;
  ulonglong uStack_28;
  
  if (param_1 == 0) {
    return;
  }
  uStack_28 = _DAT_14000b008 ^ (ulonglong)auStack_78;
  if (param_2 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
    uStack_80 = 0x140003eb5;
    iVar4 = api__stat64i32_1401d75ab(param_1,auStack_58);
    if ((iVar4 < 0) || ((uStack_52 & 0xf000) != 0x4000)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
      uStack_80 = 0x140004014;
      puVar5 = (uint *)api__errno_1400f44c7();
      uVar2 = *puVar5;
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
      uStack_80 = 0x14000401b;
      puVar6 = (undefined4 *)api__errno_140110b13();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
      uStack_80 = 0x140004023;
      uVar7 = api_strerror_14015f604(*puVar6);
      uStack_80 = 0x140004039;
      PrintMessageRecovered
                ("ERROR: Source directory does not exist \'%s\': %s (%d)\n",param_1,uVar7,
                 (ulonglong)uVar2);
    }
    else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
      uStack_80 = 0x140003ee6;
      iVar4 = api__stat64i32_1401ff062(param_2,auStack_58);
      if ((iVar4 < 0) || ((uStack_52 & 0xf000) != 0x4000)) {
        uStack_80 = 0x140003f00;
        iVar4 = native_140001cc0(param_2);
        if (iVar4 < 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
          uStack_80 = 0x140003f09;
          puVar5 = (uint *)api__errno_140118b91();
          uVar2 = *puVar5;
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
          uStack_80 = 0x140003f12;
          puVar6 = (undefined4 *)api__errno_1400b412a();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
          uStack_80 = 0x140003f19;
          uVar7 = api_strerror_1400f2be9(*puVar6);
          uStack_80 = 0x140003f2f;
          PrintMessageRecovered
                    ("ERROR: Unable to create destination directory \'%s\': %s (%d)\n",param_2,uVar7
                     ,(ulonglong)uVar2);
          goto LAB_140003ff9;
        }
      }
      uStack_80 = 0x140003f44;
      lVar8 = native_140001770(param_1);
      if (lVar8 != 0) {
        uStack_80 = 0x140003f58;
        lVar9 = native_140001840(lVar8);
        while (lVar9 != 0) {
          pcVar1 = (char *)(lVar9 + 0x1c);
          if ((*(char *)(lVar9 + 0x1c) != '.') ||
             ((*(char *)(lVar9 + 0x1d) != '\0' &&
              (((*pcVar1 != '.' || (*(char *)(lVar9 + 0x1d) != '.')) ||
               (*(char *)(lVar9 + 0x1e) != '\0')))))) {
            uStack_80 = 0x140003f8f;
            arg0 = (void *)native_1400010c0(param_1,pcVar1,0);
            uStack_80 = 0x140003fa0;
            arg0_00 = (void *)native_1400010c0(param_2,pcVar1);
            if (arg0 != (void *)0x0) {
              if (arg0_00 != (void *)0x0) {
                uStack_80 = 0x140003fb8;
                native_140003d30(arg0,arg0_00);
              }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStack_80 = 0x140003fc1;
              api_free_140203753(arg0);
            }
            if (arg0_00 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStack_80 = 0x140003fcf;
              api_free_140101c04(arg0_00);
            }
          }
          uStack_80 = 0x140003fd7;
          lVar9 = native_140001840(lVar8);
        }
        uStack_80 = 0x140003fe4;
        native_1400019b0(lVar8);
      }
    }
  }
LAB_140003ff9:
  auStack_78[0] = uStack_28 ^ (ulonglong)auStack_78;
  uStack_80 = 0x140004006;
  if ((auStack_78[0] != _DAT_14000b008) || ((short)(auStack_78[0] >> 0x30) != 0)) {
    puVar10 = auStack_b8;
    iVar4 = func_0x000140006b22(0x17);
    if (iVar4 != 0) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(2);
      puVar10 = auStack_b0;
    }
    *(undefined8 *)(puVar10 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar10 + 0x38);
    _DAT_14000b188 = puVar10 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar10 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar10 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar10 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar10 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    native_140005dc4(&UNK_1400075f0);
  }
  return;
}

