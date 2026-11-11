/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140005f7c(void)

{
  code *pcVar1;
  
  func_0x000140184f40();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

