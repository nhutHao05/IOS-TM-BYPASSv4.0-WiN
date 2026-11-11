/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int native_18001c58c(undefined8 param_1,int param_2,longlong param_3)

{
  int iVar1;
  
  if ((param_2 == 0) && (_DAT_18002c8b0 < 1)) {
    iVar1 = 0;
  }
  else if ((1 < param_2 - 1U) ||
          (((_DAT_18001e5f0 == 0 ||
            (iVar1 = (*(code *)PTR__guard_dispatch_icall_18001e580)(), iVar1 != 0)) &&
           (iVar1 = native_18001c3a0(param_1,param_2,param_3), iVar1 != 0)))) {
    iVar1 = native_180009540(param_1,param_2,param_3);
    if ((param_2 == 1) && (iVar1 == 0)) {
      native_180009540(param_1,0,param_3);
      native_18001c508(param_3 != 0);
      if (_DAT_18001e5f0 != 0) {
        (*(code *)PTR__guard_dispatch_icall_18001e580)(param_1,0,param_3);
      }
    }
    if (((param_2 == 0) || (param_2 == 3)) &&
       (iVar1 = native_18001c3a0(param_1,param_2,param_3), iVar1 != 0)) {
      if (_DAT_18001e5f0 == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = (*(code *)PTR__guard_dispatch_icall_18001e580)(param_1,param_2,param_3);
      }
    }
  }
  return iVar1;
}

