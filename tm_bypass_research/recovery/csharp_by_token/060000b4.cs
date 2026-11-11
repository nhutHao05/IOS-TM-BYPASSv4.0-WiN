// Recovered from method token 0x060000b4; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00b4_Name()
{
	using (Process process = new Process())
	{
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
		process.StartInfo.Arguments = "deactivate";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}
	Recovered_06_009a_Name();
}
