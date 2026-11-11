/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_device_list_extended_free_Recovered(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  undefined7 uVar2;
  longlong unaff_RBP;
  
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
                    /* 0x9950  78  idevice_device_list_extended_free */
  bVar1 = (byte)param_2;
  func_0x000180d8cdd6();
  *(byte *)(unaff_RBP + 0x4e) = *(byte *)(unaff_RBP + 0x4e) ^ bVar1;
                    /* WARNING: Could not recover jumptable at 0x000180b1cb7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulonglong)*(uint *)CONCAT71(uVar2,bVar1))();
  return;
}

