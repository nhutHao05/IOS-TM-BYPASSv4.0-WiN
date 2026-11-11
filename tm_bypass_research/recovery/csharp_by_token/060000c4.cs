// Recovered from method token 0x060000c4; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_00c4_Name()
{
	using (Process process = new Process())
	{
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicebackup2.exe";
		process.StartInfo.Arguments = "backup " + Recovered_04_0057_Name;
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}
	string text = "";
	using (Process process2 = new Process())
	{
		process2.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicebackup2.exe";
		process2.StartInfo.Arguments = "state";
		process2.StartInfo.UseShellExecute = false;
		process2.StartInfo.RedirectStandardOutput = true;
		process2.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process2.StartInfo.CreateNoWindow = true;
		process2.Start();
		text = process2.StandardOutput.ReadToEnd();
		process2.WaitForExit();
	}
	return text.Contains("Activated");
}
