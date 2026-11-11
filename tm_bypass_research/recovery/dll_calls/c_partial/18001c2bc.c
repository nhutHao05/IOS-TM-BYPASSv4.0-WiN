/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18001c2bc(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uStackX_8;
  undefined1 auStackX_10 [8];
  undefined1 auStackX_18 [8];
  
                    /* Recovered VMProtect thunk: kernel32.dll!RtlCaptureContext; offline emulation
                       evidence. */
  api_RtlCaptureContext_1805e5b15();
  uVar1 = *(undefined8 *)(param_1 + 0xf8);
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLookupFunctionEntry; offline
                       emulation evidence. */
  lVar2 = api_RtlLookupFunctionEntry_1804256eb(uVar1,&uStackX_8,0);
  if (lVar2 != 0) {
                    /* Recovered VMProtect thunk: ntdll.dll!RtlVirtualUnwind; offline emulation
                       evidence. */
    api_RtlVirtualUnwind_18035cf63(0,uStackX_8,uVar1,lVar2,param_1,auStackX_18,auStackX_10,0);
  }
  return;
}

