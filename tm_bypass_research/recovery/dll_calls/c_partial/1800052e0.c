/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800052e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  void *pvVar3;
  ulonglong arg0;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  undefined8 *puStack_60;
  undefined1 auStack_58 [16];
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18002c008 ^ (ulonglong)auStack_88;
  uStackX_18 = param_3;
  uStackX_20 = param_4;
  puVar2 = (ulonglong *)func_0x000180001000();
  uStack_68 = 0;
  puStack_60 = &uStackX_18;
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsprintf; offline
                       emulation evidence. */
  iVar1 = api___stdio_common_vsprintf_180b3e374(*puVar2 | 2,auStack_58,0x10,param_2);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  if (0 < iVar1) {
    arg0 = (ulonglong)(iVar1 + 1);
    if (iVar1 == -1) {
      arg0 = 0xffffffffffffffff;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    pvVar3 = api_malloc_180561478(arg0);
    *param_1 = pvVar3;
    uStack_68 = 0;
    puStack_60 = &uStackX_18;
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsprintf; offline
                       emulation evidence. */
    api___stdio_common_vsprintf_1806c234f(*puVar2 | 2,pvVar3,(longlong)(iVar1 + 1),param_2);
  }
  native_18001c0e0(uStack_48 ^ (ulonglong)auStack_88);
  return;
}

