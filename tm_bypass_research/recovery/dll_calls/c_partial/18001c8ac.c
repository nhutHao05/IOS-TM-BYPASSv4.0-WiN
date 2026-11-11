/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_18001c8ac(undefined8 param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = func_0x00018001ce8c();
  if ((iVar1 == 0) && (param_2 == 1)) {
    (*(code *)PTR__guard_dispatch_icall_18001e580)(param_1,0,param_3);
  }
  LOCK();
  UNLOCK();
  return;
}

