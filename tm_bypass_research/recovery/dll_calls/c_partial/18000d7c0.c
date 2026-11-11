/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001808fd41c) overlaps instruction at (ram,0x0001808fd41b)
    */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_client_free_Recovered(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined1 in_ZF;
  
  func_0x000180de4640();
  in(0xca);
  if ((bool)in_ZF) {
    *(uint *)(param_2 + -0x1c) = *(uint *)(param_2 + -0x1c) & (uint)param_2;
    uVar1 = in((short)param_2);
    uVar1 = uVar1 ^ 0x1151df0d;
    out(0xfb0b,CONCAT22((short)(uVar1 >> 0x10),
                        CONCAT11((char)(uVar1 >> 8) - cRam00000001bf468f4f,(char)uVar1)));
    if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (CONCAT71((int7)((ulonglong)param_1 >> 8),0xb9) == 1 || (bool)in_ZF != false) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

