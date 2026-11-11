/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180006d50(undefined8 *param_1,ulonglong param_2,ulonglong param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  void *arg0;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 auStack_a8 [32];
  ulonglong uStack_88;
  ulonglong uStack_80;
  ulonglong uStack_78;
  ulonglong uStack_70;
  void *pvStack_68;
  void *pvStack_60;
  ulonglong uStack_58;
  ulonglong uStack_50;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18002c008 ^ (ulonglong)auStack_a8;
  if (param_1 == (undefined8 *)0x0) goto LAB_1800071c7;
  pvStack_60 = (void *)0x0;
  pvStack_68 = (void *)0x0;
  uVar1 = native_180018050(*param_1,&pvStack_60,60000);
  switch(uVar1) {
  case 0:
    native_180006bc0(pvStack_60,&pvStack_68);
    pvVar4 = pvStack_68;
    if ((pvStack_68 != (void *)0x0) &&
       (iVar2 = func_0x00018001cf6d(pvStack_68,"DLMessageVersionExchange"), iVar2 == 0)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_180503cac(pvVar4);
      pvStack_68 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
      uVar3 = api_plist_array_get_size_180b2ac7a(pvStack_60);
      if (uVar3 < 3) {
        debug_info_real_Recovered
                  ("device_link_service_version_exchange",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\device_link_service.c",0xc5,
                   "DLMessageVersionExchange has unexpected format!");
        goto LAB_1800071a9;
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_array_get_item_1800715fd(pvStack_60,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
      arg0 = api_plist_array_get_item_18010446d(pvStack_60,2);
      uStack_58 = 0;
      uStack_50 = 0;
      if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
        api_plist_get_uint_val_1803be076(pvVar4,&uStack_58);
      }
      if (arg0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
        api_plist_get_uint_val_180a10adb(arg0,&uStack_50);
      }
      if (param_2 < uStack_58) {
        pcVar6 = "Version mismatch: device=(%lld,%lld) > expected=(%lld,%lld)";
        uVar5 = 0xd4;
LAB_180006efc:
        uStack_88 = uStack_58;
        uStack_80 = uStack_50;
        uStack_78 = param_2;
        uStack_70 = param_3;
        debug_info_real_Recovered
                  ("device_link_service_version_exchange",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\device_link_service.c",uVar5,
                   pcVar6);
        goto LAB_1800071a9;
      }
      if ((uStack_58 == param_2) && (param_3 < uStack_50)) {
        pcVar6 = "WARNING: Version mismatch: device=(%lld,%lld) > expected=(%lld,%lld)";
        uVar5 = 0xd8;
        goto LAB_180006efc;
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_18049afb4(pvStack_60);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_array; offline emulation
                       evidence. */
      pvStack_60 = api_plist_new_array_18042fb0d();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
      pvVar4 = api_plist_new_string_1802c0eba("DLMessageVersionExchange");
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
      api_plist_array_append_item_18056de63(pvStack_60,pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
      pvVar4 = api_plist_new_string_180947964("DLVersionsOk");
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
      api_plist_array_append_item_180814f6a(pvStack_60,pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_uint; offline emulation
                       evidence. */
      pvVar4 = api_plist_new_uint_18088cbf8(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
      api_plist_array_append_item_1805fc9bc(pvStack_60,pvVar4);
      uVar1 = native_180017ce0(*param_1,pvStack_60,1);
      switch(uVar1) {
      case 0:
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        api_plist_free_18018a16c(pvStack_60);
        pvStack_60 = (void *)0x0;
        uVar1 = native_180018050(*param_1,&pvStack_60,60000);
        switch(uVar1) {
        case 0:
          native_180006bc0(pvStack_60,&pvStack_68);
          pvVar4 = pvStack_68;
          if ((pvStack_68 == (void *)0x0) ||
             (iVar2 = func_0x00018001cf6d(pvStack_68,"DLMessageDeviceReady"), iVar2 != 0)) {
            pcVar6 = "Did not get DLMessageDeviceReady!";
            uVar5 = 0xf3;
            goto code_r0x00018000715c;
          }
          goto code_r0x000180007174;
        case 0xfffffffb:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
          break;
        case 0xfffffffc:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
          break;
        case 0xfffffffd:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
          break;
        case 0xfffffffe:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
          break;
        case 0xffffffff:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
          break;
        default:
          pcVar6 = "Error when receiving DLMessageDeviceReady!";
          uVar5 = 0xee;
        }
        break;
      case 0xfffffffb:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
        break;
      case 0xfffffffc:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
        break;
      case 0xfffffffd:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
        break;
      case 0xfffffffe:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
        break;
      case 0xffffffff:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
        break;
      default:
        pcVar6 = "Error when sending DLVersionsOk";
        uVar5 = 0xe5;
      }
      goto LAB_180007196;
    }
    pcVar6 = "Did not receive DLMessageVersionExchange from device!";
    uVar5 = 0xbc;
code_r0x00018000715c:
    debug_info_real_Recovered
              ("device_link_service_version_exchange",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\device_link_service.c",uVar5,pcVar6);
code_r0x000180007174:
    if (pvVar4 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_180718394(pvVar4);
    }
    goto LAB_1800071a9;
  case 0xfffffffb:
    break;
  case 0xfffffffc:
    break;
  case 0xfffffffd:
    break;
  case 0xfffffffe:
    break;
  case 0xffffffff:
  }
  pcVar6 = "Did not receive initial message from device!";
  uVar5 = 0xb7;
LAB_180007196:
  debug_info_real_Recovered
            ("device_link_service_version_exchange",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\device_link_service.c",uVar5,pcVar6);
LAB_1800071a9:
  if (pvStack_60 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180b9437f(pvStack_60);
  }
LAB_1800071c7:
  native_18001c0e0(uStack_48 ^ (ulonglong)auStack_a8);
  return;
}

