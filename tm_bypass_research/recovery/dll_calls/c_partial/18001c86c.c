/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined1 native_18001c86c(void)

{
  char cVar1;
  
  cVar1 = func_0x00018001cee4();
  if (cVar1 != '\0') {
    cVar1 = func_0x00018001cee4();
    if (cVar1 != '\0') {
      return 1;
    }
    func_0x00018001cee4();
  }
  return 0;
}

