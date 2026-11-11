/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180007450(longlong *param_1,undefined8 *param_2)

{
  void *arg0;
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 auStack_48 [32];
  void *pvStack_28;
  void *pvStack_20;
  ulonglong uStack_18;
  
  uStack_18 = _DAT_18002c008 ^ (ulonglong)auStack_48;
  if (((param_1 == (longlong *)0x0) || (*param_1 == 0)) || (param_2 == (undefined8 *)0x0))
  goto LAB_1800075d5;
  pvStack_20 = (void *)0x0;
  uVar1 = native_180018050(*param_1,&pvStack_20,60000);
  switch(uVar1) {
  case 0:
    pvStack_28 = (void *)0x0;
    native_180006bc0(pvStack_20,&pvStack_28);
    arg0 = pvStack_28;
    if ((pvStack_28 == (void *)0x0) ||
       (iVar2 = func_0x00018001cf6d(pvStack_28,"DLMessageProcessMessage"), iVar2 != 0)) {
      pcVar5 = "Did not receive DLMessageProcessMessage as expected!";
      uVar4 = 0x197;
LAB_180007588:
      debug_info_real_Recovered
                ("device_link_service_receive_process_message",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\device_link_service.c",uVar4,pcVar5)
      ;
    }
    else {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
      iVar2 = api_plist_array_get_size_1805a7ce0(pvStack_20);
      if (iVar2 != 2) {
        pcVar5 = "Malformed plist received for DLMessageProcessMessage";
        uVar4 = 0x19d;
        goto LAB_180007588;
      }
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
      pvVar3 = api_plist_array_get_item_1808aded4(pvStack_20,1);
      if (pvVar3 == (void *)0x0) {
        *param_2 = 0;
      }
      else {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
        uVar4 = api_plist_copy_180aedc70(pvVar3);
        *param_2 = uVar4;
      }
    }
    if (arg0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_180406ca1(arg0);
    }
    if (pvStack_20 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_180a06e41(pvStack_20);
    }
    break;
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
LAB_1800075d5:
  native_18001c0e0(uStack_18 ^ (ulonglong)auStack_48);
  return;
}

