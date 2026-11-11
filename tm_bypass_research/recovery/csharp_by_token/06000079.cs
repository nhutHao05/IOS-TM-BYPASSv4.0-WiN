// Recovered from method token 0x06000079; analyst names; not the original source.
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_0079_Name()
{
	SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/jlutil /var/mobile/Library/Preferences/com.apple.icloud.findmydeviced.FMIPAccounts.plist");
	Recovered_04_0059_Name = sshCommand.Result;
	char[] array = new char[1];
	array[0] = '\n';
	char[] separator = array;
	string[] array2 = Recovered_04_0059_Name.Split(separator);
	foreach (string text in array2)
	{
		string text2 = text.Replace("   ", "");
		if (text2.StartsWith("dsid: "))
		{
			Recovered_04_005a_Name = text2.Replace("dsid: ", "");
			break;
		}
	}
}
