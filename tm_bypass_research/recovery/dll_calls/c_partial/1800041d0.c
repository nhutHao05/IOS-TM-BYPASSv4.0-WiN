/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_file_write_Recovered(uint param_1,uint *param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  byte bVar8;
  longlong unaff_RBP;
  undefined1 *unaff_RSI;
  undefined4 *unaff_RDI;
  bool bVar9;
  
                    /* 0x41d0  14  afc_file_write */
  uRamde61b094bf5f65a6 = func_0x000180cd8a6f();
  uVar3 = in((short)param_2);
  *unaff_RDI = uVar3;
  cVar6 = (char)uRamde61b094bf5f65a6;
  out(*unaff_RSI,(short)param_2);
  *(int *)(unaff_RBP + -0x4aeda1c4) = *(int *)(unaff_RBP + -0x4aeda1c4) - param_1;
  pbVar1 = (byte *)((longlong)param_2 + -0x5c83aec9);
  bVar2 = *pbVar1;
  bVar8 = (byte)param_1;
  *pbVar1 = *pbVar1 + bVar8;
  bVar4 = unaff_RSI[0x17];
  unaff_RSI[0x17] = bVar4 << 6 | (byte)(CONCAT11(CARRY1(bVar2,bVar8),bVar4) >> 3);
  cVar5 = cRam00000001fb4914f0;
  cRam00000001fb4914f0 = cRam00000001fb4914f0 >> (bVar8 & 0x1f);
  bVar9 = (param_1 & 0x1f) != 0;
  bVar9 = !bVar9 && (bVar4 & 4) != 0 || bVar9 && (cVar5 >> (bVar8 & 0x1f) - 1 & 1U) != 0;
  cVar5 = cVar6 + -0x37;
  if ((SCARRY1(cVar6,-0x37) != SCARRY1(cVar5,bVar9)) != (char)(cVar5 + bVar9) < '\0') {
    return;
  }
  uVar7 = func_0x00016fde9db0();
  if ((uVar7 & 0x100) != 0) {
    unaff_RDI[1] = uVar7;
    *param_2 = *param_2 | (uint)param_2;
    in(0xf1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

