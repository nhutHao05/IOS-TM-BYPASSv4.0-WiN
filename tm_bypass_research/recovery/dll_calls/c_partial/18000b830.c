/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000b830(longlong *param_1,void *param_2,code *param_3,undefined8 param_4)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  void *pvVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined1 auStack_e8 [32];
  void *pvStack_c8;
  undefined *puStack_c0;
  ulonglong uStack_b8;
  undefined *puStack_b0;
  undefined *puStack_a8;
  undefined8 uStack_98;
  undefined *puStack_90;
  undefined *puStack_88;
  void *pvStack_80;
  undefined *puStack_78;
  undefined *puStack_70;
  ulonglong uStack_68;
  undefined *puStack_60;
  ulonglong uStack_58;
  
  uStack_58 = _DAT_18002c008 ^ (ulonglong)auStack_e8;
  bVar1 = false;
  puStack_88 = (undefined *)0x0;
  pvStack_80 = (void *)0x0;
  puStack_90 = (undefined *)0x0;
  puStack_78 = (undefined *)0x0;
  puStack_70 = (undefined *)0x0;
  uStack_68 = 0;
  uStack_98 = param_4;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar4 = api_plist_dict_get_item_1809c0937(param_2,"Command");
  if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
    api_plist_get_string_val_180be19e1(pvVar4,&pvStack_80);
  }
  do {
    debug_info_real_Recovered
              ("instproxy_lock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c"
               ,0xbf,"Locked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlEnterCriticalSection; offline
                       emulation evidence. */
    api_RtlEnterCriticalSection_180aaa128(param_1 + 1);
    iVar3 = native_180018050(*param_1,&puStack_88,1000);
    if (iVar3 != -5) {
      if (iVar3 == -3) {
        uVar6 = 0xfffffffd;
      }
      else if (iVar3 == -2) {
        uVar6 = 0xfffffffe;
      }
      else if (iVar3 == -1) {
        uVar6 = 0xffffffff;
      }
      else {
        if (iVar3 == 0) goto LAB_18000b965;
        uVar6 = 0xffffff00;
      }
      debug_info_real_Recovered
                ("instproxy_unlock",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0xca,
                 "Unlocked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLeaveCriticalSection; offline
                       emulation evidence. */
      api_RtlLeaveCriticalSection_18029aa7b(param_1 + 1);
      pvStack_c8 = (void *)CONCAT44(pvStack_c8._4_4_,uVar6);
      debug_info_real_Recovered
                ("instproxy_receive_status_loop",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x157,
                 "could not receive plist, error %d");
      break;
    }
LAB_18000b965:
    debug_info_real_Recovered
              ("instproxy_unlock",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0xca,"Unlocked")
    ;
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLeaveCriticalSection; offline
                       emulation evidence. */
    api_RtlLeaveCriticalSection_1800790ae(param_1 + 1);
    puVar5 = puStack_88;
    if (puStack_88 != (undefined *)0x0) {
      iVar3 = -0x100;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_dict_get_item_1803f5225(puStack_88,"Error");
      if (pvVar4 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
        api_plist_get_string_val_18088cba1(pvVar4,&puStack_78);
      }
      uStack_68 = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_dict_get_item_1808dd5f8(puVar5,"ErrorDetail");
      if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
        api_plist_get_uint_val_180784be9(pvVar4,&uStack_68);
        uStack_68 = uStack_68 & 0xffffffff;
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_dict_get_item_1804a753b(puVar5,"ErrorDescription");
      if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
        api_plist_get_string_val_180621fa2(pvVar4,&puStack_70);
      }
      puVar5 = puStack_78;
      if (puStack_78 != (undefined *)0x0) {
        iVar3 = native_18000ad00(puStack_78);
      }
      if (iVar3 != 0) {
        puStack_a8 = &UNK_180020f68;
        if (puStack_70 != (undefined *)0x0) {
          puStack_a8 = puStack_70;
        }
        puStack_b0 = puVar5;
        uStack_b8 = uStack_68;
        puStack_c0 = (undefined *)CONCAT44(puStack_c0._4_4_,iVar3);
        pvStack_c8 = pvStack_80;
        debug_info_real_Recovered
                  ("instproxy_receive_status_loop",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x160,
                   "command: %s, error %d, code 0x%08llx, name: %s, description: \"%s\"");
        bVar1 = true;
        puVar5 = puStack_78;
      }
      if (puVar5 != (undefined *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_1808ca6ea(puVar5);
        puVar5 = (undefined *)0x0;
        puStack_78 = (undefined *)0x0;
      }
      if (puStack_70 != (undefined *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_180363d91(puStack_70);
        puStack_70 = puVar5;
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_dict_get_item_1801399b3(puStack_88,"Status");
      puVar2 = puVar5;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
      if ((pvVar4 == (void *)0x0) ||
         (api_plist_get_string_val_1802bac30(pvVar4,&puStack_90), puVar2 = puStack_90,
         puStack_90 == (undefined *)0x0)) {
        puStack_90 = puVar2;
        pvStack_c8 = (void *)CONCAT44(pvStack_c8._4_4_,iVar3);
        debug_info_real_Recovered
                  ("instproxy_receive_status_loop",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x171,
                   "failed to retrieve name from status response with error %d.");
        bVar1 = true;
        if (puStack_90 != (undefined *)0x0) goto LAB_18000bb03;
      }
      else {
LAB_18000bb03:
        iVar3 = func_0x00018001cf6d(puStack_90,"Complete");
        if (iVar3 == 0) {
          bVar1 = true;
        }
        puStack_60 = puVar5;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
        pvVar4 = api_plist_dict_get_item_180a950fa(puStack_88,"PercentComplete");
        if (pvVar4 == (void *)0x0) {
LAB_18000bb85:
          puStack_c0 = puStack_90;
          pvStack_c8 = pvStack_80;
          debug_info_real_Recovered
                    ("instproxy_receive_status_loop",
                     "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x182,
                     "command: %s, status: %s");
        }
        else {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
          api_plist_get_uint_val_180c3b6dd(pvVar4,&puStack_60);
          if ((int)puStack_60 < 0) goto LAB_18000bb85;
          uStack_b8 = CONCAT44(uStack_b8._4_4_,(int)puStack_60);
          puStack_c0 = puStack_90;
          pvStack_c8 = pvStack_80;
          debug_info_real_Recovered
                    ("instproxy_receive_status_loop",
                     "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x180,
                     "command: %s, status: %s, percent (%d%%)");
        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_180372ec3(puStack_90);
        puStack_90 = puVar5;
      }
      if (param_3 != (code *)0x0) {
        (*param_3)(param_2,puStack_88,uStack_98);
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_18094797e(puStack_88);
      puStack_88 = puVar5;
      if (bVar1) break;
    }
  } while (*param_1 != 0);
  if (pvStack_80 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_1804dc0c0(pvStack_80);
  }
  native_18001c0e0(uStack_58 ^ (ulonglong)auStack_e8);
  return;
}

