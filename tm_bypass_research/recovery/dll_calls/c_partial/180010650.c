/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 lockdownd_strerror_Recovered(undefined8 param_1,undefined8 param_2)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  undefined7 uVar6;
  uint *puVar4;
  undefined8 uVar5;
  char cVar7;
  char cVar8;
  char in_CF;
  undefined1 in_ZF;
  char in_SF;
  char in_OF;
  undefined8 uStack_8;
  
  cVar8 = (char)((ulonglong)param_2 >> 8);
                    /* 0x10650  145  lockdownd_strerror */
  cVar7 = (char)param_2;
  uVar5 = func_0x000180d15cec();
  if ((bool)in_ZF || in_OF != in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar6 = (undefined7)((ulonglong)uVar5 >> 8);
  bVar3 = (char)uVar5 + '\b' + in_CF;
  uStack_8 = CONCAT71(0xffffffff95713a,cVar7 + -0x44);
  bVar3 = bVar3 | *(byte *)CONCAT71(uVar6,bVar3);
  puVar4 = (uint *)CONCAT71(uVar6,bVar3 + 0x54);
  *puVar4 = *puVar4 | (uint)puVar4;
  bVar2 = bVar3 + 0x88;
  *(byte *)CONCAT71(uVar6,bVar2) = *(byte *)CONCAT71(uVar6,bVar2) | bVar2;
  pcVar1 = (char *)(CONCAT71(uVar6,bVar3 - 0x26) + 0x50);
  *pcVar1 = *pcVar1 + cVar8 + (0xad < bVar2);
  LOCK();
  UNLOCK();
  return uStack_8;
}

