// Recovered from method token 0x060000e9; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00e9_Name()
{
	Process[] processesByName = Process.GetProcessesByName("iproxy");
	if (processesByName.Length >= 1)
	{
		Process[] array = processesByName;
		foreach (Process process in array)
		{
			process.Kill();
		}
		Recovered_04_009b_Name = null;
	}
}
