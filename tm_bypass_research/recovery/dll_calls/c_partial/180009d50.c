/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00018066828d) */
/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 idevice_connect_Recovered(int param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulonglong)param_2 >> 0x20);
  uVar3 = (undefined2)((ulonglong)param_2 >> 0x10);
  uVar2 = (undefined1)((ulonglong)param_2 >> 8);
                    /* 0x9d50  70  idevice_connect */
  uVar1 = (undefined1)param_2;
  func_0x000180dbfef6();
  *(int *)CONCAT44(uVar4,CONCAT22(uVar3,CONCAT11(uVar2,uVar1))) =
       *(int *)CONCAT44(uVar4,CONCAT22(uVar3,CONCAT11(uVar2,uVar1))) + param_1;
  LOCK();
  UNLOCK();
  return 0xffffffff84584e31;
}

