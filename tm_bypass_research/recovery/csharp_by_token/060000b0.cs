// Recovered from method token 0x060000b0; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Threading;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public SshCommand ExecuteSshCommand(string P_0)
{
	if (!Recovered_04_0042_Name.IsConnected)
	{
		Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
		Recovered_04_0042_Name.Connect();
	}
	try
	{
		SshCommand sshCommand = Recovered_04_0042_Name.CreateCommand(P_0);
		IAsyncResult asyncResult = sshCommand.BeginExecute();
		while (!asyncResult.IsCompleted)
		{
			Thread.Sleep(1000);
		}
		string text = sshCommand.EndExecute(asyncResult);
		if (Recovered_04_005e_Name)
		{
			Console.WriteLine("===========================================");
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
			if (Recovered_04_005e_Name)
			{
				Console.WriteLine("SSH Error caused by:" + P_0);
			}
			else
			{
				Thread.Sleep(2000);
			}
			Recovered_06_0094_Name();
			ExecuteSshCommand(P_0);
		}
		return null;
	}
}
