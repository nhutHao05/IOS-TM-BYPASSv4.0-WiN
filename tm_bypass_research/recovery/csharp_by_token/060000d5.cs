// Recovered from method token 0x060000d5; analyst names; not the original source.
using System;
using System.Runtime.InteropServices;

[DllImport("user32.dll", CharSet = CharSet.Auto, EntryPoint = "SendNotifyMessage", SetLastError = true)]
private static extern bool Recovered_06_00d5_Name(IntPtr P_0, uint P_1, UIntPtr P_2, string P_3);
