/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8
native_180002790(longlong *param_1,undefined8 param_2,uint param_3,longlong param_4,uint param_5,
                int *param_6)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint auStackX_8 [2];
  undefined8 uVar9;
  undefined4 uVar10;
  
  if (((param_1 != (longlong *)0x0) && (*param_1 != 0)) && (param_1[1] != 0)) {
    uVar6 = 0;
    *param_6 = 0;
    if ((param_4 == 0) || (param_5 == 0)) {
      param_5 = 0;
    }
    *(longlong *)(param_1[1] + 0x18) = *(longlong *)(param_1[1] + 0x18) + 1;
    *(undefined8 *)(param_1[1] + 0x20) = param_2;
    *(ulonglong *)(param_1[1] + 8) = (ulonglong)param_3 + 0x28 + (ulonglong)param_5;
    uVar1 = (ulonglong)param_3 + 0x28;
    *(ulonglong *)(param_1[1] + 0x10) = uVar1;
    uVar9 = *(undefined8 *)(param_1[1] + 0x10);
    debug_info_real_Recovered
              ("afc_dispatch_packet","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",0xa7,
               "packet length = %i",uVar9);
    iVar7 = param_3 + 0x28;
    native_180001310(param_1[1],iVar7);
    plVar2 = (longlong *)*param_1;
    lVar3 = param_1[1];
    uVar4 = 0;
    auStackX_8[0] = 0;
    uVar5 = uVar6;
    if (((plVar2 != (longlong *)0x0) && (uVar5 = uVar4, *plVar2 != 0)) &&
       ((lVar3 != 0 && (iVar7 != 0)))) {
      uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),iVar7);
      debug_info_real_Recovered
                ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x90,
                 "sending %d bytes",uVar9);
      iVar7 = idevice_connection_send_Recovered(*plVar2,lVar3,iVar7,auStackX_8);
      if (iVar7 != 0) {
        debug_info_real_Recovered
                  ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x93,
                   "ERROR: sending to device failed.",uVar9);
      }
      uVar5 = (ulonglong)auStackX_8[0];
    }
    *param_6 = *param_6 + (int)uVar5;
    if (uVar1 <= uVar5) {
      if (param_5 != 0) {
        if (param_5 < 0x101) {
          debug_info_real_Recovered
                    ("afc_dispatch_packet","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                     0xba,"packet payload follows",uVar9);
          uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
          uVar8 = param_5;
        }
        else {
          uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20),param_5);
          debug_info_real_Recovered
                    ("afc_dispatch_packet","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\afc.c",
                     0xb7,"packet payload follows (256/%u)",uVar9);
          uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
          uVar8 = 0x100;
        }
        native_180001310(param_4,uVar8);
        param_1 = (longlong *)*param_1;
        auStackX_8[0] = 0;
        if (((param_1 != (longlong *)0x0) && (*param_1 != 0)) && (uVar6 = 0, param_4 != 0)) {
          uVar9 = CONCAT44(uVar10,param_5);
          debug_info_real_Recovered
                    ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x90,
                     "sending %d bytes",uVar9);
          iVar7 = idevice_connection_send_Recovered(*param_1,param_4,param_5,auStackX_8);
          if (iVar7 != 0) {
            debug_info_real_Recovered
                      ("service_send","D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\service.c",0x93
                       ,"ERROR: sending to device failed.",uVar9);
          }
          uVar6 = (ulonglong)auStackX_8[0];
        }
      }
      *param_6 = *param_6 + (int)uVar6;
    }
    return 0;
  }
  return 7;
}

