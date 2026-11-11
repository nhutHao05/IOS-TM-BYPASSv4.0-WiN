/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018016caeb) overlaps instruction at (ram,0x00018016cae8)
    */
/* WARNING: Removing unreachable block (ram,0x00018016cbb7) */
/* WARNING: Removing unreachable block (ram,0x00018016cab1) */
/* WARNING: Removing unreachable block (ram,0x00018016cafe) */
/* WARNING: Removing unreachable block (ram,0x00018016cab4) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void syslog_relay_stop_capture_Recovered(ulonglong param_1,ulonglong param_2)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  longlong lVar6;
  ulonglong unaff_RBX;
  ulonglong uVar7;
  undefined2 *puVar8;
  ulonglong *puVar9;
  undefined1 *unaff_RSI;
  uint uVar10;
  longlong unaff_RDI;
  undefined2 in_FS;
  undefined1 in_CF;
  bool bVar11;
  undefined1 in_PF;
  undefined1 in_ZF;
  bool bVar12;
  undefined2 uStack_10;
  undefined6 uStack_e;
  undefined2 uStack_8;
  undefined6 uStack_6;
  
  uStack_8 = 0xb90a;
  uStack_6 = 0xffffffffd80a;
  uStack_10 = 0xcb66;
  uStack_e = 0x18016;
  puVar4 = (uint *)func_0x000180de3bb5();
  if ((bool)in_CF) {
    return;
  }
  cVar2 = (char)puVar4;
  if (!(bool)in_CF && !(bool)in_ZF) {
    puVar8 = &uStack_10;
    *(uint *)(param_2 - 0x2bcdf0f2) = *(uint *)(param_2 - 0x2bcdf0f2) & 0xffffff91;
    *(int *)(unaff_RSI + unaff_RDI) = (int)&uStack_10;
    *(int *)(param_1 - 0x4fe9f683) = *(int *)(param_1 - 0x4fe9f683) + -0x43;
    uVar7 = param_2 & 0xffffffff;
    param_2 = unaff_RBX & 0xffffffff;
    cVar2 = cVar2 + -0x21;
    goto code_r0x00018016cb82;
  }
  if ((bool)in_PF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (param_1 != 0) {
    puVar8 = &uStack_10;
    uStack_10 = SUB82(unaff_RSI,0);
    uStack_e = (undefined6)((ulonglong)unaff_RSI >> 0x10);
    lVar6 = param_1 - 1;
    if (lVar6 != 0 && (uint)unaff_RDI == *puVar4) {
      *(undefined2 *)(unaff_RSI + 0x6d) = in_FS;
      XRELEASE();
      LOCK();
      *(int *)(unaff_RDI + -0x4c) = (int)CONCAT62(uStack_e,CONCAT11(0xf1,(char)unaff_RSI));
      UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar10 = (uint)unaff_RDI ^ *(uint *)(param_1 - 0x4e);
    if ((POPCOUNT(uVar10 & 0xff) & 1U) == 0) {
      bVar11 = true;
      bVar12 = false;
      pcVar1 = (code *)swi(0x57);
      uVar3 = (*pcVar1)();
      iVar5 = (int)lVar6;
      uVar7 = unaff_RBX;
      if (bVar11 || bVar12) {
        while( true ) {
          param_1 = (ulonglong)(uint)(iVar5 - (int)uVar7);
          puVar9 = (ulonglong *)((longlong)puVar8 + -8);
          puVar8 = (undefined2 *)((longlong)puVar8 + -8);
          *puVar9 = param_2;
          cVar2 = (char)uVar3;
          if (param_1 != 0) break;
code_r0x00018016cb82:
          cRamb0708d6880f78476 = cVar2;
          iVar5 = (int)param_1;
          in(0x80);
          uVar3 = in(0x16);
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      *(undefined1 *)(ulonglong)uVar10 = *unaff_RSI;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (!(bool)in_CF) {
    unaff_RSI[-0x2fed58fb] = unaff_RSI[-0x2fed58fb];
    if (-0x6e < (char)(cVar2 + -0x2b)) {
      halt_baddata();
    }
    puVar4 = (uint *)(ulonglong)((byte)(cVar2 + 0x42) + 0xe58ca837);
  }
  out(0x84,(char)puVar4);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

