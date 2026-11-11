// Recovered from method token 0x060000f4; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_00f4_Name()
{
	string result = "";
	try
	{
		Recovered_06_00f5_Name(ApplicationResourcesRecovered.Recovered_17_0005_Name, "/usr/libexec/getserial");
		Recovered_06_00f6_Name("chmod 755 /usr/libexec/getserial");
		SshCommand sshCommand = Recovered_06_00f6_Name("/usr/libexec/getserial");
		result = sshCommand.Result.Replace("Serial:", "").Replace(" ", "").Trim();
	}
	catch (Exception ex)
	{
		File.WriteAllText("error.txt", ex.Message + "\n" + ex.StackTrace);
	}
	return result;
}
