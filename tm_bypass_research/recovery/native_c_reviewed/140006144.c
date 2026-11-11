/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong native_140006144(void)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  ulonglong unaff_RBX;
  ulonglong unaff_RSI;
  ulonglong uVar7;
  undefined8 unaff_RDI;
  
  do {
    *(ulonglong *)((longlong)register0x00000020 + 8) = unaff_RBX;
    *(ulonglong *)((longlong)register0x00000020 + 0x10) = unaff_RSI;
    *(undefined8 *)((longlong)register0x00000020 + -8) = unaff_RDI;
    *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x14000615d;
    cVar2 = native_140006310(1);
    if (cVar2 == '\0') {
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400062a5;
      native_14000663c(7);
      uVar7 = unaff_RSI;
LAB_1400062a6:
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400062b0;
      native_14000663c(7);
    }
    else {
      uVar7 = unaff_RSI & 0xffffffffffffff00;
      *(undefined1 *)((longlong)register0x00000020 + -0x18) = 0;
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006172;
      uVar3 = native_1400062d4();
      unaff_RBX = CONCAT71((int7)(unaff_RBX >> 8),uVar3);
      if (_DAT_14000b5c0 == 1) goto LAB_1400062a6;
      if (_DAT_14000b5c0 == 0) {
        _DAT_14000b5c0 = 1;
        *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400061a4;
        iVar4 = func_0x000140006ac2(&UNK_1400075a8,&UNK_1400075c0);
        if (iVar4 != 0) {
          return 0xff;
        }
        *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400061c5;
        func_0x000140006abc(&UNK_140007590,&UNK_1400075a0);
        _DAT_14000b5c0 = 2;
      }
      else {
        uVar7 = CONCAT71((int7)(unaff_RSI >> 8),1);
        *(undefined1 *)((longlong)register0x00000020 + -0x18) = 1;
      }
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400061e0;
      native_140006480(uVar3);
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400061e5;
      plVar6 = (longlong *)func_0x000140006624();
      if (*plVar6 != 0) {
        *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400061f6;
        cVar2 = native_1400063e8(plVar6);
        if (cVar2 != '\0') {
          *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x14000620c;
          (*(code *)PTR__guard_dispatch_icall_140007578)(0,2);
        }
      }
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006211;
      plVar6 = (longlong *)func_0x00014000662c();
      if (*plVar6 != 0) {
        *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006222;
        cVar2 = native_1400063e8(plVar6);
        if (cVar2 != '\0') {
          lVar1 = *plVar6;
          *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x14000622e;
          func_0x000140006af2(lVar1);
        }
      }
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006233;
      unaff_RDI = func_0x000140006ab6();
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x14000623b;
      func_0x000140006ae0();
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006243;
      func_0x000140006ada();
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006250;
      uVar5 = RunBackupRestoreRecovered();
      unaff_RBX = (ulonglong)uVar5;
      *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006257;
      cVar2 = native_140006790();
      if (cVar2 != '\0') {
        if ((char)uVar7 == '\0') {
          *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x140006265;
          func_0x000140006ae6();
        }
        *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x14000626e;
        native_1400064a4(1,0);
        return unaff_RBX;
      }
    }
    *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400062b7;
    func_0x000140006ac8(unaff_RBX & 0xffffffff);
    *(undefined8 *)((longlong)register0x00000020 + -0x40) = 0x1400062bf;
    func_0x000140006ace(unaff_RBX & 0xffffffff);
    *(undefined8 *)((longlong)register0x00000020 + -0x68) = 0x1400062c9;
    native_140006524();
    register0x00000020 = (BADSPACEBASE *)((longlong)register0x00000020 + -0x38);
    unaff_RSI = uVar7;
  } while( true );
}

