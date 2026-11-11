/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00018067b7a4) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_client_send_command_Recovered(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar5;
  longlong lVar6;
  undefined8 uVar7;
  int iVar8;
  longlong unaff_RBX;
  undefined8 *puVar9;
  int iVar11;
  longlong unaff_RBP;
  undefined4 *unaff_RSI;
  undefined4 *puVar12;
  undefined4 *unaff_RDI;
  undefined8 uStack_8;
  uint uVar4;
  longlong *plVar10;
  
  puVar9 = &uStack_8;
  uStack_8 = 0x67659c;
  uVar7 = func_0x000180cd8a6f();
  piVar5 = unaff_RDI + 1;
  puVar12 = unaff_RSI + 1;
  *unaff_RDI = *unaff_RSI;
  piVar2 = (int *)(unaff_RBX + -0x60);
  iVar11 = *piVar2;
  iVar8 = (int)param_2;
  *piVar2 = *piVar2 - iVar8;
  if (SBORROW4(iVar11,iVar8) == *piVar2 < 0) {
    *(char *)piVar5 = (char)uVar7;
    iVar11 = (int)unaff_RBP << 1;
    if (iVar11 != 0 && ((int)unaff_RBP < 0 != iVar11 < 0) == iVar11 < 0) {
      uRam00000000730db76f =
           in(-(short)CONCAT71((int7)((ulonglong)param_2 >> 8),
                               (byte)param_2 ^ *(byte *)(param_1 + -0x65c40ea6)));
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 == 0) {
    while( true ) {
      plVar10 = (longlong *)((longlong)puVar9 + 8);
      puVar9 = (undefined8 *)((longlong)puVar9 + 8);
      uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),8);
      puVar1 = (uint *)(unaff_RBP + -6);
      uVar3 = *puVar1;
      uVar4 = *puVar1;
      *puVar1 = *puVar1 - 0x67;
      if (SCARRY4(uVar4,-0x67)) {
        *piVar5 = (*piVar5 - iVar8) - (uint)(uVar3 < 0x67);
        *(byte *)(param_2 + 4) = *(byte *)(param_2 + 4) | (byte)param_2;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((POPCOUNT(*puVar1 & 0xff) & 1U) != 0) break;
      puVar12 = (undefined4 *)0xd21a4a460ab3f466;
    }
    lVar6 = *plVar10;
    *(undefined4 **)(lVar6 + -8) = unaff_RDI + 2;
    out((short)param_2,8);
    out(puVar12[1],(short)param_2);
    *(undefined8 *)(lVar6 + -8) = 0;
    unaff_RDI[2] = (int)uVar7;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

