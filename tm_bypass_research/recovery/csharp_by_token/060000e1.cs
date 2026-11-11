// Recovered from method token 0x060000e1; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00e1_Name()
{
	AuthenticationMethod[] array = new AuthenticationMethod[1];
	array[0] = new PasswordAuthenticationMethod("root", Recovered_04_0092_Name);
	AuthenticationMethod[] authenticationMethods = array;
	ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0091_Name, Recovered_04_0080_Name, "root", authenticationMethods);
	connectionInfo.Timeout = TimeSpan.FromSeconds(20.0);
	Recovered_04_009f_Name = new SshClient(connectionInfo);
	Recovered_04_00a0_Name = new ScpClient(connectionInfo);
	if (!Recovered_04_009f_Name.IsConnected)
	{
		Recovered_04_009f_Name.Connect();
	}
	if (!Recovered_04_00a0_Name.IsConnected)
	{
		Recovered_04_00a0_Name.Connect();
	}
}
