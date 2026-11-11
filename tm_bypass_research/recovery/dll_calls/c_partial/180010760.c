/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180010760(void *param_1,undefined4 *param_2)

{
  int iVar1;
  void *arg0;
  undefined1 auStack_38 [32];
  longlong lStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_38;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  iVar1 = api_plist_get_node_type_1809bdb88(param_1);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if (((iVar1 == 5) &&
      (arg0 = api_plist_dict_get_item_18089fec3(param_1,"Status"), arg0 != (void *)0x0)) &&
     (iVar1 = api_plist_get_node_type_1803a6bc7(arg0), iVar1 == 1)) {
    lStack_18 = -1;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
    api_plist_get_uint_val_1803e6fb6(arg0,&lStack_18);
    if (lStack_18 != -1) {
      *param_2 = (int)lStack_18;
    }
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

