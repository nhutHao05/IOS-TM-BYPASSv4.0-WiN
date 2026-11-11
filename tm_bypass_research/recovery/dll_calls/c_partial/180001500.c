/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180001500(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_278 [32];
  uint *puStack_258;
  uint uStack_248;
  int iStack_244;
  undefined4 auStack_238 [2];
  longlong lStack_230;
  ulonglong uStack_28;
  
  uStack_28 = _DAT_18002c008 ^ (ulonglong)auStack_278;
  if (param_1 < 0) {
    if (1 < _DAT_18002c930) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
      uVar2 = api___acrt_iob_func_1806e6174(2);
      native_180001010(uVar2,"ERROR: invalid fd in check_fd %d\n",param_1);
    }
  }
  else {
    auStack_238[0] = 1;
    lStack_230 = (longlong)param_1;
LAB_180001570:
    if (param_3 == 0) {
      puVar6 = (uint *)0x0;
    }
    else {
      uStack_248 = param_3 / 1000;
      puVar6 = &uStack_248;
      iStack_244 = (param_3 % 1000) * 1000;
    }
    if (param_2 == 0) {
      puVar4 = (undefined4 *)0x0;
      puVar7 = auStack_238;
LAB_1800015df:
      puVar8 = (undefined4 *)0x0;
    }
    else {
      if (param_2 != 1) {
        if (param_2 == 2) {
          puVar4 = auStack_238;
          puVar7 = (undefined4 *)0x0;
          goto LAB_1800015df;
        }
        goto LAB_1800016e2;
      }
      puVar4 = (undefined4 *)0x0;
      puVar7 = (undefined4 *)0x0;
      puVar8 = auStack_238;
    }
    puStack_258 = puVar6;
                    /* Recovered VMProtect thunk: ws2_32.dll!select; offline emulation evidence. */
    iVar1 = api_select_1808cb35c(param_1 + 1,puVar7,puVar8,puVar4);
    if (-1 < iVar1) {
      if ((iVar1 == 0) && (1 < _DAT_18002c930)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
        uVar2 = api___acrt_iob_func_1806e267b(2);
        native_180001010(uVar2,"%s: timeout\n","socket_check_fd");
      }
      goto LAB_1800016e2;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
    piVar3 = (int *)api__errno_1806f30cd();
    if (*piVar3 == 4) {
      if (1 < _DAT_18002c930) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
        uVar2 = api___acrt_iob_func_180226c08(2);
        native_180001010(uVar2);
      }
      goto LAB_180001570;
    }
    if (*piVar3 == 0xb) {
      if (1 < _DAT_18002c930) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
        uVar2 = api___acrt_iob_func_18063e379(2);
        native_180001010(uVar2,"%s: EAGAIN\n","socket_check_fd");
      }
    }
    else if (1 < _DAT_18002c930) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
      puVar4 = (undefined4 *)api__errno_1804ae0d0();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
      uVar2 = api_strerror_1805549bb(*puVar4);
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
      uVar5 = api___acrt_iob_func_1809cc2ed(2);
      native_180001010(uVar5,"%s: select failed: %s\n","socket_check_fd",uVar2);
    }
  }
LAB_1800016e2:
  native_18001c0e0(uStack_28 ^ (ulonglong)auStack_278);
  return;
}

