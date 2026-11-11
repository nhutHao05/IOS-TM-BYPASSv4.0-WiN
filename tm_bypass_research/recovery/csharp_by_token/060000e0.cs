// Recovered from method token 0x060000e0; analyst names; not the original source.
using System.Diagnostics;

public string Recovered_06_00e0_Name(string P_0, string P_1)
{
	Process process = new Process();
	process.StartInfo = new ProcessStartInfo
	{
		FileName = P_0,
		Arguments = P_1,
		UseShellExecute = false,
		RedirectStandardOutput = true,
		CreateNoWindow = true
	};
	process.Start();
	return process.StandardOutput.ReadToEnd();
}
