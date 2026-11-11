/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800020d0(void *param_1,char *param_2,undefined8 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined1 auStack_58 [32];
  ulonglong uStack_38;
  void *pvStack_30;
  ulonglong uStack_28;
  
  uStack_28 = _DAT_18002c008 ^ (ulonglong)auStack_58;
  if ((param_1 == (void *)0x0) || (param_3 == (undefined8 *)0x0)) {
    native_18001c0e0(uStack_28 ^ (ulonglong)auStack_58);
    return;
  }
  pvStack_30 = (void *)0x0;
  uStack_38 = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar2 = api_plist_dict_get_item_1808cbdc9(param_1,param_2);
  if (pvVar2 == (void *)0x0) {
LAB_18000216d:
    if (pvStack_30 == (void *)0x0) goto LAB_180002182;
  }
  else {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    iVar1 = api_plist_get_node_type_18031c50c(pvVar2);
    if (iVar1 != 7) goto LAB_18000216d;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_data_val; offline emulation
                       evidence. */
    api_plist_get_data_val_1806cde64(pvVar2,&pvStack_30,&uStack_38);
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    pvVar2 = api_malloc_1809d2dea(uStack_38);
    *param_3 = pvVar2;
    func_0x00018001cf67(pvVar2,pvStack_30,uStack_38);
    *(undefined4 *)(param_3 + 1) = (undefined4)uStack_38;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180b5341e(pvStack_30);
LAB_180002182:
  native_18001c0e0(uStack_28 ^ (ulonglong)auStack_58);
  return;
}

