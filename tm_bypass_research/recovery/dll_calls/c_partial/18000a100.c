/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_18000a100(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  if (-1 < param_1) {
    return 0;
  }
  if (param_1 != -0x8a) {
    if (param_1 != -0xb) {
      return 0xfffffffe;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!strerror; offline emulation evidence.
                        */
    uVar1 = api_strerror_1803fb9ed(0xb);
    debug_info_real_Recovered
              ("socket_recv_to_idevice_error",
               "D:\\Project\\X6.2\\vs\\libimobiledevice\\src\\idevice.c",0x230,
               "ERROR: received partial data %d/%d (%s)",param_3,param_2,uVar1);
    return 0xfffffffc;
  }
  return 0xfffffff9;
}

