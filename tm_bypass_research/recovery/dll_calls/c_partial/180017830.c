/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180017830(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  void *pvStackX_8;
  
  plVar1 = (longlong *)*param_1;
  do {
    if ((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) goto LAB_1800178ab;
    pvStackX_8 = (void *)0x0;
    iVar2 = preboard_receive_with_timeout_Recovered(plVar1,&pvStackX_8,1000);
    if (iVar2 != -6) {
      if (iVar2 != 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        api_plist_free_1802f4a83(pvStackX_8);
        (*(code *)param_1[1])(0,param_1[2]);
LAB_1800178ab:
        debug_info_real_Recovered
                  ("preboard_receive_status_loop_thread",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\preboard.c",0xb0,
                   "done, cleaning up.");
        if (*(longlong *)(*param_1 + 8) != 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!CloseHandle; offline emulation
                       evidence. */
          api_CloseHandle_1804a384c();
          *(undefined8 *)(*param_1 + 8) = 0;
        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_1803de815(param_1);
        return 0;
      }
      (*(code *)param_1[1])(pvStackX_8,param_1[2]);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_1809b7533(pvStackX_8);
    }
    plVar1 = (longlong *)*param_1;
  } while( true );
}

