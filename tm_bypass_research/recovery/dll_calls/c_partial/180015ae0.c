/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180015ae0(void *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  undefined1 auStack_58 [32];
  char *pcStack_38;
  char *pcStack_30;
  char *pcStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_58;
  pcStack_28 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar4 = api_plist_dict_get_item_180345345(param_1,"Error");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if ((pvVar4 != (void *)0x0) && (iVar3 = api_plist_get_node_type_1809e3e73(pvVar4), iVar3 == 3)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
    api_plist_get_string_val_180a42332(pvVar4,&pcStack_28);
  }
  pcVar5 = pcStack_28;
  if (pcStack_28 == (char *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    pvVar4 = api_plist_dict_get_item_1806a52da(param_1,"Status");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    if ((pvVar4 != (void *)0x0) && (iVar3 = api_plist_get_node_type_18037e0db(pvVar4), iVar3 == 3))
    {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
      api_plist_get_string_val_180157a90(pvVar4,&pcStack_28);
    }
    if (pcStack_28 == (char *)0x0) {
      debug_info_real_Recovered
                ("process_result",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobile_image_mounter.c",0xac,
                 "Error: Unexpected response received!");
    }
    else {
      pcVar5 = pcStack_28;
      do {
        cVar1 = *pcVar5;
        cVar2 = pcVar5[(longlong)param_2 - (longlong)pcStack_28];
        if (cVar1 != cVar2) break;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      if (cVar1 != cVar2) {
        pcStack_30 = pcStack_28;
        pcStack_38 = param_2;
        debug_info_real_Recovered
                  ("process_result",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobile_image_mounter.c",0xb0,
                   "Error: didn\'t get %s but %s");
      }
    }
  }
  else {
    iVar3 = func_0x00018001cf6d(pcStack_28,"DeviceLocked");
    if (iVar3 == 0) {
      debug_info_real_Recovered
                ("process_result",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobile_image_mounter.c",0x9e,
                 "Device is locked, can\'t mount");
    }
    else {
      pcStack_38 = pcVar5;
      debug_info_real_Recovered
                ("process_result",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobile_image_mounter.c",0xa1,
                 "Unhandled error \'%s\' received");
    }
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_18060c31f(pcStack_28);
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_58);
  return;
}

