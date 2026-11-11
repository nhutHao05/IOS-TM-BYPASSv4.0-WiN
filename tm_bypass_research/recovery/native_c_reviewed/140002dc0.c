/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SendBackupFileRecovered
                    (undefined8 param_1,undefined8 param_2,char *param_3,longlong *param_4)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  int *piVar5;
  uint *puVar6;
  void *arg3;
  ulonglong uVar7;
  void *pvVar8;
  void *arg0;
  void *pvVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  ulonglong auStackX_10 [3];
  undefined8 uStack_88;
  undefined1 auStack_80 [8];
  undefined1 auStack_78 [32];
  ulonglong uStack_58;
  undefined8 uStack_48;
  
  uStack_48 = 0x140002ddf;
  lVar3 = native_140006bc0();
  lVar3 = -lVar3;
  uStack_58 = _DAT_14000b008 ^ (ulonglong)(&stack0xffffffffffffffc0 + lVar3);
  *(longlong **)(&stack0xffffffffffffffe8 + lVar3) = param_4;
  uVar11 = 0xffffffffffffffff;
  do {
    uVar11 = uVar11 + 1;
  } while (param_3[uVar11] != '\0');
  *(undefined4 *)(&stack0xffffffffffffffe0 + lVar3) = 0;
  *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002e30;
  pcVar4 = (char *)native_1400010c0(param_2,param_3,0);
  *(char **)(&stack0xfffffffffffffff0 + lVar3) = pcVar4;
  uVar10 = (uint)uVar11;
  arg3 = (void *)0x0;
  *(uint *)(&stack0xffffffffffffffe4 + lVar3) =
       uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
  *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002e59;
  iVar2 = api_mobilebackup2_send_raw_1400f15f3
                    (param_1,&stack0xffffffffffffffe4 + lVar3,4,&stack0xffffffffffffffe0 + lVar3);
  if ((iVar2 == 0) && (*(int *)(&stack0xffffffffffffffe0 + lVar3) == 4)) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
    *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002e80;
    iVar2 = api_mobilebackup2_send_raw_1400f83fc
                      (param_1,param_3,uVar11 & 0xffffffff,&stack0xffffffffffffffe0 + lVar3);
    if ((iVar2 == 0) && (*(uint *)(&stack0xffffffffffffffe0 + lVar3) == uVar10)) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64; offline emulation evidence.
                        */
      *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002ea0;
      iVar2 = api__stat64_1401f2291(pcVar4,&stack0xfffffffffffffff8 + lVar3);
      if (iVar2 < 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002eaa;
        piVar5 = (int *)api__errno_140157b95();
        if (*piVar5 != 2) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002eb4;
          puVar6 = (uint *)api__errno_14020daf3();
          uVar10 = *puVar6;
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002ece;
          PrintMessageRecovered
                    ("%s: stat failed on \'%s\': %d\n","mb2_handle_send_file",pcVar4,
                     (ulonglong)uVar10);
        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002ed3;
        piVar5 = (int *)api__errno_14015a7bc();
LAB_140003088:
        iVar2 = *piVar5;
        if (iVar2 == 0) goto LAB_140003013;
        if (*param_4 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003099;
          pvVar8 = api_plist_new_dict_140184f29();
          *param_4 = (longlong)pvVar8;
        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400030a4;
        pcVar4 = (char *)api_strerror_140060338(iVar2);
        if (iVar2 == 2) {
          iVar2 = -6;
        }
        else if (iVar2 == 0x11) {
          iVar2 = -7;
        }
        else {
          iVar2 = -iVar2;
        }
        pvVar8 = (void *)**(undefined8 **)(&stack0xffffffffffffffe8 + lVar3);
        if (pvVar8 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400030d5;
          arg0 = api_plist_new_dict_140110b34();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400030e1;
          pvVar9 = api_plist_new_string_140089f0c(pcVar4);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400030f5;
          api_plist_dict_set_item_1401ddb50(arg0,"DLFileErrorString",pvVar9);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_uint; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400030fe;
          pvVar9 = api_plist_new_uint_1401df808((longlong)iVar2);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003111;
          api_plist_dict_set_item_14012d30a(arg0,"DLFileErrorCode",pvVar9);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003120;
          api_plist_dict_set_item_1400bf3f1(pvVar8,param_3,arg0);
        }
        uVar11 = 0xffffffffffffffff;
        uVar12 = 0xffffffffffffffff;
        do {
          uVar7 = uVar12;
          uVar12 = uVar7 + 1;
        } while (pcVar4[uVar12] != '\0');
        iVar2 = (int)uVar7;
        (&stack0x00000034)[lVar3] = 6;
        uVar10 = (iVar2 + 2U & 0xff0000 | iVar2 + 2U >> 0x10) >> 8 | (iVar2 + 2U & 0xff00) << 8 |
                 (iVar2 + 2) * 0x1000000;
        *(uint *)(&stack0xffffffffffffffe4 + lVar3) = uVar10;
        *(uint *)(&stack0x00000030 + lVar3) = uVar10;
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x14000317f;
        func_0x000140006c11(&stack0x00000035 + lVar3,pcVar4,uVar12 & 0xffffffff);
        uVar10 = (int)uVar12 + 5;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003197;
        iVar2 = api_mobilebackup2_send_raw_14008bad7
                          (param_1,&stack0x00000030 + lVar3,uVar10,&stack0xffffffffffffffe0 + lVar3)
        ;
        if (iVar2 != 0) {
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400031a8;
          PrintMessageRecovered("could not send message\n");
        }
        if (*(uint *)(&stack0xffffffffffffffe0 + lVar3) != uVar10) {
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400031bf;
          PrintMessageRecovered
                    ("could only send %d from %d\n",
                     (ulonglong)*(uint *)(&stack0xffffffffffffffe0 + lVar3),(ulonglong)uVar10);
        }
        pcVar4 = *(char **)(&stack0xfffffffffffffff0 + lVar3);
      }
      else {
        uVar11 = *(ulonglong *)((longlong)auStackX_10 + lVar3);
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002ee6;
        pvVar8 = (void *)FormatByteCountRecovered(uVar11);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002eee;
        api_free_1401b39e2(pvVar8);
        if (uVar11 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002f08;
          arg3 = api_fopen_140219c74(pcVar4,"rb");
          if (arg3 == (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002f15;
            puVar6 = (uint *)api__errno_1401c44e4();
            uVar10 = *puVar6;
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002f2f;
            PrintMessageRecovered
                      ("%s: Error opening local file \'%s\': %d\n","mb2_handle_send_file",pcVar4,
                       (ulonglong)uVar10);
code_r0x00014000307e:
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003083;
            piVar5 = (int *)api__errno_1401c7d74();
            param_4 = *(longlong **)(&stack0xffffffffffffffe8 + lVar3);
            goto LAB_140003088;
          }
          uVar12 = 0;
          do {
            (&stack0x00000034)[lVar3] = 0xc;
            iVar2 = 0x8000;
            if (uVar11 - uVar12 < 0x8000) {
              iVar2 = (int)uVar11 - (int)uVar12;
            }
            uVar10 = (iVar2 + 1U & 0xff0000 | iVar2 + 1U >> 0x10) >> 8 |
                     (iVar2 + 1) * 0x100 & 0xff0000U | (iVar2 + 1) * 0x1000000;
            *(uint *)(&stack0xffffffffffffffe4 + lVar3) = uVar10;
            *(uint *)(&stack0x00000030 + lVar3) = uVar10;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002fa4;
            iVar2 = api_mobilebackup2_send_raw_1401af660
                              (param_1,&stack0x00000030 + lVar3,5,&stack0xffffffffffffffe0 + lVar3);
            if ((iVar2 != 0) || (*(int *)(&stack0xffffffffffffffe0 + lVar3) != 5))
            goto LAB_140003055;
                    /* Recovered VMProtect thunk: ucrtbase.dll!fread; offline emulation evidence. */
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002fce;
            uVar7 = api_fread_1401af6d2(&stack0x00000030 + lVar3,1,0x8000,arg3);
            if (uVar7 == 0) {
              *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x14000307d;
              PrintMessageRecovered("%s: read error\n","mb2_handle_send_file");
              goto code_r0x00014000307e;
            }
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
            *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140002ff0;
            iVar2 = api_mobilebackup2_send_raw_1400c269b
                              (param_1,&stack0x00000030 + lVar3,uVar7 & 0xffffffff,
                               &stack0xffffffffffffffe0 + lVar3);
            if (iVar2 != 0) {
LAB_140003055:
              uVar11 = 0xffffffffffffffff;
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
              *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003065;
              api_fclose_1401c44ea(arg3);
              goto LAB_1400031db;
            }
            if (*(uint *)(&stack0xffffffffffffffe0 + lVar3) != (uint)uVar7) {
              *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003055;
              PrintMessageRecovered
                        ("Error: sent only %d of %d bytes\n",
                         (ulonglong)*(uint *)(&stack0xffffffffffffffe0 + lVar3),uVar7 & 0xffffffff);
              goto LAB_140003055;
            }
            uVar12 = uVar12 + uVar7;
          } while (uVar12 < uVar11);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
          *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003010;
          api_fclose_14005f3f0(arg3);
          arg3 = (void *)0x0;
        }
LAB_140003013:
        uVar11 = 0;
        *(undefined4 *)(&stack0xffffffffffffffe4 + lVar3) = 0x1000000;
        *(undefined4 *)(&stack0x00000030 + lVar3) = 0x1000000;
        (&stack0x00000034)[lVar3] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x140003041;
        api_mobilebackup2_send_raw_14015bf41
                  (param_1,&stack0x00000030 + lVar3,5,&stack0xffffffffffffffe0 + lVar3);
      }
      if (arg3 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
        *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400031d1;
        api_fclose_1400b7ec9(arg3);
      }
      goto LAB_1400031db;
    }
  }
  uVar11 = 0xffffffffffffffff;
LAB_1400031db:
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400031e3;
  api_free_14009e541(pcVar4);
  uVar11 = uVar11 & 0xffffffff;
  uVar12 = uStack_58 ^ (ulonglong)(&stack0xffffffffffffffc0 + lVar3);
  *(undefined8 *)((longlong)&uStack_48 + lVar3) = 0x1400031f5;
  if ((uVar12 != _DAT_14000b008) || ((short)(uVar12 >> 0x30) != 0)) {
    *(ulonglong *)(&stack0xffffffffffffffc0 + lVar3) = uVar12;
    puVar13 = auStack_80 + lVar3;
    *(undefined8 *)((longlong)&uStack_88 + lVar3) = 0x140005e0b;
    iVar2 = func_0x000140006b22(0x17);
    if (iVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(2);
      puVar13 = auStack_78 + lVar3;
    }
    *(undefined8 *)(puVar13 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar13 + 0x38);
    _DAT_14000b188 = puVar13 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar13 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar13 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar13 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar13 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    uVar11 = native_140005dc4(&UNK_1400075f0);
  }
  return uVar11;
}

