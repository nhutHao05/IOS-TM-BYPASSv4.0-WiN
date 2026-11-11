/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void service_disable_bypass_ssl_Recovered(void)

{
  code *pcVar1;
  
                    /* 0x1ae50  268  service_disable_bypass_ssl */
  func_0x000180cfc54a();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

