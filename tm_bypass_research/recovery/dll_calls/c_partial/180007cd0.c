/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180007cd0(undefined8 *param_1,char *param_2,uint param_3)

{
  void *pvVar1;
  undefined1 auStack_38 [32];
  void *pvStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_38;
  if (param_1 != (undefined8 *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    pvStack_18 = api_plist_new_dict_180814733();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar1 = api_plist_new_string_180b24678(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180b0095c(pvStack_18,"Request",pvVar1);
    if ((param_3 & 2) != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      pvVar1 = api_plist_new_bool_18087628d('\x01');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      api_plist_dict_set_item_180bb7776(pvStack_18,"WaitForDisconnect",pvVar1);
    }
    if ((param_3 & 4) != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      pvVar1 = api_plist_new_bool_1804b2e27('\x01');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      api_plist_dict_set_item_180159119(pvStack_18,"DisplayPass",pvVar1);
    }
    if ((param_3 & 8) != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      pvVar1 = api_plist_new_bool_180493913('\x01');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      api_plist_dict_set_item_18038fde4(pvStack_18,"DisplayFail",pvVar1);
    }
    if (pvStack_18 != (void *)0x0) {
      native_180017ce0(*param_1,pvStack_18,0);
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180719658(pvStack_18);
    pvStack_18 = (void *)0x0;
    native_180018050(*param_1,&pvStack_18,60000);
    if (pvStack_18 != (void *)0x0) {
      native_180007750();
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_1800aa133(pvStack_18);
    }
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

