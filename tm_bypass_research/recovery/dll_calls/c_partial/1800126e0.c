/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Instruction at (ram,0x000180140290) overlaps instruction at (ram,0x00018014028e)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000180140308) */
/* WARNING: Removing unreachable block (ram,0x000180140301) */
/* WARNING: Removing unreachable block (ram,0x000180140312) */
/* WARNING: Removing unreachable block (ram,0x0001801402ab) */
/* WARNING: Removing unreachable block (ram,0x0001801402ad) */
/* WARNING: Removing unreachable block (ram,0x0001801402ba) */
/* WARNING: Removing unreachable block (ram,0x000180140290) */
/* WARNING: Removing unreachable block (ram,0x000180140298) */
/* WARNING: Removing unreachable block (ram,0x00018014021d) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_send_backup_file_received_Recovered(void)

{
  undefined4 uVar1;
  longlong unaff_RBP;
  longlong unaff_RDI;
  undefined8 uStack_8;
  
  uStack_8 = 0xffffffffc541534e;
  uVar1 = func_0x000180de4640();
  uRambe952006dd9b8677 = uVar1;
  *(uint *)(unaff_RBP + -0x3b6fc924) = *(uint *)(unaff_RBP + -0x3b6fc924) | (uint)&uStack_8;
                    /* 0x126e0  192  mobilebackup_send_backup_file_received */
  *(char *)(unaff_RDI + 0x534e6801) = (char)((uint)uVar1 >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

