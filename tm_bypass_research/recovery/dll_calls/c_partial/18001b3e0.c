/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001b3e0(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStack_48 [32];
  undefined4 uStack_28;
  int iStack_18;
  char acStack_14 [4];
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_48;
  if (param_1 != (undefined8 *)0x0) {
    debug_info_real_Recovered
              ("syslog_relay_worker","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\syslog_relay.c",
               0x95,"Running");
    plVar1 = (longlong *)*param_1;
    lVar2 = *plVar1;
    while (lVar2 != 0) {
      iStack_18 = 0;
      uStack_28 = 100;
      iVar3 = syslog_relay_receive_with_timeout_Recovered(plVar1,acStack_14,1,&iStack_18);
      if ((1 < iVar3 + 5U) && ((iStack_18 != 0 || (iVar3 != 0)))) {
        if (iVar3 < 0) {
          debug_info_real_Recovered
                    ("syslog_relay_worker",
                     "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\syslog_relay.c",0x9e,
                     "Connection to syslog relay interrupted");
          break;
        }
        if ((*(int *)(param_1 + 3) != 0) || (acStack_14[0] != '\0')) {
          (*(code *)param_1[1])(acStack_14[0],param_1[2]);
        }
      }
      plVar1 = (longlong *)*param_1;
      lVar2 = *plVar1;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_18090d531(param_1);
    debug_info_real_Recovered
              ("syslog_relay_worker","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\syslog_relay.c",
               0xae,"Exiting");
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_48);
  return;
}

