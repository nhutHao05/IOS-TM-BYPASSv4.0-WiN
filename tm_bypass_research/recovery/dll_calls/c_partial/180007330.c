/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180007330(longlong *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *arg0;
  void *pvVar3;
  undefined8 uVar4;
  
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  if ((((param_1 != (longlong *)0x0) && (*param_1 != 0)) && (param_2 != (void *)0x0)) &&
     (iVar1 = api_plist_get_node_type_1808fba13(param_2), iVar1 == 5)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_array; offline emulation
                       evidence. */
    arg0 = api_plist_new_array_18017ef63();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    pvVar3 = api_plist_new_string_18031636e("DLMessageProcessMessage");
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
    api_plist_array_append_item_180607cf4(arg0,pvVar3);
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    pvVar3 = (void *)api_plist_copy_180589fa2(param_2);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
    api_plist_array_append_item_180b11953(arg0,pvVar3);
    uVar2 = native_180017ce0(*param_1,arg0,1);
    switch(uVar2) {
    case 0:
      uVar4 = 0;
      break;
    case 0xfffffffb:
      uVar4 = 0xfffffffb;
      break;
    case 0xfffffffc:
      uVar4 = 0xfffffffc;
      break;
    case 0xfffffffd:
      uVar4 = 0xfffffffd;
      break;
    case 0xfffffffe:
      uVar4 = 0xfffffffe;
      break;
    case 0xffffffff:
      uVar4 = 0xffffffff;
      break;
    default:
      uVar4 = 0xffffff00;
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    api_plist_free_1806f70b7(arg0);
    return uVar4;
  }
  return 0xffffffff;
}

