/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800010c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulonglong *puVar2;
  void *pvVar3;
  ulonglong arg0;
  undefined1 auStack_78 [32];
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined1 auStack_48 [16];
  ulonglong uStack_38;
  
  uStack_38 = _DAT_18002c008 ^ (ulonglong)auStack_78;
  puVar2 = (ulonglong *)func_0x000180001000();
  uStack_58 = 0;
  uStack_50 = param_3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsprintf; offline
                       emulation evidence. */
  iVar1 = api___stdio_common_vsprintf_18029b666(*puVar2 | 2,auStack_48,0x10,param_2);
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
    pvVar3 = api_malloc_1809bba56(arg0);
    *param_1 = pvVar3;
    uStack_58 = 0;
    uStack_50 = param_3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsprintf; offline
                       emulation evidence. */
    api___stdio_common_vsprintf_1809ad07f(*puVar2 | 2,pvVar3,(longlong)(iVar1 + 1),param_2);
  }
  native_18001c0e0(uStack_38 ^ (ulonglong)auStack_78);
  return;
}

