/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_18001cca8(void)

{
  longlong *plVar1;
  
  for (plVar1 = (longlong *)&UNK_180024b38; plVar1 < &UNK_180024b38; plVar1 = plVar1 + 1) {
    if (*plVar1 != 0) {
      (*(code *)PTR__guard_dispatch_icall_18001e580)();
    }
  }
  return;
}

