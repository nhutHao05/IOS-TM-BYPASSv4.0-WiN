/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000180bee0d4) overlaps instruction at (ram,0x000180bee0d3)
    */
/* WARNING: Removing unreachable block (ram,0x000180bee04d) */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined4 service_receive_Recovered(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined4 unaff_ESI;
  
                    /* 0x1ad60  271  service_receive */
  uVar1 = (undefined1)((ulonglong)param_2 >> 8);
  uRam79ed3aa3fe1f685c = func_0x000180d8cdd6();
  uRam79ed3aa3fe1f685c = uRam79ed3aa3fe1f685c & 0x30a2f612;
  if (uRam79ed3aa3fe1f685c == 0) {
    out(0x69,0xdc);
    return unaff_ESI;
  }
  LOCK();
  *(undefined1 *)((ulonglong)uRam79ed3aa3fe1f685c + 0x5c0c8e2b) = uVar1;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

