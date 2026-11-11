/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_1400065fc(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)native_140001000();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)func_0x0001400014f0();
  *puVar1 = *puVar1 | 2;
  return;
}

