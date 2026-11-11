/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c104(undefined8 param_1)

{
                    /* Recovered VMProtect thunk: kernel32.dll!SetUnhandledExceptionFilter; offline
                       emulation evidence. */
  api_SetUnhandledExceptionFilter_18074bf98(0);
                    /* Recovered VMProtect thunk: kernel32.dll!UnhandledExceptionFilter; offline
                       emulation evidence. */
  api_UnhandledExceptionFilter_1805e55f4(param_1);
                    /* Recovered VMProtect thunk: kernel32.dll!GetCurrentProcess; offline emulation
                       evidence. */
  api_GetCurrentProcess_180aedcdc();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* Recovered VMProtect thunk: kernel32.dll!TerminateProcess; offline emulation
                       evidence. */
  return;
}

