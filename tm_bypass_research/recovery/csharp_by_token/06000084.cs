// Recovered from method token 0x06000084; analyst names; not the original source.
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_0084_Name()
{
	string result = "";
	try
	{
		SshCommand sshCommand = ExecuteSshCommand("ioreg -l | grep IOPlatformSerialNumber --color=never");
		result = sshCommand.Result.Replace("\"", "").Replace("\t", "").Replace(" ", "")
			.Replace("|IOPlatformSerialNumber=", "")
			.Trim()
			.Remove(0, 13);
	}
	catch
	{
	}
	return result;
}
