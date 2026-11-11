/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_18001c950(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    DAT_18002c8e0 = 1;
  }
  native_18001cce8();
  cVar1 = func_0x00018001cee4();
  if (cVar1 != '\0') {
    cVar1 = func_0x00018001cee4();
    if (cVar1 != '\0') {
      return 1;
    }
    func_0x00018001cee4(0);
  }
  return 0;
}

