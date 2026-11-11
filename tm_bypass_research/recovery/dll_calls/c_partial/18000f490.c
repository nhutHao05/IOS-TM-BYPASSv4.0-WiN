/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_validate_pair_Recovered(undefined8 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *unaff_RSI;
  undefined4 *unaff_RDI;
  undefined2 in_SS;
  
                    /* 0xf490  147  lockdownd_validate_pair */
  func_0x000180cfc54a();
  uVar1 = in(param_2);
  *unaff_RDI = uVar1;
  unaff_RDI[1] = *unaff_RSI;
  pcVar2 = (code *)swi(1);
  uRam00000000584cfdd0 = in_SS;
  (*pcVar2)();
  return;
}

