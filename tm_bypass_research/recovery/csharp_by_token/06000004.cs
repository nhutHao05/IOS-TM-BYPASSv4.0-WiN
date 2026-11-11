// Recovered from method token 0x06000004; analyst names; not the original source.
using System.Runtime.InteropServices;

[DllImport("kernel32.dll", EntryPoint = "VirtualProtect")]
internal unsafe static extern bool Recovered_06_0004_Name(byte* lpAddress, int dwSize, uint flNewProtect, out uint lpflOldProtect);
