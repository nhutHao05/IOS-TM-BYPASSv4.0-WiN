/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

ulonglong native_140006790(void)

{
  short *psVar1;
  ulonglong uVar2;
  int *piVar3;
  
  psVar1 = (short *)func_0x0001401a7f41(0);
  if ((((psVar1 == (short *)0x0) || (*psVar1 != 0x5a4d)) ||
      (piVar3 = (int *)((longlong)*(int *)(psVar1 + 0x1e) + (longlong)psVar1), *piVar3 != 0x4550))
     || (((psVar1 = (short *)0x20b, (short)piVar3[6] != 0x20b || ((uint)piVar3[0x21] < 0xf)) ||
         (piVar3[0x3e] == 0)))) {
    uVar2 = (ulonglong)psVar1 & 0xffffffffffffff00;
  }
  else {
    uVar2 = 0x201;
  }
  return uVar2;
}

