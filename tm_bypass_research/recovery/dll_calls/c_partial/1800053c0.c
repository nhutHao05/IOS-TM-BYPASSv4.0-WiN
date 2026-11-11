/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void debugserver_client_new_Recovered(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  byte bVar9;
  uint unaff_EBX;
  undefined1 *unaff_RSI;
  undefined1 *unaff_RDI;
  undefined1 *puVar10;
  bool bVar11;
  undefined1 *puStack_8;
  
  puStack_8 = (undefined1 *)0xc4fe78;
  uVar7 = func_0x000180cd8a6f();
  iVar4 = *(int *)(&stack0xfffffffffffffff0 + param_1 * 8);
  bVar11 = (unaff_EBX & 0x400) != 0;
  uVar1 = (ulonglong)bVar11;
  *unaff_RDI = *unaff_RSI;
  bVar9 = (byte)(unaff_EBX + iVar4 >> 8);
  uVar6 = CONCAT71((int7)((ulonglong)uVar7 >> 8),(byte)uVar7 - bVar9);
  uVar8 = ((int)&puStack_8 * -0xdc604d6 - (int)&puStack_8) - (uint)((byte)uVar7 < bVar9);
  puVar10 = unaff_RDI + (ulonglong)bVar11 * -2 + 1;
  if ((POPCOUNT(uVar8 & 0xff) & 1U) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  while( true ) {
    uVar5 = (uint)uVar6 ^ 0x80a37229;
    uVar2 = (ulonglong)bVar11;
    *puVar10 = 0xb0;
    if ((int)uVar5 < 0) break;
    bVar11 = ((ulonglong)puStack_8 & 0x400) != 0;
    iVar4 = 0x271fc85a - (uint)(((ulonglong)puStack_8 & 1) != 0);
    uVar8 = (uVar8 - (int)(unaff_RSI + uVar1 * -2 + 1)) - 1;
    uVar6 = (ulonglong)CONCAT31((int3)((uint)iVar4 >> 8),(char)iVar4 + '>') & 0xffffffffffffffbf;
    puVar10 = puVar10 + uVar2 * -2 + 1;
    puStack_8 = unaff_RSI + uVar1 * -2 + 1;
  }
  if ((ulonglong)uVar8 - 1 == 0 || uVar5 == 0) {
    cRam000000001e95bdb0 = cRam000000001e95bdb0 + (char)((ulonglong)uVar8 - 1);
    pcVar3 = (code *)swi(1);
    (*pcVar3)();
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

