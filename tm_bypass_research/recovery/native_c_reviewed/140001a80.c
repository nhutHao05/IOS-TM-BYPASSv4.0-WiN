/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void HandleNotificationRecovered
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (*(char *)(param_1 + lVar4) != '\0');
  if (lVar4 != 0) {
    iVar1 = func_0x000140006c17(param_1,"com.apple.itunes-client.syncCancelRequest");
    if (iVar1 == 0) {
      PrintMessageRecovered("User has cancelled the backup process on the device.\n");
      _DAT_14000b734 = _DAT_14000b734 + 1;
      return;
    }
    iVar1 = func_0x000140006c17(param_1,"com.apple.mobile.backup.domain_changed");
    if (iVar1 != 0) {
      lStackX_10 = param_1;
      uStackX_18 = param_3;
      uStackX_20 = param_4;
      uVar2 = api___acrt_iob_func_1401bd22d(1);
      puVar3 = (undefined8 *)native_140001000();
      api___stdio_common_vfprintf_14009de07
                (*puVar3,uVar2,"Unhandled notification \'%s\' (TODO: implement)\n",0,&lStackX_10);
      return;
    }
  }
  return;
}

