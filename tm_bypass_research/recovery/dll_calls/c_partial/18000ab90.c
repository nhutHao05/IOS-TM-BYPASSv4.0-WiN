/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void idevice_connection_disable_bypass_ssl_Recovered(undefined8 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  byte unaff_BL;
  undefined7 unaff_00000019;
  undefined4 *unaff_RDI;
  undefined1 in_PF;
  undefined *puStack_10;
  undefined8 uStack_8;
  
                    /* 0xab90  71  idevice_connection_disable_bypass_ssl */
  uStack_8 = 0x31311913;
  puStack_10 = &UNK_180230abc;
  uVar2 = func_0x000180d915bb();
  *unaff_RDI = uVar2;
  if ((bool)in_PF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  piVar1 = (int *)(CONCAT71(unaff_00000019,0xe4) + -0x1bf866da);
  *piVar1 = *piVar1 + -0x23ae513a + (uint)CARRY1(unaff_BL,(byte)((uint)uVar2 >> 8));
  LOCK();
  *param_2 = (int)&puStack_10;
  UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

