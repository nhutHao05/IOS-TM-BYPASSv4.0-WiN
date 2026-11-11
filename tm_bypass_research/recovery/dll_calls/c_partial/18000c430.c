/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001801063d8) overlaps instruction at (ram,0x0001801063d5)
    */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_install_Recovered(void)

{
                    /* 0xc430  109  instproxy_install */
  func_0x000180cfc54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

