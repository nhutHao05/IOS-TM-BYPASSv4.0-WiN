// Recovered from method token 0x06000127; analyst names; not the original source.
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_0127_Name()
{
	string deviceUDID = DeviceStateRecovered.DeviceUDID;
	string contents = "@echo off\nECHO " + deviceUDID + " | vendor\\openssl.exe base64 -d | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A";
	File.WriteAllText(Recovered_04_0090_Name + "/utils/hash.cmd", contents);
	new Process();
	Process process = new Process();
	process.StartInfo = new ProcessStartInfo
	{
		FileName = Recovered_04_0090_Name + "/utils/hash.cmd",
		UseShellExecute = false,
		RedirectStandardOutput = true,
		CreateNoWindow = true
	};
	process.Start();
	string contents2 = process.StandardOutput.ReadToEnd();
	process.WaitForExit();
	File.WriteAllText(Recovered_04_0090_Name + "msys-core.dll", contents2);
}
