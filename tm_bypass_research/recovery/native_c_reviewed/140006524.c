/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140006524(void)

{
  code *pcVar1;
  undefined1 auStackX_18 [8];
  
  if (_DAT_14000b008 == 0x2b992ddfa232) {
    func_0x0001401c88ac();
    func_0x0001400a6b79();
    func_0x0001400e17c1();
    func_0x00014011baa0(auStackX_18);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _DAT_14000b000 = ~_DAT_14000b008;
  return;
}

