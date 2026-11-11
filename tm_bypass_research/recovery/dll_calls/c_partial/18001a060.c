/* Analyst pseudocode from an unpacked memory snapshot.
 * Not original source; API names come from emulated thunks.
 */

/* Only the VM entry is recovered here; the VM body remains protected. */

undefined8 sbservices_get_home_screen_wallpaper_pngdata_Recovered(void)

{
  func_0x000180d915bb();
                    /* 0x1a060  255  sbservices_get_home_screen_wallpaper_pngdata */
  LOCK();
  UNLOCK();
  return 0xfffffffff131dfc3;
}

