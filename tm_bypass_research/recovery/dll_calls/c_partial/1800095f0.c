/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800095f0(undefined4 *param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_58 [32];
  int iStack_38;
  undefined4 auStack_28 [2];
  undefined4 *puStack_20;
  int iStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_58;
  auStack_28[0] = *param_1;
  puStack_20 = param_1 + 3;
  iVar1 = param_1[0xe];
  iStack_18 = 0;
  if ((iVar1 != 1) && (iVar1 != 2)) {
    iStack_38 = iVar1;
    debug_info_real_Recovered
              ("usbmux_event_cb","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\idevice.c",0xcc,
               "Unknown connection type %d");
    iVar1 = iStack_18;
  }
  iStack_18 = iVar1;
  if (_DAT_18002c948 != (code *)0x0) {
    (*_DAT_18002c948)(auStack_28,param_2);
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_58);
  return;
}

