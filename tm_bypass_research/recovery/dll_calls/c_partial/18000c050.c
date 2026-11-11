/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000c050(undefined8 param_1,void *param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *arg0;
  void *pvVar4;
  undefined1 auStack_58 [32];
  void *pvStack_38;
  void *pvStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_58;
  pvVar4 = (void *)0x0;
  pvStack_28 = (void *)0x0;
  arg0 = pvVar4;
  if (param_2 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    iVar1 = api_plist_get_node_type_1802f76e1(param_2);
    arg0 = (void *)0x0;
    if (iVar1 == 5) {
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar3 = api_plist_dict_get_item_180c410ad(param_2,"CurrentList");
      arg0 = pvVar4;
      if (pvVar3 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
        uVar2 = api_plist_array_get_size_1804ea489(pvVar3);
        pvStack_28 = (void *)(ulonglong)uVar2;
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
        arg0 = (void *)api_plist_copy_1801a7309(pvVar3);
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar3 = api_plist_dict_get_item_18083caee(param_2,"CurrentAmount");
      if (pvVar3 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
        api_plist_get_uint_val_1803ba45a(pvVar3,&pvStack_28);
      }
    }
  }
  pvStack_38 = pvStack_28;
  debug_info_real_Recovered
            ("instproxy_append_current_list_to_result_cb",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x231,
             "current_amount: %d");
  if (pvStack_28 == (void *)0x0) {
    if (arg0 == (void *)0x0) goto LAB_18000c16d;
  }
  else {
    if (arg0 == (void *)0x0) goto LAB_18000c16d;
    for (; pvVar4 < pvStack_28; pvVar4 = (void *)((longlong)pvVar4 + 1)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
      pvVar3 = api_plist_array_get_item_180acaff1(arg0,(int)pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
      pvVar3 = (void *)api_plist_copy_1804a8efa(pvVar3);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
      api_plist_array_append_item_1801ef70c((void *)*param_3,pvVar3);
    }
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_180923f02(arg0);
LAB_18000c16d:
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_58);
  return;
}

