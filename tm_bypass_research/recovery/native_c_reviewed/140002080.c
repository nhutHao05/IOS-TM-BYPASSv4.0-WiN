/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * BuildBackupInfoPlistRecovered(char *param_1,void *param_2,void *param_3)

{
  char *pcVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  void *pvVar10;
  void *pvVar11;
  undefined8 uVar12;
  void *pvVar13;
  void *pvVar14;
  char *pcVar15;
  ulonglong uVar16;
  char *arg0;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  char *pcVar20;
  longlong lVar21;
  undefined1 *puVar22;
  uint uVar23;
  ulonglong uVar24;
  undefined1 auStack_198 [8];
  undefined1 auStack_190 [48];
  undefined8 uStack_160;
  ulonglong auStack_158 [4];
  void **ppvStack_138;
  void *pvStack_128;
  void *pvStack_120;
  char *pcStack_118;
  longlong *plStack_110;
  void *pvStack_108;
  undefined8 uStack_100;
  void *pvStack_f8;
  void *pvStack_f0;
  undefined8 uStack_e8;
  void *pvStack_e0;
  void *pvStack_d8;
  char *pcStack_d0;
  void *pvStack_c8;
  undefined8 uStack_c0;
  void *pvStack_b8;
  char *pcStack_a8;
  char *apcStack_a0 [4];
  char *pcStack_80;
  char *pcStack_78;
  char *pcStack_70;
  char *pcStack_68;
  char *pcStack_60;
  char *pcStack_58;
  undefined8 uStack_50;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_14000b008 ^ (ulonglong)auStack_158;
  uVar23 = 0;
  pvStack_128 = (void *)0x0;
  pvStack_e0 = (void *)0x0;
  pvStack_d8 = (void *)0x0;
  pvStack_108 = (void *)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_client_new_with_handshake; offline emulation
                       evidence. */
  uStack_160 = 0x1400020d6;
  pcStack_d0 = param_1;
  pvStack_b8 = param_3;
  iVar7 = api_lockdownd_client_new_with_handshake_14017638c(param_2,&pvStack_108,"idevicebackup2");
  if (iVar7 != 0) {
    pvVar9 = (void *)0x0;
    goto LAB_140002af8;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  uStack_160 = 0x140002108;
  pvVar9 = api_plist_new_dict_140150373();
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_get_value; offline
                       emulation evidence. */
  uStack_160 = 0x140002124;
  pvStack_c8 = pvVar9;
  api_lockdownd_get_value_1400f31d7(pvStack_108,(char *)0x0,(char *)0x0,&pvStack_128);
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_get_value; offline
                       emulation evidence. */
  uStack_160 = 0x14000213e;
  api_lockdownd_get_value_14018a0f8(pvStack_108,"com.apple.iTunes",(char *)0x0,&pvStack_e0);
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_get_value; offline
                       emulation evidence. */
  uStack_160 = 0x14000215a;
  api_lockdownd_get_value_140184fa1
            (pvStack_108,"com.apple.mobile.iTunes","MinITunesVersion",&pvStack_d8);
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_client_free; offline
                       emulation evidence. */
  uStack_160 = 0x140002165;
  api_lockdownd_client_free_14016de53(pvStack_108);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  uStack_160 = 0x14000216b;
  pvVar10 = api_plist_new_dict_14007fbb6();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_array; offline emulation
                       evidence. */
  uStack_160 = 0x140002174;
  pvVar11 = api_plist_new_array_1401d0fe1();
  uStack_e8 = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_start_service;
                       offline emulation evidence. */
  uStack_160 = 0x140002197;
  pvStack_f8 = pvVar11;
  iVar7 = api_instproxy_client_start_service_14020e875(param_2,&uStack_e8,"idevicebackup2");
  pvVar13 = pvVar11;
  if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_options_new;
                       offline emulation evidence. */
    uStack_160 = 0x1400021a4;
    uVar12 = api_instproxy_client_options_new_1401af1bf();
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_options_add;
                       offline emulation evidence. */
    uStack_160 = 0x1400021c5;
    uStack_c0 = uVar12;
    api_instproxy_client_options_add_1401d7c70(uVar12,"ApplicationType","User",0);
    ppvStack_138 = (void **)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!instproxy_client_options_set_return_attributes; offline
                       emulation evidence. */
    uStack_160 = 0x1400021e9;
    api_instproxy_client_options_set_return_attributes_1401d1d22
              (uVar12,"CFBundleIdentifier","ApplicationSINF","iTunesMetadata");
    pvStack_120 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_browse; offline
                       emulation evidence. */
    uStack_160 = 0x140002200;
    api_instproxy_browse_14018f81f(uStack_e8,uVar12,&pvStack_120);
    plStack_110 = (longlong *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!sbservices_client_start_service;
                       offline emulation evidence. */
    uStack_160 = 0x14000221a;
    iVar7 = api_sbservices_client_start_service_14005e3b0(param_2,&plStack_110,"idevicebackup2");
    if (iVar7 != 0) {
      uStack_160 = 0x14000222b;
      PrintMessageRecovered("Couldn\'t establish sbservices connection. Continuing anyway.\n");
    }
    if (pvStack_120 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
      uStack_160 = 0x14000223e;
      iVar7 = api_plist_get_node_type_1401fac20(pvStack_120);
      if (iVar7 == 4) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
        uStack_160 = 0x140002253;
        uVar8 = api_plist_array_get_size_140219bee(pvStack_120);
        if (uVar8 != 0) {
          do {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
            uStack_160 = 0x14000226e;
            pvVar13 = api_plist_array_get_item_1401501c9(pvStack_120,uVar23);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
            uStack_160 = 0x140002280;
            pvVar9 = api_plist_dict_get_item_14014b330(pvVar13,"CFBundleIdentifier");
            if (pvVar9 != (void *)0x0) {
              pcStack_118 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
              uStack_160 = 0x14000229e;
              pvVar14 = (void *)api_plist_copy_1401f5b09(pvVar9);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
              uStack_160 = 0x1400022ab;
              api_plist_array_append_item_1401c628b(pvVar11,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
              uStack_160 = 0x1400022b9;
              api_plist_get_string_val_1400edb2d(pvVar9,&pcStack_118);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
              uStack_160 = 0x1400022c8;
              pvVar9 = api_plist_dict_get_item_140132e32(pvVar13,"ApplicationSINF");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
              uStack_160 = 0x1400022dc;
              pvVar13 = api_plist_dict_get_item_14017fca2(pvVar13,"iTunesMetadata");
              if ((pvVar9 != (void *)0x0) && (pvVar13 != (void *)0x0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
                uStack_160 = 0x1400022f6;
                pvVar14 = api_plist_new_dict_1401bd172();
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
                uStack_160 = 0x140002303;
                pvVar9 = (void *)api_plist_copy_1400fdab1(pvVar9);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                uStack_160 = 0x140002316;
                api_plist_dict_set_item_14020e828(pvVar14,"ApplicationSINF",pvVar9);
                if (plStack_110 != (longlong *)0x0) {
                  pvStack_f0 = (void *)0x0;
                  uStack_100 = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!sbservices_get_icon_pngdata;
                       offline emulation evidence. */
                  uStack_160 = 0x140002340;
                  api_sbservices_get_icon_pngdata_1401e84d3
                            (plStack_110,pcStack_118,&pvStack_f0,&uStack_100);
                  if (pvStack_f0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
                    uStack_160 = 0x140002356;
                    pvVar9 = (void *)api_plist_new_data_140117c89(pvStack_f0,uStack_100);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                    uStack_160 = 0x140002368;
                    api_plist_dict_set_item_1400c1986(pvVar14,"PlaceholderIcon",pvVar9);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                    uStack_160 = 0x140002373;
                    api_free_1401ac43c(pvStack_f0);
                  }
                }
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
                uStack_160 = 0x14000237c;
                pvVar13 = (void *)api_plist_copy_14006d868(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                uStack_160 = 0x140002390;
                api_plist_dict_set_item_1401d7561(pvVar14,"iTunesMetadata",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                uStack_160 = 0x1400023a0;
                api_plist_dict_set_item_14004febf(pvVar10,pcStack_118,pvVar14);
              }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStack_160 = 0x1400023ac;
              api_free_1401c024e(pcStack_118);
            }
            uVar23 = uVar23 + 1;
            uVar12 = uStack_c0;
            pvVar13 = pvStack_f8;
            pvVar9 = pvStack_c8;
          } while (uVar23 < uVar8);
        }
      }
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStack_160 = 0x1400023cf;
    api_plist_free_1400a52f5(pvStack_120);
    if (plStack_110 != (longlong *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!sbservices_client_free; offline
                       emulation evidence. */
      uStack_160 = 0x1400023df;
      api_sbservices_client_free_140063996();
    }
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_options_free;
                       offline emulation evidence. */
    uStack_160 = 0x1400023e8;
    api_instproxy_client_options_free_140052d29(uVar12);
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_free; offline
                       emulation evidence. */
    uStack_160 = 0x1400023f2;
    api_instproxy_client_free_140202ba4(uStack_e8);
    param_1 = pcStack_d0;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002409;
  api_plist_dict_set_item_1401b3477(pvVar9,"Applications",pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x14000241c;
  pvVar10 = api_plist_dict_get_item_14005e3a4(pvStack_128,"BuildVersion");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x140002425;
  pvVar10 = (void *)api_plist_copy_14005e2e6(pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002438;
  api_plist_dict_set_item_140063969(pvVar9,"Build Version",pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002449;
  pvVar10 = api_plist_dict_get_item_1400ccc43(pvStack_128,"DeviceName");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x140002456;
  pvVar11 = (void *)api_plist_copy_140210ed1(pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002468;
  api_plist_dict_set_item_1401cd320(pvVar9,"Device Name",pvVar11);
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x140002472;
  pvVar10 = (void *)api_plist_copy_14013b2f9(pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002484;
  api_plist_dict_set_item_1401e6356(pvVar9,"Display Name",pvVar10);
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  uStack_160 = 0x140002490;
  pcVar15 = (char *)api_malloc_1400b7959(0x21);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  uStack_160 = 0x14000249b;
  uVar12 = api__time64_14017cac2(0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!srand; offline emulation evidence. */
  uStack_160 = 0x1400024a3;
  api_srand_1401cc241(uVar12);
  lVar21 = 0;
  do {
                    /* Recovered VMProtect thunk: ucrtbase.dll!rand; offline emulation evidence. */
    uStack_160 = 0x1400024b5;
    uVar23 = api_rand_140154d82();
    uVar23 = uVar23 & 0x8000000f;
    if ((int)uVar23 < 0) {
      uVar23 = (uVar23 - 1 | 0xfffffff0) + 1;
    }
    pcVar15[lVar21] = "ABCDEF0123456789"[(int)uVar23];
    lVar21 = lVar21 + 1;
  } while (lVar21 < 0x20);
  pcVar15[0x20] = '\0';
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  uStack_160 = 0x1400024e3;
  pvVar10 = api_plist_new_string_14006aff9(pcVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400024f6;
  api_plist_dict_set_item_1401503bd(pvVar9,"GUID",pvVar10);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStack_160 = 0x140002500;
  api_free_14009b92d(pcVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002511;
  pvVar10 = api_plist_dict_get_item_1400915cd(pvStack_128,"IntegratedCircuitCardIdentity");
  if (pvVar10 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uStack_160 = 0x14000251f;
    pvVar10 = (void *)api_plist_copy_1401159ff(pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStack_160 = 0x140002532;
    api_plist_dict_set_item_1401d060d(pvVar9,"ICCID",pvVar10);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002544;
  pvVar10 = api_plist_dict_get_item_1401ef17f(pvStack_128,"InternationalMobileEquipmentIdentity");
  if (pvVar10 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uStack_160 = 0x140002553;
    pvVar10 = (void *)api_plist_copy_14021ad98(pvVar10);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStack_160 = 0x140002565;
    api_plist_dict_set_item_14009de01(pvVar9,"IMEI",pvVar10);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002578;
  api_plist_dict_set_item_14017d883(pvVar9,"Installed Applications",pvVar13);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  uStack_160 = 0x140002581;
  iVar7 = api__time64_14017aabc(0);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_date; offline emulation
                       evidence. */
  uStack_160 = 0x14000258e;
  pvVar13 = (void *)api_plist_new_date_1401fd1e6(iVar7 + -0x3a4fc880,0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400025a2;
  api_plist_dict_set_item_1401df1d6(pvVar9,"Last Backup Date",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400025b3;
  pvVar13 = api_plist_dict_get_item_140124285(pvStack_128,"MobileEquipmentIdentifier");
  if (pvVar13 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uStack_160 = 0x1400025c1;
    pvVar13 = (void *)api_plist_copy_1401b1932(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStack_160 = 0x1400025d4;
    api_plist_dict_set_item_14004d3a8(pvVar9,"MEID",pvVar13);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400025e6;
  pvVar13 = api_plist_dict_get_item_14008efd3(pvStack_128,"PhoneNumber");
  if (pvVar13 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    uStack_160 = 0x1400025f7;
    iVar7 = api_plist_get_node_type_140204f5c(pvVar13);
    if (iVar7 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
      uStack_160 = 0x140002606;
      pvVar13 = (void *)api_plist_copy_1401ee606(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStack_160 = 0x140002619;
      api_plist_dict_set_item_1401eb5dd(pvVar9,"Phone Number",pvVar13);
    }
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x14000262a;
  pvVar13 = api_plist_dict_get_item_1400c387b(pvStack_128,"ProductType");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x140002633;
  pvVar13 = (void *)api_plist_copy_140076f22(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002646;
  api_plist_dict_set_item_14012a727(pvVar9,"Product Type",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002658;
  pvVar13 = api_plist_dict_get_item_1401f4b72(pvStack_128,"ProductVersion");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x140002661;
  pvVar13 = (void *)api_plist_copy_1401d1d88(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002674;
  api_plist_dict_set_item_1401c0e7e(pvVar9,"Product Version",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002686;
  pvVar13 = api_plist_dict_get_item_1400a527c(pvStack_128,"SerialNumber");
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
  uStack_160 = 0x14000268f;
  pvVar13 = (void *)api_plist_copy_14019f6c6(pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400026a3;
  api_plist_dict_set_item_14020e867(pvVar9,"Serial Number",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400026b4;
  api_plist_dict_get_item_14018b84a(pvStack_128,"UniqueDeviceID");
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  uStack_160 = 0x1400026bd;
  pvVar13 = api_plist_new_string_1400a5282(param_1);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400026d0;
  api_plist_dict_set_item_14006b1ec(pvVar9,"Target Identifier",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  uStack_160 = 0x1400026dd;
  pvVar13 = api_plist_new_string_140203fa2("Device");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x1400026f0;
  api_plist_dict_set_item_140099dd0(pvVar9,"Target Type",pvVar13);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
  uStack_160 = 0x1400026f9;
  pcVar15 = (char *)api__mbsdup_14016d129(param_1);
  uVar23 = 0;
  lVar21 = -1;
  do {
    lVar21 = lVar21 + 1;
  } while (pcVar15[lVar21] != '\0');
  if (lVar21 != 0) {
    uVar24 = 0;
    do {
                    /* Recovered VMProtect thunk: ucrtbase.dll!toupper; offline emulation evidence.
                        */
      uStack_160 = 0x140002720;
      cVar6 = api_toupper_1400af94d((int)pcVar15[uVar24]);
      pcVar15[uVar24] = cVar6;
      uVar23 = uVar23 + 1;
      uVar24 = (ulonglong)uVar23;
      uVar16 = 0xffffffffffffffff;
      do {
        uVar16 = uVar16 + 1;
      } while (pcVar15[uVar16] != '\0');
    } while (uVar24 < uVar16);
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  uStack_160 = 0x140002746;
  pvVar13 = api_plist_new_string_1401d6e88(pcVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002759;
  api_plist_dict_set_item_14012728e(pvVar9,"Unique Identifier",pvVar13);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStack_160 = 0x140002763;
  api_free_14020e8c1(pcVar15);
  pvVar13 = pvStack_b8;
  pcStack_d0 = (char *)0x0;
  if (pvStack_b8 != (void *)0x0) {
    plStack_110 = (longlong *)0x0;
    uVar23 = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_get_file_info; offline
                       emulation evidence. */
    uStack_160 = 0x140002792;
    api_afc_get_file_info_1400ccc62();
    if (plStack_110 != (longlong *)0x0) {
      iVar7 = 0;
      if (*plStack_110 == 0) {
LAB_1400027ef:
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_dictionary_free; offline
                       emulation evidence. */
        uStack_160 = 0x1400027f8;
        api_afc_dictionary_free_140140ad4(plStack_110);
        if (uVar23 != 0) {
          pcStack_118 = (char *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_open; offline emulation
                       evidence. */
          uStack_160 = 0x14000281f;
          api_afc_file_open_1401d7c48(pvVar13,"/Books/iBooksData2.plist",1,&pcStack_118);
          if (pcStack_118 != (char *)0x0) {
            pcVar15 = (char *)(ulonglong)uVar23;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
            uStack_160 = 0x140002836;
            pvVar10 = api_malloc_14019c4a4((ulonglong)uVar23);
            uVar8 = 0;
            if (uVar23 == 0) {
LAB_1400028a4:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStack_160 = 0x1400028ad;
              api_free_1401c4e9b(pvVar10);
              pcVar15 = pcStack_d0;
              pvVar10 = (void *)0x0;
            }
            else {
              do {
                ppvStack_138 = &pvStack_120;
                pvStack_120 = (void *)((ulonglong)pvStack_120 & 0xffffffff00000000);
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_read; offline emulation
                       evidence. */
                uStack_160 = 0x140002869;
                api_afc_file_read_140214c44
                          (pvVar13,pcStack_118,(ulonglong)uVar8 + (longlong)pvVar10,0x10000);
                if ((int)pvStack_120 == 0) break;
                uVar8 = uVar8 + (int)pvStack_120;
              } while (uVar8 < uVar23);
              if (uVar8 != uVar23) goto LAB_1400028a4;
            }
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_close; offline
                       emulation evidence. */
            uStack_160 = 0x1400028be;
            api_afc_file_close_1401eb5ef(pvVar13,(ulonglong)pcStack_118);
            if (pvVar10 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
              uStack_160 = 0x1400028d0;
              pvVar11 = (void *)api_plist_new_data_14004cdda(pvVar10,pcVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
              uStack_160 = 0x1400028e2;
              api_plist_dict_set_item_1401bf64a(pvVar9,"iBooks Data 2",pvVar11);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStack_160 = 0x1400028eb;
              api_free_1401f5b42(pvVar10);
            }
          }
        }
      }
      else {
        lVar21 = *plStack_110;
        lVar19 = 0;
        do {
          lVar17 = 0;
          while (lVar18 = lVar17 + 1, *(char *)(lVar21 + lVar17) == "st_size"[lVar17]) {
            lVar17 = lVar18;
            if (lVar18 == 8) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!atol; offline emulation evidence. */
              uStack_160 = 0x1400027e7;
              uVar23 = api_atol_140109421(plStack_110[(longlong)iVar7 + 1]);
              goto LAB_1400027ef;
            }
          }
          lVar21 = plStack_110[lVar19 + 2];
          lVar19 = lVar19 + 2;
          iVar7 = iVar7 + 2;
        } while (lVar21 != 0);
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_dictionary_free; offline
                       emulation evidence. */
        uStack_160 = 0x1400028a1;
        api_afc_dictionary_free_140168b8f(plStack_110);
      }
    }
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
  uStack_160 = 0x1400028f1;
  pvVar10 = api_plist_new_dict_14006f848();
  pcVar15 = "ApertureAlbumPrefs";
  pcStack_a8 = "ApertureAlbumPrefs";
  uStack_50 = 0;
  apcStack_a0[0] = "IC-Info.sidb";
  lVar21 = 0;
  apcStack_a0[1] = "IC-Info.sidv";
  apcStack_a0[2] = "PhotosFolderAlbums";
  apcStack_a0[3] = "PhotosFolderName";
  pcStack_80 = "PhotosFolderPrefs";
  pcStack_78 = "VoiceMemos.plist";
  pcStack_70 = "iPhotoAlbumPrefs";
  pcStack_68 = "iTunesApplicationIDs";
  pcStack_60 = "iTunesPrefs";
  pcStack_58 = "iTunesPrefs.plist";
  do {
    pvStack_f8 = (void *)0x0;
    uStack_100 = 0;
    lVar19 = -1;
    do {
      lVar17 = lVar19;
      lVar19 = lVar17 + 1;
    } while (pcVar15[lVar19] != '\0');
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    uStack_160 = 0x1400029b3;
    arg0 = (char *)api_malloc_140146975(lVar17 + 0x19);
    uVar5 = s__iTunes_Control_iTunes__140007bb8._12_4_;
    uVar4 = s__iTunes_Control_iTunes__140007bb8._8_4_;
    uVar3 = s__iTunes_Control_iTunes__140007bb8._4_4_;
    *(undefined4 *)arg0 = s__iTunes_Control_iTunes__140007bb8._0_4_;
    *(undefined4 *)(arg0 + 4) = uVar3;
    *(undefined4 *)(arg0 + 8) = uVar4;
    *(undefined4 *)(arg0 + 0xc) = uVar5;
    pcVar20 = arg0 + -1;
    *(undefined8 *)(arg0 + 0x10) = s__iTunes_Control_iTunes__140007bb8._16_8_;
    do {
      pcVar1 = pcVar20 + 1;
      pcVar20 = pcVar20 + 1;
    } while (*pcVar1 != '\0');
    lVar19 = 0;
    do {
      cVar6 = pcVar15[lVar19];
      pcVar20[lVar19] = cVar6;
      lVar19 = lVar19 + 1;
    } while (cVar6 != '\0');
    uStack_160 = 0x140002a04;
    native_140001b00(pvVar13,arg0,&pvStack_f8,&uStack_100);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStack_160 = 0x140002a0d;
    api_free_14014ece3(arg0);
    pvVar11 = pvStack_f8;
    if (pvStack_f8 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
      uStack_160 = 0x140002a24;
      pvVar14 = (void *)api_plist_new_data_140209275(pvStack_f8,uStack_100);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStack_160 = 0x140002a33;
      api_plist_dict_set_item_14019820e(pvVar10,pcVar15,pvVar14);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStack_160 = 0x140002a3d;
      api_free_14017e7ee(pvVar11);
    }
    pcVar15 = apcStack_a0[lVar21];
    lVar21 = lVar21 + 1;
  } while (pcVar15 != (char *)0x0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002a61;
  api_plist_dict_set_item_140202ddc(pvVar9,"iTunes Files",pvVar10);
  if (pvStack_e0 == (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    uStack_160 = 0x140002a88;
    pvVar13 = api_plist_new_dict_140150c1c();
  }
  else {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uStack_160 = 0x140002a81;
    pvVar13 = (void *)api_plist_copy_1401c8889();
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002a9c;
  api_plist_dict_set_item_14012a94c(pvVar9,"iTunes Settings",pvVar13);
  if (pvStack_d8 == (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    uStack_160 = 0x140002aba;
    pvVar13 = api_plist_new_string_1401c4f0d("10.0.1");
  }
  else {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uStack_160 = 0x140002aab;
    pvVar13 = (void *)api_plist_copy_14010a4ed();
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  uStack_160 = 0x140002acc;
  api_plist_dict_set_item_14013965d(pvVar9,"iTunes Version",pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStack_160 = 0x140002ad8;
  api_plist_free_14017ed84(pvStack_e0);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStack_160 = 0x140002ae2;
  api_plist_free_14017461b(pvStack_d8);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStack_160 = 0x140002aed;
  api_plist_free_140063ab7(pvStack_128);
LAB_140002af8:
  auStack_158[0] = uStack_48 ^ (ulonglong)auStack_158;
  uStack_160 = 0x140002b04;
  if ((auStack_158[0] != _DAT_14000b008) || ((short)(auStack_158[0] >> 0x30) != 0)) {
    puVar22 = auStack_198;
    iVar7 = func_0x000140006b22(0x17);
    if (iVar7 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(2);
      puVar22 = auStack_190;
    }
    *(undefined8 *)(puVar22 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar22 + 0x38);
    _DAT_14000b188 = puVar22 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar22 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar22 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar22 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar22 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    pvVar9 = (void *)native_140005dc4(&UNK_1400075f0);
  }
  return pvVar9;
}

