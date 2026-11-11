/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ReceiveBackupFilesRecovered(void *param_1,void *param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  void *pvVar13;
  char *pcVar14;
  void *pvVar15;
  undefined8 uVar16;
  int *piVar17;
  undefined4 *puVar18;
  ulonglong uVar19;
  char *arg0;
  undefined1 *puVar20;
  char *pcVar21;
  uint uVar22;
  char *arg0_00;
  char *arg0_01;
  int iVar23;
  double dVar24;
  undefined4 unaff_XMM6_Da;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  ulonglong uStackX_8;
  longlong alStackX_10 [2];
  undefined8 uStack_80;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [48];
  undefined8 uStack_40;
  
  uStack_40 = 0x140003382;
  lVar11 = native_140006bc0();
  lVar11 = -lVar11;
  uVar12 = _DAT_14000b008 ^ (ulonglong)(&stack0xffffffffffffffc8 + lVar11);
  arg0_00 = (char *)0x0;
  iVar10 = 0;
  iVar23 = 0;
  *(undefined8 *)((longlong)alStackX_10 + lVar11 + 8) = param_3;
  *(void **)(&stack0x00000030 + lVar11) = param_1;
  (&stack0xffffffffffffffe8)[lVar11] = 0;
  *(undefined8 *)((longlong)&uStackX_8 + lVar11) = 0;
  *(undefined4 *)(&stack0xffffffffffffffec + lVar11) = 0;
  *(undefined8 *)(&stack0x00000000 + lVar11) = 0;
  *(undefined8 *)((longlong)alStackX_10 + lVar11) = 0;
  *(undefined4 *)(&stack0xfffffffffffffffc + lVar11) = 0;
  *(undefined8 *)(&stack0x00000028 + lVar11) = 0;
  if (param_2 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400033e9;
    iVar8 = api_plist_get_node_type_140100cf2(param_2);
    if (iVar8 == 4) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
      *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400033fc;
      uVar9 = api_plist_array_get_size_1401557b4(param_2);
      if ((3 < uVar9) && (*(longlong *)((longlong)alStackX_10 + lVar11 + 8) != 0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
        *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000341d;
        pvVar13 = api_plist_array_get_item_1401f6433(param_2,3);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
        *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000342a;
        iVar8 = api_plist_get_node_type_14012d2ef(pvVar13);
        if (iVar8 == 1) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000343d;
          api_plist_get_uint_val_140214eb2(pvVar13,(void *)((longlong)&uStackX_8 + lVar11));
        }
        if (*(longlong *)((longlong)&uStackX_8 + lVar11) != 0) {
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003450;
          PrintMessageRecovered("Receiving files\n");
        }
        dVar7 = _DAT_140008ca8;
        dVar6 = _DAT_140008ca0;
        pcVar14 = arg0_00;
        if (_DAT_14000b734 == 0) {
          *(undefined4 *)(&stack0x00008088 + lVar11) = unaff_XMM6_Da;
          *(undefined4 *)(&stack0x0000808c + lVar11) = unaff_XMM6_Db;
          *(undefined4 *)(&stack0x00008090 + lVar11) = unaff_XMM6_Dc;
          *(undefined4 *)(&stack0x00008094 + lVar11) = unaff_XMM6_Dd;
          *(undefined4 *)(&stack0x00008078 + lVar11) = unaff_XMM7_Da;
          *(undefined4 *)(&stack0x0000807c + lVar11) = unaff_XMM7_Db;
          *(undefined4 *)(&stack0x00008080 + lVar11) = unaff_XMM7_Dc;
          *(undefined4 *)(&stack0x00008084 + lVar11) = unaff_XMM7_Dd;
          *(undefined4 *)(&stack0x00008068 + lVar11) = unaff_XMM8_Da;
          *(undefined4 *)(&stack0x0000806c + lVar11) = unaff_XMM8_Db;
          *(undefined4 *)(&stack0x00008070 + lVar11) = unaff_XMM8_Dc;
          *(undefined4 *)(&stack0x00008074 + lVar11) = unaff_XMM8_Dd;
          *(undefined4 *)(&stack0x00008058 + lVar11) = unaff_XMM9_Da;
          *(undefined4 *)(&stack0x0000805c + lVar11) = unaff_XMM9_Db;
          *(undefined4 *)(&stack0x00008060 + lVar11) = unaff_XMM9_Dc;
          *(undefined4 *)(&stack0x00008064 + lVar11) = unaff_XMM9_Dd;
          *(undefined4 *)(&stack0x00008048 + lVar11) = unaff_XMM10_Da;
          *(undefined4 *)(&stack0x0000804c + lVar11) = unaff_XMM10_Db;
          *(undefined4 *)(&stack0x00008050 + lVar11) = unaff_XMM10_Dc;
          *(undefined4 *)(&stack0x00008054 + lVar11) = unaff_XMM10_Dd;
          pcVar21 = arg0_00;
          arg0_01 = arg0_00;
          do {
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400034ad;
            uVar9 = ReceiveFilenameRecovered(param_1,(longlong)alStackX_10 + lVar11);
            *(uint *)(&stack0xffffffffffffffec + lVar11) = uVar9;
            iVar23 = iVar10;
            if (uVar9 == 0) break;
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400034c6;
            iVar8 = ReceiveFilenameRecovered(param_1,(longlong)&stack0x00000000 + lVar11);
            *(int *)(&stack0xffffffffffffffec + lVar11) = iVar8;
            if (iVar8 == 0) {
              arg0_01 = *(char **)(&stack0x00000000 + lVar11);
              uVar9 = 0;
              break;
            }
            if (pcVar14 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400034df;
              api_free_1400c9e47(pcVar14);
            }
            arg0_01 = *(char **)(&stack0x00000000 + lVar11);
            uVar16 = *(undefined8 *)((longlong)alStackX_10 + lVar11 + 8);
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400034f5;
            pcVar14 = (char *)native_1400010c0(uVar16,arg0_01,0);
            *(char **)(&stack0x00000020 + lVar11) = pcVar14;
            if (arg0_01 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000350b;
              api_free_140073c88(arg0_01);
              *(undefined8 *)(&stack0x00000000 + lVar11) = 0;
              arg0_01 = arg0_00;
            }
            *(undefined4 *)(&stack0xfffffffffffffff0 + lVar11) = 0;
            *(undefined4 *)(&stack0xffffffffffffffec + lVar11) = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003536;
            api_mobilebackup2_receive_raw_1401bb467
                      (param_1,&stack0xffffffffffffffec + lVar11,4,&stack0xfffffffffffffff0 + lVar11
                      );
            if (*(int *)(&stack0xfffffffffffffff0 + lVar11) != 4) {
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003939;
              PrintMessageRecovered
                        ("ERROR: %s: could not receive code length!\n","mb2_handle_receive_files");
              uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
              break;
            }
            uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
            *(uint *)(&stack0xffffffffffffffec + lVar11) =
                 (uVar9 & 0xff0000 | uVar9 >> 0x10) >> 8 | (uVar9 & 0xff00 | uVar9 << 0x10) << 8;
            (&stack0xfffffffffffffff4)[lVar11] = (&stack0xffffffffffffffe8)[lVar11];
            (&stack0xffffffffffffffe8)[lVar11] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003593;
            api_mobilebackup2_receive_raw_14017e7d6
                      (param_1,&stack0xffffffffffffffe8 + lVar11,1,&stack0xfffffffffffffff0 + lVar11
                      );
            if (*(int *)(&stack0xfffffffffffffff0 + lVar11) != 1) {
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003920;
              PrintMessageRecovered
                        ("ERROR: %s: could not receive code!\n","mb2_handle_receive_files");
              uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
              break;
            }
            cVar1 = (&stack0xffffffffffffffe8)[lVar11];
            if ((cVar1 != '\0') && (1 < (byte)(cVar1 - 0xbU))) {
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400035bc;
              PrintMessageRecovered("Found new flag %02x\n",(ulonglong)(uint)(int)cVar1);
            }
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400035c5;
            iVar8 = api_DeleteFileA_14015039b(pcVar14);
            if (iVar8 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400035cf;
              api_GetLastError_1400872d9();
            }
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400035de;
            pvVar13 = api_fopen_1401a1570(pcVar14,"wb");
            if (pvVar13 == (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400038c0;
              piVar17 = (int *)api__errno_140076ece();
              iVar23 = *piVar17;
              if (iVar23 == 2) {
                iVar23 = -6;
              }
              else if (iVar23 == 0x11) {
                iVar23 = -7;
              }
              else {
                iVar23 = -iVar23;
              }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400038e8;
              puVar18 = (undefined4 *)api__errno_1400879b0();
              uVar2 = *puVar18;
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400038ef;
              uVar16 = api_strerror_1400c195a(uVar2);
              *(undefined8 *)(&stack0x00000028 + lVar11) = uVar16;
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003907;
              PrintMessageRecovered("Error opening \'%s\' for writing: %s\n",pcVar14,uVar16);
              uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
              break;
            }
            while ((&stack0xffffffffffffffe8)[lVar11] == '\f') {
              uVar22 = *(int *)(&stack0xffffffffffffffec + lVar11) - 1;
              pcVar14 = arg0_00;
              uVar9 = 0;
              if (uVar22 != 0) {
                do {
                  uVar9 = (uint)pcVar14;
                  uVar4 = 0x8000;
                  if (uVar22 - uVar9 < 0x8000) {
                    uVar4 = uVar22 - uVar9;
                  }
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
                  *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003634;
                  api_mobilebackup2_receive_raw_1401627d0
                            (param_1,&stack0x00000038 + lVar11,uVar4,
                             &stack0xfffffffffffffff0 + lVar11);
                  if ((int)*(uint *)(&stack0xfffffffffffffff0 + lVar11) < 1) break;
                    /* Recovered VMProtect thunk: ucrtbase.dll!fwrite; offline emulation evidence.
                        */
                  *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003652;
                  api_fwrite_14009e64d
                            (&stack0x00000038 + lVar11,1,
                             (ulonglong)*(uint *)(&stack0xfffffffffffffff0 + lVar11),pvVar13);
                  uVar9 = uVar9 + *(int *)(&stack0xfffffffffffffff0 + lVar11);
                  pcVar14 = (char *)(ulonglong)uVar9;
                } while (uVar9 < uVar22);
              }
              if (uVar9 == uVar22) {
                pcVar21 = pcVar21 + uVar22;
              }
              uVar19 = *(ulonglong *)((longlong)&uStackX_8 + lVar11);
              if ((uVar19 != 0) &&
                 (dVar24 = ((double)pcVar21 / (double)uVar19) * dVar7, 0.0 <= dVar24)) {
                dVar5 = dVar7;
                if (dVar24 <= dVar7) {
                  dVar5 = dVar24;
                }
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400036e7;
                PrintMessageRecovered("\r[");
                pcVar14 = arg0_00;
                do {
                  arg0 = "=";
                  if (dVar5 * dVar6 <= (double)(int)pcVar14) {
                    arg0 = " ";
                  }
                  *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000371c;
                  PrintMessageRecovered(arg0);
                  uVar9 = (int)pcVar14 + 1;
                  pcVar14 = (char *)(ulonglong)uVar9;
                } while ((int)uVar9 < 0x32);
                param_1 = *(void **)(&stack0x00000030 + lVar11);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000373c;
                PrintMessageRecovered("] %3.0f%%",dVar5);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003744;
                pvVar15 = (void *)FormatByteCountRecovered(pcVar21);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003756;
                PrintMessageRecovered(" (%s",pvVar15);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000375f;
                api_free_1400fb637(pvVar15);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003767;
                pvVar15 = (void *)FormatByteCountRecovered(uVar19);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003779;
                PrintMessageRecovered("/%s)     ",pvVar15);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003781;
                api_free_1400600eb(pvVar15);
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000378c;
                uVar16 = api___acrt_iob_func_140055b95(1);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fflush; offline emulation evidence.
                        */
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003796;
                api_fflush_1401ce323(uVar16);
                if (dVar5 == dVar7) {
                  *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400037ab;
                  PrintMessageRecovered("\n");
                }
              }
              if (_DAT_14000b734 != 0) break;
              *(undefined4 *)(&stack0xffffffffffffffec + lVar11) = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400037d2;
              api_mobilebackup2_receive_raw_14014ecd3
                        (param_1,&stack0xffffffffffffffec + lVar11,4,
                         &stack0xfffffffffffffff0 + lVar11);
              uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
              uVar9 = (uVar9 & 0xff0000 | uVar9 >> 0x10) >> 8 |
                      (uVar9 & 0xff00 | uVar9 << 0x10) << 8;
              *(uint *)(&stack0xffffffffffffffec + lVar11) = uVar9;
              if (uVar9 == 0) break;
              (&stack0xfffffffffffffff4)[lVar11] = (&stack0xffffffffffffffe8)[lVar11];
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003820;
              api_mobilebackup2_receive_raw_140114079
                        (param_1,&stack0xffffffffffffffe8 + lVar11,1,
                         &stack0xfffffffffffffff0 + lVar11);
            }
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000382f;
            api_fclose_140150bae(pvVar13);
            uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
            *(int *)(&stack0xfffffffffffffffc + lVar11) =
                 *(int *)(&stack0xfffffffffffffffc + lVar11) + 1;
            if (uVar9 == 0) {
              pcVar14 = *(char **)(&stack0x00000020 + lVar11);
              break;
            }
            if ((&stack0xffffffffffffffe8)[lVar11] == '\v') {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000384e;
              pvVar13 = api_malloc_1400639cf((ulonglong)uVar9);
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000386a;
              api_mobilebackup2_receive_raw_140130671
                        (param_1,pvVar13,*(int *)(&stack0xffffffffffffffec + lVar11) + -1,
                         &stack0xfffffffffffffff0 + lVar11);
              cVar1 = (&stack0xfffffffffffffff4)[lVar11];
              *(undefined1 *)
               ((ulonglong)*(uint *)(&stack0xfffffffffffffff0 + lVar11) + (longlong)pvVar13) = 0;
              if (cVar1 != '\f') {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003883;
                uVar16 = api___acrt_iob_func_1401627e1(1);
                *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003896;
                native_140001010(uVar16,"\nReceived an error message from device: %s\n");
              }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000389e;
              api_free_140074635(pvVar13);
              uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
            }
            pcVar14 = *(char **)(&stack0x00000020 + lVar11);
          } while (_DAT_14000b734 == 0);
          if (arg0_01 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x14000398a;
            api_free_1400a1d15(arg0_01);
            arg0_00 = *(char **)((longlong)alStackX_10 + lVar11);
            goto LAB_140003990;
          }
          arg0_00 = *(char **)((longlong)alStackX_10 + lVar11);
        }
        else {
LAB_140003990:
          uVar9 = *(uint *)(&stack0xffffffffffffffec + lVar11);
        }
        if (0 < (int)(uVar9 - 1)) {
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039a6;
          PrintMessageRecovered("\nDiscarding current data hunk.\n");
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039b2;
          pvVar13 = api_malloc_14014a55d
                              ((ulonglong)(*(int *)(&stack0xffffffffffffffec + lVar11) - 1));
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039cd;
          api_mobilebackup2_receive_raw_140063a36
                    (param_1,pvVar13,*(int *)(&stack0xffffffffffffffec + lVar11) + -1,
                     &stack0xfffffffffffffff0 + lVar11);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039d7;
          api_free_1401cd36d(pvVar13);
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039e0;
          iVar10 = api_DeleteFileA_140202da2(pcVar14);
          if (iVar10 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
            *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039ea;
            api_GetLastError_1400eb3ef();
          }
        }
        if (pcVar14 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x1400039f8;
          api_free_1402074fc(pcVar14);
        }
        if (arg0_00 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003a05;
          api_free_1400c3935(arg0_00);
        }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
        *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003a0c;
        pvVar13 = api_plist_new_dict_1400b0e7f();
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
        *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003a23;
        api_mobilebackup2_send_status_response_14017ab13
                  (param_1,iVar23,*(char **)(&stack0x00000028 + lVar11),pvVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003a2b;
        api_plist_free_1401f6b98(pvVar13);
        uVar19 = (ulonglong)*(uint *)(&stack0xfffffffffffffffc + lVar11);
        goto LAB_140003a3e;
      }
    }
  }
  uVar19 = 0;
LAB_140003a3e:
  uVar12 = uVar12 ^ (ulonglong)(&stack0xffffffffffffffc8 + lVar11);
  *(undefined8 *)((longlong)&uStack_40 + lVar11) = 0x140003a4d;
  if ((uVar12 != _DAT_14000b008) || ((short)(uVar12 >> 0x30) != 0)) {
    *(ulonglong *)(&stack0xffffffffffffffc8 + lVar11) = uVar12;
    puVar20 = auStack_78 + lVar11;
    *(undefined8 *)((longlong)&uStack_80 + lVar11) = 0x140005e0b;
    iVar23 = func_0x000140006b22(0x17);
    if (iVar23 != 0) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(2);
      puVar20 = auStack_70 + lVar11;
    }
    *(undefined8 *)(puVar20 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar20 + 0x38);
    _DAT_14000b188 = puVar20 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar20 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar20 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar20 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar20 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    uVar19 = native_140005dc4(&UNK_1400075f0);
  }
  return uVar19;
}

