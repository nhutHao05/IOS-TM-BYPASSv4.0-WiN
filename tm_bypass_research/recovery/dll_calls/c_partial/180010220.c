/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_deactivate_Recovered(byte param_1,undefined8 param_2,longlong param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 *unaff_RBP;
  int unaff_ESI;
  undefined4 *unaff_RDI;
  longlong unaff_R12;
  undefined4 *puStack_a601;
  undefined8 uStack_18;
  undefined8 uStack_8;
  
                    /* 0x10220  126  lockdownd_deactivate */
  uStack_8 = 0x6015392;
  uVar2 = func_0x000180cfc54a();
  *unaff_RDI = uVar2;
  puVar3 = (undefined8 *)&stack0xfffffffffffffff0;
  cVar1 = '\x15';
  do {
    unaff_RBP = unaff_RBP + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *unaff_RBP;
    cVar1 = cVar1 + -1;
  } while ('\0' < cVar1);
  *(longlong *)(param_3 + -0x17) =
       *(longlong *)(param_3 + -0x17) + unaff_R12 + (ulonglong)(param_1 < (byte)((uint)uVar2 >> 8));
  *puStack_a601 = *(undefined4 *)(ulonglong)(unaff_ESI + 0x77);
  *(undefined1 *)(puStack_a601 + 1) =
       *(undefined1 *)((undefined4 *)(ulonglong)(unaff_ESI + 0x77) + 1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

