/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001cac0(char param_1)

{
  int iVar1;
  
  iVar1 = func_0x00018001ce8c();
  if ((iVar1 != 0) && (param_1 == '\0')) {
    LOCK();
    _DAT_18002c8d8 = 0;
    UNLOCK();
  }
  return;
}

