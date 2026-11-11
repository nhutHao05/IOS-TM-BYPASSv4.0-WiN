/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Instruction at (ram,0x0001800cd3c7) overlaps instruction at (ram,0x0001800cd3c5)
    */
/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_get_device_list_extended_Recovered(void)

{
  ulonglong uVar1;
  undefined8 unaff_RBP;
  
  uVar1 = func_0x000180dbfef6();
                    /* 0x9740  85  idevice_get_device_list_extended */
  *(undefined8 *)((uVar1 & 0xffffffff | 0x40) - 8) = unaff_RBP;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

