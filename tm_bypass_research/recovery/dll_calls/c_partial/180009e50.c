/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00018075f99f) overlaps instruction at (ram,0x00018075f99d)
    */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_disconnect_Recovered
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 unaff_BL;
  undefined1 unaff_BH;
  undefined6 unaff_0000001a;
  undefined8 *puVar5;
  int unaff_ESI;
  
  uVar3 = func_0x000180dbfef6();
  bVar2 = *(int *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) == 0;
  if (unaff_ESI == 0 && bVar2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (unaff_ESI == 0 && bVar2) {
    *(undefined **)((ulonglong)uVar3 - 8) = &UNK_18075f98a;
    func_0x0001c84a36f2();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  pcVar1 = (code *)swi(0x49);
  uVar4 = (*pcVar1)();
  while( true ) {
    *(uint *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) =
         *(uint *)CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) & (uint)uVar4;
    puVar5 = (undefined8 *)
             CONCAT71((int7)((ulonglong)register0x00000020 >> 8),
                      (byte)register0x00000020 ^ *(byte *)(param_4 + 0x71a29041 + uVar4 * 8));
    uVar3 = (uint)uVar4 ^ 0x19;
    uVar4 = (ulonglong)uVar3;
    if (uVar3 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    register0x00000020 = (BADSPACEBASE *)(puVar5 + 1);
    if (uVar3 != 0) break;
    if (param_1 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  *puVar5 = CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

