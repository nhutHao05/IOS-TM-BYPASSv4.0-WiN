/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180017900(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      return 0xfffffff6;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    puVar1 = (undefined8 *)api_malloc_1808cbb2d(0x18);
    uVar3 = 0xffffff00;
    if (puVar1 != (undefined8 *)0x0) {
      puVar1[2] = param_3;
      *puVar1 = param_1;
      puVar1[1] = param_2;
                    /* Recovered VMProtect thunk: kernel32.dll!CreateThread; offline emulation
                       evidence. */
      lVar2 = api_CreateThread_18085bfb5(0,0,native_180017830,puVar1,0,0);
      if (lVar2 != 0) {
        param_1[1] = lVar2;
        uVar3 = 0;
      }
    }
    return uVar3;
  }
  return 0xffffffff;
}

