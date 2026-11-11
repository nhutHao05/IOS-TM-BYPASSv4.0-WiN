// Recovered from method token 0x0600010b; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_010b_Name()
{
	try
	{
		return "https://iservicevn.com/";
	}
	catch (Exception ex)
	{
		if (DeviceStateRecovered.DiagnosticMode)
		{
			Console.WriteLine(ex.ToString());
		}
		return "CONECTION_ERROR";
	}
}
