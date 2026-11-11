/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180006bc0(void *param_1,longlong *param_2)

{
  int iVar1;
  void *arg0;
  ulonglong uVar2;
  undefined1 auStack_38 [32];
  void *pvStack_18;
  ulonglong uStack_10;
  
  uStack_10 = _DAT_18002c008 ^ (ulonglong)auStack_38;
  pvStack_18 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
  iVar1 = api_plist_get_node_type_180074240(param_1);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
  if ((((iVar1 == 4) && (iVar1 = api_plist_array_get_size_1805a9226(param_1), iVar1 != 0)) &&
      (arg0 = api_plist_array_get_item_180171824(param_1,0), arg0 != (void *)0x0)) &&
     ((iVar1 = api_plist_get_node_type_1804bd018(arg0), iVar1 == 3 &&
      (api_plist_get_string_val_18016a49f(arg0,&pvStack_18), pvStack_18 != (void *)0x0)))) {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(char *)((longlong)pvStack_18 + uVar2) != '\0');
                    /* Recovered VMProtect thunk: ucrtbase.dll!strncmp; offline emulation evidence.
                        */
    if ((uVar2 < 9) || (iVar1 = api_strncmp_1805e8b67(pvStack_18,&UNK_18001f67c,2), iVar1 != 0)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1802ceb62(pvStack_18);
    }
    else if (param_2 != (longlong *)0x0) {
      *param_2 = (longlong)pvStack_18;
    }
  }
  native_18001c0e0(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

