/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_140006310(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    DAT_14000b5d0 = 1;
  }
  native_1400068c8();
  cVar1 = func_0x0001400065f4();
  if (cVar1 != '\0') {
    cVar1 = func_0x0001400065f4();
    if (cVar1 != '\0') {
      return 1;
    }
    func_0x0001400065f4(0);
  }
  return 0;
}

