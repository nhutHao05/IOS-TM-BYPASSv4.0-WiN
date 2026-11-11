/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18000c290(undefined8 param_1,void *param_2,undefined8 *param_3)

{
  void *pvVar1;
  undefined8 uVar2;
  
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar1 = api_plist_dict_get_item_1801620f2(param_2,"LookupResult");
  if (pvVar1 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_copy; offline emulation evidence.
                        */
    uVar2 = api_plist_copy_1808cf5ed(pvVar1);
    *param_3 = uVar2;
  }
  return;
}

