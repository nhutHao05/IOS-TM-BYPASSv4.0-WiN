/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140001e10(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [48];
  undefined8 uStack_a0;
  ulonglong auStack_98 [4];
  undefined1 auStack_78 [6];
  ushort uStack_72;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_14000b008 ^ (ulonglong)auStack_98;
  uStack_a0 = 0x140001e37;
  lVar3 = native_140001770();
  if (lVar3 != 0) {
    uStack_a0 = 0x140001e5a;
    lVar4 = native_140001840(lVar3);
    while (lVar4 != 0) {
      if ((*(char *)(lVar4 + 0x1c) != '.') ||
         ((*(char *)(lVar4 + 0x1d) != '\0' &&
          (((*(char *)(lVar4 + 0x1c) != '.' || (*(char *)(lVar4 + 0x1d) != '.')) ||
           (*(char *)(lVar4 + 0x1e) != '\0')))))) {
        uStack_a0 = 0x140001ea0;
        lVar4 = native_1400010c0(param_1,(char *)(lVar4 + 0x1c),0);
        if (lVar4 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
          uStack_a0 = 0x140001eb6;
          iVar2 = api__stat64i32_140155782(lVar4,auStack_78);
          if (iVar2 != 0) goto LAB_140001f34;
          if ((uStack_72 & 0xf000) == 0x4000) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
            uStack_a0 = 0x140001ed2;
            plVar5 = (longlong *)api_malloc_14020a73f(0x10);
            if (plVar5 == (longlong *)0x0) goto LAB_140001f34;
            *plVar5 = lVar4;
            plVar5[1] = *param_3;
            *param_3 = (longlong)plVar5;
            uStack_a0 = 0x140001ef2;
            native_140001e10(lVar4,param_2);
          }
          else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
            uStack_a0 = 0x140001efa;
            plVar5 = (longlong *)api_malloc_1401c2abf(0x10);
            if (plVar5 == (longlong *)0x0) goto LAB_140001f34;
            *plVar5 = lVar4;
            plVar5[1] = *param_2;
            *param_2 = (longlong)plVar5;
          }
        }
      }
      uStack_a0 = 0x140001f14;
      lVar4 = native_140001840(lVar3);
    }
    uStack_a0 = 0x140001f25;
    native_1400019b0(lVar3);
  }
LAB_140001f34:
  auStack_98[0] = uStack_48 ^ (ulonglong)auStack_98;
  uStack_a0 = 0x140001f41;
  if ((auStack_98[0] != _DAT_14000b008) || ((short)(auStack_98[0] >> 0x30) != 0)) {
    puVar6 = auStack_d8;
    iVar2 = func_0x000140006b22(0x17);
    if (iVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(2);
      puVar6 = auStack_d0;
    }
    *(undefined8 *)(puVar6 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar6 + 0x38);
    _DAT_14000b188 = puVar6 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar6 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar6 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar6 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar6 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    native_140005dc4(&UNK_1400075f0);
  }
  return;
}

