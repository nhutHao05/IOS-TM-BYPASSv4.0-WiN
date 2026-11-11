// Recovered from method token 0x0600000f; analyst names; not the original source.
using System;
using System.Runtime.InteropServices;

[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
internal static extern bool Recovered_06_000f_Name(IntPtr lpAddress, uint dwSize, uint flNewProtect, out uint lpflOldProtect);
