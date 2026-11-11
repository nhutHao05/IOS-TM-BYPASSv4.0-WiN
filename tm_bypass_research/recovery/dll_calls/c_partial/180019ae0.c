/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* Only the VM entry is recovered here; the VM body remains protected. */

void sbservices_set_icon_state_Recovered(char *param_1,undefined2 param_2)

{
  undefined1 uVar1;
  uint *puVar2;
  undefined1 *unaff_RDI;
  undefined1 in_SF;
  
                    /* 0x19ae0  259  sbservices_set_icon_state */
  puVar2 = (uint *)func_0x000180dbfef6();
  if (!(bool)in_SF) {
    uVar1 = in(CONCAT11((char)((ushort)param_2 >> 8) + *param_1,(char)param_2));
    *unaff_RDI = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uRam325d35f2311c69fa = SUB81(puVar2,0);
  *puVar2 = *puVar2 ^ (uint)puVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

