/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18001cb20(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined8 unaff_retaddr;
  undefined8 uStackX_10;
  undefined1 auStackX_18 [8];
  undefined1 auStackX_20 [8];
  undefined1 auStack_5c8 [8];
  undefined1 auStack_5c0 [232];
  undefined1 auStack_4d8 [152];
  undefined1 *puStack_440;
  undefined8 uStack_3e0;
  
  puVar5 = auStack_5c8;
                    /* Recovered VMProtect thunk: kernel32.dll!IsProcessorFeaturePresent; offline
                       emulation evidence. */
  iVar2 = api_IsProcessorFeaturePresent_1801b6d98(0x17);
  if (iVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(param_1);
    puVar5 = auStack_5c0;
  }
  *(undefined8 *)(puVar5 + -8) = 0x18001cb54;
  func_0x00018001cb18(3);
  *(undefined8 *)(puVar5 + -8) = 0x18001cb65;
  func_0x00018001ceac(auStack_4d8,0,0x4d0);
                    /* Recovered VMProtect thunk: kernel32.dll!RtlCaptureContext; offline emulation
                       evidence. */
  *(undefined8 *)(puVar5 + -8) = 0x18001cb6f;
  api_RtlCaptureContext_1801b2268(auStack_4d8);
                    /* Recovered VMProtect thunk: ntdll.dll!RtlLookupFunctionEntry; offline
                       emulation evidence. */
  *(undefined8 *)(puVar5 + -8) = 0x18001cb88;
  lVar4 = api_RtlLookupFunctionEntry_180aa503b(uStack_3e0,&uStackX_10,0);
  if (lVar4 != 0) {
    *(undefined8 *)(puVar5 + 0x38) = 0;
    *(undefined1 **)(puVar5 + 0x30) = auStackX_18;
    *(undefined1 **)(puVar5 + 0x28) = auStackX_20;
    *(undefined1 **)(puVar5 + 0x20) = auStack_4d8;
                    /* Recovered VMProtect thunk: ntdll.dll!RtlVirtualUnwind; offline emulation
                       evidence. */
    *(undefined8 *)(puVar5 + -8) = 0x18001cbca;
    api_RtlVirtualUnwind_180bc8ba8(0,uStackX_10,uStack_3e0,lVar4);
  }
  puStack_440 = &stack0x00000008;
  *(undefined8 *)(puVar5 + -8) = 0x18001cbfc;
  func_0x00018001ceac(puVar5 + 0x50,0,0x98);
  *(undefined8 *)(puVar5 + 0x60) = unaff_retaddr;
  *(undefined4 *)(puVar5 + 0x50) = 0x40000015;
  *(undefined4 *)(puVar5 + 0x54) = 1;
                    /* Recovered VMProtect thunk: kernel32.dll!IsDebuggerPresent; offline emulation
                       evidence. */
  *(undefined8 *)(puVar5 + -8) = 0x18001cc1e;
  iVar2 = api_IsDebuggerPresent_1801b6102();
  *(undefined1 **)(puVar5 + 0x40) = puVar5 + 0x50;
  *(undefined1 **)(puVar5 + 0x48) = auStack_4d8;
                    /* Recovered VMProtect thunk: kernel32.dll!SetUnhandledExceptionFilter; offline
                       emulation evidence. */
  *(undefined8 *)(puVar5 + -8) = 0x18001cc3f;
  api_SetUnhandledExceptionFilter_1803c19b7(0);
                    /* Recovered VMProtect thunk: kernel32.dll!UnhandledExceptionFilter; offline
                       emulation evidence. */
  *(undefined8 *)(puVar5 + -8) = 0x18001cc49;
  iVar3 = api_UnhandledExceptionFilter_18032c7ce(puVar5 + 0x40);
  if ((iVar3 == 0) && (iVar2 != 1)) {
    *(undefined8 *)(puVar5 + -8) = 0x18001cc5a;
    func_0x00018001cb18(3);
  }
  return;
}

