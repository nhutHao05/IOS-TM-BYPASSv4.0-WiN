// Recovered from method token 0x060000d8; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00d8_Name()
{
	Recovered_06_00f8_Name();
	Thread.Sleep(2000);
	using (Process process = new Process())
	{
		process.StartInfo.FileName = Recovered_04_007f_Name + "\\vendor\\iproxy.exe";
		process.StartInfo.Arguments = Recovered_04_0080_Name + " 44";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
	}
	try
	{
		Recovered_06_00e1_Name();
	}
	catch
	{
	}
}
