// Recovered from method token 0x06000083; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_0083_Name()
{
	string result = "";
	try
	{
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0005_Name, "/usr/libexec/getserial");
		ExecuteSshCommand("chmod 755 /usr/libexec/getserial");
		SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/getserial");
		result = sshCommand.Result.Replace("Serial:", "").Replace(" ", "").Trim();
	}
	catch (Exception ex)
	{
		File.WriteAllText("error.txt", ex.Message + "\n" + ex.StackTrace);
	}
	return result;
}
