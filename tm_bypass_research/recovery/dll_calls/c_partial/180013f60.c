/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobilesync_client_start_service_Recovered(undefined8 param_1,undefined2 param_2)

{
                    /* 0x13f60  205  mobilesync_client_start_service */
  func_0x000180cfc54a();
  in(param_2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

