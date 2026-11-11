// Recovered from method token 0x060000c5; analyst names; not the original source.
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00c5_Name()
{
	string deviceUDID = DeviceStateRecovered.DeviceUDID;
	using Process process = new Process();
	process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\irestores.exe";
	ProcessStartInfo startInfo = process.StartInfo;
	string[] array = new string[8];
	array[0] = Recovered_04_0057_Name;
	array[1] = "\\";
	array[2] = deviceUDID;
	array[3] = " dumpkeys ";
	array[4] = Recovered_04_0057_Name;
	array[5] = "\\";
	array[6] = deviceUDID;
	array[7] = ".lol";
	startInfo.Arguments = string.Concat(array);
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	process.StandardOutput.ReadToEnd();
	process.WaitForExit();
}
