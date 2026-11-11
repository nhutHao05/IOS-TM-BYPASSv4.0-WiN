/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_start_service_Recovered
               (undefined8 param_1,char param_2,undefined8 param_3,byte param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  longlong unaff_RBP;
  
                    /* 0x10060  141  lockdownd_start_service */
  iVar2 = func_0x000180de3bb5();
  uVar3 = iVar2 * 2 + 0x64050002;
  uVar3 = uVar3 | *(uint *)(ulonglong)uVar3;
  piVar4 = (int *)(ulonglong)uVar3;
  *(byte *)(unaff_RBP + 1) = *(byte *)(unaff_RBP + 1) & (byte)uVar3;
  *(char *)((longlong)piVar4 + 0x45) = *(char *)((longlong)piVar4 + 0x45) + param_2;
  *piVar4 = *piVar4 + uVar3;
  pbVar1 = (byte *)((longlong)piVar4 * 2 + 0x5f808b48);
  *pbVar1 = *pbVar1 | param_4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

