/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RunBackupRestoreRecovered(void)

{
  char cVar1;
  char cVar2;
  code *pcVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  void *pvVar14;
  void *pvVar15;
  void *pvVar16;
  undefined4 *puVar17;
  int *piVar18;
  uint *puVar19;
  longlong lVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  undefined1 *puVar23;
  ulonglong uVar24;
  uint3 uVar25;
  undefined *puVar26;
  char *pcVar27;
  bool bVar28;
  undefined1 auStackY_a48 [8];
  undefined1 auStackY_a40 [48];
  undefined8 uStackY_a10;
  ulonglong auStackY_a08 [4];
  uint uStack_9d8;
  uint uStack_9d4;
  uint uStack_9d0;
  char acStack_9cc [4];
  char *pcStack_9c8;
  void *pvStack_9c0;
  void *pvStack_9b8;
  char *pcStack_9b0;
  void *pvStack_9a8;
  void *pvStack_9a0;
  void *pvStack_998;
  undefined1 uStack_990;
  undefined1 auStack_98f [7];
  short *psStack_988;
  uint auStack_980 [2];
  char *pcStack_978;
  void *pvStack_970;
  void *pvStack_968;
  int iStack_960;
  ulonglong uStack_958;
  void *pvStack_950;
  void *pvStack_948;
  void *pvStack_940;
  void *pvStack_938;
  void *pvStack_930;
  void *pvStack_928;
  void *pvStack_920;
  void *pvStack_918;
  void *pvStack_910;
  void *pvStack_908;
  void *pvStack_900;
  undefined4 auStack_8f8 [2];
  longlong lStack_8f0;
  undefined8 uStack_8e8;
  undefined8 uStack_8e0;
  undefined1 auStack_8d8 [6];
  ushort uStack_8d2;
  undefined8 uStack_8a8;
  undefined4 uStack_8a0;
  char *pcStack_898;
  char *pcStack_890;
  char *pcStack_888;
  char *pcStack_880;
  undefined8 uStack_878;
  undefined1 auStack_868 [2048];
  ulonglong uStack_68;
  
  uStack_68 = _DAT_14000b008 ^ (ulonglong)auStackY_a08;
  uVar25 = 0;
  pcStack_9b0 = (char *)0x0;
  psStack_988 = (short *)0x0;
  uStack_9d8 = 0xffffffff;
  pvStack_940 = (void *)0x0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!signal; offline emulation evidence.
                        */
  uStackY_a10 = 0x1400040c5;
  api_signal_14006a65f(2,native_140004040);
                    /* Recovered VMProtect thunk: ucrtbase.dll!signal; offline emulation evidence.
                        */
  uStackY_a10 = 0x1400040d6;
  api_signal_14017921b(0xf,native_140004040);
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_set_debug_level; offline
                       emulation evidence. */
  uStackY_a10 = 0x1400040dd;
  api_idevice_set_debug_level_14015a860(0);
  uVar10 = 1;
  uStack_9d0 = 1;
  uStackY_a10 = 0x1400040fe;
  func_0x000140006a92(auStack_868,0,0x800);
                    /* Recovered VMProtect thunk: kernel32.dll!GetTempPathA; offline emulation
                       evidence. */
  uStackY_a10 = 0x140004110;
  api_GetTempPathA_14014fbba(0x800,auStack_868);
                    /* Recovered VMProtect thunk: ucrtbase.dll!strncat; offline emulation evidence.
                        */
  uStackY_a10 = 0x140004127;
  api_strncat_1400a78ee(auStack_868,"ikey",4);
  pvStack_9a0 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_new_with_options;
                       offline emulation evidence. */
  uStackY_a10 = 0x140004140;
  iVar7 = api_idevice_new_with_options_14017e827(&pvStack_9a0,pcStack_9b0,2);
  if (iVar7 != 0) {
    uStackY_a10 = 0x140004151;
    PrintMessageRecovered("ERROR\n");
    uStack_9d8 = 0xffffffff;
    goto LAB_140005d4d;
  }
  if (pcStack_9b0 == (char *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_get_udid; offline
                       emulation evidence. */
    uStackY_a10 = 0x140004183;
    api_idevice_get_udid_14008cb47(pvStack_9a0,&pcStack_9b0);
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_mbsdup; offline emulation evidence.
                        */
  uStackY_a10 = 0x14000418d;
  pcVar12 = (char *)api__mbsdup_1400757f6(pcStack_9b0);
  uStack_990 = 0;
  uStackY_a10 = 0x1400041b4;
  pcStack_9c8 = pcVar12;
  pcVar13 = (char *)native_1400010c0(auStack_868,pcVar12,"Info.plist",0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
  uStackY_a10 = 0x1400041c4;
  iVar7 = api__stat64i32_14015afca(pcVar13,auStack_8d8);
  if (iVar7 != 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_free; offline emulation
                       evidence. */
    uStackY_a10 = 0x1400041d3;
    api_idevice_free_14008658b(pvStack_9a0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x1400041dc;
    api_free_14020a144(pcVar13);
    uStackY_a10 = 0x1400041e8;
    PrintMessageRecovered("ERROR\n");
    uStack_9d8 = 0xffffffff;
    goto LAB_140005d4d;
  }
  uStackY_a10 = 0x140004211;
  pvVar14 = (void *)native_1400010c0(auStack_868,pcVar12,"Manifest.plist",0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
  uStackY_a10 = 0x140004221;
  iVar7 = api__stat64i32_1400d6e70(pvVar14,auStack_8d8);
  if (iVar7 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x14000422e;
    api_free_14014477a(pcVar13);
  }
  pvStack_9b8 = (void *)0x0;
  uStackY_a10 = 0x140004240;
  native_1400013c0(&pvStack_9b8,pvVar14);
  if (pvStack_9b8 == (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_free; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004254;
    api_idevice_free_1401d5230(pvStack_9a0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x14000425d;
    api_free_140168b4f(pcVar13);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x140004266;
    api_free_1401b3e80(pvVar14);
    uStackY_a10 = 0x140004273;
    PrintMessageRecovered("ERROR\n");
    uStack_9d8 = 0xffffffff;
    goto LAB_140005d4d;
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
  uStackY_a10 = 0x140004287;
  pvStack_998 = api_plist_dict_get_item_14010ad72(pvStack_9b8,"IsEncrypted");
  if (pvStack_998 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    uStackY_a10 = 0x14000429a;
    iVar7 = api_plist_get_node_type_1400d6e69(pvStack_998);
    if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_bool_val; offline emulation
                       evidence. */
      uStackY_a10 = 0x1400042ae;
      api_plist_get_bool_val_1401c28d7(pvStack_998,&uStack_990);
    }
  }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStackY_a10 = 0x1400042ba;
  api_plist_free_1401d7bde(pvStack_9b8);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStackY_a10 = 0x1400042c2;
  api_free_140050556(pvVar14);
  pvStack_968 = (void *)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_client_new_with_handshake; offline emulation
                       evidence. */
  uStackY_a10 = 0x1400042de;
  iVar7 = api_lockdownd_client_new_with_handshake_1400614bc
                    (pvStack_9a0,&pvStack_968,"idevicebackup2");
  if (iVar7 != 0) {
    uStackY_a10 = 0x1400042ef;
    PrintMessageRecovered("ERROR\n");
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_free; offline emulation
                       evidence. */
    uStackY_a10 = 0x1400042fa;
    api_idevice_free_1400cce5b(pvStack_9a0);
    uStack_9d8 = 0xffffffff;
    goto LAB_140005d4d;
  }
  acStack_9cc[0] = '\0';
  pvStack_998 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_get_value; offline
                       emulation evidence. */
  uStackY_a10 = 0x140004328;
  api_lockdownd_get_value_1401d7c41
            (pvStack_968,"com.apple.mobile.backup","WillEncrypt",&pvStack_998);
  if (pvStack_998 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004338;
    iVar7 = api_plist_get_node_type_1400d1f73(pvStack_998);
    if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_bool_val; offline emulation
                       evidence. */
      uStackY_a10 = 0x14000434b;
      api_plist_get_bool_val_14017cafd(pvStack_998,acStack_9cc);
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x140004356;
    api_plist_free_1401bbced(pvStack_998);
  }
  lStack_8f0 = 0;
  pvStack_998 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_get_value; offline
                       emulation evidence. */
  uStackY_a10 = 0x140004378;
  api_lockdownd_get_value_1400c38db(pvStack_968,(char *)0x0,"ProductVersion",&pvStack_998);
  if (pvStack_998 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004387;
    iVar7 = api_plist_get_node_type_1401bc32c(pvStack_998);
    if (iVar7 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
      uStackY_a10 = 0x14000439b;
      api_plist_get_string_val_14006b035(pvStack_998,&lStack_8f0);
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x1400043a6;
    api_plist_free_14013885c(pvStack_998);
    pvStack_998 = (void *)0x0;
  }
  if (lStack_8f0 != 0) {
    uStack_8a8 = 0;
    uStack_8a0 = 0;
    uStackY_a10 = 0x1400043d9;
    iVar7 = native_140001560(lStack_8f0,"%d.%d.%d",&uStack_8a8,(longlong)&uStack_8a8 + 4);
    if (1 < iVar7) {
      uVar25 = CONCAT21(CONCAT11((undefined1)uStack_8a8,uStack_8a8._4_1_),(undefined1)uStack_8a0);
    }
  }
  pvStack_920 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_start_service; offline
                       emulation evidence. */
  uStackY_a10 = 0x14000440d;
  iVar7 = api_lockdownd_start_service_1400d1978
                    (pvStack_968,"com.apple.mobile.notification_proxy",&psStack_988);
  if (((iVar7 == 0) && (psStack_988 != (short *)0x0)) && (*psStack_988 != 0)) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_new; offline
                       emulation evidence. */
    uStackY_a10 = 0x140004430;
    api_instproxy_client_new_1400c97a3(pvStack_9a0,psStack_988,&pvStack_920);
                    /* Recovered VMProtect thunk: imobiledevice.dll!np_set_notify_callback; offline
                       emulation evidence. */
    uStackY_a10 = 0x140004444;
    api_np_set_notify_callback_1400bf506(pvStack_920,HandleNotificationRecovered,0);
    pcStack_898 = "com.apple.itunes-client.syncCancelRequest";
    uStack_878 = 0;
    pcStack_890 = "com.apple.itunes-client.syncSuspendRequest";
    pcStack_888 = "com.apple.itunes-client.syncResumeRequest";
    pcStack_880 = "com.apple.mobile.backup.domain_changed";
                    /* Recovered VMProtect thunk: imobiledevice.dll!np_observe_notifications;
                       offline emulation evidence. */
    uStackY_a10 = 0x14000448b;
    api_np_observe_notifications_1401b9085(pvStack_920,&pcStack_898);
  }
  pvStack_970 = (void *)0x0;
  *psStack_988 = 0;
  *(undefined1 *)(psStack_988 + 1) = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_start_service; offline
                       emulation evidence. */
  uStackY_a10 = 0x1400044b2;
  iVar7 = api_lockdownd_start_service_14013ad45(pvStack_968,"com.apple.afc",&psStack_988);
  if ((iVar7 == 0) && (*psStack_988 != 0)) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_client_new; offline
                       emulation evidence. */
    uStackY_a10 = 0x1400044d1;
    api_afc_client_new_1401f5b3c(pvStack_9a0,psStack_988,&pvStack_970);
  }
  if (psStack_988 != (short *)0x0) {
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_service_descriptor_free; offline emulation
                       evidence. */
    uStackY_a10 = 0x1400044e0;
    api_lockdownd_service_descriptor_free_14016de42();
    psStack_988 = (short *)0x0;
  }
  pvStack_9c0 = (void *)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_start_service_with_escrow_bag; offline emulation
                       evidence. */
  uStackY_a10 = 0x1400044ff;
  iVar7 = api_lockdownd_start_service_with_escrow_bag_140218b1b
                    (pvStack_968,"com.apple.mobilebackup2",&psStack_988);
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_client_free; offline
                       emulation evidence. */
  uStackY_a10 = 0x14000450a;
  api_lockdownd_client_free_1401c59d8(pvStack_968);
  pvStack_968 = (void *)0x0;
  if (((iVar7 != 0) || (psStack_988 == (short *)0x0)) || (*psStack_988 == 0)) {
    uStackY_a10 = 0x140005ca4;
    PrintMessageRecovered("ERROR: Could not start service %s.\n","com.apple.mobilebackup2");
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_client_free; offline
                       emulation evidence. */
    uStackY_a10 = 0x140005cae;
    api_lockdownd_client_free_1401c622a(pvStack_968);
    uStack_9d8 = 0xffffffff;
    goto LAB_140005cb4;
  }
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_client_new;
                       offline emulation evidence. */
  uStackY_a10 = 0x140004546;
  api_mobilebackup2_client_new_140169917(pvStack_9a0,psStack_988,&pvStack_9c0);
  if (psStack_988 != (short *)0x0) {
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_service_descriptor_free; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004556;
    api_lockdownd_service_descriptor_free_140179241();
    psStack_988 = (short *)0x0;
  }
  iVar7 = 0;
  uStack_8a8 = 0;
  uStack_8e8 = _DAT_140008ce0;
  uStack_8e0 = _UNK_140008ce8;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_version_exchange;
                       offline emulation evidence. */
  uStackY_a10 = 0x14000458a;
  uVar8 = api_mobilebackup2_version_exchange_14017bdeb(pvStack_9c0,&uStack_8e8,'\x02',&uStack_8a8);
  if (uVar8 != 0) {
    uStackY_a10 = 0x14000459d;
    PrintMessageRecovered
              ("Could not perform backup protocol version exchange, error code %d\n",
               (ulonglong)uVar8);
    uStack_9d8 = 0xffffffff;
    uStack_9d0 = 6;
    goto LAB_140004803;
  }
  if (0 < _DAT_14000b734) {
    uStack_9d8 = 0xffffffff;
    uStack_9d0 = 6;
    goto LAB_140004803;
  }
  if (pcVar13 == (char *)0x0) {
LAB_140005c7e:
    uStack_958 = 0;
    uStack_9d0 = 6;
    goto LAB_140004803;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
  uStackY_a10 = 0x1400045dd;
  iVar9 = api__stat64i32_1401e27bc(pcVar13,auStack_8d8);
  if (iVar9 != 0) goto LAB_140005c7e;
  uStackY_a10 = 0x1400045f2;
  native_1400013c0(&pvStack_940,pcVar13);
  bVar28 = pvStack_940 == (void *)0x0;
  if (bVar28) {
    uStackY_a10 = 0x140004604;
    PrintMessageRecovered("ERROR\n");
  }
  uStack_958 = 0;
  uStackY_a10 = 0x14000462c;
  PostSyncNotificationRecovered(pvStack_9a0,"com.apple.itunes-mobdev.syncWillStart");
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_open; offline emulation
                       evidence. */
  uStackY_a10 = 0x140004646;
  api_afc_file_open_1401e29a7(pvStack_970,"/com.apple.itunes.lock_sync",2,&uStack_958);
  if (uStack_958 == 0) {
LAB_140004def:
    uStackY_a10 = 0x140004dfe;
    iVar7 = CheckFinishedSnapshotRecovered(auStack_868,pcVar12);
    if (iVar7 == 0) {
      uStack_9d0 = 6;
    }
    else {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e10;
      pvVar14 = api_plist_new_dict_140116f39();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e1b;
      pvVar15 = api_plist_new_bool_1401bbcc9('\0');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e2e;
      api_plist_dict_set_item_1400830e4(pvVar14,"RestoreSystemFiles",pvVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e36;
      pvVar15 = api_plist_new_bool_14007b42f('\x01');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e4a;
      api_plist_dict_set_item_1401ac360(pvVar14,"RestoreDontCopyBackup",pvVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e52;
      pvVar15 = api_plist_new_bool_1400ab958('\x01');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e64;
      api_plist_dict_set_item_14011e1c7(pvVar14,"RestorePreserveSettings",pvVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e72;
      pvVar15 = api_plist_new_string_1400c0a7f("mdm");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004e85;
      api_plist_dict_set_item_14014da90(pvVar14,"Password",pvVar15);
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
      uStackY_a10 = 0x140004ea4;
      iVar7 = api_mobilebackup2_send_request_14010b810
                        (pvStack_9c0,"Restore",pcStack_9b0,pcVar12,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      uStackY_a10 = 0x140004eaf;
      api_plist_free_140063b8a(pvVar14);
      if (iVar7 == 0) goto code_r0x000140004d71;
      if (1 < iVar7 + 7U) {
code_r0x000140004ebf:
        uStackY_a10 = 0x140004ecb;
        PrintMessageRecovered("ERROR\n");
      }
      uStack_9d0 = 6;
    }
    goto LAB_140004803;
  }
  uStackY_a10 = 0x140004663;
  PostSyncNotificationRecovered(pvStack_9a0,"com.apple.itunes-mobdev.syncLockRequest");
  fVar6 = _DAT_140008cd4;
  fVar5 = _DAT_140008cd0;
  do {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_lock; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004693;
    iVar9 = api_afc_file_lock_140181c84(pvStack_970,uStack_958,6);
    if (iVar9 == 0) {
      uStackY_a10 = 0x14000474e;
      PostSyncNotificationRecovered(pvStack_9a0,"com.apple.itunes-mobdev.syncDidStart");
      goto LAB_14000474e;
    }
    if (iVar9 == 0x13) {
                    /* Recovered VMProtect thunk: kernel32.dll!QueryPerformanceFrequency; offline
                       emulation evidence. */
      uStackY_a10 = 0x1400046ac;
      api_QueryPerformanceFrequency_140184036(&pvStack_9b8);
                    /* Recovered VMProtect thunk: kernel32.dll!QueryPerformanceCounter; offline
                       emulation evidence. */
      uStackY_a10 = 0x1400046b5;
      api_QueryPerformanceCounter_140052d22(&pvStack_918);
      do {
                    /* Recovered VMProtect thunk: kernel32.dll!QueryPerformanceCounter; offline
                       emulation evidence. */
        uStackY_a10 = 0x1400046bf;
        api_QueryPerformanceCounter_14006cb92();
      } while (((float)((longlong)pvStack_938 - (longlong)pvStack_918) /
               (float)(longlong)pvStack_9b8) * fVar5 * fVar5 < fVar6);
    }
    else {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_close; offline
                       emulation evidence. */
      uStackY_a10 = 0x1400046fb;
      api_afc_file_close_140109121(pvStack_970,uStack_958);
      uVar10 = 6;
      uStack_958 = 0;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x32);
  if (iVar7 == 0x32) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_close; offline
                       emulation evidence. */
    uStackY_a10 = 0x14000472d;
    api_afc_file_close_14017cab6(pvStack_970,uStack_958);
    uStack_958 = 0;
    uStack_9d0 = 6;
    goto LAB_140004803;
  }
LAB_14000474e:
  pcVar12 = pcStack_9c8;
  uStack_9d0 = uVar10;
  switch(uVar10) {
  case 0:
    uStackY_a10 = 0x140004872;
    PrintMessageRecovered("Starting backup...\n");
    pcVar12 = pcStack_9c8;
    uStackY_a10 = 0x140004889;
    pcVar27 = (char *)native_1400010c0(auStack_868,pcStack_9c8,0);
                    /* Recovered VMProtect thunk: kernel32.dll!CreateDirectoryA; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004897;
    iVar7 = api_CreateDirectoryA_14016a57a(pcVar27,(void *)0x0);
    uStack_9d8 = (uint)(iVar7 == 0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x1400048ac;
    api_free_1401dbdbc(pcVar27);
    if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
      uStackY_a10 = 0x1400048b7;
      iVar7 = api_GetLastError_1401edefe();
      if (iVar7 != 0xb7) {
        uStackY_a10 = 0x1400048ca;
        PrintMessageRecovered("Error creating the backup directory, error code\n");
        goto LAB_1400047e2;
      }
    }
    lVar20 = (longlong)pcStack_9b0 - (longlong)pcVar12;
    do {
      cVar1 = *pcVar12;
      cVar2 = pcVar12[lVar20];
      if (cVar1 != cVar2) break;
      pcVar12 = pcVar12 + 1;
    } while (cVar2 != '\0');
    if (cVar1 != cVar2) {
      uStackY_a10 = 0x14000490c;
      pcVar12 = (char *)native_1400010c0(auStack_868,pcStack_9b0,0);
                    /* Recovered VMProtect thunk: kernel32.dll!CreateDirectoryA; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004919;
      api_CreateDirectoryA_1401e29c8(pcVar12,(void *)0x0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStackY_a10 = 0x140004922;
      api_free_1400f8ea8(pcVar12);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStackY_a10 = 0x14000492c;
      api_free_140211ca5(pcVar13);
      uStackY_a10 = 0x140004947;
      pcVar13 = (char *)native_1400010c0(auStack_868,pcStack_9b0,"Info.plist",0);
    }
    if (pvStack_940 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
      uStackY_a10 = 0x14000495e;
      api_plist_free_1401504b7(pvStack_940);
      pvStack_940 = (void *)0x0;
    }
    uStackY_a10 = 0x14000497e;
    pvStack_940 = (void *)BuildBackupInfoPlistRecovered(pcStack_9b0,pvStack_9a0,pvStack_970);
    if (pvStack_940 == (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004997;
      uVar21 = api___acrt_iob_func_14015a834(2);
      uStackY_a10 = 0x1400049a7;
      native_140001010(uVar21,"Failed to generate Info.plist - aborting\n");
      uStack_9d0 = 6;
    }
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
    uStackY_a10 = 0x1400049bb;
    iVar7 = api_DeleteFileA_140214bf1(pcVar13);
    if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
      uStackY_a10 = 0x1400049c4;
      api_GetLastError_1401e1722();
    }
    pvStack_9b8 = (void *)0x0;
    if ((pvStack_940 != (void *)0x0) && (pcVar13 != (char *)0x0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_to_xml; offline emulation
                       evidence. */
      uStackY_a10 = 0x1400049e6;
      api_plist_to_xml_140204ed6(pvStack_940,&pvStack_9b8,auStack_980);
      uVar10 = auStack_980[0];
      pvVar14 = pvStack_9b8;
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
      uStackY_a10 = 0x1400049fe;
      pvVar15 = api_fopen_14010f9f6(pcVar13,"wb");
      if (pvVar15 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fwrite; offline emulation evidence.
                        */
        uStackY_a10 = 0x140004a1b;
        api_fwrite_1401bd21f(pvVar14,1,(ulonglong)uVar10,pvVar15);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
        uStackY_a10 = 0x140004a24;
        api_fclose_1400cce62(pvVar15);
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStackY_a10 = 0x140004a2e;
      api_free_1401cf9b2(pvStack_9b8);
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    uStackY_a10 = 0x140004a39;
    api_free_1400c8032(pcVar13);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x140004a43;
    api_plist_free_1400a4181(pvStack_940);
    pcVar12 = "Backup will be encrypted.\n";
    pvStack_940 = (void *)0x0;
    if (acStack_9cc[0] == '\0') {
      pcVar12 = "Backup will be unencrypted.\n";
    }
    uStackY_a10 = 0x140004a64;
    PrintMessageRecovered(pcVar12);
    uStackY_a10 = 0x140004a70;
    PrintMessageRecovered("Requesting backup from device...\n");
    pcVar12 = pcStack_9c8;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
    uStackY_a10 = 0x140004a94;
    iVar7 = api_mobilebackup2_send_request_14005e3b6
                      (pvStack_9c0,"Backup",pcStack_9b0,pcStack_9c8,(void *)0x0);
    if (iVar7 == 0) {
      pcVar13 = "Full backup mode.\n";
      if (!bVar28) {
        pcVar13 = "Incremental backup mode.\n";
      }
      uStackY_a10 = 0x140004ab2;
      PrintMessageRecovered(pcVar13);
    }
    else if (iVar7 == -6) {
      uStack_9d0 = 6;
      uStackY_a10 = 0x140004ad3;
      PrintMessageRecovered
                ("ERROR: Could not start backup process: backup protocol version mismatch!\n");
    }
    else {
      pcVar13 = 
      "ERROR: Could not start backup process: device refused to start the backup process.\n";
      if (iVar7 != -7) {
        pcVar13 = "ERROR: Could not start backup process: unspecified error occurred\n";
      }
      uStack_9d0 = 6;
      uStackY_a10 = 0x140004afd;
      PrintMessageRecovered(pcVar13);
    }
    goto LAB_140004d64;
  case 1:
    goto LAB_140004def;
  case 2:
    uStackY_a10 = 0x140004b0e;
    PrintMessageRecovered("ERROR\n");
    pcVar12 = pcStack_9c8;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
    uStackY_a10 = 0x140004b39;
    iVar7 = api_mobilebackup2_send_request_14013ad4b
                      (pvStack_9c0,"Info",pcStack_9b0,pcStack_9c8,(void *)0x0);
    if (iVar7 != 0) goto code_r0x000140004ebf;
    break;
  case 3:
    uStackY_a10 = 0x140004b53;
    PrintMessageRecovered("Requesting backup list from device...\n");
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
    uStackY_a10 = 0x140004b75;
    uVar10 = api_mobilebackup2_send_request_1400ea761
                       (pvStack_9c0,"List",pcStack_9b0,pcStack_9c8,(void *)0x0);
    if (uVar10 != 0) {
      uStackY_a10 = 0x140004b91;
      PrintMessageRecovered
                ("Error requesting backup list from device, error code %d\n",(ulonglong)uVar10);
      uStack_9d0 = 6;
      pcVar12 = pcStack_9c8;
      goto LAB_140004803;
    }
    break;
  case 4:
    uStackY_a10 = 0x140004bab;
    PrintMessageRecovered("Starting to unpack backup...\n");
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004bb0;
    pvVar14 = api_plist_new_dict_1402036f6();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004bc0;
    pvVar15 = api_plist_new_string_14018cd63("mdm");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004bd3;
    api_plist_dict_set_item_140206541(pvVar14,"Password",pvVar15);
    uStackY_a10 = 0x140004be7;
    PrintMessageRecovered("Backup password: %s\n",&UNK_140008810);
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
    uStackY_a10 = 0x140004c07;
    uVar10 = api_mobilebackup2_send_request_1401cc247
                       (pvStack_9c0,"Unback",pcStack_9b0,pcStack_9c8,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x140004c13;
    api_plist_free_140047695(pvVar14);
    if (uVar10 != 0) {
      pcVar12 = "Error requesting unback operation from device, error code %d\n";
code_r0x0001400047db:
      uStackY_a10 = 0x1400047e2;
      PrintMessageRecovered(pcVar12,(ulonglong)uVar10);
LAB_1400047e2:
      uStack_9d0 = 6;
      pcVar12 = pcStack_9c8;
      goto LAB_140004803;
    }
    break;
  case 5:
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004c32;
    pvVar14 = api_plist_new_dict_1401865e8();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004c40;
    pvVar15 = api_plist_new_string_14007b3f8(pcStack_9b0);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004c52;
    api_plist_dict_set_item_14011ba5a(pvVar14,"TargetIdentifier",pvVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004c5f;
    pvVar15 = api_plist_new_string_140181c9c("mdm");
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004c73;
    api_plist_dict_set_item_1401cd2d7(pvVar14,"OldPassword",pvVar15);
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_message;
                       offline emulation evidence. */
    uStackY_a10 = 0x140004c87;
    api_mobilebackup2_send_message_1400f7148(pvStack_9c0,"ChangePassword",pvVar14);
    auStack_98f[0] = 0;
    if (0xcffff < uVar25) {
      pvStack_950 = (void *)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!diagnostics_relay_client_start_service; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004cb6;
      iVar7 = api_diagnostics_relay_client_start_service_1400dde52
                        (pvStack_9a0,&pvStack_950,"idevicebackup2");
      if (iVar7 == 0) {
        pvStack_9b8 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_new_array; offline emulation
                       evidence. */
        uStackY_a10 = 0x140004cc9;
        pvVar15 = api_plist_new_array_140175924();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_string; offline emulation
                       evidence. */
        uStackY_a10 = 0x140004cd9;
        pvVar16 = api_plist_new_string_1400a6b66("PasswordConfigured");
                    /* Recovered VMProtect thunk: plist.dll!plist_array_append_item; offline
                       emulation evidence. */
        uStackY_a10 = 0x140004ce5;
        api_plist_array_append_item_140094713(pvVar15,pvVar16);
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!diagnostics_relay_query_mobilegestalt; offline emulation
                       evidence. */
        uStackY_a10 = 0x140004cf7;
        iVar7 = api_diagnostics_relay_query_mobilegestalt_14004e5de
                          (pvStack_950,pvVar15,&pvStack_9b8);
        if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_access_path; offline emulation
                       evidence. */
          uStackY_a10 = 0x140004d17;
          pvVar16 = (void *)api_plist_access_path_140076eb6(pvStack_9b8,2,"MobileGestalt");
                    /* Recovered VMProtect thunk: plist.dll!plist_get_bool_val; offline emulation
                       evidence. */
          uStackY_a10 = 0x140004d24;
          api_plist_get_bool_val_1401e635c(pvVar16,auStack_98f);
        }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        uStackY_a10 = 0x140004d2e;
        api_plist_free_1401d5a11(pvVar15);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        uStackY_a10 = 0x140004d38;
        api_plist_free_1400c97dc(pvStack_9b8);
                    /* Recovered VMProtect thunk: imobiledevice.dll!diagnostics_relay_goodbye;
                       offline emulation evidence. */
        uStackY_a10 = 0x140004d43;
        api_diagnostics_relay_goodbye_140088fa3(pvStack_950);
                    /* Recovered VMProtect thunk: imobiledevice.dll!diagnostics_relay_client_free;
                       offline emulation evidence. */
        uStackY_a10 = 0x140004d4c;
        api_diagnostics_relay_client_free_1401a2313(pvStack_950);
      }
    }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x140004d56;
    api_plist_free_14012ffdc(pvVar14);
    break;
  default:
LAB_140004d64:
    if (uStack_9d0 == 6) {
LAB_140004803:
      if (uStack_958 != 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_lock; offline emulation
                       evidence. */
        uStackY_a10 = 0x140004825;
        api_afc_file_lock_1400f8403(pvStack_970,uStack_958,0xc);
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_file_close; offline
                       emulation evidence. */
        uStackY_a10 = 0x140004832;
        api_afc_file_close_1400ac545(pvStack_970,uStack_958);
        uStack_958 = 0;
        if (uStack_9d0 < 2) {
          uStackY_a10 = 0x14000484e;
          PostSyncNotificationRecovered(pvStack_9a0,"com.apple.itunes-mobdev.syncDidFinish");
        }
      }
      if (pvStack_968 != (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_client_free; offline
                       emulation evidence. */
        uStackY_a10 = 0x140004860;
        api_lockdownd_client_free_1401c289c(pvStack_968);
LAB_140005cb4:
        pvStack_968 = (void *)0x0;
      }
      if (pvStack_9c0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_client_free;
                       offline emulation evidence. */
        uStackY_a10 = 0x140005cc7;
        api_mobilebackup2_client_free_140216529(pvStack_9c0);
        pvStack_9c0 = (void *)0x0;
      }
      if (pvStack_970 != (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_client_free; offline
                       emulation evidence. */
        uStackY_a10 = 0x140005cdb;
        api_afc_client_free_140114b5e(pvStack_970);
        pvStack_970 = (void *)0x0;
      }
      if (pvStack_920 != (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!np_client_free; offline
                       emulation evidence. */
        uStackY_a10 = 0x140005cef;
        api_np_client_free_140126b78(pvStack_920);
        pvStack_920 = (void *)0x0;
      }
                    /* Recovered VMProtect thunk: imobiledevice.dll!idevice_free; offline emulation
                       evidence. */
      uStackY_a10 = 0x140005cfe;
      api_idevice_free_140146f5f(pvStack_9a0);
      pvStack_9a0 = (void *)0x0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      uStackY_a10 = 0x140005d0f;
      api_free_1400f8303(&UNK_140008294);
      if (pcStack_9b0 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        uStackY_a10 = 0x140005d1f;
        api_free_14016cae1(pcStack_9b0);
        pcStack_9b0 = (char *)0x0;
      }
      if (pcVar12 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
        uStackY_a10 = 0x140005d33;
        api_free_1401ff06d(pcVar12);
      }
LAB_140005d4d:
      auStackY_a08[0] = uStack_68 ^ (ulonglong)auStackY_a08;
      uStackY_a10 = 0x140005d5c;
      if ((auStackY_a08[0] != _DAT_14000b008) || ((short)(auStackY_a08[0] >> 0x30) != 0)) {
        puVar23 = auStackY_a48;
        iVar7 = func_0x000140006b22(0x17);
        if (iVar7 != 0) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(2);
          puVar23 = auStackY_a40;
        }
        *(undefined8 *)(puVar23 + -8) = 0x140005e22;
        native_140005fec(0x14000b0f0);
        _DAT_14000b060 = *(undefined8 *)(puVar23 + 0x38);
        _DAT_14000b188 = puVar23 + 0x40;
        _DAT_14000b170 = *(undefined8 *)(puVar23 + 0x40);
        _DAT_14000b050 = 0xc0000409;
        _DAT_14000b054 = 1;
        _DAT_14000b068 = 1;
        uRam000000014000b070 = 2;
        *(ulonglong *)(puVar23 + 0x20) = _DAT_14000b008;
        *(undefined8 *)(puVar23 + 0x28) = _DAT_14000b000;
        *(undefined8 *)(puVar23 + -8) = 0x140005ec4;
        _DAT_14000b1e8 = _DAT_14000b060;
        uStack_9d8 = native_140005dc4(&UNK_1400075f0);
      }
      return uStack_9d8;
    }
    break;
  case 7:
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
    uStackY_a10 = 0x14000477c;
    pvVar14 = api_plist_new_dict_140117c5f();
                    /* Recovered VMProtect thunk: plist.dll!plist_new_bool; offline emulation
                       evidence. */
    uStackY_a10 = 0x140004788;
    pvVar15 = api_plist_new_bool_1401c44d7('\0');
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    uStackY_a10 = 0x14000479b;
    api_plist_dict_set_item_1400e8cbb(pvVar14,"CloudBackupState",pvVar15);
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_request;
                       offline emulation evidence. */
    uStackY_a10 = 0x1400047bc;
    uVar10 = api_mobilebackup2_send_request_1401f45fc
                       (pvStack_9c0,"EnableCloudBackup",pcStack_9b0,pcStack_9c8,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
    uStackY_a10 = 0x1400047c6;
    api_plist_free_1401bbd13(pvVar14);
    if (uVar10 != 0) {
      pcVar12 = "Error setting cloud backup state on device, error code %d\n";
      goto code_r0x0001400047db;
    }
  }
code_r0x000140004d71:
  dVar4 = _DAT_140008ca8;
  uVar24 = 0;
  iStack_960 = 0;
  pvStack_9a8 = (void *)0x0;
  auStack_980[0] = 0;
  uStack_9d4 = 0;
  uVar22 = uVar24;
LAB_140004da0:
  pcVar12 = (char *)0x0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStackY_a10 = 0x140004da7;
  api_free_140086006((void *)0x0);
  pvStack_950 = (void *)0x0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_message;
                       offline emulation evidence. */
  uStackY_a10 = 0x140004dc0;
  uVar10 = api_mobilebackup2_receive_message_14009fa68(pvStack_9c0,&pvStack_9a8,&pvStack_950);
  pvVar14 = pvStack_950;
  if (uVar10 == 0xfffffffb) goto LAB_140005046;
  if (uVar10 != 0) {
    uStackY_a10 = 0x140004ddf;
    PrintMessageRecovered("ERROR: Could not receive from mobilebackup2 (%d)\n",(ulonglong)uVar10);
    _DAT_14000b734 = _DAT_14000b734 + 1;
    goto LAB_140005046;
  }
  uStackY_a10 = 0x140004ee9;
  iVar7 = func_0x000140006c17(pvStack_950,"DLMessageDownloadFiles");
  if (iVar7 == 0) {
    uStackY_a10 = 0x140004efe;
    LogDeviceLinkOperationRecovered(pvStack_9a8,pvVar14);
    pvVar15 = pvStack_9a8;
    pvVar14 = pvStack_9c0;
    pcStack_978 = (char *)0x0;
    if (pvStack_9a8 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
      uStackY_a10 = 0x140004f21;
      iVar7 = api_plist_get_node_type_1401d7c29(pvStack_9a8);
      if (iVar7 == 4) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
        uStackY_a10 = 0x140004f32;
        uVar10 = api_plist_array_get_size_1400f44e3(pvVar15);
        if (1 < uVar10) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
          uStackY_a10 = 0x140004f4a;
          pvVar15 = api_plist_array_get_item_14008ac97(pvVar15,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
          uStackY_a10 = 0x140004f56;
          uVar10 = api_plist_array_get_size_1400cbe96(pvVar15);
          pcVar13 = pcVar12;
          if (uVar10 != 0) {
            do {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
              uStackY_a10 = 0x140004f6a;
              pvVar16 = api_plist_array_get_item_1400c44e6(pvVar15,(int)pcVar12);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
              uStackY_a10 = 0x140004f76;
              iVar7 = api_plist_get_node_type_140082238(pvVar16);
              if (iVar7 == 3) {
                pvStack_910 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                uStackY_a10 = 0x140004f8d;
                api_plist_get_string_val_1401f13d7(pvVar16,&pvStack_910);
                if (pvStack_910 != (void *)0x0) {
                  uStackY_a10 = 0x140004fa9;
                  iVar7 = SendBackupFileRecovered(pvVar14,auStack_868,pvStack_910,&pcStack_978);
                  if (iVar7 < 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                    uStackY_a10 = 0x140004fc4;
                    api_free_1400bbce7(pvStack_910);
                    pcVar13 = pcStack_978;
                    break;
                  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                  uStackY_a10 = 0x140004fb6;
                  api_free_1401d5248(pvStack_910);
                }
              }
              uVar8 = (int)pcVar12 + 1;
              pcVar12 = (char *)(ulonglong)uVar8;
              pcVar13 = pcStack_978;
            } while (uVar8 < uVar10);
          }
          auStack_8f8[0] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_send_raw; offline
                       emulation evidence. */
          uStackY_a10 = 0x140004fe3;
          api_mobilebackup2_send_raw_1400bfacd(pvVar14,auStack_8f8,4,&pvStack_948);
          if (pcVar13 == (char *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
            uStackY_a10 = 0x140004ff3;
            pcVar13 = (char *)api_plist_new_dict_14005e9a1();
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
            uStackY_a10 = 0x140005006;
            api_mobilebackup2_send_status_response_140204f7d(pvVar14,0,(char *)0x0,pcVar13);
          }
          else {
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
            uStackY_a10 = 0x1400050f9;
            api_mobilebackup2_send_status_response_140079fcb(pvVar14,-0xd,"Multi status",pcVar13);
          }
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
          uStackY_a10 = 0x140005010;
          api_plist_free_1401d1191(pcVar13);
        }
      }
    }
LAB_140005016:
    uVar22 = (ulonglong)uStack_9d4;
  }
  else {
    uStackY_a10 = 0x140005111;
    iVar7 = func_0x000140006c17(pvVar14,"DLMessageUploadFiles");
    if (iVar7 == 0) {
      uStackY_a10 = 0x140005122;
      LogDeviceLinkOperationRecovered(pvStack_9a8,pvVar14);
      uStackY_a10 = 0x140005138;
      iVar7 = ReceiveBackupFilesRecovered(pvStack_9c0,pvStack_9a8,auStack_868);
      auStack_980[0] = (int)uVar24 + iVar7;
    }
    else {
      uStackY_a10 = 0x140005151;
      iVar7 = func_0x000140006c17(pvVar14,"DLMessageGetFreeDiskSpace");
      if (iVar7 == 0) {
        pcStack_978 = (char *)0x0;
                    /* Recovered VMProtect thunk: kernel32.dll!GetDiskFreeSpaceExA; offline
                       emulation evidence. */
        uStackY_a10 = 0x140005170;
        iVar7 = api_GetDiskFreeSpaceExA_1400c9e14(auStack_868,&pcStack_978,0,0);
        pcVar13 = (char *)0xffffffff;
        if (iVar7 != 0) {
          pcVar13 = pcVar12;
        }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_uint; offline emulation
                       evidence. */
        uStackY_a10 = 0x140005183;
        pvVar14 = api_plist_new_uint_14012f1a0((ulonglong)pcStack_978);
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
        uStackY_a10 = 0x140005198;
        api_mobilebackup2_send_status_response_1400f03fd
                  (pvStack_9c0,(int)pcVar13,(char *)0x0,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
        uStackY_a10 = 0x1400051a2;
        api_plist_free_14006ee5c(pvVar14);
        uVar22 = (ulonglong)uStack_9d4;
      }
      else {
        uStackY_a10 = 0x1400051ba;
        iVar7 = func_0x000140006c17(pvVar14,"DLContentsOfDirectory");
        if (iVar7 == 0) {
          uStackY_a10 = 0x1400051d4;
          BuildDirectoryListingRecovered(pvStack_9c0,pvStack_9a8,auStack_868);
        }
        else {
          uStackY_a10 = 0x1400051e8;
          iVar7 = func_0x000140006c17(pvVar14,"DLMessageCreateDirectory");
          pvVar16 = pvStack_9a8;
          pvVar15 = pvStack_9c0;
          if (iVar7 == 0) {
            if (pvStack_9a8 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
              uStackY_a10 = 0x14000520c;
              iVar7 = api_plist_get_node_type_1401bbd00(pvStack_9a8);
              if (iVar7 == 4) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
                uStackY_a10 = 0x14000521d;
                uVar10 = api_plist_array_get_size_1401c8674(pvVar16);
                if (1 < uVar10) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005235;
                  pvVar14 = api_plist_array_get_item_14010ad57(pvVar16,1);
                  pvStack_918 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                  uStackY_a10 = 0x14000524b;
                  api_plist_get_string_val_14020255f(pvVar14,&pvStack_918);
                  uStackY_a10 = 0x14000525f;
                  pvVar14 = (void *)native_1400010c0(auStack_868,pvStack_918,0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                  uStackY_a10 = 0x14000526c;
                  api_free_1401d5a00(pvStack_918);
                  uStackY_a10 = 0x140005274;
                  iVar7 = native_140001cc0(pvVar14);
                  pcVar13 = pcVar12;
                  if (iVar7 < 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                    uStackY_a10 = 0x14000527d;
                    puVar17 = (undefined4 *)api__errno_140155a4d();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
                    uStackY_a10 = 0x140005285;
                    pcVar13 = (char *)api_strerror_1401060b5(*puVar17);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                    uStackY_a10 = 0x14000528e;
                    piVar18 = (int *)api__errno_140150199();
                    if (*piVar18 != 0x11) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                      uStackY_a10 = 0x140005299;
                      puVar19 = (uint *)api__errno_1400f1f36();
                      uStackY_a10 = 0x1400052ac;
                      PrintMessageRecovered("mkdir: %s (%d)\n",pcVar13,(ulonglong)*puVar19);
                    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                    uStackY_a10 = 0x1400052b1;
                    piVar18 = (int *)api__errno_14008973d();
                    iVar7 = *piVar18;
                    if (iVar7 == 2) {
                      pcVar12 = (char *)0xfffffffa;
                    }
                    else if (iVar7 == 0x11) {
                      pcVar12 = (char *)0xfffffff9;
                    }
                    else {
                      pcVar12 = (char *)(ulonglong)(uint)-iVar7;
                    }
                  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                  uStackY_a10 = 0x1400052d6;
                  api_free_14012f165(pvVar14);
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400052e8;
                  uVar10 = api_mobilebackup2_send_status_response_1401b3db4
                                     (pvVar15,(int)pcVar12,pcVar13,(void *)0x0);
                  if (uVar10 != 0) {
                    uStackY_a10 = 0x1400052fe;
                    PrintMessageRecovered
                              ("Could not send status response, error %d\n",(ulonglong)uVar10);
                  }
                  goto LAB_140005016;
                }
              }
            }
          }
          else {
            uStackY_a10 = 0x140005312;
            iVar7 = func_0x000140006c17(pvVar14,"DLMessageMoveFiles");
            if (iVar7 != 0) {
              uStackY_a10 = 0x140005329;
              iVar7 = func_0x000140006c17(pvVar14,"DLMessageMoveItems");
              if (iVar7 != 0) {
                uStackY_a10 = 0x140005340;
                iVar7 = func_0x000140006c17(pvVar14,"DLMessageRemoveFiles");
                if (iVar7 == 0) {
LAB_1400055ba:
                  uStackY_a10 = 0x1400055c7;
                  LogDeviceLinkOperationRecovered(pvStack_9a8,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400055d9;
                  pcVar13 = (char *)api_plist_array_get_item_1401d6e8e(pvStack_9a8,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_size; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400055e9;
                  pcStack_978 = pcVar13;
                  uVar10 = api_plist_array_get_size_1401cda6b(pcVar13);
                  puVar26 = &UNK_140008964;
                  if (uVar10 == 1) {
                    puVar26 = &UNK_140007683;
                  }
                  uStackY_a10 = 0x14000560f;
                  PrintMessageRecovered("Removing %d file%s\n",(ulonglong)uVar10,puVar26);
                  uVar8 = 0;
                  pcVar27 = pcVar12;
                  if (uVar10 != 0) {
                    do {
                      bVar28 = false;
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                      uStackY_a10 = 0x14000562c;
                      pvVar14 = api_plist_array_get_item_1401d2f68(pcVar13,uVar8);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                      uStackY_a10 = 0x140005637;
                      iVar7 = api_plist_get_node_type_1400e1113(pvVar14);
                      if (iVar7 == 3) {
                        pvStack_908 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                        uStackY_a10 = 0x140005651;
                        api_plist_get_string_val_14007ca36(pvVar14,&pvStack_908);
                        if (pvStack_908 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!strchr; offline emulation evidence.
                        */
                          uStackY_a10 = 0x140005669;
                          lVar20 = api_strchr_1401adf5d(pvStack_908,0x2f);
                          if (lVar20 != 0) {
                            uStackY_a10 = 0x14000567f;
                            iVar7 = func_0x000140006c17(lVar20 + 1,"Manifest.mbdx");
                            if (iVar7 == 0) {
                              bVar28 = true;
                            }
                          }
                          uStackY_a10 = 0x140005697;
                          pvVar14 = (void *)native_1400010c0(auStack_868,pvStack_908,0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                          uStackY_a10 = 0x1400056a4;
                          api_free_140150454(pvStack_908);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
                          uStackY_a10 = 0x1400056b1;
                          iVar7 = api__stat64i32_1400bfac6(pvVar14,auStack_8d8);
                          if ((iVar7 == 0) && ((uStack_8d2 & 0xf000) == 0x4000)) {
                            uStackY_a10 = 0x1400056d3;
                            uVar11 = native_140001f50(pvVar14);
                            uVar22 = (ulonglong)uVar11;
                          }
                          else {
                            uVar22 = 0;
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
                            uStackY_a10 = 0x1400056e3;
                            iVar7 = api_DeleteFileA_1401c62c6(pvVar14);
                            if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
                              uStackY_a10 = 0x1400056ee;
                              iVar7 = api_GetLastError_1401159bf();
                              if (iVar7 == 2) {
                                uVar22 = 2;
                              }
                              else {
                                uVar22 = 0x11;
                                if (iVar7 != 0xb7) {
                                  uVar22 = 0xe;
                                }
                              }
                            }
                          }
                          if ((uVar22 & 0xfffffffd) != 0) {
                            if (!bVar28) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
                              uStackY_a10 = 0x140005720;
                              uVar21 = api_strerror_1400ca742(uVar22);
                              uStackY_a10 = 0x140005735;
                              PrintMessageRecovered
                                        ("Could not remove \'%s\': %s (%d)\n",pvVar14,uVar21,uVar22)
                              ;
                            }
                            if ((int)uVar22 == 0x11) {
                              pcVar27 = (char *)0xfffffff9;
                            }
                            else {
                              pcVar27 = (char *)(ulonglong)(uint)-(int)uVar22;
                            }
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
                            uStackY_a10 = 0x14000574f;
                            pcVar12 = (char *)api_strerror_140211651(uVar22);
                          }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                          uStackY_a10 = 0x14000575b;
                          api_free_140198255(pvVar14);
                        }
                      }
                      uVar8 = uVar8 + 1;
                      pcVar13 = pcStack_978;
                    } while (uVar8 < uVar10);
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005776;
                  pvVar14 = api_plist_new_dict_14015a813();
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
                  uStackY_a10 = 0x14000578d;
                  uVar10 = api_mobilebackup2_send_status_response_1401a926f
                                     (pvStack_9c0,(int)pcVar27,pcVar12,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
                  uStackY_a10 = 0x140005798;
                  api_plist_free_14017c8a0(pvVar14);
                  if (uVar10 == 0) {
                    uVar22 = (ulonglong)uStack_9d4;
                  }
                  else {
                    uStackY_a10 = 0x1400057af;
                    PrintMessageRecovered
                              ("Could not send status response, error %d\n",(ulonglong)uVar10);
                    uVar22 = (ulonglong)uStack_9d4;
                  }
                  goto LAB_140005025;
                }
                uStackY_a10 = 0x140005357;
                iVar7 = func_0x000140006c17(pvVar14,"DLMessageRemoveItems");
                if (iVar7 == 0) goto LAB_1400055ba;
                uStackY_a10 = 0x14000536e;
                iVar7 = func_0x000140006c17(pvVar14,"DLMessageCopyItem");
                if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005388;
                  pvVar14 = api_plist_array_get_item_14014e276(pvStack_9a8,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005399;
                  pvVar15 = api_plist_array_get_item_1401b3467(pvStack_9a8,2);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400053a4;
                  iVar7 = api_plist_get_node_type_14013ad3e(pvVar14);
                  if (iVar7 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                    uStackY_a10 = 0x1400053b6;
                    iVar7 = api_plist_get_node_type_14018d561(pvVar15);
                    if (iVar7 == 3) {
                      pcStack_978 = (char *)0x0;
                      pvStack_930 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                      uStackY_a10 = 0x1400053d4;
                      api_plist_get_string_val_1401cafc4(pvVar14,&pcStack_978);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                      uStackY_a10 = 0x1400053e2;
                      api_plist_get_string_val_140063987(pvVar15,&pvStack_930);
                      if ((pcStack_978 != (char *)0x0) && (pvStack_930 != (void *)0x0)) {
                        uStackY_a10 = 0x14000540c;
                        pvVar14 = (void *)native_1400010c0(auStack_868,pcStack_978,0);
                        uStackY_a10 = 0x140005422;
                        pvVar15 = (void *)native_1400010c0(auStack_868,pvStack_930,0);
                        uStackY_a10 = 0x140005439;
                        PrintMessageRecovered("Copying \'%s\' to \'%s\'\n",pcStack_978);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
                        uStackY_a10 = 0x140005446;
                        iVar7 = api__stat64i32_14004f879(pvVar14,auStack_8d8);
                        if ((iVar7 == 0) && ((uStack_8d2 & 0xf000) == 0x4000)) {
                          uStackY_a10 = 0x140005463;
                          native_140003e70(pvVar14);
                        }
                        else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
                          uStackY_a10 = 0x140005471;
                          iVar7 = api__stat64i32_140063a65(pvVar14);
                          if ((iVar7 == 0) && ((uStack_8d2 & 0xf000) == 0x8000)) {
                            uStackY_a10 = 0x140005493;
                            native_140003d30(pvVar14);
                          }
                        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                        uStackY_a10 = 0x14000549b;
                        api_free_140153df6(pvVar15);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                        uStackY_a10 = 0x1400054a5;
                        api_free_14014ab7b(pvVar14);
                      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x1400054af;
                      api_free_140203fa8(pcStack_978);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x1400054b8;
                      api_free_14020b53f(pvStack_930);
                    }
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400054bf;
                  pvVar14 = api_plist_new_dict_1401fc2c5();
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
                  uStackY_a10 = 0x1400054d4;
                  uVar10 = api_mobilebackup2_send_status_response_140202585
                                     (pvStack_9c0,0,(char *)0x0,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
                  uStackY_a10 = 0x1400054df;
                  api_plist_free_140168b49(pvVar14);
                  if (uVar10 != 0) {
                    uStackY_a10 = 0x1400054f2;
                    PrintMessageRecovered
                              ("Could not send status response, error %d\n",(ulonglong)uVar10);
                  }
                  uVar22 = (ulonglong)uStack_9d4;
                  goto LAB_140005025;
                }
                uStackY_a10 = 0x14000550a;
                iVar9 = func_0x000140006c17(pvVar14,"DLMessageDisconnect");
                iVar7 = iStack_960;
                if (iVar9 == 0) goto LAB_14000507a;
                uStackY_a10 = 0x140005521;
                iVar7 = func_0x000140006c17(pvVar14,"DLMessageProcessMessage");
                if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x14000553d;
                  pvStack_998 = api_plist_array_get_item_14014c548(pvStack_9a8,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                  uStackY_a10 = 0x14000554b;
                  iVar7 = api_plist_get_node_type_14006f7a4(pvStack_998);
                  if (iVar7 != 5) {
                    uStackY_a10 = 0x14000555c;
                    PrintMessageRecovered("Unknown message received!\n");
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x14000556d;
                  pvVar14 = api_plist_dict_get_item_1401cd1cf(pvStack_998,"ErrorCode");
                  uVar10 = 0xffffffff;
                  iVar7 = iStack_960;
                  if (pvVar14 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                    uStackY_a10 = 0x140005583;
                    iVar9 = api_plist_get_node_type_140053365(pvVar14);
                    iVar7 = iStack_960;
                    if (iVar9 == 1) {
                      pvStack_938 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_uint_val; offline emulation
                       evidence. */
                      uStackY_a10 = 0x14000559d;
                      api_plist_get_uint_val_1401c7da7(pvVar14,&pvStack_938);
                      uVar10 = (uint)pvStack_938;
                      if ((uint)pvStack_938 == 0) {
                        uStack_9d8 = 0;
                        iVar7 = 1;
                      }
                      else {
                        uStack_9d8 = -(uint)pvStack_938;
                        iVar7 = iStack_960;
                      }
                    }
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005a7e;
                  pvVar14 = api_plist_dict_get_item_1400cfde5(pvStack_998,"ErrorDescription");
                  pvStack_948 = (void *)0x0;
                  if (pvVar14 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                    uStackY_a10 = 0x140005a97;
                    iVar9 = api_plist_get_node_type_140174625(pvVar14);
                    if (iVar9 == 3) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                      uStackY_a10 = 0x140005aa9;
                      api_plist_get_string_val_1401e9fad(pvVar14,&pvStack_948);
                    }
                  }
                  if (uVar10 != 0) {
                    if (pvStack_948 == (void *)0x0) {
                      uStackY_a10 = 0x140005ad7;
                      PrintMessageRecovered("ErrorCode %d: (Unknown)\n",(ulonglong)uVar10);
                    }
                    else {
                      uStackY_a10 = 0x140005ac9;
                      PrintMessageRecovered("ErrorCode %d: %s\n",(ulonglong)uVar10,pvStack_948);
                    }
                  }
                  if (pvStack_948 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                    uStackY_a10 = 0x140005ae6;
                    api_free_140149a40(pvStack_948);
                  }
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_item; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005af8;
                  pvVar14 = api_plist_dict_get_item_1400d1968(pvStack_998,"Content");
                  if (pvVar14 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                    uStackY_a10 = 0x140005b0c;
                    iVar9 = api_plist_get_node_type_140123b53(pvVar14);
                    if (iVar9 == 3) {
                      pvStack_948 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                      uStackY_a10 = 0x140005b26;
                      api_plist_get_string_val_14020e816(pvVar14,&pvStack_948);
                      uStackY_a10 = 0x140005b33;
                      PrintMessageRecovered("Content:\n");
                      uStackY_a10 = 0x140005b43;
                      PrintMessageRecovered("%s",pvStack_948);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x140005b4d;
                      api_free_140218b48(pvStack_948);
                    }
                  }
                  goto LAB_14000507a;
                }
                goto LAB_140005025;
              }
            }
            uStackY_a10 = 0x1400057da;
            LogDeviceLinkOperationRecovered(pvStack_9a8,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_array_get_item; offline emulation
                       evidence. */
            uStackY_a10 = 0x1400057ec;
            pvVar14 = api_plist_array_get_item_1401f4613(pvStack_9a8,1);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_get_size; offline emulation
                       evidence. */
            uStackY_a10 = 0x1400057f8;
            uVar10 = api_plist_dict_get_size_14004d8c9(pvVar14);
            puVar26 = &UNK_140008964;
            if (uVar10 == 1) {
              puVar26 = &UNK_140007683;
            }
            uStackY_a10 = 0x14000581a;
            PrintMessageRecovered("Moving %d file%s\n",(ulonglong)uVar10,puVar26);
            pvStack_9b8 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_array_new_iter; offline emulation
                       evidence. */
            uStackY_a10 = 0x14000582c;
            api_plist_array_new_iter_1400a972d(pvVar14,&pvStack_9b8);
            if (pvStack_9b8 == (void *)0x0) {
              iVar7 = -1;
              pcVar13 = "Could not create dict iterator";
              uStackY_a10 = 0x1400059e5;
              PrintMessageRecovered("Could not create dict iterator\n");
            }
            else {
              pvStack_928 = (void *)0x0;
              pvStack_900 = (void *)0x0;
              do {
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_next_item; offline emulation
                       evidence. */
                uStackY_a10 = 0x140005860;
                api_plist_dict_next_item_1401d7c4e(pvVar14,pvStack_9b8,&pvStack_928,&pvStack_900);
                if (pvStack_928 != (void *)0x0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_get_node_type; offline emulation
                       evidence. */
                  uStackY_a10 = 0x140005876;
                  iVar7 = api_plist_get_node_type_140210eeb(pvStack_900);
                  if (iVar7 == 3) {
                    pvStack_938 = (void *)0x0;
                    /* Recovered VMProtect thunk: plist.dll!plist_get_string_val; offline emulation
                       evidence. */
                    uStackY_a10 = 0x140005890;
                    api_plist_get_string_val_1401f8bfd(pvStack_900,&pvStack_938);
                    if (pvStack_938 != (void *)0x0) {
                      uStackY_a10 = 0x1400058ad;
                      pvVar15 = (void *)native_1400010c0(auStack_868,pvStack_938,0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x1400058b9;
                      api_free_14012397e(pvStack_938);
                      uStackY_a10 = 0x1400058cd;
                      pvVar16 = (void *)native_1400010c0(auStack_868,pvStack_928,0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_stat64i32; offline emulation
                       evidence. */
                      uStackY_a10 = 0x1400058dd;
                      iVar7 = api__stat64i32_14006e269(pvVar15,auStack_8d8);
                      if ((iVar7 == 0) && ((uStack_8d2 & 0xf000) == 0x4000)) {
                        uStackY_a10 = 0x1400058ff;
                        native_140001f50(pvVar15);
                      }
                      else {
                    /* Recovered VMProtect thunk: kernel32.dll!DeleteFileA; offline emulation
                       evidence. */
                        uStackY_a10 = 0x14000590a;
                        iVar7 = api_DeleteFileA_1401afd55(pvVar15);
                        if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: kernel32.dll!GetLastError; offline emulation
                       evidence. */
                          uStackY_a10 = 0x140005913;
                          api_GetLastError_1401ede88();
                        }
                      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!rename; offline emulation evidence.
                        */
                      uStackY_a10 = 0x14000591f;
                      iVar7 = api_rename_14004adcd(pvVar16,pvVar15);
                      if (iVar7 < 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                        uStackY_a10 = 0x14000595b;
                        api__errno_1400faa2b();
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                        uStackY_a10 = 0x140005963;
                        puVar17 = (undefined4 *)api__errno_140214c52();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
                        uStackY_a10 = 0x14000596b;
                        uVar21 = api_strerror_1401e27c2(*puVar17);
                        uStackY_a10 = 0x140005984;
                        PrintMessageRecovered
                                  ("Renameing \'%s\' to \'%s\' failed: %s (%d)\n",pvVar16,pvVar15,
                                   uVar21);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                        uStackY_a10 = 0x14000598a;
                        piVar18 = (int *)api__errno_140207474();
                        iVar7 = *piVar18;
                        if (iVar7 == 2) {
                          pcVar12 = (char *)0xfffffffa;
                        }
                        else if (iVar7 == 0x11) {
                          pcVar12 = (char *)0xfffffff9;
                        }
                        else {
                          pcVar12 = (char *)(ulonglong)(uint)-iVar7;
                        }
                    /* Recovered VMProtect thunk: ucrtbase.dll!_errno; offline emulation evidence.
                        */
                        uStackY_a10 = 0x1400059b2;
                        puVar17 = (undefined4 *)api__errno_140217bd2();
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
                        uStackY_a10 = 0x1400059b9;
                        pcVar13 = (char *)api_strerror_1400ad322(*puVar17);
                        break;
                      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x14000592d;
                      api_free_1400cbf20(pvVar16);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                      uStackY_a10 = 0x140005935;
                      api_free_14012b3b3(pvVar15);
                    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
                    uStackY_a10 = 0x14000593f;
                    api_free_14018f825(pvStack_928);
                    pvStack_928 = (void *)0x0;
                  }
                }
                pcVar13 = pcVar12;
              } while (pvStack_900 != (void *)0x0);
              iVar7 = (int)pcVar12;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
              uStackY_a10 = 0x1400059c7;
              api_free_1401ccba4(pvStack_9b8);
            }
                    /* Recovered VMProtect thunk: plist.dll!plist_new_dict; offline emulation
                       evidence. */
            uStackY_a10 = 0x1400059eb;
            pvVar14 = api_plist_new_dict_1401ab765();
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!mobilebackup2_send_status_response; offline emulation
                       evidence. */
            uStackY_a10 = 0x140005a01;
            uVar10 = api_mobilebackup2_send_status_response_1401cfc61
                               (pvStack_9c0,iVar7,pcVar13,pvVar14);
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
            uStackY_a10 = 0x140005a0d;
            api_plist_free_14016ea18(pvVar14);
            if (uVar10 != 0) {
              uStackY_a10 = 0x140005a1f;
              PrintMessageRecovered("Could not send status response, error %d\n",(ulonglong)uVar10);
            }
            uVar22 = (ulonglong)uStack_9d4;
          }
        }
      }
    }
  }
LAB_140005025:
  if ((0.0 < _DAT_14000b738) && ((int)uVar22 == 0)) {
    if (dVar4 <= _DAT_14000b738) {
      uVar22 = 1;
    }
    uStack_9d4 = (uint)uVar22;
  }
  uVar24 = (ulonglong)auStack_980[0];
LAB_140005046:
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStackY_a10 = 0x140005050;
  api_plist_free_140209290(pvStack_9a8);
  pvStack_9a8 = (void *)0x0;
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStackY_a10 = 0x14000505f;
  api_free_1401034ed(pvStack_950);
  pvStack_950 = (void *)0x0;
  iVar7 = iStack_960;
  if (0 < _DAT_14000b734) goto LAB_14000507a;
  goto LAB_140004da0;
LAB_14000507a:
                    /* Recovered VMProtect thunk: plist.dll!plist_free; offline emulation evidence.
                        */
  uStackY_a10 = 0x140005084;
  api_plist_free_1401d5482(pvStack_9a8);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  uStackY_a10 = 0x14000508e;
  api_free_14016e021(pvStack_950);
  if (uStack_9d0 == 0) {
    uStackY_a10 = 0x140005c1a;
    PrintMessageRecovered("Received %d files from device.\n",uVar24);
    if (iVar7 != 0) {
      uStackY_a10 = 0x140005c2f;
      iVar7 = CheckFinishedSnapshotRecovered(auStack_868,pcStack_9b0);
      if (iVar7 != 0) {
        uStackY_a10 = 0x140005c3f;
        PrintMessageRecovered("Backup Successful.\n");
        pcVar12 = pcStack_9c8;
        goto LAB_140004803;
      }
    }
    if (_DAT_14000b734 == 0) {
      uStackY_a10 = 0x140005c72;
      PrintMessageRecovered("Backup Failed (Error Code %d).\n",(ulonglong)-uStack_9d8);
      pcVar12 = pcStack_9c8;
    }
    else {
      uStackY_a10 = 0x140005c59;
      PrintMessageRecovered("Backup Aborted.\n");
      pcVar12 = pcStack_9c8;
    }
  }
  else if (uStack_9d0 == 1) {
    if (iVar7 == 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_remove_path; offline
                       emulation evidence. */
      uStackY_a10 = 0x140005be9;
      api_afc_remove_path_1401242a8(pvStack_970,"/iTunesRestore/RestoreApplications.plist");
                    /* Recovered VMProtect thunk: imobiledevice.dll!afc_remove_path; offline
                       emulation evidence. */
      uStackY_a10 = 0x140005bfa;
      api_afc_remove_path_14010b981(pvStack_970,"/iTunesRestore");
      uStackY_a10 = 0x140005c07;
      PrintMessageRecovered("ERROR\n");
      pcVar12 = pcStack_9c8;
    }
    else {
      uStackY_a10 = 0x140005baa;
      PrintMessageRecovered("IKEY MDM Successful.\n");
      uStackY_a10 = 0x140005bb6;
      PrintMessageRecovered("IKEY MDM Successful.\n");
      uStackY_a10 = 0x140005bc2;
      PrintMessageRecovered("IKEY MDM Successful.\n");
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
      uStackY_a10 = 0x140005bca;
      uVar21 = api___acrt_iob_func_1400ba4a0(1);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fflush; offline emulation evidence.
                        */
      uStackY_a10 = 0x140005bd3;
      api_fflush_140094d02(uVar21);
      pcVar12 = pcStack_9c8;
    }
  }
  else if (uStack_9d0 == 4) {
    if (_DAT_14000b734 == 0) {
      uStackY_a10 = 0x140005b89;
      PrintMessageRecovered("The files can now be found in the \"_unback_\" directory.\n");
      uStackY_a10 = 0x140005b95;
      PrintMessageRecovered("Unback Successful.\n");
      pcVar12 = pcStack_9c8;
    }
    else {
      uStackY_a10 = 0x140005b78;
      PrintMessageRecovered("Unback Aborted.\n");
      pcVar12 = pcStack_9c8;
    }
  }
  else {
    pcVar12 = pcStack_9c8;
    if ((uStack_9d0 != 5) && (uStack_9d0 != 7)) {
      if (_DAT_14000b734 == 0) {
        uStackY_a10 = 0x140005b5e;
        PrintMessageRecovered("Operation Successful.\n");
        pcVar12 = pcStack_9c8;
      }
      else {
        uStackY_a10 = 0x1400050dd;
        PrintMessageRecovered("Operation Aborted.\n");
        pcVar12 = pcStack_9c8;
      }
    }
  }
  goto LAB_140004803;
}

