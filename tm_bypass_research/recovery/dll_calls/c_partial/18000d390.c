/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000d390(void *param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_58 [32];
  char *pcStack_38;
  char *pcStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_58;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar4 = api_plist_dict_get_item_1801fb136(param_1,"Request");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if ((pvVar4 == (void *)0x0) || (iVar3 = api_plist_get_node_type_1805c94f3(pvVar4), iVar3 != 3))
  goto LAB_18000d5af;
  lVar7 = 0;
  pcStack_28 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
  api_plist_get_string_val_1800b07de(pvVar4,&pcStack_28);
  if (pcStack_28 == (char *)0x0) goto LAB_18000d5af;
  if (param_2 == 0) {
LAB_18000d433:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_18081cb19(pcStack_28);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    pvVar4 = api_plist_dict_get_item_180a8f0a3(param_1,"Result");
    if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
      iVar3 = api_plist_get_node_type_180976fac(pvVar4);
      if (iVar3 != 3) goto LAB_18000d5af;
      pcStack_28 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
      api_plist_get_string_val_180153e06(pvVar4,&pcStack_28);
      lVar8 = lVar7;
      if (pcStack_28 == (char *)0x0) goto LAB_18000d5af;
      do {
        lVar6 = lVar8 + 1;
        if (pcStack_28[lVar8] != "Success"[lVar8]) goto LAB_18000d560;
        lVar8 = lVar6;
      } while (lVar6 != 8);
      goto LAB_18000d59f;
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    pvVar4 = api_plist_dict_get_item_18054c4d6(param_1,"Error");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    if ((pvVar4 == (void *)0x0) || (iVar3 = api_plist_get_node_type_180994828(pvVar4), iVar3 != 3))
    goto LAB_18000d5af;
    pcStack_28 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
    api_plist_get_string_val_180632955(pvVar4,&pcStack_28);
    if (pcStack_28 == (char *)0x0) {
      debug_info_real_Recovered
                ("lockdown_check_result","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                 0xc4,"ERROR: unknown error occurred");
      goto LAB_18000d5af;
    }
    pcStack_38 = pcStack_28;
    debug_info_real_Recovered
              ("lockdown_check_result","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
               0xc0,"ERROR: %s");
    native_18000d300(pcStack_28);
  }
  else {
    pcVar5 = pcStack_28;
    do {
      cVar1 = *pcVar5;
      cVar2 = pcVar5[param_2 - (longlong)pcStack_28];
      if (cVar1 != cVar2) break;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    if (cVar1 == cVar2) goto LAB_18000d433;
  }
  goto LAB_18000d5a7;
  while (lVar7 = lVar8, lVar8 != 8) {
LAB_18000d560:
    lVar8 = lVar7 + 1;
    if (pcStack_28[lVar7] != "Failure"[lVar7]) {
      pcStack_38 = pcStack_28;
      debug_info_real_Recovered
                ("lockdown_check_result","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                 0xda,"ERROR: unknown result value \'%s\'");
      break;
    }
  }
LAB_18000d59f:
  if (pcStack_28 == (char *)0x0) goto LAB_18000d5af;
LAB_18000d5a7:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180397898(pcStack_28);
LAB_18000d5af:
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_58);
  return;
}

