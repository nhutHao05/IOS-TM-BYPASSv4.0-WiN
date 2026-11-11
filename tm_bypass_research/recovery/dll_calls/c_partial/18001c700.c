/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c700(void)

{
  uint uVar1;
  ulonglong uStackX_8;
  ulonglong uStackX_10;
  uint uStackX_18;
  undefined4 uStackX_1c;
  
  if (_DAT_18002c008 == 0x2b992ddfa232) {
    uStackX_10 = 0;
                    /* Recovered VMProtect thunk: kernel32.dll!GetSystemTimeAsFileTime; offline
                       emulation evidence. */
    api_GetSystemTimeAsFileTime_180c0a56e(&uStackX_10);
    uStackX_8 = uStackX_10;
                    /* Recovered VMProtect thunk: kernel32.dll!GetCurrentThreadId; offline emulation
                       evidence. */
    uVar1 = api_GetCurrentThreadId_1806d0cf2();
    uStackX_8 = uStackX_8 ^ uVar1;
                    /* Recovered VMProtect thunk: kernel32.dll!GetCurrentProcessId; offline
                       emulation evidence. */
    uVar1 = api_GetCurrentProcessId_1805ef75d();
    uStackX_8 = uStackX_8 ^ uVar1;
                    /* Recovered VMProtect thunk: kernel32.dll!QueryPerformanceCounter; offline
                       emulation evidence. */
    api_QueryPerformanceCounter_1805bb164(&uStackX_18);
    _DAT_18002c008 =
         ((ulonglong)uStackX_18 << 0x20 ^ CONCAT44(uStackX_1c,uStackX_18) ^ uStackX_8 ^
         (ulonglong)&uStackX_8) & 0xffffffffffff;
    if (_DAT_18002c008 == 0x2b992ddfa232) {
      _DAT_18002c008 = 0x2b992ddfa233;
    }
  }
  _DAT_18002c000 = ~_DAT_18002c008;
  return;
}

