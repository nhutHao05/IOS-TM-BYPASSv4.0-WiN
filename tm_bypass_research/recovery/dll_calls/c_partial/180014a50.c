/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_clear_all_records_on_device_Recovered(void)

{
                    /* 0x14a50  202  mobilesync_clear_all_records_on_device */
  func_0x000180de3bb5();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

