// Recovered from method token 0x060000dd; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Threading;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00dd_Name()
{
	try
	{
		Recovered_06_00e1_Name();
		SshCommand sshCommand = Recovered_04_009f_Name.CreateCommand("mount -o rw,union,update /");
		IAsyncResult asyncResult = sshCommand.BeginExecute();
		while (!asyncResult.IsCompleted)
		{
			Thread.Sleep(2000);
		}
		sshCommand.EndExecute(asyncResult);
		string text = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
		string text2 = Recovered_06_00e0_Name(text, "-s");
		if (!text2.StartsWith("ERROR: "))
		{
		}
	}
	catch (Exception ex)
	{
		if (ex.Message.Contains("Wait Please"))
		{
		}
	}
}
