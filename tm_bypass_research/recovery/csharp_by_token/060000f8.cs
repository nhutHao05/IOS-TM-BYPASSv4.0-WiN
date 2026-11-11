// Recovered from method token 0x060000f8; analyst names; not the original source.
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00f8_Name()
{
	Process[] processesByName = Process.GetProcessesByName("iproxy");
	foreach (Process process in processesByName)
	{
		process.Kill();
	}
	if (File.Exists("%USERPROFILE%\\.ssh\\known_hosts"))
	{
		File.Delete("%USERPROFILE%\\.ssh\\known_hosts");
	}
}
