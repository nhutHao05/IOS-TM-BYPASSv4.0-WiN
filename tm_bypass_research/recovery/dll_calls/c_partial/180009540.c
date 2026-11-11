/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_180009540(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    LOCK();
    UNLOCK();
    if (_DAT_18002c950 != 0) {
      do {
        _DAT_18002c950 = 1;
                    /* Recovered VMProtect thunk: kernel32.dll!Sleep; offline emulation evidence. */
        api_Sleep_1801d50ce(1);
        LOCK();
        UNLOCK();
      } while (_DAT_18002c950 != 0);
    }
    if (_DAT_18002c954 == 0) {
      _DAT_18002c954 = 1;
    }
    LOCK();
    _DAT_18002c950 = 0;
    UNLOCK();
  }
  else if (param_2 == 1) {
    LOCK();
    UNLOCK();
    if (_DAT_18002c940 != 0) {
      do {
        _DAT_18002c940 = 1;
                    /* Recovered VMProtect thunk: kernel32.dll!Sleep; offline emulation evidence. */
        api_Sleep_18021d3b7(1);
        LOCK();
        UNLOCK();
      } while (_DAT_18002c940 != 0);
    }
    if (_DAT_18002c944 == 0) {
      _DAT_18002c944 = 1;
    }
    LOCK();
    _DAT_18002c940 = 0;
    UNLOCK();
    return 1;
  }
  return 1;
}

