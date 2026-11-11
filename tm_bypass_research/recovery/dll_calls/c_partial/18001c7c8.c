/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18001c7c8(void)

{
  ulonglong *puVar1;
  
  puVar1 = (ulonglong *)func_0x000180001000();
  *puVar1 = *puVar1 | 0x24;
  puVar1 = (ulonglong *)func_0x00018000d290();
  *puVar1 = *puVar1 | 2;
  return;
}

