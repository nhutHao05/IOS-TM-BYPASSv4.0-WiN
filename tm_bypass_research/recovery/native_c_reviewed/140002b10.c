/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

bool CheckFinishedSnapshotRecovered(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  void *pvVar2;
  bool bVar3;
  void *pvStackX_18;
  void *pvStackX_20;
  
  bVar3 = false;
  pvStackX_18 = (void *)0x0;
  pvVar2 = (void *)native_1400010c0(param_1,param_2,"Status.plist",0);
  native_1400013c0(&pvStackX_18,pvVar2);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_1400a5298(pvVar2);
  if (pvStackX_18 == (void *)0x0) {
    PrintMessageRecovered("Could not read Status.plist!\n");
    return false;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  pvVar2 = api_plist_dict_get_item_140219d1d(pvStackX_18,"SnapshotState");
  if (pvVar2 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    iVar1 = api_plist_get_node_type_1400c9e31(pvVar2);
    if (iVar1 == 3) {
      pvStackX_20 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
      api_plist_get_string_val_1400ef604(pvVar2,&pvStackX_20);
      pvVar2 = pvStackX_20;
      if (pvStackX_20 != (void *)0x0) {
        iVar1 = func_0x000140006c17(pvStackX_20,"finished");
        bVar3 = iVar1 == 0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_1400a396e(pvVar2);
      }
      goto LAB_140002be4;
    }
  }
  PrintMessageRecovered
            ("%s: ERROR could not get SnapshotState key from Status.plist!\n",
             "mb2_status_check_snapshot_state");
LAB_140002be4:
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  api_plist_free_140114c96(pvStackX_18);
  return bVar3;
}

