/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BuildDirectoryListingRecovered(void *param_1,void *param_2,longlong param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  void *arg0;
  longlong lVar5;
  longlong lVar6;
  void *arg0_00;
  void *arg0_01;
  void *pvVar7;
  char *arg0_02;
  undefined1 *puVar8;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [48];
  undefined8 uStack_b0;
  ulonglong auStack_a8 [4];
  void *pvStack_88;
  void *pvStack_80;
  undefined1 auStack_78 [6];
  ushort uStack_72;
  int iStack_64;
  int iStack_58;
  ulonglong uStack_48;
  
  if (param_2 != (void *)0x0) {
    uStack_48 = _DAT_14000b008 ^ (ulonglong)auStack_a8;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    uStack_b0 = 0x140003aaa;
    pvStack_80 = param_1;
    iVar2 = api_plist_get_node_type_14010f12f(param_2);
    if (iVar2 == 4) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
      uStack_b0 = 0x140003abb;
      uVar3 = api_plist_array_get_size_140184fe3(param_2);
      if ((1 < uVar3) && (param_3 != 0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
        uStack_b0 = 0x140003adb;
        pvVar4 = api_plist_array_get_item_1401a1dbe(param_2,1);
        pvStack_88 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
        uStack_b0 = 0x140003af1;
        iVar2 = api_plist_get_node_type_1401df834(pvVar4);
        if (iVar2 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
          uStack_b0 = 0x140003b03;
          api_plist_get_string_val_140218adf(pvVar4,&pvStack_88);
        }
        if (pvStack_88 == (void *)0x0) {
          uStack_b0 = 0x140003b1a;
          PrintMessageRecovered("ERROR: Malformed DLContentsOfDirectory message\n");
        }
        else {
          uStack_b0 = 0x140003b3c;
          pvVar4 = (void *)native_1400010c0(param_3);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          uStack_b0 = 0x140003b4a;
          api_free_14021160a(pvStack_88);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
          uStack_b0 = 0x140003b4f;
          arg0 = api_plist_new_dict_1400d1f5d();
          uStack_b0 = 0x140003b5b;
          lVar5 = native_140001770(pvVar4);
          if (lVar5 != 0) {
            uStack_b0 = 0x140003b6f;
            lVar6 = native_140001840(lVar5);
            while (lVar6 != 0) {
              if ((*(char *)(lVar6 + 0x1c) != '.') ||
                 ((*(char *)(lVar6 + 0x1d) != '\0' &&
                  (((*(char *)(lVar6 + 0x1c) != '.' || (*(char *)(lVar6 + 0x1d) != '.')) ||
                   (*(char *)(lVar6 + 0x1e) != '\0')))))) {
                uStack_b0 = 0x140003bcc;
                arg0_00 = (void *)native_1400010c0(pvVar4);
                if (arg0_00 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003bdd;
                  arg0_01 = api_plist_new_dict_1400e0803();
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003bef;
                  api__stat64i32_140076735(arg0_00,auStack_78);
                  if ((uStack_72 & 0xf000) == 0x4000) {
                    arg0_02 = "DLFileTypeDirectory";
                  }
                  else {
                    arg0_02 = "DLFileTypeRegular";
                    if ((uStack_72 & 0xf000) != 0x8000) {
                      arg0_02 = "DLFileTypeUnknown";
                    }
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c27;
                  pvVar7 = api_plist_new_string_1401c62a4(arg0_02);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c39;
                  api_plist_dict_set_item_140126b95(arg0_01,"DLFileType",pvVar7);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_uint; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c44;
                  pvVar7 = api_plist_new_uint_140101bdb((longlong)iStack_64);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c57;
                  api_plist_dict_set_item_14018f840(arg0_01,"DLFileSize",pvVar7);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_date; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c6a;
                  pvVar7 = (void *)api_plist_new_date_1401adf4f(iStack_58 + -0x3a4fc880,0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c7c;
                  api_plist_dict_set_item_1401ccbd1(arg0_01,"DLFileModificationDate",pvVar7);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
                  uStack_b0 = 0x140003c8b;
                  api_plist_dict_set_item_140052d1c(arg0,(char *)(lVar6 + 0x1c),arg0_01);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                  uStack_b0 = 0x140003c95;
                  api_free_1400c198c(arg0_00);
                }
              }
              uStack_b0 = 0x140003c9d;
              lVar6 = native_140001840(lVar5);
              param_1 = pvStack_80;
            }
            uStack_b0 = 0x140003cc3;
            native_1400019b0(lVar5);
          }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          uStack_b0 = 0x140003ccc;
          api_free_14006cb98(pvVar4);
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
          uStack_b0 = 0x140003cdd;
          uVar3 = api_mobilebackup2_send_status_response_1400c4488(param_1,0,(char *)0x0,arg0);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
          uStack_b0 = 0x140003ce8;
          api_plist_free_14020a734(arg0);
          if (uVar3 != 0) {
            uStack_b0 = 0x140003d0c;
            PrintMessageRecovered("Could not send status response, error %d\n",(ulonglong)uVar3);
          }
        }
      }
    }
    auStack_a8[0] = uStack_48 ^ (ulonglong)auStack_a8;
    uStack_b0 = 0x140003d19;
    if ((auStack_a8[0] != _DAT_14000b008) || ((short)(auStack_a8[0] >> 0x30) != 0)) {
      puVar8 = auStack_e8;
      iVar2 = func_0x000140006b22(0x17);
      if (iVar2 != 0) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(2);
        puVar8 = auStack_e0;
      }
      *(undefined8 *)(puVar8 + -8) = 0x140005e22;
      native_140005fec(0x14000b0f0);
      _DAT_14000b060 = *(undefined8 *)(puVar8 + 0x38);
      _DAT_14000b188 = puVar8 + 0x40;
      _DAT_14000b170 = *(undefined8 *)(puVar8 + 0x40);
      _DAT_14000b050 = 0xc0000409;
      _DAT_14000b054 = 1;
      _DAT_14000b068 = 1;
      uRam000000014000b070 = 2;
      *(ulonglong *)(puVar8 + 0x20) = _DAT_14000b008;
      *(undefined8 *)(puVar8 + 0x28) = _DAT_14000b000;
      *(undefined8 *)(puVar8 + -8) = 0x140005ec4;
      _DAT_14000b1e8 = _DAT_14000b060;
      native_140005dc4(&UNK_1400075f0);
    }
  }
  return;
}

