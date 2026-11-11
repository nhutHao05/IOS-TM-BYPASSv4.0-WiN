/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilebackup_send_error_Recovered(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = func_0x000180d15cec();
  out(0x54,uVar1);
  *(int *)(param_1 + -1) = *(int *)(param_1 + -1) << 8;
                    /* 0x12eb0  193  mobilebackup_send_error */
  LOCK();
  UNLOCK();
  return;
}

