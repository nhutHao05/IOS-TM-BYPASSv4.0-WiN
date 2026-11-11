// Recovered from method token 0x06000094; analyst names; not the original source.
using System.ComponentModel;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0094_Name()
{
	Recovered_06_0095_Name();
	try
	{
		Process process = new Process
		{
			StartInfo = new ProcessStartInfo
			{
				FileName = Recovered_04_0052_Name + "\\vendor\\iproxy.exe",
				Arguments = Recovered_04_0046_Name + " 44",
				UseShellExecute = false,
				RedirectStandardOutput = true,
				CreateNoWindow = true
			}
		};
		process.Start();
	}
	catch (Win32Exception)
	{
		MessageBox.Show("iproxy not found");
	}
}
