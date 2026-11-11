/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18001c32c(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uStackX_8;
  undefined1 auStackX_10 [8];
  undefined1 auStackX_18 [16];
  
                    /* Recovered VMProtect thunk: kernel32.dll!RtlCaptureContext; offline emulation
                       evidence. */
  api_RtlCaptureContext_1800c5cfd();
  uVar1 = *(undefined8 *)(param_1 + 0xf8);
  iVar3 = 0;
  do {
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLookupFunctionEntry; offline
                       emulation evidence. */
    lVar2 = api_RtlLookupFunctionEntry_180a5c066(uVar1,&uStackX_8,0);
    if (lVar2 == 0) {
      return;
    }
                    /* Recovered VMProtect thunk: ntdll.dll!RtlVirtualUnwind; offline emulation
                       evidence. */
    api_RtlVirtualUnwind_180a3e78b(0,uStackX_8,uVar1,lVar2,param_1,auStackX_18,auStackX_10,0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}

