/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_1800017e0(void *param_1,longlong *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  void *arg0;
  void *arg0_00;
  void *arg0_01;
  void *arg0_02;
  void *arg0_03;
  void *pvVar10;
  void *pvVar11;
  void *pvVar12;
  void *pvVar13;
  undefined1 auStack_d8 [32];
  undefined4 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  longlong lStack_80;
  longlong lStack_78;
  longlong lStack_70;
  longlong lStack_68;
  longlong *plStack_60;
  void *pvStack_58;
  undefined8 uStack_50;
  longlong lStack_48;
  ulonglong uStack_40;
  
  uStack_40 = _DAT_18002c008 ^ (ulonglong)auStack_d8;
  arg0_03 = (void *)0x0;
  uStack_84 = 0xfffffffd;
  uStack_88 = 0;
  pvVar12 = (void *)0x0;
  uStack_8c = 0;
  pvVar11 = (void *)0x0;
  uStack_94 = 0;
  pvVar13 = (void *)0x0;
  uStack_90 = 0;
  pvVar10 = (void *)0x0;
  plStack_60 = param_2;
  pvStack_58 = param_1;
  if ((param_1 == (void *)0x0) || (*param_2 == 0)) goto LAB_1800020a0;
  debug_info_real_Recovered
            ("pair_record_generate_keys_and_certs",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",0x18c,
             "Generating keys and certificates...");
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BN_new; offline emulation
                       evidence. */
  uVar4 = api_BN_new_180c00607();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!RSA_new; offline emulation
                       evidence. */
  uVar5 = api_RSA_new_1808dae0d();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!RSA_new; offline emulation
                       evidence. */
  uVar6 = api_RSA_new_180b2cd60();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BN_set_word; offline
                       emulation evidence. */
  api_BN_set_word_180864ddf(uVar4,0x10001);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!RSA_generate_key_ex; offline
                       emulation evidence. */
  api_RSA_generate_key_ex_18052ce78(uVar5,0x800,uVar4,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!RSA_generate_key_ex; offline
                       emulation evidence. */
  api_RSA_generate_key_ex_180170387(uVar6,0x800,uVar4,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BN_free; offline emulation
                       evidence. */
  api_BN_free_1802daf94(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_new; offline
                       emulation evidence. */
  lStack_68 = api_EVP_PKEY_new_180127513();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_assign; offline
                       emulation evidence. */
  api_EVP_PKEY_assign_180538e17(lStack_68,6,uVar5);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_new; offline
                       emulation evidence. */
  lStack_80 = api_EVP_PKEY_new_1800b81d1();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_assign; offline
                       emulation evidence. */
  api_EVP_PKEY_assign_1804f5298(lStack_80,6,uVar6);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_new; offline emulation
                       evidence. */
  lVar7 = api_X509_new_180412342();
  lStack_70 = lVar7;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_new; offline
                       emulation evidence. */
  uVar4 = api_ASN1_INTEGER_new_1801c6900();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_set; offline
                       emulation evidence. */
  api_ASN1_INTEGER_set_1803b5f71(uVar4,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_serialNumber;
                       offline emulation evidence. */
  api_X509_set_serialNumber_1800ba043(lVar7,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_free; offline
                       emulation evidence. */
  api_ASN1_INTEGER_free_1806703a4(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_version; offline
                       emulation evidence. */
  api_X509_set_version_1803573dc(lVar7,2);
  native_180001710(lVar7,0x57,"critical,CA:TRUE");
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_new; offline
                       emulation evidence. */
  uVar4 = api_ASN1_TIME_new_180852060();
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  uVar5 = api__time64_1803431a9(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
  api_ASN1_TIME_set_18040efe1(uVar4,uVar5);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notBefore; offline
                       emulation evidence. */
  api_X509_set1_notBefore_180541f46(lVar7,uVar4);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  lVar8 = api__time64_180ca3104(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
  api_ASN1_TIME_set_1801975f3(uVar4,lVar8 + 0x12cc0300);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notAfter; offline
                       emulation evidence. */
  api_X509_set1_notAfter_1805bb190(lVar7,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_free; offline
                       emulation evidence. */
  api_ASN1_TIME_free_18022baa6(uVar4);
  lVar8 = lStack_68;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_pubkey; offline
                       emulation evidence. */
  api_X509_set_pubkey_180436e15(lVar7,lStack_68);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_sha1; offline emulation
                       evidence. */
  uVar4 = api_EVP_sha1_1800e2b4a();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_sign; offline emulation
                       evidence. */
  api_X509_sign_18080faa6(lVar7,lVar8,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_new; offline emulation
                       evidence. */
  lVar9 = api_X509_new_1806ae50f();
  lStack_78 = lVar9;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_new; offline
                       emulation evidence. */
  uVar4 = api_ASN1_INTEGER_new_1803c56b0();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_set; offline
                       emulation evidence. */
  api_ASN1_INTEGER_set_18042de30(uVar4,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_serialNumber;
                       offline emulation evidence. */
  api_X509_set_serialNumber_1802faf15(lVar9,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_free; offline
                       emulation evidence. */
  api_ASN1_INTEGER_free_180253ef3(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_version; offline
                       emulation evidence. */
  api_X509_set_version_18054d151(lVar9,2);
  native_180001710(lVar9,0x57,"critical,CA:FALSE");
  native_180001710(lVar9,0x53,"critical,digitalSignature,keyEncipherment");
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_new; offline
                       emulation evidence. */
  uVar4 = api_ASN1_TIME_new_18036cef4();
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  uVar5 = api__time64_18099281e(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
  api_ASN1_TIME_set_1808b1650(uVar4,uVar5);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notBefore; offline
                       emulation evidence. */
  api_X509_set1_notBefore_180c718e4(lVar9,uVar4);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
  lVar7 = api__time64_18080abff(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
  api_ASN1_TIME_set_18009160a(uVar4,lVar7 + 0x12cc0300);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notAfter; offline
                       emulation evidence. */
  api_X509_set1_notAfter_1808bae7b(lVar9,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_free; offline
                       emulation evidence. */
  api_ASN1_TIME_free_180c6fa36(uVar4);
  lVar7 = lStack_80;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_pubkey; offline
                       emulation evidence. */
  api_X509_set_pubkey_1802a1441(lVar9,lStack_80);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_sha1; offline emulation
                       evidence. */
  uVar4 = api_EVP_sha1_180165305();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_sign; offline emulation
                       evidence. */
  api_X509_sign_18032b8b6(lVar9,lVar8,uVar4);
  arg0_01 = arg0_03;
  arg0 = arg0_03;
  arg0_00 = arg0_03;
  arg0_02 = arg0_03;
  if ((lStack_70 != 0) &&
     (((arg0_01 = pvVar10, arg0 = pvVar11, arg0_00 = pvVar12, arg0_02 = pvVar13, lVar8 != 0 &&
       (lVar9 != 0)) && (lVar7 != 0)))) {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_s_mem; offline emulation
                       evidence. */
    uVar4 = api_BIO_s_mem_1803e429a();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new; offline emulation
                       evidence. */
    uVar4 = api_BIO_new_1807a1e72(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_write_bio_X509; offline
                       emulation evidence. */
    iVar2 = api_PEM_write_bio_X509_180a20885(uVar4,lStack_70);
    arg0 = arg0_03;
    if (0 < iVar2) {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_ctrl; offline emulation
                       evidence. */
      uVar3 = api_BIO_ctrl_180c149d9(uVar4,3,0,&uStack_50);
      uStack_8c = uVar3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
      arg0 = api_malloc_180a9c6fc((ulonglong)uVar3);
      if (arg0 != (void *)0x0) {
        func_0x00018001cf67(arg0,uStack_50,uVar3);
      }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
      api_BIO_free_1802bcea8(uVar4);
      lVar9 = lStack_78;
    }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_s_mem; offline emulation
                       evidence. */
    uVar4 = api_BIO_s_mem_1801cf540();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new; offline emulation
                       evidence. */
    uVar4 = api_BIO_new_180b43ad1(uVar4);
    uStack_a8 = 0;
    uStack_b0 = 0;
    uStack_b8 = 0;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_write_bio_PrivateKey;
                       offline emulation evidence. */
    iVar2 = api_PEM_write_bio_PrivateKey_180290ea2(uVar4,lVar8,0,0);
    arg0_00 = arg0_03;
    if (0 < iVar2) {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_ctrl; offline emulation
                       evidence. */
      uVar3 = api_BIO_ctrl_1800d9f66(uVar4,3,0,&uStack_50);
      uStack_88 = uVar3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
      arg0_00 = api_malloc_1809bbc44((ulonglong)uVar3);
      if (arg0_00 != (void *)0x0) {
        func_0x00018001cf67(arg0_00,uStack_50,uVar3);
      }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
      api_BIO_free_1804c6cbe(uVar4);
      lVar9 = lStack_78;
    }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_s_mem; offline emulation
                       evidence. */
    uVar4 = api_BIO_s_mem_180646dde();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new; offline emulation
                       evidence. */
    uVar4 = api_BIO_new_1809da291(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_write_bio_X509; offline
                       emulation evidence. */
    iVar2 = api_PEM_write_bio_X509_180363d97(uVar4,lVar9);
    arg0_01 = arg0_03;
    if (0 < iVar2) {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_ctrl; offline emulation
                       evidence. */
      uVar3 = api_BIO_ctrl_180c036f0(uVar4,3,0,&uStack_50);
      uStack_90 = uVar3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
      arg0_01 = api_malloc_180955202((ulonglong)uVar3);
      if (arg0_01 != (void *)0x0) {
        func_0x00018001cf67(arg0_01,uStack_50,uVar3);
      }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
      api_BIO_free_180153518(uVar4);
    }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_s_mem; offline emulation
                       evidence. */
    uVar4 = api_BIO_s_mem_180c2fa46();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new; offline emulation
                       evidence. */
    uVar4 = api_BIO_new_18047548b(uVar4);
    uStack_a8 = 0;
    uStack_b0 = 0;
    uStack_b8 = 0;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_write_bio_PrivateKey;
                       offline emulation evidence. */
    iVar2 = api_PEM_write_bio_PrivateKey_1807f6bf6(uVar4,lStack_80,0,0);
    if (0 < iVar2) {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_ctrl; offline emulation
                       evidence. */
      uVar3 = api_BIO_ctrl_1805af653(uVar4,3,0,&uStack_50);
      uStack_94 = uVar3;
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
      arg0_02 = api_malloc_1808a595e((ulonglong)uVar3);
      if (arg0_02 != (void *)0x0) {
        func_0x00018001cf67(arg0_02,uStack_50,uVar3);
      }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
      api_BIO_free_18078d1a6(uVar4);
    }
  }
  lStack_48 = 0;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new_mem_buf; offline
                       emulation evidence. */
  uVar4 = api_BIO_new_mem_buf_180762e6a(*plStack_60,(int)plStack_60[1]);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_read_bio_RSAPublicKey;
                       offline emulation evidence. */
  lVar7 = api_PEM_read_bio_RSAPublicKey_180c01a27(uVar4,&lStack_48,0,0);
  if (lVar7 == 0) {
    debug_info_real_Recovered
              ("pair_record_generate_keys_and_certs",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",0x211,
               "WARNING: Could not read public key");
  }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
  api_BIO_free_1806f37b6(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_new; offline emulation
                       evidence. */
  lVar7 = api_X509_new_18023855f();
  if ((lStack_48 == 0) || (lVar7 == 0)) {
LAB_180001f05:
    uVar3 = 0;
  }
  else {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_new; offline
                       emulation evidence. */
    uVar4 = api_ASN1_INTEGER_new_1803bbd2b();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_set; offline
                       emulation evidence. */
    api_ASN1_INTEGER_set_180a01370(uVar4,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_serialNumber;
                       offline emulation evidence. */
    api_X509_set_serialNumber_1807678a6(lVar7,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_INTEGER_free; offline
                       emulation evidence. */
    api_ASN1_INTEGER_free_180ae3e47(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_version; offline
                       emulation evidence. */
    api_X509_set_version_180670800(lVar7,2);
    native_180001710(lVar7,0x57,"critical,CA:FALSE");
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_new; offline
                       emulation evidence. */
    uVar4 = api_ASN1_TIME_new_18036da21();
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
    uVar5 = api__time64_1808f70ed(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
    api_ASN1_TIME_set_1800ba050(uVar4,uVar5);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notBefore; offline
                       emulation evidence. */
    api_X509_set1_notBefore_180bd0644(lVar7,uVar4);
                    /* Recovered VMProtect thunk: ucrtbase.dll!_time64; offline emulation evidence.
                        */
    lVar9 = api__time64_180c7450d(0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_set; offline
                       emulation evidence. */
    api_ASN1_TIME_set_1805effc7(uVar4,lVar9 + 0x12cc0300);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set1_notAfter; offline
                       emulation evidence. */
    api_X509_set1_notAfter_180b59f29(lVar7,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!ASN1_TIME_free; offline
                       emulation evidence. */
    api_ASN1_TIME_free_180204aad(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_new; offline
                       emulation evidence. */
    uVar4 = api_EVP_PKEY_new_1808dac0e();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_assign; offline
                       emulation evidence. */
    api_EVP_PKEY_assign_1801c6913(uVar4,6,lStack_48);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_set_pubkey; offline
                       emulation evidence. */
    api_X509_set_pubkey_1807e0720(lVar7,uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_free; offline
                       emulation evidence. */
    api_EVP_PKEY_free_18034196c(uVar4);
    native_180001710(lVar7,0x52,"hash");
    native_180001710(lVar7,0x53,"critical,digitalSignature,keyEncipherment");
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_sha1; offline emulation
                       evidence. */
    uVar4 = api_EVP_sha1_180ab6588();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_sign; offline emulation
                       evidence. */
    iVar2 = api_X509_sign_18098a5bf(lVar7,lVar8,uVar4);
    if (iVar2 == 0) {
      debug_info_real_Recovered
                ("pair_record_generate_keys_and_certs",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",0x23f,
                 "ERROR: Signing device certificate with root private key failed!");
      goto LAB_180001f05;
    }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_s_mem; offline emulation
                       evidence. */
    uVar4 = api_BIO_s_mem_180a0f2a0();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_new; offline emulation
                       evidence. */
    uVar4 = api_BIO_new_1805abcaa(uVar4);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!PEM_write_bio_X509; offline
                       emulation evidence. */
    iVar2 = api_PEM_write_bio_X509_180c9023b(uVar4,lVar7);
    if (iVar2 < 1) goto LAB_180001f05;
    uStack_50 = 0;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_ctrl; offline emulation
                       evidence. */
    uVar3 = api_BIO_ctrl_18013a2f3(uVar4,3,0,&uStack_50);
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
    arg0_03 = api_malloc_180836798((ulonglong)uVar3);
    if (arg0_03 != (void *)0x0) {
      func_0x00018001cf67(arg0_03,uStack_50,uVar3);
    }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!BIO_free; offline emulation
                       evidence. */
    api_BIO_free_180acb02c(uVar4);
  }
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509V3_EXT_cleanup; offline
                       emulation evidence. */
  api_X509V3_EXT_cleanup_1809b9eec();
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_free; offline emulation
                       evidence. */
  api_X509_free_1800bc9c3(lVar7);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_free; offline
                       emulation evidence. */
  api_EVP_PKEY_free_1808d9cc9(lStack_68);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!EVP_PKEY_free; offline
                       emulation evidence. */
  api_EVP_PKEY_free_180c0acae(lStack_80);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_free; offline emulation
                       evidence. */
  api_X509_free_1807a1c94(lStack_78);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_free; offline emulation
                       evidence. */
  api_X509_free_18016139e(lStack_70);
  uVar1 = uStack_88;
  if (((((arg0 != (void *)0x0) && (uStack_8c != 0)) &&
       ((arg0_00 != (void *)0x0 &&
        ((((uStack_88 != 0 && (arg0_01 != (void *)0x0)) && (uStack_90 != 0)) &&
         ((arg0_02 != (void *)0x0 && (uStack_94 != 0)))))))) && (arg0_03 != (void *)0x0)) &&
     (uVar3 != 0)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar11 = (void *)api_plist_new_data_1801c8f42(arg0_03,uVar3);
    pvVar10 = pvStack_58;
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1803c2e6b(pvStack_58,"DeviceCertificate",pvVar11);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar11 = (void *)api_plist_new_data_18095dd2a(arg0_02,uStack_94);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_18099338c(pvVar10,"HostPrivateKey",pvVar11);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar11 = (void *)api_plist_new_data_180bcaf36(arg0_01,uStack_90);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_180bfe7db(pvVar10,"HostCertificate",pvVar11);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar11 = (void *)api_plist_new_data_1806dff2d(arg0_00,uVar1);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1805c94ca(pvVar10,"RootPrivateKey",pvVar11);
                    /* Recovered VMProtect thunk: plist.dll!plist_new_data; offline emulation
                       evidence. */
    pvVar11 = (void *)api_plist_new_data_1806243e1(arg0,uStack_8c);
                    /* Recovered VMProtect thunk: plist.dll!plist_dict_set_item; offline emulation
                       evidence. */
    api_plist_dict_set_item_1800b108f(pvVar10,"RootCertificate",pvVar11);
    uStack_84 = 0;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_18090faf6(arg0_03);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_1804c1aa9(arg0_00);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180560b1b(arg0);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180be412e(arg0_02);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_180691068(arg0_01);
LAB_1800020a0:
  native_18001c0e0(uStack_40 ^ (ulonglong)auStack_d8);
  return;
}

