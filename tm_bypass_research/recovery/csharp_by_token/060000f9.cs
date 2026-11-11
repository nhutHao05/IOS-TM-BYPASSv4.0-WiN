// Recovered from method token 0x060000f9; analyst names; not the original source.
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00f9_Name(string P_0, int P_1, string P_2)
{
	AuthenticationMethod[] array = new AuthenticationMethod[1];
	array[0] = new PasswordAuthenticationMethod("root", P_2);
	AuthenticationMethod[] authenticationMethods = array;
	ConnectionInfo connectionInfo = new ConnectionInfo(P_0, P_1, "root", authenticationMethods);
	SshClient sshClient = new SshClient(connectionInfo);
	sshClient.Connect();
	sshClient.Disconnect();
}
