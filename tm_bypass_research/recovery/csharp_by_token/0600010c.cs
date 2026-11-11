// Recovered from method token 0x0600010c; analyst names; not the original source.
using System;
using System.Threading;

private static void Recovered_06_010c_Name(Action P_0)
{
	AutoResetEvent Recovered_04_00cc_Name = new AutoResetEvent(initialState: false);
	Thread thread = new Thread((ThreadStart)delegate
	{
		P_0();
		Recovered_04_00cc_Name.Set();
	});
	thread.SetApartmentState(ApartmentState.STA);
	thread.Start();
	Recovered_04_00cc_Name.WaitOne();
}
