// Recovered from method token 0x06000093; analyst names; not the original source.
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_0093_Name(string P_0)
{
	string currentDirectory = Directory.GetCurrentDirectory();
	try
	{
		Process process = ((!(P_0 == "pair")) ? new Process
		{
			StartInfo = new ProcessStartInfo
			{
				FileName = currentDirectory + "\\vendor\\idevicepair.exe",
				Arguments = "validate",
				UseShellExecute = false,
				RedirectStandardOutput = true,
				CreateNoWindow = true
			}
		} : new Process
		{
			StartInfo = new ProcessStartInfo
			{
				FileName = currentDirectory + "\\vendor\\idevicepair.exe",
				Arguments = "pair",
				UseShellExecute = false,
				RedirectStandardOutput = true,
				CreateNoWindow = true
			}
		});
		try
		{
			process.Start();
			StreamReader standardOutput = process.StandardOutput;
			string text = standardOutput.ReadToEnd();
			Thread.Sleep(2000);
			try
			{
				process.Kill();
			}
			catch
			{
			}
			if (text.Contains("SUCCESS"))
			{
				standardOutput.Dispose();
				return true;
			}
			return false;
		}
		catch
		{
		}
	}
	catch (Win32Exception)
	{
		MessageBox.Show("Idevicepair not found");
		return false;
	}
	return false;
}
