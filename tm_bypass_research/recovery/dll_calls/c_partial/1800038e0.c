/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 afc_make_directory_Recovered(void)

{
  undefined8 uVar1;
  
  uVar1 = func_0x000180dbfef6();
                    /* 0x38e0  18  afc_make_directory */
  LOCK();
  UNLOCK();
  return uVar1;
}

