/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c90c(void)

{
  int iVar1;
  
  iVar1 = func_0x00018001ce8c();
  if (iVar1 != 0) {
    LOCK();
    UNLOCK();
    LOCK();
    UNLOCK();
    return;
  }
  iVar1 = func_0x00018001cee8();
  if (iVar1 == 0) {
    func_0x00018001cedc();
  }
  return;
}

