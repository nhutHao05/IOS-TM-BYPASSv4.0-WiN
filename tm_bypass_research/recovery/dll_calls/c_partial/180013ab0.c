/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup2_send_request_Recovered(longlong param_1,undefined2 param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  uint unaff_EBP;
  int unaff_ESI;
  undefined1 in_PF;
  char in_ZF;
  
  puVar6 = (undefined1 *)register0x00000020;
                    /* 0x13ab0  180  mobilebackup2_send_request */
  while( true ) {
    *(undefined8 *)(puVar6 + -8) = 0xffffffffc446a294;
    *(undefined **)(puVar6 + -0x10) = &UNK_180716d39;
    lVar5 = func_0x000180dbfef6();
    if ((bool)in_PF) {
      in(param_2);
      uVar4 = in(0xe1);
      lVar5 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar4);
      unaff_EBP = 0x1d4409c0;
      out(param_2,(int)lVar5);
    }
    if (param_1 + -1 == 0 || in_ZF == '\0') break;
    out(0x2d,(char)lVar5);
    *(undefined4 *)(lVar5 + -0x55) = 0x933a692b;
    puVar1 = (uint *)(param_1 + 0x5b);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 - unaff_EBP;
    if (uVar2 < unaff_EBP) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    cVar3 = ((char)lVar5 -
            ((longlong)(int)((longlong)unaff_ESI * 0x69266a8b) != (longlong)unaff_ESI * 0x69266a8b))
            + '$';
    in_ZF = cVar3 == '\0';
    in_PF = (POPCOUNT(cVar3) & 1U) == 0;
    param_1 = param_1 + -1;
    puVar6 = puVar6 + -8;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

