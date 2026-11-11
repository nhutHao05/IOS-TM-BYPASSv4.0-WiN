/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

void PostSyncNotificationRecovered(void *param_1,undefined8 param_2)

{
  int iVar1;
  short *psStackX_18;
  void *pvStackX_20;
  void *apvStack_18 [2];
  
  psStackX_18 = (short *)0x0;
  pvStackX_20 = (void *)0x0;
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_client_new_with_handshake; offline emulation
                       evidence. */
  iVar1 = api_lockdownd_client_new_with_handshake_140063da1(param_1,&pvStackX_20,"idevicebackup2");
  if (iVar1 == 0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_start_service; offline
                       emulation evidence. */
    api_lockdownd_start_service_140161fc5
              (pvStackX_20,"com.apple.mobile.notification_proxy",&psStackX_18);
    if ((psStackX_18 == (short *)0x0) || (*psStackX_18 == 0)) {
      PrintMessageRecovered("Could not start %s\n","com.apple.mobile.notification_proxy");
    }
    else {
                    /* Recovered VMProtect thunk: imobiledevice.dll!instproxy_client_new; offline
                       emulation evidence. */
      api_instproxy_client_new_1401b5c47(param_1,psStackX_18,apvStack_18);
      if (apvStack_18[0] != (void *)0x0) {
                    /* Recovered VMProtect thunk: imobiledevice.dll!np_post_notification; offline
                       emulation evidence. */
        api_np_post_notification_14017aaf0(apvStack_18[0],param_2);
                    /* Recovered VMProtect thunk: imobiledevice.dll!np_client_free; offline
                       emulation evidence. */
        api_np_client_free_1400ac51d(apvStack_18[0]);
      }
    }
    if (psStackX_18 != (short *)0x0) {
                    /* Recovered VMProtect thunk:
                       imobiledevice.dll!lockdownd_service_descriptor_free; offline emulation
                       evidence. */
      api_lockdownd_service_descriptor_free_1400ddc09();
      psStackX_18 = (short *)0x0;
    }
                    /* Recovered VMProtect thunk: imobiledevice.dll!lockdownd_client_free; offline
                       emulation evidence. */
    api_lockdownd_client_free_14009e51a(pvStackX_20);
  }
  return;
}

