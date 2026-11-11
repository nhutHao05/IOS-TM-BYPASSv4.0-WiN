/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140005fec(void)

{
  code *pcVar1;
  
  func_0x0001400c3f42();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

