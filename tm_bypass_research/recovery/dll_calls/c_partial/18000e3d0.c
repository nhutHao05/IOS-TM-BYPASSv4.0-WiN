/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void lockdownd_get_device_name_Recovered(void)

{
  longlong unaff_RSI;
  
                    /* 0xe3d0  128  lockdownd_get_device_name */
  uRamd823eeab2489adbf = func_0x000180cd8a6f();
  *(char *)(unaff_RSI + 0x6b) = *(char *)(unaff_RSI + 0x6b) << 6;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

