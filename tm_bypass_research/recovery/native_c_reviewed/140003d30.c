/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Inlined function: CheckSecurityCookieRecovered */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void native_140003d30(char *param_1,char *param_2)

{
  code *pcVar1;
  int iVar2;
  void *arg3;
  void *arg3_00;
  ulonglong arg2;
  undefined1 *puVar3;
  undefined1 auStack_278 [8];
  undefined1 auStack_270 [48];
  undefined8 uStack_240;
  ulonglong auStack_238 [4];
  undefined1 auStack_218 [512];
  ulonglong uStack_18;
  
  uStack_18 = _DAT_14000b008 ^ (ulonglong)auStack_238;
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
  uStack_240 = 0x140003d66;
  arg3 = api_fopen_1401b3e42(param_1,"rb");
  if (arg3 == (void *)0x0) {
    uStack_240 = 0x140003d7e;
    PrintMessageRecovered("Cannot open source path \'%s\'.\n",param_1);
  }
  else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
    uStack_240 = 0x140003d93;
    arg3_00 = api_fopen_1401ce2ff(param_2,"wb");
    if (arg3_00 == (void *)0x0) {
      uStack_240 = 0x140003daa;
      PrintMessageRecovered("Cannot open destination file \'%s\'.\n",param_2);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
      uStack_240 = 0x140003db3;
      api_fclose_1401b3e04(arg3);
    }
    else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fread; offline emulation evidence. */
      uStack_240 = 0x140003dd0;
      arg2 = api_fread_14011c8eb(auStack_218,1,0x200,arg3);
      while (arg2 != 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fwrite; offline emulation evidence.
                        */
        uStack_240 = 0x140003df5;
        api_fwrite_14006bc74(auStack_218,1,arg2,arg3_00);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fread; offline emulation evidence. */
        uStack_240 = 0x140003e0e;
        arg2 = api_fread_140166f4e(auStack_218,1,0x200,arg3);
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
      uStack_240 = 0x140003e1d;
      iVar2 = api_fclose_140079fc1(arg3);
      if (iVar2 == -1) {
        uStack_240 = 0x140003e2e;
        PrintMessageRecovered("Error closing source file.\n");
      }
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
      uStack_240 = 0x140003e36;
      iVar2 = api_fclose_1400edd48(arg3_00);
      if (iVar2 == -1) {
        uStack_240 = 0x140003e48;
        PrintMessageRecovered("Error closing destination file.\n");
      }
    }
  }
  auStack_238[0] = uStack_18 ^ (ulonglong)auStack_238;
  uStack_240 = 0x140003e58;
  if ((auStack_238[0] != _DAT_14000b008) || ((short)(auStack_238[0] >> 0x30) != 0)) {
    puVar3 = auStack_278;
    iVar2 = func_0x000140006b22(0x17);
    if (iVar2 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)(2);
      puVar3 = auStack_270;
    }
    *(undefined8 *)(puVar3 + -8) = 0x140005e22;
    native_140005fec(0x14000b0f0);
    _DAT_14000b060 = *(undefined8 *)(puVar3 + 0x38);
    _DAT_14000b188 = puVar3 + 0x40;
    _DAT_14000b170 = *(undefined8 *)(puVar3 + 0x40);
    _DAT_14000b050 = 0xc0000409;
    _DAT_14000b054 = 1;
    _DAT_14000b068 = 1;
    uRam000000014000b070 = 2;
    *(ulonglong *)(puVar3 + 0x20) = _DAT_14000b008;
    *(undefined8 *)(puVar3 + 0x28) = _DAT_14000b000;
    *(undefined8 *)(puVar3 + -8) = 0x140005ec4;
    _DAT_14000b1e8 = _DAT_14000b060;
    native_140005dc4(&UNK_1400075f0);
  }
  return;
}

