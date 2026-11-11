// Recovered from method token 0x0600008b; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_008b_Name()
{
	string text = "";
	using Process process = new Process();
	process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicediagnostics.exe";
	process.StartInfo.Arguments = "restart";
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	text = process.StandardOutput.ReadToEnd();
	process.WaitForExit();
}
