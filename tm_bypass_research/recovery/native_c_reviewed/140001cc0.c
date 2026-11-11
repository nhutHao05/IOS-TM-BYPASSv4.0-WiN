/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong native_140001cc0(char *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  char *arg0;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffffffffffff;
  }
                    /* Recovered VMProtect thunk: kernel32.dll!CreateDirectoryA; offline emulation
                       evidence. */
  iVar2 = api_CreateDirectoryA_1400bdcec(param_1,(void *)0x0);
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
  if (((iVar2 != 0) || (iVar2 = api_GetLastError_140169b3c(), iVar2 == 0xb7)) || (iVar2 == 0)) {
    return 0;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
  arg0 = (char *)api__mbsdup_140149a73(param_1);
  if (arg0 != (char *)0x0) {
    uVar4 = 0xffffffffffffffff;
    do {
      uVar5 = uVar4;
      uVar4 = uVar5 + 1;
    } while (arg0[uVar4] != '\0');
    if (uVar4 != 0) {
      if ((arg0[uVar5] != '/') && (arg0[uVar5] != '\\')) goto LAB_140001d60;
      while (uVar4 = uVar5, uVar4 != 0) {
LAB_140001d60:
        if (arg0[uVar4 - 1] == '/') {
LAB_140001dc4:
          if (uVar4 != 1) {
            func_0x000140006c11(&DAT_14000b630,arg0,uVar4 - 1);
            if (0x103 < uVar4) {
              native_140005ecc();
              pcVar1 = (code *)swi(3);
              uVar4 = (*pcVar1)();
              return uVar4;
            }
            (&DAT_14000b630)[uVar4] = 0;
            goto LAB_140001d7f;
          }
          if ((*arg0 == '/') || (*arg0 == '\\')) {
            _DAT_14000b630 = 0x2f;
            goto LAB_140001d7f;
          }
          break;
        }
        if (arg0[uVar4 - 1] == '\\') {
          if (uVar4 != 0) goto LAB_140001dc4;
          break;
        }
        uVar5 = uVar4 - 1;
      }
    }
  }
  _DAT_14000b630 = 0x2e;
LAB_140001d7f:
  uVar3 = native_140001cc0(&DAT_14000b630,0x1ed);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_1401a48b5(arg0);
  if (uVar3 == 0) {
    native_140001cc0(param_1,0x1ed);
  }
  return (ulonglong)uVar3;
}

