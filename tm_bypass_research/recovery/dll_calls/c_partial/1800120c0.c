/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

int native_1800120c0(longlong *param_1,char *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *arg0;
  void *arg2;
  
  if (param_1 == (longlong *)0x0) {
    return -1;
  }
  if (*param_1 == 0) {
    return -1;
  }
  if (param_2 == (char *)0x0) {
    if (param_3 == (void *)0x0) {
      return -1;
    }
LAB_180012115:
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    iVar1 = api_plist_get_node_type_180bd395f(param_3);
    if (iVar1 != 5) {
      return -1;
    }
    if (param_2 == (char *)0x0) {
      uVar2 = native_180007330(*param_1,param_3);
      switch(uVar2) {
      case 0:
        return 0;
      case 0xfffffffa:
        iVar1 = -6;
        break;
      case 0xfffffffb:
        iVar1 = -5;
        break;
      case 0xfffffffc:
        iVar1 = -4;
        break;
      case 0xfffffffd:
        iVar1 = -3;
        break;
      case 0xfffffffe:
        iVar1 = -2;
        break;
      case 0xffffffff:
        iVar1 = -1;
        break;
      default:
        iVar1 = -0x100;
      }
      goto LAB_180012239;
    }
    if (param_3 == (void *)0x0) goto code_r0x0001800121ad;
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    arg0 = (void *)api_plist_copy_180b4482f(param_3);
  }
  else {
    if (param_3 != (void *)0x0) goto LAB_180012115;
code_r0x0001800121ad:
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    arg0 = api_plist_new_dict_180c13aeb();
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
  arg2 = api_plist_new_string_18064d941(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
  api_plist_dict_set_item_180783ca8(arg0,"BackupMessageTypeKey",arg2);
  uVar2 = native_180007330(*param_1,arg0);
  switch(uVar2) {
  case 0:
    iVar1 = 0;
    break;
  case 0xfffffffa:
    iVar1 = -6;
    break;
  case 0xfffffffb:
    iVar1 = -5;
    break;
  case 0xfffffffc:
    iVar1 = -4;
    break;
  case 0xfffffffd:
    iVar1 = -3;
    break;
  case 0xfffffffe:
    iVar1 = -2;
    break;
  case 0xffffffff:
    iVar1 = -1;
    break;
  default:
    iVar1 = -0x100;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_180a8a8f6(arg0);
  if (iVar1 == 0) {
    return 0;
  }
LAB_180012239:
  debug_info_real_Recovered
            ("mobilebackup_send_message",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\mobilebackup.c",0xac,
             "ERROR: Could not send message \'%s\' (%d)!",param_2,iVar1);
  return iVar1;
}

