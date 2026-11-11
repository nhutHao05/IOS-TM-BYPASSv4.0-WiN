/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Instruction at (ram,0x00018013e28d) overlaps instruction at (ram,0x00018013e28b)
    */
/* WARNING: Removing unreachable block (ram,0x00018013e28d) */
/* WARNING: Removing unreachable block (ram,0x00018013e2a7) */
/* Only the VM entry is recovered here; the VM body remains protected. */

void service_disable_ssl_Recovered(undefined8 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  undefined1 *unaff_RSI;
  undefined4 *unaff_RDI;
  
                    /* 0x1ade0  269  service_disable_ssl */
  func_0x000180de3bb5();
  uVar1 = func_0x000180cd8a6f();
  out(param_2,uVar1);
  *unaff_RDI = *unaff_RDI;
  out(*unaff_RSI,param_2);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

