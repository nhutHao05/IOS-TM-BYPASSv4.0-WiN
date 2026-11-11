// Recovered from method token 0x060000f7; analyst names; not the original source.
using System.ComponentModel;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00f7_Name()
{
	Recovered_06_00f8_Name();
	try
	{
		Process process = new Process
		{
			StartInfo = new ProcessStartInfo
			{
				FileName = Recovered_04_007f_Name + "\\vendor\\iproxy.exe",
				Arguments = Recovered_04_0080_Name + " 44",
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
