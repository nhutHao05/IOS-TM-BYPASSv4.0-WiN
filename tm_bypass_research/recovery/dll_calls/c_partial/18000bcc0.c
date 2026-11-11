/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_18000bcc0(longlong *param_1)

{
  longlong lVar1;
  
  native_18000b830(*param_1,param_1[1],param_1[2],param_1[3]);
  lVar1 = *param_1;
  debug_info_real_Recovered
            ("instproxy_lock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",
             0xbf,"Locked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlEnterCriticalSection; offline
                       emulation evidence. */
  api_RtlEnterCriticalSection_1800aaa73(lVar1 + 8);
  debug_info_real_Recovered
            ("instproxy_receive_status_loop_thread",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c",0x1ad,
             "done, cleaning up.");
  if ((void *)param_1[1] != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_1805b8b82((void *)param_1[1]);
  }
  lVar1 = *param_1;
  if (*(longlong *)(lVar1 + 0x30) != 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!CloseHandle; offline emulation
                       evidence. */
    api_CloseHandle_1806a98a9();
    *(undefined8 *)(*param_1 + 0x30) = 0;
    lVar1 = *param_1;
  }
  debug_info_real_Recovered
            ("instproxy_unlock","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\installation_proxy.c"
             ,0xca,"Unlocked");
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLeaveCriticalSection; offline
                       emulation evidence. */
  api_RtlLeaveCriticalSection_1803190b9(lVar1 + 8);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_18075b95d(param_1);
  return 0;
}

