// Recovered from method token 0x060000cf; analyst names; not the original source.
using System;
using System.Runtime.InteropServices;

[DllImport("kernel32.dll", EntryPoint = "CheckRemoteDebuggerPresent", ExactSpelling = true, SetLastError = true)]
private static extern bool CheckRemoteDebuggerPresentRecovered(IntPtr P_0, ref bool P_1);
