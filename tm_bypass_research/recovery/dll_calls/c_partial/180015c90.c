/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000180287ac5) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobile_image_mounter_upload_image_Recovered(undefined8 param_1,char *param_2)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 unaff_RBX;
  uint unaff_EBP;
  int unaff_ESI;
  undefined1 *unaff_RDI;
  uint unaff_R14D;
  byte in_CF;
  
                    /* 0x15c90  162  mobile_image_mounter_upload_image */
  uVar5 = func_0x000180cef54a();
  *param_2 = *param_2 + -1;
  uVar6 = (unaff_ESI - iRam00000000117c42f3) - (uint)in_CF;
  uVar7 = *(int *)(ulonglong)uVar6 + 0x117c42f3;
  if ((int)uVar7 < 0) {
    while( true ) {
      uVar2 = uVar7;
      uVar7 = unaff_EBP | 0x22e78ff5;
      bVar4 = (byte)uVar7 | *(byte *)((ulonglong)uVar6 + 0x24 + (longlong)unaff_RDI * 2);
      if (CONCAT31((int3)(uVar7 >> 8),bVar4) == 0) break;
      uVar7 = CONCAT22((short)(uVar7 >> 0x10),
                       CONCAT11((byte)(uVar7 >> 8) ^ (byte)((int)uVar2 >> 0x1f),bVar4));
      unaff_EBP = unaff_R14D;
      unaff_R14D = uVar2;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *unaff_RDI = (char)uVar6;
  LOCK();
  *(undefined4 *)(ulonglong)CONCAT22((short)(uVar7 >> 0x10),CONCAT11(0x62,(char)uVar7)) = uVar5;
  UNLOCK();
  cVar3 = in(0xf6);
  pbVar1 = (byte *)((ulonglong)CONCAT41(unaff_EBP >> 8,cVar3 + -0xb) + 0x4c);
  *pbVar1 = *pbVar1 & (byte)((ulonglong)unaff_RBX >> 8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

