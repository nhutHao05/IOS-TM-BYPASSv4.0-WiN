/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140004040(void)

{
  undefined8 uVar1;
  
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
  uVar1 = api___acrt_iob_func_14016cadb(2);
  native_140001010(uVar1,"Exiting...\n");
  _DAT_14000b734 = _DAT_14000b734 + 1;
  return;
}

