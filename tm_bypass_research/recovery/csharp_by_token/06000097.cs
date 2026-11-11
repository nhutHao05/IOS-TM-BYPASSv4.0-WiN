// Recovered from method token 0x06000097; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_0097_Name()
{
	string text = Recovered_06_00a8_Name();
	string text2 = "";
	using (Process process = new Process())
	{
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
		process.StartInfo.Arguments = "activate -s " + text;
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		text2 = process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}
	string text3 = "";
	using (Process process2 = new Process())
	{
		process2.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
		process2.StartInfo.Arguments = "state";
		process2.StartInfo.UseShellExecute = false;
		process2.StartInfo.RedirectStandardOutput = true;
		process2.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process2.StartInfo.CreateNoWindow = true;
		process2.Start();
		text3 = process2.StandardOutput.ReadToEnd();
		process2.WaitForExit();
	}
	if (text3.Contains("Activated"))
	{
		return true;
	}
	return false;
}
