// Recovered from method token 0x06000003; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Threading;

private static void Recovered_06_0003_Name(object thread)
{
	Thread thread2 = thread as Thread;
	if (thread2 == null)
	{
		thread2 = new Thread(Recovered_06_0003_Name);
		thread2.IsBackground = true;
		thread2.Start(Thread.CurrentThread);
		Thread.Sleep(500);
	}
	while (true)
	{
		if (Debugger.IsAttached || Debugger.IsLogging())
		{
			Environment.FailFast(null);
		}
		if (!thread2.IsAlive)
		{
			Environment.FailFast(null);
		}
		Thread.Sleep(1000);
	}
}
