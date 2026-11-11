/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_event_subscribe_Recovered(byte param_1,longlong param_2)

{
  ulonglong *puVar1;
  byte *pbVar2;
  code *pcVar3;
  int *unaff_RBX;
  longlong unaff_RBP;
  
                    /* 0x9690  81  idevice_event_subscribe */
  uRam6471df7ccda42a59 = func_0x000180de3bb5();
  pbVar2 = &stack0xffffffffa0e073f8 + param_2 * 4;
  *pbVar2 = *pbVar2 >> 1 | *pbVar2 << 7;
  *unaff_RBX = *unaff_RBX + -0x1cb3f276 + (uint)((char)*pbVar2 < '\0');
  puVar1 = (ulonglong *)(unaff_RBP + -0x2b);
  *puVar1 = *puVar1 >> (param_1 & 0x3f) | *puVar1 << 0x40 - (param_1 & 0x3f);
  pcVar3 = (code *)swi(1);
  (*pcVar3)();
  return;
}

