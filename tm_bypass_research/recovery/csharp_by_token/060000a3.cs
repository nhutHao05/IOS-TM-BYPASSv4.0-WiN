// Recovered from method token 0x060000a3; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00a3_Name()
{
	SshClient sshClient = new SshClient("127.0.0.1", "root", "alpine");
	try
	{
		if (!sshClient.IsConnected)
		{
			sshClient.Connect();
		}
		sshClient.CreateCommand("key=$(cat /./Library/Preferences/SystemConfiguration/com.apple.radios.plist); if test -z $key; then plutil -create /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -1 /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -binary /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; chflags uchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; else plutil -AirPlaneMode -remove /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -1 /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; chflags uchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; fi ").Execute();
	}
	catch (Exception ex)
	{
		MessageBox.Show(ex.Message, "ERROR");
	}
}
