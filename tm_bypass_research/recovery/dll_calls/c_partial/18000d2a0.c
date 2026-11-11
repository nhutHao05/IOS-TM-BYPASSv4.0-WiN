/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18000d2a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  
  uStackX_18 = param_3;
  uStackX_20 = param_4;
  puVar1 = (undefined8 *)func_0x00018000d290();
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vsscanf; offline
                       emulation evidence. */
  api___stdio_common_vsscanf_1809a3085(*puVar1,param_1,0xffffffffffffffff,param_2,0,&uStackX_18);
  return;
}

