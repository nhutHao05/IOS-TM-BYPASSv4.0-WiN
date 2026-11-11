/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000ea40(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  char *arg0;
  undefined8 uVar6;
  void *arg2;
  char *arg0_00;
  char *pcVar7;
  undefined1 auStack_98 [32];
  char *pcStack_78;
  char *pcStack_70;
  void *apvStack_68 [2];
  char *pcStack_58;
  undefined4 uStack_50;
  char *pcStack_48;
  char *pcStack_40;
  undefined8 uStack_38;
  ulonglong uStack_30;
  
  uStack_30 = _DAT_18002c008 ^ (ulonglong)auStack_98;
  pcVar7 = (char *)0x0;
  uStack_50 = 0;
  pcStack_48 = (char *)0x0;
  apvStack_68[0] = (void *)0x0;
  pcStack_40 = (char *)0x0;
  uStack_38 = 0;
  iVar3 = lockdownd_get_value_Recovered(param_1,0,"DevicePublicKey",apvStack_68);
  if (iVar3 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_data_val; offline emulation
                       evidence. */
    api_plist_get_data_val_1807e3af1(apvStack_68[0],&pcStack_40,&uStack_38);
    arg0_00 = pcStack_40;
    uVar1 = (undefined4)uStack_38;
    pcStack_58 = pcStack_40;
    uStack_50 = (undefined4)uStack_38;
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180b3e37a(apvStack_68[0]);
    pcStack_70 = arg0_00;
    pcStack_78._0_4_ = uVar1;
    debug_info_real_Recovered
              ("pair_record_generate","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",
               0x322,"device public key follows:\n%.*s");
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    pvVar5 = api_plist_new_dict_180c34d0c();
    *param_2 = pvVar5;
    native_1800017e0(pvVar5,&pcStack_58);
                    /* Recovered VMProtect thunk: usbmuxd.dll!usbmuxd_read_buid; offline emulation
                       evidence. */
    iVar3 = api_usbmuxd_read_buid_18085a6e8(&pcStack_48);
    if (iVar3 == 0) {
      pcStack_70 = "SystemBUID";
      pcStack_78 = pcStack_48;
      debug_info_real_Recovered
                ("userpref_read_system_buid",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",0xc6,"using %s as %s"
                );
    }
    else {
      pcStack_78 = (char *)CONCAT44(pcStack_78._4_4_,iVar3);
      debug_info_real_Recovered
                ("userpref_read_system_buid",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",200,
                 "could not read system buid, error %d");
    }
    if (pcStack_48 != (char *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
      pvVar5 = api_plist_new_string_18018ea63(pcStack_48);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      api_plist_dict_set_item_1808a3e41((void *)*param_2,"SystemBUID",pvVar5);
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    arg0 = (char *)api_malloc_180856723(0x25);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
    uVar6 = api__time64_180745726(0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!srand; offline emulation evidence. */
    api_srand_1802b664f(uVar6);
    do {
      if ((pcVar7 < (char *)0x18) && ((0x842100UL >> ((ulonglong)pcVar7 & 0x3f) & 1) != 0)) {
        cVar2 = '-';
      }
      else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!rand; offline emulation evidence. */
        uVar4 = api_rand_180417e10();
        uVar4 = uVar4 & 0x8000000f;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
        }
        cVar2 = "ABCDEF0123456789"[(int)uVar4];
      }
      arg0[(longlong)pcVar7] = cVar2;
      pcVar7 = pcVar7 + 1;
    } while ((longlong)pcVar7 < 0x24);
    arg0[0x24] = '\0';
    pvVar5 = (void *)*param_2;
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    arg2 = api_plist_new_string_180538de8(arg0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180badf18(pvVar5,"HostID",arg2);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_1806c98b1(arg0);
  }
  else {
    debug_info_real_Recovered
              ("pair_record_generate","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\lockdown.c",799
               ,"device refused to send public key.");
    arg0_00 = pcVar7;
  }
  if (pcStack_48 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_1805eaa5e(pcStack_48);
  }
  if (arg0_00 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_18054a559(arg0_00);
  }
  native_18001c0e0(uStack_30 ^ (ulonglong)auStack_98);
  return;
}

