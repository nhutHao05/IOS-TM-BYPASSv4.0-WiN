/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void mobile_image_mounter_free_Recovered(undefined8 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined1 in_SF;
  
                    /* 0x158c0  156  mobile_image_mounter_free */
  func_0x000180cfc54a();
  if (!(bool)in_SF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in(param_2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

