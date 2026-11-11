/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ReceiveFilenameRecovered(undefined8 param_1,longlong *param_2)

{
  void *pvVar1;
  uint auStackX_18 [2];
  uint auStackX_20 [2];
  
  while( true ) {
    auStackX_18[0] = 0;
    auStackX_20[0] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
    api_mobilebackup2_receive_raw_1400e4e7e(param_1,auStackX_18,4,auStackX_20);
    auStackX_18[0] =
         (auStackX_18[0] & 0xff0000 | auStackX_18[0] >> 0x10) >> 8 |
         (auStackX_18[0] & 0xff00 | auStackX_18[0] << 0x10) << 8;
    if ((auStackX_18[0] == 0) && (auStackX_20[0] == 4)) {
      return 0;
    }
    if (auStackX_20[0] != 0) break;
    if (_DAT_14000b734 != 0) {
      return auStackX_18[0];
    }
  }
  if (0x1000 < auStackX_18[0]) {
    PrintMessageRecovered
              ("ERROR: %s: too large filename length (%d)!\n","mb2_receive_filename",
               (ulonglong)auStackX_18[0]);
    return 0;
  }
  if ((void *)*param_2 != (void *)0x0) {
                    /* Recovered VMProtect thunk: ucrtbase.dll!free; offline emulation evidence. */
    api_free_1401eb5f5((void *)*param_2);
    *param_2 = 0;
  }
                    /* Recovered VMProtect thunk: ucrtbase.dll!malloc; offline emulation evidence.
                        */
  pvVar1 = api_malloc_14006f7af((ulonglong)(auStackX_18[0] + 1));
  *param_2 = (longlong)pvVar1;
  auStackX_20[0] = 0;
                    /* Recovered VMProtect thunk: imobiledevice.dll!mobilebackup2_receive_raw;
                       offline emulation evidence. */
  api_mobilebackup2_receive_raw_1400aa559(param_1,pvVar1,auStackX_18[0],auStackX_20);
  if (auStackX_20[0] == auStackX_18[0]) {
    *(undefined1 *)((ulonglong)auStackX_20[0] + *param_2) = 0;
    return auStackX_18[0];
  }
  PrintMessageRecovered("ERROR: %s: could not read filename\n","mb2_receive_filename");
  return 0;
}

