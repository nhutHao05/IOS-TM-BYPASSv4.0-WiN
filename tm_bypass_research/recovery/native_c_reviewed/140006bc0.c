/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void native_140006bc0(void)

{
  undefined1 *in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  longlong unaff_GS_OFFSET;
  undefined1 auStackX_8 [32];
  
  puVar1 = auStackX_8 + -(longlong)in_RAX;
  if (auStackX_8 < in_RAX) {
    puVar1 = (undefined1 *)0x0;
  }
  puVar2 = *(undefined1 **)(unaff_GS_OFFSET + 0x10);
  if (puVar1 < puVar2) {
    do {
      puVar2 = puVar2 + -0x1000;
      *puVar2 = 0;
    } while ((undefined1 *)((ulonglong)puVar1 & 0xfffffffffffff000) != puVar2);
  }
  return;
}

