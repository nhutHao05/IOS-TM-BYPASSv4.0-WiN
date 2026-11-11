// Recovered from method token 0x060000b1; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00b1_Name()
{
	if (!Recovered_04_0042_Name.IsConnected)
	{
		Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
		Recovered_04_0042_Name.Connect();
	}
	try
	{
		Recovered_04_0042_Name.CreateCommand("ldrestart").Execute();
		Thread.Sleep(10000);
		Recovered_04_0042_Name.Disconnect();
	}
	catch
	{
	}
	Recovered_06_0094_Name();
	Thread.Sleep(1000);
}
