/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void sbservices_client_new_Recovered(void)

{
  func_0x000180cd8a6f();
  LOCK();
  UNLOCK();
                    /* 0x156b0  160  mobile_image_mounter_new
                       0x156b0  253  sbservices_client_new */
  return;
}

