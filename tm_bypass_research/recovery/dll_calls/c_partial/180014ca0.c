/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_acknowledge_changes_from_device_Recovered(void)

{
                    /* 0x14ca0  195  mobilesync_acknowledge_changes_from_device */
  func_0x000180cef54a();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

