/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

void house_arrest_send_request_Recovered(void)

{
                    /* 0x9250  69  house_arrest_send_request */
  func_0x000180de4640();
  LOCK();
  UNLOCK();
  return;
}

