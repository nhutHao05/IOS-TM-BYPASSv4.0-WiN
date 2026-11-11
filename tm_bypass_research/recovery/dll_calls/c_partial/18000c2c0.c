/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 instproxy_lookup_Recovered(void)

{
  char *pcVar1;
  undefined1 in_SF;
  undefined8 unaff_retaddr;
  
  pcVar1 = (char *)func_0x000180d15cec();
  if (!(bool)in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  *pcVar1 = *pcVar1 + (char)pcVar1;
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
  return unaff_retaddr;
}

