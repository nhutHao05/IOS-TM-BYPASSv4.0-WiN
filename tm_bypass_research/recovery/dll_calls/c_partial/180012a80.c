/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_receive_restore_file_received_Recovered(undefined8 param_1,undefined8 param_2)

{
  byte *pbVar1;
  byte bVar2;
  longlong unaff_RBP;
  undefined4 unaff_EDI;
  undefined4 unaff_0000003c;
  
                    /* 0x12a80  188  mobilebackup_receive_restore_file_received */
  bVar2 = (byte)((ulonglong)param_2 >> 8);
  func_0x000180cd8a6f();
  in(0xc5);
  pbVar1 = (byte *)(CONCAT44(unaff_0000003c,unaff_EDI) + 0x11 + unaff_RBP * 8);
  *pbVar1 = *pbVar1 & bVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

