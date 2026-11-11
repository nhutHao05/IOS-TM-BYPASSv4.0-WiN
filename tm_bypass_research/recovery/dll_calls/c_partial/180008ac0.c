/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00018077fea2) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void heartbeat_client_start_service_Recovered(longlong param_1)

{
  undefined1 unaff_BL;
  char unaff_BH;
  undefined6 unaff_0000001a;
  
  func_0x000180cd8a6f();
  if (param_1 != 1 &&
      unaff_BH != *(char *)(CONCAT62(unaff_0000001a,CONCAT11(unaff_BH,unaff_BL)) + -0x79)) {
    LOCK();
    UNLOCK();
    return;
  }
  return;
}

