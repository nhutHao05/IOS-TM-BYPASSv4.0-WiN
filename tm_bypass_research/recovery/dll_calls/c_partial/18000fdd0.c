/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18000fdd0(undefined8 *param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  void *pvVar4;
  undefined1 auStack_58 [32];
  void *pvStack_38;
  void *pvStack_30;
  undefined1 auStack_28 [8];
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_58;
  if (((param_1 != (undefined8 *)0x0) && (param_2 != 0)) && (param_4 != (longlong *)0x0)) {
    if ((undefined2 *)*param_4 != (undefined2 *)0x0) {
      *(undefined2 *)*param_4 = 0;
      *(undefined1 *)(*param_4 + 2) = 0;
    }
    pvStack_38 = (void *)0x0;
    iVar1 = native_18000fba0();
    if (iVar1 == 0) {
      iVar1 = lockdownd_send_Recovered(param_1,pvStack_38);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      api_plist_free_180146bda(pvStack_38);
      pvStack_38 = (void *)0x0;
      if (iVar1 == 0) {
        uVar2 = native_180018050(*param_1,&pvStack_38,60000);
        switch(uVar2) {
        case 0:
          if (pvStack_38 != (void *)0x0) {
            iVar1 = native_18000d390(pvStack_38,"StartService");
            if (iVar1 == 0) {
              puVar3 = (undefined2 *)*param_4;
              if (puVar3 == (undefined2 *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
                puVar3 = (undefined2 *)api_malloc_1803a5565(4);
                *param_4 = (longlong)puVar3;
              }
              *puVar3 = 0;
              *(undefined1 *)(*param_4 + 2) = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
              pvVar4 = api_plist_dict_get_item_180ca30c1(pvStack_38,"Port");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
              if ((pvVar4 != (void *)0x0) &&
                 (iVar1 = api_plist_get_node_type_1809da275(pvVar4), iVar1 == 1)) {
                pvStack_30 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
                api_plist_get_uint_val_180388a65(pvVar4,&pvStack_30);
                if ((pvStack_30 != (void *)0x0) && ((short)pvStack_30 != 0)) {
                  *(short *)*param_4 = (short)pvStack_30;
                }
              }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
              pvVar4 = api_plist_dict_get_item_1801b610f(pvStack_38,"EnableServiceSSL");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
              if ((pvVar4 != (void *)0x0) &&
                 (iVar1 = api_plist_get_node_type_180aff1dd(pvVar4), iVar1 == 0)) {
                auStack_28[0] = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_bool_val; offline emulation
                       evidence. */
                api_plist_get_bool_val_18076eb65(pvVar4,auStack_28);
                *(undefined1 *)(*param_4 + 2) = auStack_28[0];
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
                api_plist_free_180c96ef5(pvStack_38);
                break;
              }
            }
            else {
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
              pvVar4 = api_plist_dict_get_item_180c507a3(pvStack_38,"Error");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
              if ((pvVar4 != (void *)0x0) &&
                 (iVar1 = api_plist_get_node_type_18043db6f(pvVar4), iVar1 == 3)) {
                pvStack_30 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                api_plist_get_string_val_1803452f9(pvVar4,&pvStack_30);
                native_18000d300(pvStack_30);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                api_free_180c6fa30(pvStack_30);
              }
            }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
            api_plist_free_1808c1f63(pvStack_38);
            break;
          }
        case 0xfffffffe:
          break;
        case 0xfffffffb:
          break;
        case 0xfffffffc:
          break;
        case 0xfffffffd:
          break;
        case 0xffffffff:
        }
      }
    }
  }
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_58);
  return;
}

