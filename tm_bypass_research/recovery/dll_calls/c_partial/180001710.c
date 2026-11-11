/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180001710(undefined8 param_1,undefined4 param_2,ulonglong param_3)

{
  longlong lVar1;
  undefined1 auStack_88 [32];
  undefined8 uStack_68;
  ulonglong uStack_60;
  undefined1 auStack_58 [48];
  undefined8 uStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18002c008 ^ (ulonglong)auStack_88;
  uStack_60 = uStack_60 & 0xffffffff00000000;
  uStack_68 = 0;
  uStack_28 = 0;
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509V3_set_ctx; offline
                       emulation evidence. */
  api_X509V3_set_ctx_180252b73(auStack_58,0,param_1,0);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509V3_EXT_conf_nid; offline
                       emulation evidence. */
  lVar1 = api_X509V3_EXT_conf_nid_180073b87(0,auStack_58,param_2,param_3);
  if (lVar1 == 0) {
    uStack_68 = CONCAT44(uStack_68._4_4_,param_2);
    uStack_60 = param_3;
    debug_info_real_Recovered
              ("X509_add_ext_helper","D:\\Project\\X6.2\\vs\\libimobiledevice\\common\\userpref.c",
               0x16b,"ERROR: X509V3_EXT_conf_nid(%d, %s) failed");
  }
  else {
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_add_ext; offline
                       emulation evidence. */
    api_X509_add_ext_1807b38d2(param_1,lVar1,0xffffffff);
                    /* Recovered VMProtect thunk: libcrypto-1_1-x64.dll!X509_EXTENSION_free; offline
                       emulation evidence. */
    api_X509_EXTENSION_free_180b44eda(lVar1);
  }
  native_18001c0e0(uStack_20 ^ (ulonglong)auStack_88);
  return;
}

