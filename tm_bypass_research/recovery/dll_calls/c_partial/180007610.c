/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_180007610(undefined8 *param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined8 *)0x0) && (param_2 != 0)) {
    uVar1 = native_180017ce0(*param_1,param_2,1);
    switch(uVar1) {
    case 0:
      return 0;
    case 0xfffffffb:
      return 0xfffffffb;
    case 0xfffffffc:
      return 0xfffffffc;
    case 0xfffffffd:
      return 0xfffffffd;
    case 0xfffffffe:
      return 0xfffffffe;
    case 0xffffffff:
      break;
    default:
      return 0xffffff00;
    }
  }
  return 0xffffffff;
}

