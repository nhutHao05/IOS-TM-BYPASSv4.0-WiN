/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 afc_make_link_Recovered(void)

{
  func_0x000180dbfef6();
  LOCK();
  UNLOCK();
  LOCK();
  UNLOCK();
                    /* 0x4be0  19  afc_make_link */
  return 0xffffffff844dad49;
}

