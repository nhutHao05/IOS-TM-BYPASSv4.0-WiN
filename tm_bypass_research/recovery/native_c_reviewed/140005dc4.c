/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140005dc4(void)

{
  code *pcVar1;
  
  func_0x00014020e82e(0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

