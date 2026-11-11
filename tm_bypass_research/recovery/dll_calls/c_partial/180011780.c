/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_create_activation_info_Recovered(undefined8 param_1,longlong param_2)

{
                    /* 0x11780  168  mobileactivation_create_activation_info */
  func_0x000180d8cdd6();
                    /* WARNING: Could not recover jumptable at 0x00018073c57f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_2 + 0x46))();
  return;
}

