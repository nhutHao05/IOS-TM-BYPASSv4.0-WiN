/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_180017ce0(longlong *param_1,void *param_2,int param_3)

{
  longlong *plVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_98 [32];
  uint uStack_78;
  void *pvStack_70;
  uint auStack_68 [2];
  void *pvStack_60;
  void *pvStack_58;
  uint uStack_50;
  uint uStack_4c;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18002c008 ^ (ulonglong)auStack_98;
  pvStack_60 = (void *)0x0;
  uStack_50 = 0;
  if (((param_1 == (longlong *)0x0) || (*param_1 == 0)) || (param_2 == (void *)0x0))
  goto LAB_180018011;
  if (param_3 == 0) {
                    /* Recovered VMProtect thunk: plist.dll!plist_to_xml; offline emulation
                       evidence. */
    api_plist_to_xml_1808fb9d3(param_2,&pvStack_60,&uStack_50);
  }
  else {
                    /* Recovered VMProtect thunk: plist.dll!plist_to_bin; offline emulation
                       evidence. */
    api_plist_to_bin_180c13b0d(param_2,&pvStack_60,&uStack_50);
  }
  if ((pvStack_60 == (void *)0x0) || (uStack_50 == 0)) goto LAB_180018011;
  uStack_78 = uStack_50;
  uStack_4c = (uStack_50 & 0xff0000 | uStack_50 >> 0x10) >> 8 |
              (uStack_50 & 0xff00 | uStack_50 << 0x10) << 8;
  debug_info_real_Recovered
            ("internal_plist_send",
             "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x84,
             "sending %d bytes");
  plVar1 = (longlong *)*param_1;
  auStack_68[0] = 0;
  if ((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) {
LAB_180017fbe:
    debug_info_real_Recovered
              ("internal_plist_send",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x93,
               "ERROR: sending to device failed.");
  }
  else {
    uStack_78 = 4;
    debug_info_real_Recovered
              ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x90,
               "sending %d bytes");
    iVar4 = idevice_connection_send_Recovered(*plVar1,&uStack_4c,4,auStack_68);
    if (iVar4 != 0) {
      debug_info_real_Recovered
                ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x93,
                 "ERROR: sending to device failed.");
    }
    uVar3 = uStack_50;
    pvVar2 = pvStack_60;
    uVar5 = auStack_68[0];
    if (auStack_68[0] == 4) {
      param_1 = (longlong *)*param_1;
      auStack_68[0] = 0;
      if (((param_1 != (longlong *)0x0) && (*param_1 != 0)) &&
         ((pvStack_60 != (void *)0x0 && (uStack_50 != 0)))) {
        uStack_78 = uStack_50;
        debug_info_real_Recovered
                  ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x90,
                   "sending %d bytes");
        iVar4 = idevice_connection_send_Recovered(*param_1,pvVar2,uVar3,auStack_68);
        if (iVar4 != 0) {
          debug_info_real_Recovered
                    ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x93,
                     "ERROR: sending to device failed.");
        }
        uVar5 = auStack_68[0];
        if (auStack_68[0] == 0) goto LAB_180017fbe;
      }
      uStack_78 = uVar5;
      debug_info_real_Recovered
                ("internal_plist_send",
                 "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x89,
                 "sent %d bytes");
      pvStack_58 = (void *)0x0;
      auStack_68[0] = 0;
                    /* Recovered VMProtect thunk: plist.dll!plist_to_xml; offline emulation
                       evidence. */
      api_plist_to_xml_180422ad6(param_2,&pvStack_58,auStack_68);
      if (*(char *)((ulonglong)(auStack_68[0] - 1) + (longlong)pvStack_58) == '\n') {
        *(undefined1 *)((ulonglong)(auStack_68[0] - 1) + (longlong)pvStack_58) = 0;
      }
      if (auStack_68[0] < 0x4001) {
        pvStack_70 = pvStack_58;
        uStack_78 = auStack_68[0];
        debug_info_real_Recovered
                  ("internal_plist_send",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x8a,
                   "printing %i bytes plist:\n%s");
      }
      else {
        uStack_78 = auStack_68[0];
        debug_info_real_Recovered
                  ("internal_plist_send",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x8a,
                   "supress printing %i bytes plist...\n");
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
      api_free_180666fa5(pvStack_58);
      if (uVar5 != uStack_50) {
        pvStack_70 = (void *)CONCAT44(pvStack_70._4_4_,uStack_50);
        uStack_78 = uVar5;
        debug_info_real_Recovered
                  ("internal_plist_send",
                   "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\property_list_service.c",0x8e,
                   "ERROR: Could not send all data (%d of %d)!");
      }
    }
    if (uVar5 == 0) goto LAB_180017fbe;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
  api_free_1803e69b4(pvStack_60);
LAB_180018011:
  native_18001c0e0(uStack_48 ^ (ulonglong)auStack_98);
  return;
}

