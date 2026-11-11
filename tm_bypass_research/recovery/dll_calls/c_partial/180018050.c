/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180018050(longlong *param_1,undefined8 *param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  longlong *arg0;
  uint uVar3;
  int iVar5;
  uint uVar6;
  undefined1 auStack_88 [32];
  uint uStack_68;
  void *pvStack_60;
  uint uStack_58;
  uint uStack_54;
  void *pvStack_50;
  ulonglong uStack_48;
  ulonglong uVar4;
  ulonglong uVar7;
  
  uStack_48 = _DAT_18002c008 ^ (ulonglong)auStack_88;
  uVar4 = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  if (((param_1 == (longlong *)0x0) || (*param_1 == 0)) || (param_2 == (undefined8 *)0x0))
  goto LAB_18001819c;
  *param_2 = 0;
  iVar5 = -1;
  pvStack_50 = (void *)((ulonglong)pvStack_50 & 0xffffffff00000000);
  if (((longlong *)*param_1 == (longlong *)0x0) || (lVar1 = *(longlong *)*param_1, lVar1 == 0)) {
    debug_info_real_Recovered
              ("internal_plist_receive_timeout",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0xc4,
               "initial read failed!");
code_r0x000180018548:
  }
  else {
    uStack_68 = param_3;
    iVar2 = idevice_connection_receive_timeout_Recovered(lVar1,&uStack_58,4,&pvStack_50);
    if (iVar2 == -7) {
      iVar5 = -7;
LAB_180018138:
      uStack_54 = (uint)pvStack_50;
      uVar3 = (uint)pvStack_50;
    }
    else {
      if (iVar2 == -6) {
        iVar5 = -4;
      }
      else if (iVar2 == -4) {
        iVar5 = -6;
      }
      else if (iVar2 != -1) {
        iVar5 = 0;
        if (iVar2 == 0) goto LAB_180018138;
        iVar5 = -0x100;
      }
      debug_info_real_Recovered
                ("service_receive_with_timeout",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0xa7,
                 "could not read data");
      uVar3 = 0;
    }
    if (iVar5 == 0) {
      if (uVar3 != 0) {
        uStack_68 = uVar3;
        debug_info_real_Recovered
                  ("internal_plist_receive_timeout",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0xcd,
                   "initial read=%i");
        uStack_68 = (uStack_58 & 0xff0000 | uStack_58 >> 0x10) >> 8 |
                    (uStack_58 & 0xff00 | uStack_58 << 0x10) << 8;
        uStack_58 = uStack_68;
        debug_info_real_Recovered
                  ("internal_plist_receive_timeout",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0xd3,
                   "%d bytes following");
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
        arg0 = (longlong *)api_malloc_1802e62f3((ulonglong)uStack_58);
        if (arg0 == (longlong *)0x0) {
          uStack_68 = uStack_58;
          debug_info_real_Recovered
                    ("internal_plist_receive_timeout",
                     "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0xd6,
                     "out of memory when allocating %d bytes");
        }
        else {
          uVar7 = uVar4;
          if (uStack_58 != 0) {
            do {
              uVar6 = (uint)uVar7;
              uStack_68 = 120000;
              iVar5 = service_receive_with_timeout_Recovered
                                (*param_1,uVar7 + (longlong)arg0,uStack_58 - uVar6,&uStack_54);
              uVar3 = uStack_54;
              if (iVar5 != 0) {
                switch(iVar5) {
                case -7:
                  break;
                case -6:
                  break;
                default:
                  break;
                case -4:
                  break;
                case -3:
                  break;
                case -1:
                  break;
                }
                if (uVar6 < uStack_58) {
                  pvStack_60 = (void *)CONCAT44(pvStack_60._4_4_,uStack_58);
                  uStack_68 = uVar6;
                  debug_info_real_Recovered
                            ("internal_plist_receive_timeout",
                             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c"
                             ,0xe5,"received incomplete packet (%d of %d bytes)");
                  if (uVar6 != 0) {
                    debug_info_real_Recovered
                              ("internal_plist_receive_timeout",
                               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c"
                               ,0xe7,"incomplete packet following:");
                    native_180001310(arg0,uVar7);
                  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                  api_free_1802f0978(arg0);
                  goto LAB_18001819c;
                }
                break;
              }
              uStack_68 = uStack_54;
              debug_info_real_Recovered
                        ("internal_plist_receive_timeout",
                         "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",
                         0xe0,"received %d bytes");
              uVar7 = (ulonglong)(uVar6 + uVar3);
            } while (uVar6 + uVar3 < uStack_58);
          }
          if ((uStack_58 < 9) || (*arg0 != 0x30307473696c7062)) {
            if ((uStack_58 < 6) ||
               (((int)*arg0 != 0x6d783f3c || (*(char *)((longlong)arg0 + 4) != 'l')))) {
              debug_info_real_Recovered
                        ("internal_plist_receive_timeout",
                         "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",
                         0xf8,"WARNING: received unexpected non-plist content");
              native_180001310(arg0,uStack_58);
            }
            else {
              if (uStack_58 != 1) {
                do {
                  if ((*(byte *)(uVar4 + (longlong)arg0) < 0x20) &&
                     ((0xffffd9ffU >> ((int)(char)*(byte *)(uVar4 + (longlong)arg0) & 0x1fU) & 1) !=
                      0)) {
                    *(undefined1 *)(uVar4 + (longlong)arg0) = 0x20;
                  }
                  uVar3 = (int)uVar4 + 1;
                  uVar4 = (ulonglong)uVar3;
                } while (uVar3 < uStack_58 - 1);
              }
                    /* Recovered VMProtect thunk: plist.dll!plist_from_xml; offline emulation
                       evidence. */
              api_plist_from_xml_180bea771((char *)arg0,uStack_58,param_2);
            }
          }
          else {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_bin; offline emulation
                       evidence. */
            api_plist_from_bin_1807d07dd((char *)arg0,uStack_58,param_2);
          }
          if ((void *)*param_2 == (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
            api_free_1809a3e82(arg0);
          }
          else {
            pvStack_50 = (void *)0x0;
            uStack_54 = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_to_xml; offline emulation
                       evidence. */
            api_plist_to_xml_18038d1d1((void *)*param_2,&pvStack_50,&uStack_54);
            if (*(char *)((ulonglong)(uStack_54 - 1) + (longlong)pvStack_50) == '\n') {
              *(undefined1 *)((ulonglong)(uStack_54 - 1) + (longlong)pvStack_50) = 0;
            }
            if (uStack_54 < 0x4001) {
              pvStack_60 = pvStack_50;
              uStack_68 = uStack_54;
              debug_info_real_Recovered
                        ("internal_plist_receive_timeout",
                         "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",
                         0xfd,"printing %i bytes plist:\n%s");
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_18044264e(pvStack_50);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_1806e5293(arg0);
            }
            else {
              uStack_68 = uStack_54;
              debug_info_real_Recovered
                        ("internal_plist_receive_timeout",
                         "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",
                         0xfd,"supress printing %i bytes plist...\n");
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_1805effbb(pvStack_50);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_18015a2cd(arg0);
            }
          }
        }
      }
      goto LAB_18001819c;
    }
    debug_info_real_Recovered
              ("internal_plist_receive_timeout",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0xc4,
               "initial read failed!");
    switch(iVar5) {
    case -7:
      break;
    case -6:
      break;
    default:
      break;
    case -4:
      break;
    case -3:
      break;
    case -1:
      goto code_r0x000180018548;
    }
  }
LAB_18001819c:
  native_18001c0e0(uStack_48 ^ (ulonglong)auStack_88);
  return;
}

