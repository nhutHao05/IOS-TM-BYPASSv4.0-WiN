/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180007750(void *param_1)

{
  int iVar1;
  void *pvVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_48 [32];
  void *pvStack_28;
  void *pvStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_48;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar2 = api_plist_dict_get_item_180795cab(param_1,"Status");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if ((pvVar2 == (void *)0x0) || (iVar1 = api_plist_get_node_type_180bc8b42(pvVar2), iVar1 != 3))
  goto LAB_18000785d;
  lVar4 = 0;
  pvStack_18 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
  api_plist_get_string_val_180777499(pvVar2,&pvStack_18);
  pvVar2 = pvStack_18;
  lVar5 = lVar4;
  if (pvStack_18 == (void *)0x0) goto LAB_18000785d;
  do {
    lVar3 = lVar5 + 1;
    if (*(char *)((longlong)pvStack_18 + lVar5) != "Success"[lVar5]) goto LAB_1800077f0;
    lVar5 = lVar3;
  } while (lVar3 != 8);
  goto LAB_18000784a;
  while (lVar4 = lVar5, lVar5 != 8) {
LAB_1800077f0:
    lVar5 = lVar4 + 1;
    if (*(char *)((longlong)pvStack_18 + lVar4) != "Failure"[lVar4]) {
      iVar1 = func_0x00018001cf6d(pvStack_18,"UnknownRequest");
      if (iVar1 != 0) {
        pvStack_28 = pvVar2;
        debug_info_real_Recovered
                  ("diagnostics_relay_check_result",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\diagnostics_relay.c",0x43,
                   "ERROR: unknown result value \'%s\'");
        pvVar2 = pvStack_18;
      }
      break;
    }
  }
LAB_18000784a:
  if (pvVar2 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_180a1d70d(pvVar2);
  }
LAB_18000785d:
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_48);
  return;
}

