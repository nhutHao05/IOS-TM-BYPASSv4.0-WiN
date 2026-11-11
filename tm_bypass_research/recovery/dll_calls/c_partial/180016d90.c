/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180016d90(longlong *param_1,longlong *param_2)

{
  char *pcVar1;
  int iVar2;
  void *pvVar3;
  undefined1 auStack_78 [32];
  char *pcStack_58;
  longlong lStack_50;
  void *pvStack_48;
  char *pcStack_40;
  longlong lStack_38;
  ulonglong uStack_30;
  
  uStack_30 = _DAT_18002c008 ^ (ulonglong)auStack_78;
  pvStack_48 = (void *)0x0;
  if (((param_1 != (longlong *)0x0) && (*param_1 != 0)) && (*param_2 == 0)) {
    debug_info_real_Recovered
              ("np_lock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x34,
               "Locked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlEnterCriticalSection; offline
                       emulation evidence. */
    api_RtlEnterCriticalSection_1808dc313(param_1 + 1);
    iVar2 = native_180018050(*param_1,&pvStack_48,500);
    if (iVar2 == -5) {
      debug_info_real_Recovered
                ("np_get_notification",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x10f,
                 "NotificationProxy: no notification received!");
    }
    else if (iVar2 != 0) {
      pcStack_58 = (char *)CONCAT44(pcStack_58._4_4_,iVar2);
      debug_info_real_Recovered
                ("np_get_notification",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x112,
                 "NotificationProxy: error %d occurred!");
    }
    if (pvStack_48 != (void *)0x0) {
      pcStack_40 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar3 = api_plist_dict_get_item_180321331(pvStack_48,"Command");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
      iVar2 = api_plist_get_node_type_180a73aed(pvVar3);
      if (iVar2 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
        api_plist_get_string_val_18091d85e(pvVar3,&pcStack_40);
      }
      pcVar1 = pcStack_40;
      if (pcStack_40 != (char *)0x0) {
        iVar2 = func_0x00018001cf6d(pcStack_40,"RelayNotification");
        if (iVar2 == 0) {
          lStack_38 = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
          pvVar3 = api_plist_dict_get_item_180883ac1(pvStack_48,"Name");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
          iVar2 = api_plist_get_node_type_1807f64e5(pvVar3);
          if (iVar2 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
            api_plist_get_string_val_1807ec051(pvVar3,&lStack_38);
          }
          if ((pvVar3 != (void *)0x0) && (lStack_38 != 0)) {
            lStack_50 = lStack_38;
            pcStack_58 = "np_get_notification";
            *param_2 = lStack_38;
            debug_info_real_Recovered
                      ("np_get_notification",
                       "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x128,
                       "got notification %s");
          }
        }
        else {
          iVar2 = func_0x00018001cf6d(pcVar1,"ProxyDeath");
          if (iVar2 == 0) {
            debug_info_real_Recovered
                      ("np_get_notification",
                       "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",300,
                       "NotificationProxy died!");
          }
          else {
            pcStack_58 = pcVar1;
            debug_info_real_Recovered
                      ("np_get_notification",
                       "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x12f,
                       "unknown NotificationProxy command \'%s\' received!");
          }
        }
        if (pcStack_40 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_180535dcd(pcStack_40);
        }
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_1805fa752(pvStack_48);
      pvStack_48 = (void *)0x0;
    }
    debug_info_real_Recovered
              ("np_unlock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0x3f
               ,"Unlocked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLeaveCriticalSection; offline
                       emulation evidence. */
    api_RtlLeaveCriticalSection_1803ae7b7(param_1 + 1);
  }
  native_18001c0e0(uStack_30 ^ (ulonglong)auStack_78);
  return;
}

