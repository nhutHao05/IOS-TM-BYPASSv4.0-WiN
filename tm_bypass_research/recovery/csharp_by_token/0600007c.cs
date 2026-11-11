// Recovered from method token 0x0600007c; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_007c_Name()
{
	SshClient sshClient = new SshClient("127.0.0.1", "root", "alpine");
	try
	{
		if (!sshClient.IsConnected)
		{
			sshClient.Connect();
		}
		sshClient.CreateCommand("cp /private/preboot/active /./").Execute();
		sshClient.CreateCommand("mount -o rw,union,update /private/preboot").Execute();
		sshClient.CreateCommand("key=$(cat /./active); mv /private/preboot/$key/usr/local/standalone/firmware/Baseband2 /private/preboot/$key/usr/local/standalone/firmware/Baseband").Execute();
		sshClient.CreateCommand("key=$(cat /./Library/Preferences/SystemConfiguration/com.apple.radios.plist); if test -z $key; then echo '' &>log; rm /log; else chflags nouchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -remove /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; killall CommCenter; fi ").Execute();
	}
	catch (Exception ex)
	{
		MessageBox.Show(ex.Message, "ERROR");
	}
}
