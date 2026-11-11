/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140006850(void)

{
  longlong *plVar1;
  
  for (plVar1 = (longlong *)&UNK_140009170; plVar1 < &UNK_140009170; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_140007578)();
    }
  }
  return;
}

