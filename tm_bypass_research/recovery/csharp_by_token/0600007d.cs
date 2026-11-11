// Recovered from method token 0x0600007d; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_007d_Name()
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
		sshClient.CreateCommand("key=$(cat /./active); mv /private/preboot/$key/usr/local/standalone/firmware/Baseband /private/preboot/$key/usr/local/standalone/firmware/Baseband2").Execute();
		sshClient.CreateCommand("path=\"/System/Library/LaunchDaemons\"; launchctl unload -w -F $path*; launchctl load -w -F $path*").Execute();
		sshClient.CreateCommand("mv /usr/local/standalone/firmware/Baseband /usr/local/standalone/firmware/Baseband2");
		SshCommand sshCommand = sshClient.CreateCommand("find /private/preboot -type d -name \"Baseband\"");
		Recovered_04_0060_Name = sshCommand.Result.Replace("/standalone/firmware/Baseband", "").Replace("\n", "").Replace("//", "/");
		sshClient.CreateCommand("mount -o rw,union,update /private/preboot");
		string[] array = new string[5];
		array[0] = "mv ";
		array[1] = Recovered_04_0060_Name;
		array[2] = "/standalone/firmware/Baseband ";
		array[3] = Recovered_04_0060_Name;
		array[4] = "/standalone/firmware/Baseband2";
		sshClient.CreateCommand(string.Concat(array));
	}
	catch (Exception ex)
	{
		MessageBox.Show(ex.Message, "ERROR");
	}
}
