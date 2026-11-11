/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001cfb6(undefined8 param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_2 + 0x40);
  iVar2 = func_0x00018001ce8c();
  if ((iVar2 != 0) && (cVar1 == '\0')) {
    LOCK();
    _DAT_18002c8d8 = 0;
    UNLOCK();
  }
  return;
}

