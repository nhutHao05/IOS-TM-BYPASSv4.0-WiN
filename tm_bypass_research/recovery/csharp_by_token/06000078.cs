// Recovered from method token 0x06000078; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0078_Name()
{
	SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/jlutil /private/var/wireless/Library/Preferences/com.apple.commcenter.plist");
	Recovered_04_0059_Name = sshCommand.Result;
	File.WriteAllText(Recovered_04_0054_Name + "/utils/numb.dll", Recovered_04_0059_Name);
	char[] array = new char[1];
	array[0] = '\n';
	char[] separator = array;
	string[] array2 = Recovered_04_0059_Name.Split(separator);
	foreach (string text in array2)
	{
		string text2 = text.Replace("   ", "");
		if (text2.StartsWith("mdn: "))
		{
			Recovered_04_005b_Name = Recovered_04_005b_Name + text2.Replace("mdn: ", "") + Environment.NewLine;
			break;
		}
	}
}
