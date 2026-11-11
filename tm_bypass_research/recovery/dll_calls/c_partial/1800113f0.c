/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800113f0(undefined8 *param_1,void *param_2,undefined8 *param_3)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  undefined1 auStack_68 [32];
  void *pvStack_48;
  void *pvStack_40;
  void *pvStack_38;
  void *pvStack_30;
  void *pvStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_68;
  if ((param_1 != (undefined8 *)0x0) && (param_2 != (void *)0x0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    pvVar2 = api_plist_dict_get_item_18029e669(param_2,"Command");
    pvStack_38 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
    if ((pvVar2 != (void *)0x0) &&
       (api_plist_get_string_val_1805d4d59(pvVar2,&pvStack_38), pvStack_38 != (void *)0x0)) {
      *param_3 = 0;
      native_180017ce0(*param_1,param_2,1);
      pvStack_28 = (void *)0x0;
      native_180018050(*param_1,&pvStack_28,60000);
      pvVar3 = pvStack_28;
      pvVar2 = pvStack_38;
      if (pvStack_28 == (void *)0x0) {
        pvStack_48 = pvStack_38;
        debug_info_real_Recovered
                  ("mobileactivation_send_command_plist",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobileactivation.c",0x98,
                   "ERROR: Did not get reply for %s command");
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_1802361e8(pvStack_38);
      }
      else {
        *param_3 = pvStack_28;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
        iVar1 = api_plist_get_node_type_1807c6655(pvStack_28);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
        if ((iVar1 == 5) &&
           (pvVar3 = api_plist_dict_get_item_180ab48d8(pvVar3,"Error"), pvVar3 != (void *)0x0)) {
          pvStack_30 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
          api_plist_get_string_val_1808cac2e(pvVar3,&pvStack_30);
          pvStack_40 = pvStack_30;
          pvStack_48 = pvVar2;
          debug_info_real_Recovered
                    ("mobileactivation_check_result",
                     "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobileactivation.c",0x7c,
                     "ERROR: %s: %s");
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_180b7dc60(pvStack_30);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_180214aad(pvStack_38);
        }
        else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_180335f7c(pvStack_38);
        }
      }
    }
  }
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_68);
  return;
}

