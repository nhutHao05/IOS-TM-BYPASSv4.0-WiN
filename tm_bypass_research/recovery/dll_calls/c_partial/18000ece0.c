/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000ece0(undefined8 *param_1,longlong *param_2,char *param_3,longlong param_4,
                     undefined8 *param_5)

{
  char *arg0;
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  void *arg2;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *arg0_00;
  undefined1 auStack_b8 [32];
  char *pcStack_98;
  longlong lStack_88;
  undefined8 *puStack_80;
  void *pvStack_78;
  void *pvStack_70;
  longlong *plStack_68;
  int iStack_60;
  int iStack_5c;
  ulonglong uStack_58;
  
  uStack_58 = _DAT_18002c008 ^ (ulonglong)auStack_b8;
  puStack_80 = param_5;
  lStack_88 = param_4;
  if (param_1 == (undefined8 *)0x0) goto LAB_18000f3b6;
  plVar6 = (longlong *)0x0;
  arg0_00 = (longlong *)0x0;
  pvStack_70 = (void *)0x0;
  plStack_68 = (longlong *)0x0;
  iStack_60 = 0;
  lVar10 = -1;
  if (((param_2 == (longlong *)0x0) || (param_2[4] == 0)) || (param_2[3] == 0)) {
    do {
      plVar11 = plVar6 + 0x30004394;
      plVar6 = (longlong *)((longlong)plVar6 + 1);
      if ((char)*plVar11 != (param_3 + -1)[(longlong)plVar6]) {
        plStack_68 = (longlong *)0x0;
        iStack_5c = 0;
                    /* Recovered VMProtect thunk: usbmuxd.dll!usbmuxd_read_pair_record; offline
                       emulation evidence. */
        iVar2 = api_usbmuxd_read_pair_record_180b2da2a(param_1[3],&plStack_68,&iStack_5c);
        if (iVar2 < 0) {
          if (plStack_68 != (longlong *)0x0) goto code_r0x00018000f06b;
        }
        else {
          if (*plStack_68 == 0x30307473696c7062) {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_bin; offline emulation
                       evidence. */
            api_plist_from_bin_180262f7d((char *)plStack_68,iStack_5c,&pvStack_70);
          }
          else {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_xml; offline emulation
                       evidence. */
            api_plist_from_xml_180b93d26((char *)plStack_68,iStack_5c,&pvStack_70);
          }
code_r0x00018000f06b:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_1808f62b6(plStack_68);
        }
        if (pvStack_70 != (void *)0x0) goto LAB_18000ee50;
        goto LAB_18000f3b6;
      }
    } while (plVar6 != (longlong *)0x5);
    iVar2 = native_18000ea40(param_1,&pvStack_70);
    if (iVar2 != 0) {
      if (pvStack_70 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        api_plist_free_180341588(pvStack_70);
      }
      goto LAB_18000f3b6;
    }
    lockdownd_get_value_Recovered(param_1,0,"WiFiAddress",&plStack_68);
    arg0_00 = plStack_68;
  }
  else {
    if (((*param_2 == 0) || (param_2[1] == 0)) || (param_2[2] == 0)) goto LAB_18000f3b6;
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    pvVar4 = api_plist_new_dict_1807d5f66();
    lVar9 = lVar10;
    do {
      lVar9 = lVar9 + 1;
    } while (*(char *)(*param_2 + lVar9) != '\0');
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar5 = (void *)api_plist_new_data_18026347f();
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_18031e984(pvVar4,"DeviceCertificate",pvVar5);
    lVar9 = lVar10;
    do {
      lVar9 = lVar9 + 1;
    } while (*(char *)(param_2[1] + lVar9) != '\0');
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar5 = (void *)api_plist_new_data_180a4e62d();
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1806cfaba(pvVar4,"HostCertificate",pvVar5);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar5 = api_plist_new_string_180ac7b72((char *)param_2[3]);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180446c87(pvVar4,"HostID",pvVar5);
    do {
      lVar10 = lVar10 + 1;
    } while (*(char *)(param_2[2] + lVar10) != '\0');
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar5 = (void *)api_plist_new_data_18085f1dc();
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1805f7c40(pvVar4,"RootCertificate",pvVar5);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar5 = api_plist_new_string_180186a0a((char *)param_2[4]);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_18035815e(pvVar4,"SystemBUID",pvVar5);
    iStack_60 = 1;
    arg0_00 = plVar6;
    pvStack_70 = pvVar4;
  }
LAB_18000ee50:
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  pvVar4 = (void *)api_plist_copy_1800c9eba(pvStack_70);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_remove_item; offline
                       emulation evidence. */
  api_plist_dict_remove_item_1800935d4(pvVar4,"RootPrivateKey");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_remove_item; offline
                       emulation evidence. */
  api_plist_dict_remove_item_1808ac916(pvVar4,"HostPrivateKey");
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  pvVar5 = api_plist_new_dict_1807e5e34();
  pvStack_78 = pvVar5;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if (((pvVar5 != (void *)0x0) && (arg0 = (char *)param_1[4], arg0 != (char *)0x0)) &&
     (iVar2 = api_plist_get_node_type_1802337fe(pvVar5), iVar2 == 5)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    arg2 = api_plist_new_string_18012e192(arg0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_18090a2ae(pvVar5,"Label",arg2);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_180b27f40(pvStack_78,"PairRecord",pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar4 = api_plist_new_string_180a0137d(param_3);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_1804adaea(pvStack_78,"Request",pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  pvVar4 = api_plist_new_string_1805f7bf1("2");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_1803a28d2(pvStack_78,"ProtocolVersion",pvVar4);
  if (lStack_88 != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    pvVar4 = (void *)api_plist_copy_1802bd0a0(lStack_88);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180899c5a(pvStack_78,"PairingOptions",pvVar4);
  }
  iVar2 = lockdownd_send_Recovered(param_1,pvStack_78);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_180207598(pvStack_78);
  plVar6 = (longlong *)0x0;
  pvStack_78 = (void *)0x0;
  if (iVar2 != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_18036537b(pvStack_70);
    if (arg0_00 != (longlong *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_180750af6(arg0_00);
    }
    goto LAB_18000f3b6;
  }
  uVar3 = native_180018050(*param_1,&pvStack_78,60000);
  switch(uVar3) {
  case 0:
    plVar11 = plVar6;
    do {
      plVar7 = (longlong *)((longlong)plVar11 + 1);
      if (param_3[(longlong)plVar11] != (char)plVar11[0x3000439d]) {
        iVar2 = native_18000d390(pvStack_78,param_3);
        goto joined_r0x00018000f1b1;
      }
      plVar11 = plVar7;
    } while (plVar7 != (longlong *)0x7);
    iVar2 = native_18000d390(pvStack_78,0);
joined_r0x00018000f1b1:
    pcStack_98 = param_3;
    if (iVar2 == 0) {
      debug_info_real_Recovered
                ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                 0x3bc,"%s success");
      if (iStack_60 == 0) {
        debug_info_real_Recovered
                  ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                   0x3be,"internal pairing mode");
        plVar11 = plVar6;
        do {
          plVar7 = plVar11 + 0x3000439d;
          plVar11 = (longlong *)((longlong)plVar11 + 1);
          plVar8 = plVar6;
          if ((char)*plVar7 != (param_3 + -1)[(longlong)plVar11]) goto code_r0x00018000f240;
        } while (plVar11 != (longlong *)0x7);
                    /* Recovered VMProtect thunk: usbmuxd.dll!usbmuxd_delete_pair_record; offline
                       emulation evidence. */
        api_usbmuxd_delete_pair_record_180b36219(param_1[3]);
      }
      else {
        debug_info_real_Recovered
                  ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                   0x3d7,"external pairing mode");
      }
    }
    else {
      debug_info_real_Recovered
                ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
                 0x3da,"%s failure");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
      pvVar4 = api_plist_dict_get_item_180856717(pvStack_78,"Error");
      if (pvVar4 != (void *)0x0) {
        plStack_68 = (longlong *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
        api_plist_get_string_val_1806155b1(pvVar4,&plStack_68);
        plVar6 = plStack_68;
        if (plStack_68 != (longlong *)0x0) {
          native_18000d300(plStack_68);
          goto code_r0x00018000f161;
        }
      }
    }
    goto code_r0x00018000f167;
  case 0xfffffffb:
    break;
  case 0xfffffffc:
    break;
  case 0xfffffffd:
    break;
  case 0xfffffffe:
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_180a594af(pvStack_70);
  if (arg0_00 != (longlong *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180290f18(arg0_00);
  }
  goto LAB_18000f3b6;
  while (plVar8 = plVar11, plVar11 != (longlong *)0x5) {
code_r0x00018000f240:
    plVar11 = (longlong *)((longlong)plVar8 + 1);
    if ((char)plVar8[0x30004394] != (param_3 + -1)[(longlong)plVar11]) goto code_r0x00018000f167;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar4 = api_plist_dict_get_item_180c46542(pvStack_78,"EscrowBag");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if ((pvVar4 != (void *)0x0) && (iVar2 = api_plist_get_node_type_1809bf935(pvVar4), iVar2 == 7)) {
    debug_info_real_Recovered
              ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",0x3c7,
               "Saving EscrowBag from response in pair record");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    pvVar4 = (void *)api_plist_copy_180787b53(pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1805a77d5(pvStack_70,"EscrowBag",pvVar4);
  }
  if (arg0_00 != (longlong *)0x0) {
    debug_info_real_Recovered
              ("lockdownd_do_pair","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",0x3cd,
               "Saving WiFiAddress from device in pair record");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    pvVar4 = (void *)api_plist_copy_180815b88(arg0_00);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_18058f68d(pvStack_70,"WiFiMACAddress",pvVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180c0ef06(arg0_00);
    arg0_00 = plVar6;
  }
  uVar3 = *(undefined4 *)(param_1 + 5);
  uVar1 = param_1[3];
  plStack_68 = (longlong *)0x0;
  iStack_60 = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_to_bin; offline emulation
                       evidence. */
  api_plist_to_bin_180113706(pvStack_70,&plStack_68,&iStack_60);
                    /* Recovered VMProtect thunk:
                       usbmuxd.dll!usbmuxd_save_pair_record_with_device_id; offline emulation
                       evidence. */
  api_usbmuxd_save_pair_record_with_device_id_1801bd215(uVar1,uVar3,plStack_68,iStack_60);
  plVar6 = plStack_68;
code_r0x00018000f161:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180438950(plVar6);
code_r0x00018000f167:
  if (pvStack_70 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_1806f8f00(pvStack_70);
    pvStack_70 = (void *)0x0;
  }
  if (arg0_00 != (longlong *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_18018f128(arg0_00);
  }
  if (puStack_80 == (undefined8 *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180c7cdf9(pvStack_78);
  }
  else {
    *puStack_80 = pvStack_78;
  }
LAB_18000f3b6:
  native_18001c0e0(uStack_58 ^ (ulonglong)auStack_b8);
  return;
}

