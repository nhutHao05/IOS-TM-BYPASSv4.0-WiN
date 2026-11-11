/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180016b10(undefined8 *param_1,char *param_2)

{
  int iVar1;
  void *arg0;
  void *pvVar2;
  undefined8 uVar3;
  
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  arg0 = api_plist_new_dict_1803aa0c6();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar2 = api_plist_new_string_18072dfec("ObserveNotification");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_18031ffde(arg0,"Command",pvVar2);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar2 = api_plist_new_string_18012f9f5(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_180c1170c(arg0,"Name",pvVar2);
  iVar1 = native_180017ce0(*param_1,arg0,0);
  if (iVar1 == -3) {
    uVar3 = 0xfffffffd;
  }
  else if (iVar1 == -2) {
    uVar3 = 0xfffffffe;
  }
  else if (iVar1 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    if (iVar1 == 0) {
      uVar3 = 0;
      goto LAB_180016bc9;
    }
    uVar3 = 0xffffff00;
  }
  debug_info_real_Recovered
            ("internal_np_observe_notification",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\notification_proxy.c",0xc9,
             "Error sending XML plist to device!");
LAB_180016bc9:
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_180c3fbdc(arg0);
  return uVar3;
}

