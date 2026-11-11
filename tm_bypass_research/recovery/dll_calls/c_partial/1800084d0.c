/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined2 file_relay_request_sources_timeout_Recovered(void)

{
  char cVar1;
  undefined1 uVar2;
  char in_AF;
  
  uVar2 = func_0x000180db85e3();
  cVar1 = bRam000000002f972278 + 0x1f;
  if (cVar1 == '\0') {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  LOCK();
  UNLOCK();
  return CONCAT11((cVar1 < '\0') << 7 | (cVar1 == '\0') << 6 | in_AF << 4 |
                  ((POPCOUNT(cVar1) & 1U) == 0) << 2 | 2U | bRam000000002f972278 < 0xe1,uVar2);
}

