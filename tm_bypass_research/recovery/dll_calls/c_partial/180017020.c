/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180017020(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  void *arg0;
  int iVar3;
  void *pvStackX_8;
  
  pvStackX_8 = (void *)0x0;
  if (param_1 != (undefined8 *)0x0) {
    debug_info_real_Recovered
              ("np_notifier","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",
               0x14a,"starting callback.");
    plVar1 = (longlong *)*param_1;
    lVar2 = *plVar1;
    while (lVar2 != 0) {
      iVar3 = native_180016d90(plVar1,&pvStackX_8);
      arg0 = pvStackX_8;
      if (iVar3 < 0) {
        (*(code *)param_1[1])(&UNK_18001e9b1,param_1[2]);
        break;
      }
      if (pvStackX_8 != (void *)0x0) {
        (*(code *)param_1[1])(pvStackX_8,param_1[2]);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_180321c6c(arg0);
        pvStackX_8 = (void *)0x0;
      }
                    /* Recovered VMProtect thunk: kernel32.dll!Sleep; offline emulation evidence. */
      api_Sleep_1804c5d80(1000);
      plVar1 = (longlong *)*param_1;
      lVar2 = *plVar1;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_180b2f26e(param_1);
  }
  return 0;
}

