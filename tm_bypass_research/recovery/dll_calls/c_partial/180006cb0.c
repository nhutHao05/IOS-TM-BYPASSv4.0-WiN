/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined4 native_180006cb0(undefined8 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    uVar1 = property_list_service_client_free_Recovered(*param_1);
    switch(uVar1) {
    case 0:
      uVar1 = 0;
      break;
    case 0xfffffffb:
      uVar1 = 0xfffffffb;
      break;
    case 0xfffffffc:
      uVar1 = 0xfffffffc;
      break;
    case 0xfffffffd:
      uVar1 = 0xfffffffd;
      break;
    case 0xfffffffe:
      uVar1 = 0xfffffffe;
      break;
    case 0xffffffff:
      uVar1 = 0xffffffff;
      break;
    default:
      uVar1 = 0xffffff00;
    }
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_1804271d1(param_1);
    return uVar1;
  }
  return 0xffffffff;
}

