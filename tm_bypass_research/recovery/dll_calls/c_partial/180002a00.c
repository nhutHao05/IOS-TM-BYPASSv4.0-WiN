/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180002a00(undefined8 *param_1,undefined8 *param_2,uint *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong *arg0;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  char *pcVar7;
  ulonglong uVar8;
  undefined1 auStack_a8 [32];
  undefined8 uStack_88;
  ulonglong uStack_80;
  ulonglong uStack_78;
  undefined1 auStack_68 [8];
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  ulonglong uStack_50;
  ulonglong uStack_48;
  ulonglong uStack_40;
  
  uStack_40 = _DAT_18002c008 ^ (ulonglong)auStack_a8;
  uVar8 = 0xffffffffffffffff;
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  uStack_88 = CONCAT44(uStack_88._4_4_,120000);
  service_receive_with_timeout_Recovered(*param_1,auStack_68,0x28,param_3);
  if (*param_3 == 0) {
    debug_info_real_Recovered
              ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xe4,
               "Just didn\'t get enough.");
  }
  else if (*param_3 < 0x28) {
    debug_info_real_Recovered
              ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xe7,
               "Did not even get the AFCPacket header");
  }
  else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!strncmp; offline emulation evidence.
                        */
    iVar3 = api_strncmp_180b6df05(auStack_68,"CFA6LPAA",8);
    if (iVar3 != 0) {
      debug_info_real_Recovered
                ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xed,
                 "Invalid AFC packet received (magic != CFA6LPAA)!");
    }
    if (uStack_50 == *(ulonglong *)(param_1[1] + 0x18)) {
      uVar2 = CONCAT44(uStack_54,iStack_58);
      if (uVar2 < 0x28) {
        debug_info_real_Recovered
                  ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xf9,
                   "Invalid AFCPacket header received!");
      }
      else {
        uVar1 = CONCAT44(uStack_5c,iStack_60);
        if ((uVar2 == uVar1) && (uVar1 == 0x28)) {
          debug_info_real_Recovered
                    ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xfd,
                     "Empty AFCPacket received!");
          *param_3 = 0;
        }
        else {
          uStack_78 = uStack_48;
          uStack_88 = uVar1;
          uStack_80 = uVar2;
          debug_info_real_Recovered
                    ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0x106,
                     "received AFC packet, full len=%lld, this len=%lld, operation=0x%llx");
          uVar5 = iStack_60 - 0x28;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
          arg0 = (ulonglong *)api_malloc_1805f8abe((ulonglong)uVar5);
          uVar4 = iStack_58 - 0x28;
          if (uVar4 != 0) {
            uStack_88 = CONCAT44(uStack_88._4_4_,120000);
            service_receive_with_timeout_Recovered(*param_1,arg0,uVar4,param_3);
            if (*param_3 == 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_1805ec38c(arg0);
              debug_info_real_Recovered
                        ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                         0x110,"Did not get packet contents!");
              goto LAB_180002ed1;
            }
            if (*param_3 < uVar4) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_1804333db(arg0);
              uStack_88 = CONCAT44(uStack_88._4_4_,uVar4);
              debug_info_real_Recovered
                        ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                         0x114,"Could not receive this_len=%d bytes");
              goto LAB_180002ed1;
            }
          }
          for (; uVar4 < uVar5; uVar4 = uVar4 + *param_3) {
            uStack_88._4_4_ = (undefined4)(uStack_88 >> 0x20);
            uStack_88 = CONCAT44(uStack_88._4_4_,120000);
            service_receive_with_timeout_Recovered
                      (*param_1,(ulonglong)uVar4 + (longlong)arg0,uVar5 - uVar4,param_3);
            if (*param_3 == 0) {
              uStack_88 = uStack_88 & 0xffffffff00000000;
              debug_info_real_Recovered
                        ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                         0x11f,"Error receiving data (recv returned %d)");
              if (uVar4 < uVar5) {
                uStack_80 = CONCAT44(uStack_80._4_4_,uVar5);
                uStack_88 = CONCAT44(uStack_88._4_4_,uVar4);
                debug_info_real_Recovered
                          ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                           0x125,"WARNING: could not receive full packet (read %s, size %d)");
              }
              break;
            }
          }
          if (7 < uVar4) {
            uVar8 = *arg0;
          }
          uStack_88 = CONCAT44(uStack_88._4_4_,uVar4);
          debug_info_real_Recovered
                    ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0x12d,
                     "packet data size = %i");
          if (uVar4 < 0x101) {
            debug_info_real_Recovered
                      ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                       0x132,"packet data follows");
            uVar5 = uVar4;
          }
          else {
            uStack_88 = CONCAT44(uStack_88._4_4_,uVar4);
            debug_info_real_Recovered
                      ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                       0x12f,"packet data follows (256/%u)");
            uVar5 = 0x100;
          }
          native_180001310(arg0,uVar5);
          if (uStack_48 == 1) {
            uStack_88 = uVar8;
            debug_info_real_Recovered
                      ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                       0x139,"got a status response, code=%lld");
            if (uVar8 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              api_free_1802d80ce(arg0);
              goto LAB_180002ed1;
            }
          }
          else if (uStack_48 == 2) {
            debug_info_real_Recovered
                      ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                       0x143,"got a data response");
          }
          else {
            if (uStack_48 == 0xe) {
              pcVar7 = "got a file handle response, handle=%lld";
              uVar6 = 0x146;
            }
            else {
              if (uStack_48 != 0x13) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                api_free_180132fc9(arg0);
                uStack_88 = uStack_48;
                *param_3 = 0;
                uStack_80 = uVar8;
                debug_info_real_Recovered
                          ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                           0x14f,"WARNING: Unknown operation code received 0x%llx param1=%lld");
                goto LAB_180002ed1;
              }
              pcVar7 = "got a tell response, position=%lld";
              uVar6 = 0x149;
            }
            uStack_88 = uVar8;
            debug_info_real_Recovered
                      ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                       uVar6,pcVar7);
          }
          if (param_2 == (undefined8 *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
            api_free_18054f57d(arg0);
            *param_3 = uVar4;
          }
          else {
            *param_2 = arg0;
            *param_3 = uVar4;
          }
        }
      }
    }
    else {
      uStack_88 = uStack_50;
      uStack_80 = *(ulonglong *)(param_1[1] + 0x18);
      debug_info_real_Recovered
                ("afc_receive_data","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xf3,
                 "ERROR: Unexpected packet number (%lld != %lld) aborting.");
    }
  }
LAB_180002ed1:
  native_18001c0e0(uStack_40 ^ (ulonglong)auStack_a8);
  return;
}

