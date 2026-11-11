/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void instproxy_browse_with_callback_Recovered(void)

{
  ushort uVar1;
  
                    /* 0xbf80  98  instproxy_browse_with_callback */
  uVar1 = func_0x000180cfc54a();
  uRam251cab06af00077a = uVar1 & 0xff2a;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

