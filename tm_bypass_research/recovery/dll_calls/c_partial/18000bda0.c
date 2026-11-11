/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8
native_18000bda0(longlong *param_1,longlong param_2,int param_3,undefined8 param_4,
                undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  if (((param_1 == (longlong *)0x0) || (*param_1 == 0)) || (param_2 == 0)) {
    return 0xffffffff;
  }
  if (param_1[6] != 0) {
    return 0xfffffffc;
  }
  debug_info_real_Recovered
            ("instproxy_lock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",
             0xbf,"Locked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlEnterCriticalSection; offline
                       emulation evidence. */
  api_RtlEnterCriticalSection_18008e422(param_1 + 1);
  iVar1 = native_180017ce0(*param_1,param_2,0);
  uVar6 = 0xffffff00;
  if (iVar1 == -5) {
    uVar2 = 0xfffffffa;
  }
  else if (iVar1 == -3) {
    uVar2 = 0xfffffffd;
  }
  else if (iVar1 == -2) {
    uVar2 = 0xfffffffe;
  }
  else if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if (iVar1 == 0) goto LAB_18000be95;
    uVar2 = 0xffffff00;
  }
  debug_info_real_Recovered
            ("instproxy_send_command",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",299,
             "could not send command plist, error %d",uVar2);
LAB_18000be95:
  debug_info_real_Recovered
            ("instproxy_unlock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c"
             ,0xca,"Unlocked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLeaveCriticalSection; offline
                       emulation evidence. */
  api_RtlLeaveCriticalSection_180a6c52c(param_1 + 1);
  if (*param_1 == 0) {
    uVar6 = 0xffffffff;
  }
  else if (param_1[6] == 0) {
    if (param_3 == 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
      puVar3 = (undefined8 *)api_malloc_1801e3cd3(0x20);
      if (puVar3 != (undefined8 *)0x0) {
        *puVar3 = param_1;
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
        uVar4 = api_plist_copy_18047d14e(param_2);
        puVar3[3] = param_5;
        puVar3[1] = uVar4;
        puVar3[2] = param_4;
                    /* Recovered VMProtect thunk: kernel32.dll!CreateThread; offline emulation
                       evidence. */
        lVar5 = api_CreateThread_1802df076(0,0,native_18000bcc0,puVar3,0,0);
        if (lVar5 != 0) {
          uVar6 = 0;
          param_1[6] = lVar5;
        }
      }
    }
    else {
      uVar6 = native_18000b830(param_1,param_2,param_4,param_5);
    }
  }
  else {
    uVar6 = 0xfffffffc;
  }
  return uVar6;
}

