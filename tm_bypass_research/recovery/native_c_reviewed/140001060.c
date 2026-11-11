/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

int native_140001060(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  
  uStackX_18 = param_3;
  uStackX_20 = param_4;
  puVar2 = (ulonglong *)native_140001000();
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsprintf; offline
                       emulation evidence. */
  iVar1 = api___stdio_common_vsprintf_140183063
                    (*puVar2 | 1,param_1,0xffffffffffffffff,param_2,0,&uStackX_18);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

