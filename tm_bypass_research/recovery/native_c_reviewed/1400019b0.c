/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

ulonglong native_1400019b0(void *param_1)

{
  void *arg0;
  ulonglong uVar1;
  
  if (param_1 != (void *)0x0) {
    arg0 = *(void **)((longlong)param_1 + 0x128);
    if (arg0 == (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
      api__set_errno_140063ae5(9);
      uVar1 = 0xffffffffffffffff;
    }
    else {
      if (*(longlong *)((longlong)arg0 + 0x480) != -1) {
                    /* Recovered VMProtect thunk: kernel32.dll!FindClose; offline emulation
                       evidence. */
        api_FindClose_1400bb703();
        *(undefined8 *)((longlong)arg0 + 0x480) = 0xffffffffffffffff;
      }
      if (*(void **)((longlong)arg0 + 0x488) != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        api_free_140168b5e(*(void **)((longlong)arg0 + 0x488));
        *(undefined8 *)((longlong)arg0 + 0x488) = 0;
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_140100d07(arg0);
      uVar1 = 0;
    }
    *(undefined8 *)((longlong)param_1 + 0x128) = 0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_140155a70(param_1);
    return uVar1 & 0xffffffff;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
  api__set_errno_14018a08f(9);
  return 0xffffffffffffffff;
}

