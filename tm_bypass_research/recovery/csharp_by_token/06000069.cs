// Recovered from method token 0x06000069; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void RunMdmSetupProcess()
{
	using Process process = new Process();
	process.StartInfo.FileName = MdmWorkingDirectory + "MDM_SETUP.exe";
	process.StartInfo.Arguments = "";
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	process.StandardOutput.ReadToEnd();
	process.WaitForExit();
}
