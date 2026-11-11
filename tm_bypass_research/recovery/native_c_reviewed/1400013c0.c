/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

undefined8 native_1400013c0(void *param_1,char *param_2)

{
  int iVar1;
  void *arg0;
  longlong *arg0_00;
  ulonglong uVar2;
  ulonglong arg2;
  
  if (param_2 != (char *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fopen; offline emulation evidence. */
    arg0 = api_fopen_1400f402e(param_2,"rb");
    if (arg0 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fseek; offline emulation evidence. */
      api_fseek_14012b3d2(arg0,0,2);
                    /* Recovered VMProtect thunk: ucrtbase.dll!ftell; offline emulation evidence. */
      iVar1 = api_ftell_1401d544c(arg0);
      arg2 = (ulonglong)iVar1;
                    /* Recovered VMProtect thunk: ucrtbase.dll!rewind; offline emulation evidence.
                        */
      api_rewind_14010fa0c(arg0);
      if (arg2 == 0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
        api_fclose_1400c70ac(arg0);
      }
      else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
        arg0_00 = (longlong *)api_malloc_140217baa(arg2 + 1);
                    /* Recovered VMProtect thunk: ucrtbase.dll!fread; offline emulation evidence. */
        uVar2 = api_fread_14004f869(arg0_00,1,arg2,arg0);
        if (uVar2 == arg2) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
          api_fclose_1401977f4(arg0);
        }
        else {
                    /* Recovered VMProtect thunk: ucrtbase.dll!fclose; offline emulation evidence.
                        */
          api_fclose_1400cfa71(arg0);
          arg2 = 0;
        }
        if (arg0_00 != (longlong *)0x0) {
          if ((8 < arg2) && (*arg0_00 == 0x30307473696c7062)) {
                    /* Recovered VMProtect thunk: plist.dll!plist_from_bin; offline emulation
                       evidence. */
            api_plist_from_bin_1400a8151((char *)arg0_00,(int)arg2,param_1);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
            api_free_1401ce2f9(arg0_00);
            return 1;
          }
                    /* Recovered VMProtect thunk: plist.dll!plist_from_xml; offline emulation
                       evidence. */
          api_plist_from_xml_14018a09e((char *)arg0_00,(int)arg2,param_1);
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
          api_free_140219c40(arg0_00);
          return 1;
        }
      }
    }
  }
  return 0;
}

