/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined4 native_180007230(undefined8 *param_1,char *param_2)

{
  undefined4 uVar1;
  void *arg0;
  void *pvVar2;
  
  if (param_1 != (undefined8 *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_array; offline emulation
                       evidence. */
    arg0 = api_plist_new_array_1802efceb();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar2 = api_plist_new_string_18022baa0("DLMessageDisconnect");
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
    api_plist_array_append_item_18046f9c3(arg0,pvVar2);
    if (param_2 == (char *)0x0) {
      param_2 = "___EmptyParameterString___";
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar2 = api_plist_new_string_180b440fe(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
    api_plist_array_append_item_18029e67b(arg0,pvVar2);
    uVar1 = native_180017ce0(*param_1,arg0,1);
    switch(uVar1) {
    case 0:
      uVar1 = 0;
      break;
    case 0xfffffffb:
      uVar1 = 0xfffffffb;
      break;
    case 0xfffffffc:
      uVar1 = 0xfffffffc;
      break;
    case 0xfffffffd:
      uVar1 = 0xfffffffd;
      break;
    case 0xfffffffe:
      uVar1 = 0xfffffffe;
      break;
    case 0xffffffff:
      uVar1 = 0xffffffff;
      break;
    default:
      uVar1 = 0xffffff00;
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_1805f0a6d(arg0);
    return uVar1;
  }
  return 0xffffffff;
}

