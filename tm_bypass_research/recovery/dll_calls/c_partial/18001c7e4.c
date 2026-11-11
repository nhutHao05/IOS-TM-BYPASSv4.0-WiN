/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 native_18001c7e4(void)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong unaff_GS_OFFSET;
  bool bVar6;
  
  iVar3 = func_0x00018001ce8c();
  if (iVar3 == 0) {
LAB_18001c812:
    uVar5 = 0;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x30) + 8);
    do {
      lVar4 = 0;
      LOCK();
      bVar6 = _DAT_18002c8d8 == 0;
      lVar2 = lVar1;
      if (!bVar6) {
        lVar4 = _DAT_18002c8d8;
        lVar2 = _DAT_18002c8d8;
      }
      _DAT_18002c8d8 = lVar2;
      UNLOCK();
      if (bVar6) goto LAB_18001c812;
    } while (lVar1 != lVar4);
    uVar5 = 1;
  }
  return uVar5;
}

