// Recovered from method token 0x06000095; analyst names; not the original source.
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0095_Name()
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
