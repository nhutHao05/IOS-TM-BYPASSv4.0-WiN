/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800122b0(longlong *param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  char cVar2;
  void *arg0;
  undefined4 uVar3;
  void *arg0_00;
  char *pcVar4;
  longlong lVar5;
  undefined1 auStack_68 [32];
  longlong lStack_48;
  void *pvStack_38;
  char *pcStack_30;
  ulonglong uStack_28;
  
  uStack_28 = _DAT_18002c008 ^ (ulonglong)auStack_68;
  if (((param_1 == (longlong *)0x0) || (lVar5 = *param_1, lVar5 == 0)) || (param_2 == 0))
  goto LAB_18001245c;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
    lVar5 = *param_1;
  }
  pvStack_38 = (void *)0x0;
  uVar3 = native_180007450(lVar5,&pvStack_38);
  arg0 = pvStack_38;
  switch(uVar3) {
  case 0:
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
    arg0_00 = api_plist_dict_get_item_1808f85f9(pvStack_38,"BackupMessageTypeKey");
    if (arg0_00 == (void *)0x0) {
      debug_info_real_Recovered
                ("mobilebackup_receive_message",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobilebackup.c",0xd7,
                 "ERROR: BackupMessageTypeKey not found in plist!");
      goto code_r0x00018001239f;
    }
    pcStack_30 = (char *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
    api_plist_get_string_val_180108586(arg0_00,&pcStack_30);
    if (pcStack_30 == (char *)0x0) {
code_r0x0001800123e7:
      lStack_48 = param_2;
      debug_info_real_Recovered
                ("mobilebackup_receive_message",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobilebackup.c",0xe1,
                 "ERROR: BackupMessageTypeKey value does not match \'%s\'!");
    }
    else {
      pcVar4 = pcStack_30;
      do {
        cVar1 = *pcVar4;
        cVar2 = pcVar4[param_2 - (longlong)pcStack_30];
        if (cVar1 != cVar2) break;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      if (cVar1 != cVar2) goto code_r0x0001800123e7;
    }
    if (pcStack_30 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_18085fc51(pcStack_30);
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = arg0;
      goto LAB_18001245c;
    }
    break;
  case 0xfffffffa:
    break;
  case 0xfffffffb:
    break;
  case 0xfffffffc:
    break;
  case 0xfffffffd:
    break;
  case 0xfffffffe:
code_r0x00018001239f:
    break;
  case 0xffffffff:
  }
  if (arg0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_180b0eafa(arg0);
  }
LAB_18001245c:
  native_18001c0e0(uStack_28 ^ (ulonglong)auStack_68);
  return;
}

