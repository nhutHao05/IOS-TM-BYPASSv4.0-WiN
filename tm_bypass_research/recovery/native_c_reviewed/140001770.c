/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * native_140001770(char *param_1)

{
  code *pcVar1;
  int iVar2;
  void *arg0;
  longlong lVar3;
  undefined1 *puVar4;
  undefined1 auStack_2a8 [8];
  undefined1 auStack_2a0 [48];
  undefined8 uStack_270;
  ulonglong auStack_268 [4];
  undefined8 uStack_248;
  undefined1 auStack_238 [16];
  undefined1 auStack_228 [528];
  ulonglong uStack_18;
  
  uStack_18 = _DAT_14000b008 ^ (ulonglong)auStack_268;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
    uStack_270 = 0x140001818;
    api__set_errno_14005833c(2);
    arg0 = (void *)0x0;
  }
  else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    uStack_270 = 0x1400017ab;
    arg0 = api_malloc_1401cbaf5(0x130);
    if (arg0 != (void *)0x0) {
      uStack_248 = 0x105;
                    /* Recovered VMProtect thunk: ucrtbase.dll!mbstowcs_s; offline emulation
                       evidence. */
      uStack_270 = 0x1400017d5;
      iVar2 = api_mbstowcs_s_140207b31(auStack_238,auStack_228,0x105,param_1);
      if (iVar2 == 0) {
        uStack_270 = 0x1400017e3;
        lVar3 = native_1400015c0(auStack_228);
        *(longlong *)((longlong)arg0 + 0x128) = lVar3;
        if (lVar3 != 0) goto LAB_14000181b;
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStack_270 = 0x1400017ff;
      api_free_1400ac523(arg0);
      arg0 = (void *)0x0;
    }
  }
LAB_14000181b:
  auStack_268[0] = uStack_18 ^ (ulonglong)auStack_268;
  uStack_270 = 0x14000182b;
  if ((auStack_268[0] != _DAT_14000b008) || ((short)(auStack_268[0] >> 0x30) != 0)) {
    puVar4 = auStack_2a8;
    iVar2 = func_0x000140006b22(0x17);
    if (iVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(2);
      puVar4 = auStack_2a0;
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
    arg0 = (void *)native_140005dc4(&UNK_1400075f0);
  }
  return arg0;
}

