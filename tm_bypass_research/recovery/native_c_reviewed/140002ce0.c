/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LogDeviceLinkOperationRecovered(void *param_1,undefined8 param_2)

{
  int iVar1;
  void *pvVar2;
  double adStackX_18 [2];
  
  adStackX_18[0] = 0.0;
  iVar1 = func_0x000140006c17(param_2,"DLMessageDownloadFiles");
  if (iVar1 != 0) {
    iVar1 = func_0x000140006c17(param_2,"DLMessageUploadFiles");
    if (iVar1 == 0) {
      iVar1 = 2;
      goto LAB_140002d7a;
    }
    iVar1 = func_0x000140006c17(param_2,"DLMessageMoveFiles");
    if ((((iVar1 != 0) && (iVar1 = func_0x000140006c17(param_2,"DLMessageMoveItems"), iVar1 != 0))
        && (iVar1 = func_0x000140006c17(param_2,"DLMessageRemoveFiles"), iVar1 != 0)) &&
       (iVar1 = func_0x000140006c17(param_2,"DLMessageRemoveItems"), iVar1 != 0)) {
      return;
    }
  }
  iVar1 = 3;
LAB_140002d7a:
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
  pvVar2 = api_plist_array_get_item_140082884(param_1,iVar1);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_real_val; offline emulation
                       evidence. */
  if ((pvVar2 != (void *)0x0) &&
     (api_plist_get_real_val_140141753(pvVar2,adStackX_18), 0.0 < adStackX_18[0])) {
    _DAT_14000b738 = adStackX_18[0];
  }
  return;
}

