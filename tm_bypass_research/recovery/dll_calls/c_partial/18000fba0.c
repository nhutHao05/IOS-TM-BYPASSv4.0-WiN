/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000fba0(longlong param_1,char *param_2,int param_3,undefined8 *param_4)

{
  char *arg0;
  int iVar1;
  void *arg0_00;
  void *pvVar2;
  undefined1 auStack_78 [32];
  char *pcStack_58;
  void *pvStack_48;
  longlong *plStack_40;
  int aiStack_38 [2];
  ulonglong uStack_30;
  
  uStack_30 = _DAT_18002c008 ^ (ulonglong)auStack_78;
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  arg0_00 = api_plist_new_dict_180c35944();
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if (((arg0_00 != (void *)0x0) && (arg0 = *(char **)(param_1 + 0x20), arg0 != (char *)0x0)) &&
     (iVar1 = api_plist_get_node_type_180768361(arg0_00), iVar1 == 5)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar2 = api_plist_new_string_18073396d(arg0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1800a1e59(arg0_00,"Label",pvVar2);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar2 = api_plist_new_string_180c35960("StartService");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_1802ad114(arg0_00,"Request",pvVar2);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar2 = api_plist_new_string_180a3573d(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_1804d7ddc(arg0_00,"Service",pvVar2);
  if (param_3 != 0) {
    pvStack_48 = (void *)0x0;
    plStack_40 = (longlong *)0x0;
    aiStack_38[0] = 0;
                    /* Recovered VMProtect thunk: usbmuxd.dll!usbmuxd_read_pair_record; offline
                       emulation evidence. */
    iVar1 = api_usbmuxd_read_pair_record_1808fb9cd
                      (*(undefined8 *)(param_1 + 0x18),&plStack_40,aiStack_38);
    if (iVar1 < 0) {
      if (plStack_40 != (longlong *)0x0) goto code_r0x00018000fcbc;
    }
    else {
      if (*plStack_40 == 0x30307473696c7062) {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_bin; offline emulation
                       evidence. */
        api_plist_from_bin_180a9e85e((char *)plStack_40,aiStack_38[0],&pvStack_48);
      }
      else {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_xml; offline emulation
                       evidence. */
        api_plist_from_xml_18025743b((char *)plStack_40,aiStack_38[0],&pvStack_48);
      }
code_r0x00018000fcbc:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1804d2e74(plStack_40);
    }
    if (pvStack_48 == (void *)0x0) {
      pcStack_58 = *(char **)(param_1 + 0x18);
      debug_info_real_Recovered
                ("lockdownd_build_start_service_request",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",0x4ce,
                 "ERROR: failed to read pair record for device: %s");
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_180989775(arg0_00);
      goto LAB_18000fd78;
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    pvVar2 = api_plist_dict_get_item_180a81eca(pvStack_48,"EscrowBag");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    if ((pvVar2 == (void *)0x0) || (iVar1 = api_plist_get_node_type_18036bb4f(pvVar2), iVar1 != 7))
    {
      debug_info_real_Recovered
                ("lockdownd_build_start_service_request",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",0x4d6,
                 "ERROR: Failed to retrieve the escrow bag from the device\'s record");
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_18049799a(arg0_00);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_18057ca6f(pvStack_48);
      goto LAB_18000fd78;
    }
    pcStack_58 = param_2;
    debug_info_real_Recovered
              ("lockdownd_build_start_service_request",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",0x4dc,
               "Adding escrow bag to StartService for %s");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    pvVar2 = (void *)api_plist_copy_1803fba1d(pvVar2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180c43925(arg0_00,"EscrowBag",pvVar2);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180589f73(pvStack_48);
  }
  *param_4 = arg0_00;
LAB_18000fd78:
  native_18001c0e0(uStack_30 ^ (ulonglong)auStack_78);
  return;
}

