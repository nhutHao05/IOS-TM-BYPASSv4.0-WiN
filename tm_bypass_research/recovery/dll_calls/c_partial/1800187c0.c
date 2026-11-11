/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void restored_client_free_Recovered(undefined8 param_1,int *param_2)

{
  uint *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  byte *pbVar4;
  byte bVar5;
  undefined7 uVar6;
  char *unaff_RSI;
  char *unaff_RDI;
  undefined1 in_CF;
  undefined1 in_ZF;
  undefined1 in_SF;
  
  uVar6 = (undefined7)((ulonglong)param_1 >> 8);
                    /* 0x187c0  241  restored_client_free */
  bVar5 = (byte)param_1;
  uVar3 = func_0x000180de4640();
  if (!(bool)in_CF && !(bool)in_ZF) {
    if (!(bool)in_SF) {
      pbVar4 = (byte *)CONCAT71((int7)((ulonglong)uVar3 >> 8),0x7c);
      if (CONCAT71(uVar6,bVar5) == 0) {
        *pbVar4 = *pbVar4 >> 1 | 0x80;
        return;
      }
      out(0x67,0x7c);
      return;
    }
    if (*unaff_RDI <= *unaff_RSI) {
      *param_2 = *param_2 + 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  puVar1 = (uint *)(param_2 + 0x34dcd6);
  *puVar1 = *puVar1 >> (bVar5 & 0x1f) | *puVar1 << 0x20 - (bVar5 & 0x1f);
  pcVar2 = (code *)swi(1);
  (*pcVar2)();
  return;
}

