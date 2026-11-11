/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined4 * native_140001840(undefined4 *param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lStackX_8;
  
  lVar2 = *(longlong *)(param_1 + 0x4a);
  if (*(int *)(lVar2 + 0x478) == 0) {
    if (*(longlong *)(lVar2 + 0x480) == -1) {
      return (undefined4 *)0x0;
    }
                    /* Recovered VMProtect thunk: kernel32.dll!FindNextFileW; offline emulation
                       evidence. */
    iVar3 = api_FindNextFileW_140127b6e(*(longlong *)(lVar2 + 0x480),lVar2 + 0x228);
    if (iVar3 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!FindClose; offline emulation
                       evidence. */
      api_FindClose_140097ff3(*(undefined8 *)(lVar2 + 0x480));
      *(undefined8 *)(lVar2 + 0x480) = 0xffffffffffffffff;
      return (undefined4 *)0x0;
    }
  }
  else {
    *(undefined4 *)(lVar2 + 0x478) = 0;
  }
  if ((uint *)(lVar2 + 0x228) == (uint *)0x0) {
    return (undefined4 *)0x0;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!wcstombs_s; offline emulation
                       evidence. */
  iVar3 = api_wcstombs_s_1401d2f87(&lStackX_8,param_1 + 7,0x105,lVar2 + 0x254,0x105);
  if (iVar3 != 0) {
    if (*(short *)(lVar2 + 0x45c) != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!wcstombs_s; offline emulation
                       evidence. */
      iVar3 = api_wcstombs_s_1401e44ab(&lStackX_8,param_1 + 7,0x105,(short *)(lVar2 + 0x45c),0x105);
    }
    if (iVar3 != 0) {
      *(undefined2 *)(param_1 + 7) = 0x3f;
      *(undefined8 *)(param_1 + 4) = 1;
      param_1[6] = 0;
      *param_1 = 0;
      param_1[1] = 0xffffffff;
      *(undefined2 *)(param_1 + 2) = 0;
      return param_1;
    }
  }
  *(longlong *)(param_1 + 4) = lStackX_8 + -1;
  uVar1 = *(uint *)(lVar2 + 0x228);
  if ((uVar1 & 0x40) == 0) {
    uVar4 = 0x8000;
    if ((uVar1 & 0x10) != 0) {
      uVar4 = 0x4000;
    }
    param_1[6] = uVar4;
    *param_1 = 0;
    param_1[1] = 0;
    *(undefined2 *)(param_1 + 2) = 0x128;
    return param_1;
  }
  param_1[6] = 0x2000;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0x128;
  return param_1;
}

