/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_140001f50(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puStackX_10;
  undefined8 *apuStackX_18 [2];
  
  uVar5 = 0;
  puStackX_10 = (undefined8 *)0x0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  apuStackX_18[0] = (undefined8 *)api_malloc_1400a6b88(0x10);
  if (apuStackX_18[0] != (undefined8 *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
    uVar4 = api__mbsdup_14008c3b9(param_1);
    apuStackX_18[0][1] = 0;
    *apuStackX_18[0] = uVar4;
    native_140001e10(param_1,&puStackX_10,apuStackX_18);
    puVar2 = puStackX_10;
    while (puVar1 = apuStackX_18[0], puVar2 != (undefined8 *)0x0) {
      uVar5 = 0;
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
      iVar3 = api_DeleteFileA_1400a646d(*puVar2);
      if (iVar3 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
        iVar3 = api_GetLastError_1401d506d();
        if (iVar3 == 2) {
          uVar5 = 2;
        }
        else {
          uVar5 = 0x11;
          if (iVar3 != 0xb7) {
            uVar5 = 0xe;
          }
        }
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1401d0638((void *)*puVar2);
      puVar1 = (undefined8 *)puVar2[1];
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1401adef3(puVar2);
      puVar2 = puVar1;
    }
    while (puVar1 != (undefined8 *)0x0) {
      uVar5 = 0;
                    /* Recovered VMProtect thunk: kernel32.dll!RemoveDirectoryA; offline emulation
                       evidence. */
      iVar3 = api_RemoveDirectoryA_1401f0963(*puVar1);
      if (iVar3 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
        iVar3 = api_GetLastError_1400c4508();
        if (iVar3 == 2) {
          uVar5 = 2;
        }
        else {
          uVar5 = 0x11;
          if (iVar3 != 0xb7) {
            uVar5 = 0xe;
          }
        }
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1401e636b((void *)*puVar1);
      puVar2 = (undefined8 *)puVar1[1];
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_1401d7bcf(puVar1);
      puVar1 = puVar2;
    }
    return uVar5;
  }
  return 0xc;
}

