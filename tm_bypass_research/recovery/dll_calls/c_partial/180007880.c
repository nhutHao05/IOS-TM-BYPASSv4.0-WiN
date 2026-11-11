/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void mobileactivation_client_new_Recovered(void)

{
                    /* 0x7880  43  diagnostics_relay_client_new
                       0x7880  54  file_relay_client_new
                       0x7880  166  mobileactivation_client_new */
  func_0x000180de3bb5();
  return;
}

