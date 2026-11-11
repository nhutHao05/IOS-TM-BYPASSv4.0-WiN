/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180011350(void *param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined4 auStack_28 [2];
  void *pvStack_20;
  ulonglong uStack_18;
  
  uStack_18 = _DAT_18002c008 ^ (ulonglong)auStack_48;
  if (param_1 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    iVar1 = api_plist_get_node_type_18064caf4(param_1);
    if (iVar1 == 7) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
      api_plist_copy_1807c95c9(param_1);
      native_18001c0e0(uStack_18 ^ (ulonglong)auStack_48);
      return;
    }
  }
  pvStack_20 = (void *)0x0;
  auStack_28[0] = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_to_xml; offline emulation
                       evidence. */
  api_plist_to_xml_180c97ee1(param_1,&pvStack_20,auStack_28);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
  api_plist_new_data_180b89940(pvStack_20,auStack_28[0]);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180526f61(pvStack_20);
  native_18001c0e0(uStack_18 ^ (ulonglong)auStack_48);
  return;
}

