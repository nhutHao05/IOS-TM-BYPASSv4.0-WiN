// Recovered from method token 0x0600009c; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_009c_Name(string P_0, string P_1)
{
	try
	{
		if (!Recovered_04_0043_Name.IsConnected)
		{
			Recovered_04_0043_Name.Connect();
		}
		Recovered_04_0043_Name.Upload(new FileInfo(P_0), P_1);
		return true;
	}
	catch (Exception)
	{
		throw new ApplicationException("Error Upload Resource File");
	}
}
