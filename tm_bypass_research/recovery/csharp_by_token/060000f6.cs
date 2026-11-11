// Recovered from method token 0x060000f6; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Threading;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public SshCommand Recovered_06_00f6_Name(string P_0)
{
	if (!Recovered_04_009f_Name.IsConnected)
	{
		Recovered_04_009f_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
		Recovered_04_009f_Name.Connect();
	}
	try
	{
		SshCommand sshCommand = Recovered_04_009f_Name.CreateCommand(P_0);
		sshCommand.CommandTimeout = TimeSpan.FromSeconds(30.0);
		sshCommand.Execute();
		if (DeviceStateRecovered.DiagnosticMode)
		{
			Console.WriteLine("=================");
			Console.WriteLine("Command Name = {0} " + sshCommand.CommandText);
			Console.WriteLine("Return Value = {0}", sshCommand.ExitStatus);
			Console.WriteLine("Error = {0}", sshCommand.Error);
			Console.WriteLine("Result = {0}", sshCommand.Result);
		}
		return sshCommand;
	}
	catch
	{
		if (!(P_0 == "ls") && !(P_0 == "uicache --all"))
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine("SSH Error caused by:" + P_0);
			}
			else
			{
				Thread.Sleep(2000);
			}
			Recovered_06_00f7_Name();
			Recovered_06_00f6_Name(P_0);
		}
		return null;
	}
}
