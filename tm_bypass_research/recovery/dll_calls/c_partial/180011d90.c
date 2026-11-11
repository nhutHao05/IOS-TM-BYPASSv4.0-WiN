/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_client_start_service_Recovered(undefined8 param_1)

{
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined6 uVar7;
  longlong unaff_RBP;
  undefined8 unaff_RSI;
  undefined4 unaff_EDI;
  undefined4 unaff_0000003c;
  undefined8 unaff_R12;
  
  uVar7 = (undefined6)((ulonglong)param_1 >> 0x10);
  bVar6 = (byte)((ulonglong)param_1 >> 8);
                    /* 0x11d90  185  mobilebackup_client_start_service */
  uVar5 = (undefined1)param_1;
  func_0x000180cef54a();
  uVar4 = uRamed14b134c838352c;
  uRamffffffffa99d48eb = unaff_RSI;
  if (0x423eabba < uRamed14b134c838352c) {
    *(char *)(unaff_RBP + 0x61) = *(char *)(unaff_RBP + 0x61) - bVar6;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uRamffffffffa99d48e3 = 0xffffffffa99d48eb;
  LOCK();
  puVar2 = (undefined1 *)(CONCAT44(unaff_0000003c,unaff_EDI) + 0x6945869e);
  uVar3 = *puVar2;
  *puVar2 = (char)uRamed14b134c838352c;
  UNLOCK();
  pbVar1 = (byte *)((ulonglong)
                    (uint)(CONCAT31((int3)(uVar4 >> 8),uVar3) *
                          *(int *)(CONCAT62(uVar7,CONCAT11(bVar6,uVar5)) + -0x69)) + 0x18);
  *pbVar1 = *pbVar1 ^ bVar6;
  if (*pbVar1 != 0) {
    uRamffffffffa99d48e3 = unaff_R12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

