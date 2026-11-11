/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_status_get_current_list_Recovered(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
                    /* 0xcca0  114  instproxy_status_get_current_list */
  func_0x000180de4640();
  iVar1 = in(0x21);
  uVar2 = iVar1 + 0x64050002;
  puVar3 = (uint *)(ulonglong)uVar2;
  *puVar3 = *puVar3 | uVar2;
  *puVar3 = *puVar3 + uVar2;
  uVar2 = CONCAT31((int3)(uVar2 >> 8),*param_2);
  *(int *)(ulonglong)uVar2 = *(int *)(ulonglong)uVar2 + uVar2;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

