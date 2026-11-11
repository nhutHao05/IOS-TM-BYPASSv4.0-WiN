/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined4 house_arrest_send_command_Recovered(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined6 uVar3;
  undefined4 unaff_ESI;
  
  uVar3 = (undefined6)((ulonglong)param_2 >> 0x10);
                    /* 0x9340  68  house_arrest_send_command */
  uVar2 = (undefined1)param_2;
  func_0x000180cfc54a();
  puVar1 = (uint *)(CONCAT62(uVar3,CONCAT11(0xd2,uVar2)) + 7);
  *puVar1 = *puVar1 >> 1;
  return unaff_ESI;
}

