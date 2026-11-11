/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140001b00(void *param_1,char *param_2,undefined8 *param_3,ulonglong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  void *arg0;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar7;
  ulonglong uVar8;
  int aiStackX_8 [2];
  ulonglong uStack_38;
  longlong *plStack_30;
  ulonglong uVar6;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  if (param_3 == (undefined8 *)0x0) {
    return;
  }
  if (param_4 == (ulonglong *)0x0) {
    return;
  }
  uVar6 = 0;
  plStack_30 = (longlong *)0x0;
  uVar1 = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_get_file_info; offline
                       emulation evidence. */
  api_afc_get_file_info_140206538(param_1,param_2,&plStack_30);
  if (plStack_30 == (longlong *)0x0) {
    return;
  }
  if (*plStack_30 != 0) {
    lVar4 = *plStack_30;
    uVar2 = uVar6;
    uVar8 = uVar6;
    uVar7 = uVar6;
    do {
      while( true ) {
        uVar3 = uVar2 + 1;
        if (*(char *)(lVar4 + uVar2) == "st_size"[uVar2]) break;
        lVar4 = plStack_30[uVar7 + 2];
        uVar7 = uVar7 + 2;
        uVar8 = (ulonglong)((int)uVar8 + 2);
        uVar2 = uVar6;
        if (lVar4 == 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_dictionary_free; offline
                       emulation evidence. */
          api_afc_dictionary_free_1401c7d84(plStack_30);
          return;
        }
      }
      uVar2 = uVar3;
    } while (uVar3 != 8);
                    /* Recovered VMProtect thunk: ucrtbase.dll!atol; offline emulation evidence. */
    uVar1 = api_atol_1401df7ea(plStack_30[(longlong)(int)uVar8 + 1]);
  }
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_dictionary_free; offline
                       emulation evidence. */
  api_afc_dictionary_free_14012fff1(plStack_30);
  if (uVar1 == 0) {
    return;
  }
  uStack_38 = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_open; offline emulation
                       evidence. */
  api_afc_file_open_1400605d3(param_1,param_2,1,&uStack_38);
  if (uStack_38 == 0) {
    return;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  arg0 = api_malloc_1400de406((ulonglong)uVar1);
  if (uVar1 != 0) {
    do {
      uVar5 = (uint)uVar6;
      aiStackX_8[0] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_read; offline emulation
                       evidence. */
      api_afc_file_read_1400dd5fd(param_1,uStack_38,uVar6 + (longlong)arg0,0x10000,aiStackX_8);
      if (aiStackX_8[0] == 0) break;
      uVar5 = uVar5 + aiStackX_8[0];
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar1);
    if (uVar5 == uVar1) {
      *param_4 = (ulonglong)uVar1;
      *param_3 = arg0;
      goto LAB_140001c7e;
    }
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_1401c6235(arg0);
LAB_140001c7e:
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_close; offline
                       emulation evidence. */
  api_afc_file_close_1401af635(param_1,uStack_38);
  return;
}

