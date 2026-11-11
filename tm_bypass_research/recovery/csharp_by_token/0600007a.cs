// Recovered from method token 0x0600007a; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
private bool Recovered_06_007a_Name()
{
	SshCommand sshCommand = ExecuteSshCommand("cd /usr/libexec && tar -xf /usr/libexec/lib.tar.gz  && /usr/libexec/kawabonza -f 'com.apple.account.DeviceLocator.find-my-iphone-app-token'");
	string result = sshCommand.Result;
	char[] array = new char[1];
	array[0] = '\n';
	string[] array2 = result.Split(array);
	Recovered_04_005c_Name = "";
	Recovered_04_005d_Name = "";
	string[] array3 = array2;
	foreach (string text in array3)
	{
		string text2 = text.Replace("\r", "");
		if (text2.Contains("\"Account\""))
		{
			string[] array4 = new string[1];
			array4[0] = "\" : \"";
			Recovered_04_005c_Name = text2.Split(array4, StringSplitOptions.None)[1].Replace("\"", "").Replace(",", "");
		}
		if (text2.Contains("\"Data\""))
		{
			string[] array5 = new string[1];
			array5[0] = "\" : \"";
			Recovered_04_005d_Name = text2.Split(array5, StringSplitOptions.None)[1].Replace("\"", "").Replace(",", "");
		}
	}
	if (!(Recovered_04_005c_Name == "") && !(Recovered_04_005d_Name == ""))
	{
		return true;
	}
	MessageBox.Show("Token is not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	return false;
}
