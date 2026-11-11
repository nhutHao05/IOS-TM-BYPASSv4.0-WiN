/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_1400067f4(undefined8 *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1f928c9d) && (piVar1[6] == 4)) {
    if ((piVar1[8] + 0xe66cfae0U < 3) || (piVar1[8] == 0x1994000)) {
      puVar3 = (undefined8 *)func_0x000140006a86();
      *puVar3 = piVar1;
      uVar4 = param_1[1];
      puVar3 = (undefined8 *)func_0x000140006a8c();
      *puVar3 = uVar4;
      func_0x000140006b1c();
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
  }
  return 0;
}

