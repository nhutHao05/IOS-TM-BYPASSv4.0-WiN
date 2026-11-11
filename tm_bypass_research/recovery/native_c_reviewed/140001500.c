/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

int PrintMessageRecovered(char *arg0,...)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 in_RDX;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  
  uStackX_10 = in_RDX;
  uStackX_18 = in_R8;
  uStackX_20 = in_R9;
                    /* Recovered VMProtect thunk: ucrtbase.dll!__acrt_iob_func; offline emulation
                       evidence. */
  uVar1 = api___acrt_iob_func_1401bd22d(1);
  puVar2 = (undefined8 *)native_140001000();
                    /* Recovered VMProtect thunk: ucrtbase.dll!__stdio_common_vfprintf; offline
                       emulation evidence. */
  iVar3 = api___stdio_common_vfprintf_14009de07(*puVar2,uVar1,arg0,0,&uStackX_10);
  return iVar3;
}

