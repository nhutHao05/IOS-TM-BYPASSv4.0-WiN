// Recovered from method token 0x060000c6; analyst names; not the original source.
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00c6_Name()
{
	string deviceUDID = DeviceStateRecovered.DeviceUDID;
	using Process process = new Process();
	process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\busybox.exe";
	ProcessStartInfo startInfo = process.StartInfo;
	string[] array = new string[5];
	array[0] = "grep -A4 -B19 com.apple.gs.idms.pet.com.apple.account.AppleIDAuthentication.token ";
	array[1] = Recovered_04_0057_Name;
	array[2] = "\\";
	array[3] = deviceUDID;
	array[4] = ".lol";
	startInfo.Arguments = string.Concat(array);
	process.StartInfo.UseShellExecute = false;
	process.StartInfo.RedirectStandardOutput = true;
	process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
	process.StartInfo.CreateNoWindow = true;
	process.Start();
	StreamReader standardOutput = process.StandardOutput;
	string contents = standardOutput.ReadToEnd();
	File.WriteAllText(Recovered_04_0057_Name + "\\" + deviceUDID + ".dump", contents);
	process.WaitForExit();
	if (File.Exists(Recovered_04_0057_Name + "\\" + deviceUDID + ".lol"))
	{
		File.Delete(Recovered_04_0057_Name + "\\" + deviceUDID + ".lol");
	}
}
