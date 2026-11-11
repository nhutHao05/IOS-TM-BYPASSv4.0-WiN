/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void preboard_commit_stashbag_Recovered(void)

{
  undefined1 extraout_AH;
  longlong unaff_RBX;
  longlong unaff_RSI;
  
                    /* 0x17aa0  228  preboard_commit_stashbag */
  func_0x000180d8cdd6();
  *(undefined1 *)(unaff_RSI + unaff_RBX) = extraout_AH;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

