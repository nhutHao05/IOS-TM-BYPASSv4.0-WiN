// Recovered from method token 0x060000a1; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00a1_Name()
{
	AuthenticationMethod[] array = new AuthenticationMethod[1];
	array[0] = new PasswordAuthenticationMethod("root", Recovered_04_0045_Name);
	AuthenticationMethod[] authenticationMethods = array;
	ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0044_Name, Recovered_04_0046_Name, "root", authenticationMethods);
	connectionInfo.Timeout = TimeSpan.FromSeconds(300.0);
	Recovered_04_0042_Name = new SshClient(connectionInfo);
	Recovered_04_0043_Name = new ScpClient(connectionInfo);
	if (!Recovered_04_0042_Name.IsConnected)
	{
		Recovered_04_0042_Name.Connect();
	}
	if (!Recovered_04_0043_Name.IsConnected)
	{
		Recovered_04_0043_Name.Connect();
	}
}
