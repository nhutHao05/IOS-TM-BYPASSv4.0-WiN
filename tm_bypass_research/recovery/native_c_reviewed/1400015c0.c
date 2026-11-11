/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void * native_1400015c0(short *param_1)

{
  short sVar1;
  uint uVar2;
  void *arg0;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longlong lVar5;
  void *pvVar6;
  void *pvVar7;
  
  if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
    api__set_errno_140141188(2);
    return (void *)0x0;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  arg0 = api_malloc_140117c6d(0x490);
  pvVar7 = arg0;
  if (arg0 != (void *)0x0) {
    pvVar7 = (void *)0x0;
    *(undefined8 *)((longlong)arg0 + 0x480) = 0xffffffffffffffff;
    *(undefined4 *)((longlong)arg0 + 0x478) = 0;
                    /* Recovered VMProtect thunk: kernel32.dll!GetFullPathNameW; offline emulation
                       evidence. */
    uVar2 = api_GetFullPathNameW_1401d546c(param_1,0,0,0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    puVar3 = (undefined4 *)api_malloc_1401b087a((ulonglong)uVar2 * 2 + 0x10);
    *(undefined4 **)((longlong)arg0 + 0x488) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetFullPathNameW; offline emulation
                       evidence. */
      uVar2 = api_GetFullPathNameW_1400f31de(param_1,(ulonglong)uVar2,puVar3,0);
      if (uVar2 == 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
        api__set_errno_140166ee8(2);
      }
      else {
        puVar4 = (undefined4 *)((longlong)puVar3 + (ulonglong)uVar2 * 2);
        if ((((puVar3 < puVar4) && (sVar1 = *(short *)((longlong)puVar4 + -2), sVar1 != 0x2f)) &&
            (sVar1 != 0x3a)) && (sVar1 != 0x5c)) {
          *(undefined2 *)puVar4 = 0x5c;
          puVar4 = (undefined4 *)((longlong)puVar4 + 2);
        }
        *puVar4 = 0x2a;
                    /* Recovered VMProtect thunk: kernel32.dll!FindFirstFileExW; offline emulation
                       evidence. */
        lVar5 = api_FindFirstFileExW_1401865bd(puVar3,0,(void *)((longlong)arg0 + 0x228),0,0,0);
        *(longlong *)((longlong)arg0 + 0x480) = lVar5;
        pvVar6 = (void *)((longlong)arg0 + 0x228);
        if (lVar5 == -1) {
          pvVar6 = pvVar7;
        }
        *(uint *)((longlong)arg0 + 0x478) = (uint)(lVar5 != -1);
        if (pvVar6 != (void *)0x0) {
          return arg0;
        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_set_errno; offline emulation
                       evidence. */
        api__set_errno_1401aa29a(2);
        if (*(longlong *)((longlong)arg0 + 0x480) != -1) {
                    /* Recovered VMProtect thunk: kernel32.dll!FindClose; offline emulation
                       evidence. */
          api_FindClose_140063bca();
          *(undefined8 *)((longlong)arg0 + 0x480) = 0xffffffffffffffff;
        }
      }
    }
    if (*(void **)((longlong)arg0 + 0x488) != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_14013e0ec(*(void **)((longlong)arg0 + 0x488));
      *(undefined8 *)((longlong)arg0 + 0x488) = 0;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_14004b5e5(arg0);
  }
  return pvVar7;
}

