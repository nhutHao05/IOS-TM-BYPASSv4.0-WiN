/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void afc_get_device_info_Recovered(undefined8 param_1,int param_2)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 *unaff_RDI;
  undefined1 in_SF;
  undefined8 auStack_18 [3];
  
  puVar3 = auStack_18 + 2;
  auStack_18[2] = 0x2eb69d93;
  while( true ) {
    puVar3[-1] = &UNK_1808e9cda;
    func_0x000180db85e3();
    if (!(bool)in_SF) break;
    *puVar3 = unaff_RDI;
    param_2 = param_2 + -0x2622c1b3;
    in_SF = param_2 < 0;
    puVar2 = puVar3 + -1;
    puVar3 = puVar3 + -1;
    *puVar2 = 0x2eb69d93;
  }
  puVar3[-1] = 0x61;
  uVar1 = in((short)param_2);
  *unaff_RDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

