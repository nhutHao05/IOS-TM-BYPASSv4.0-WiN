/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_client_set_label_Recovered(int param_1)

{
  uint uVar1;
  int3 iVar2;
  ulonglong uVar3;
  int iVar4;
  int *piVar5;
  byte bVar6;
  undefined8 unaff_RBX;
  longlong unaff_RBP;
  undefined1 *unaff_RSI;
  longlong unaff_RDI;
  byte unaff_R14B;
  float10 fVar8;
  byte bVar7;
  
                    /* 0x18880  243  restored_client_set_label */
  piVar5 = (int *)func_0x000180dbfef6();
  iVar4 = iRam0000000134004602;
  uVar3 = CONCAT71((int7)((ulonglong)unaff_RBX >> 8),*unaff_RSI);
  iRam0000000134004602 = iRam0000000134004602 >> 0xc;
  bVar7 = (byte)(param_1 >> 4);
  iVar2 = (int3)(param_1 >> 0xc);
  bVar6 = bVar7 + unaff_R14B;
  fVar8 = *(float10 *)
           ((ulonglong)
            (((int)uVar3 - *(int *)((uVar3 & 0xffffffff) + (ulonglong)(uint)(*piVar5 * 0x71) * 2)) -
            (uint)((iVar4 >> 0xb & 1U) != 0)) + 0x3a5388dd);
  uVar1 = *(uint *)(unaff_RBP + -0x4c93b6ae);
  *(uint *)(unaff_RBP + -0x4c93b6ae) =
       uVar1 << 0xd | (uint)(CONCAT14(CARRY1(bVar7,unaff_R14B),uVar1) >> 0x14);
  bVar7 = *(byte *)((ulonglong)CONCAT31(iVar2,bVar6) + 0x21df244c);
  uVar1 = *(uint *)(unaff_RBP + -0x4c8f40b2);
  *(uint *)(unaff_RBP + -0x4c8f40b2) =
       (uint)(CONCAT14((byte)unaff_RSI[5] < *(byte *)(unaff_RDI + 4),uVar1) >> 0x12) | uVar1 << 0xf;
  *(short *)(&stack0xffffffffa83f49ae + (ulonglong)CONCAT31(iVar2,bVar6 ^ bVar7) * 2) = (short)fVar8
  ;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

