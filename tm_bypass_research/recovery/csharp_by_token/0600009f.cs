// Recovered from method token 0x0600009f; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool UploadResourceViaScp(byte[] P_0, string P_1)
{
	try
	{
		if (!Recovered_04_0043_Name.IsConnected)
		{
			Recovered_04_0043_Name.Connect();
		}
		MemoryStream source = new MemoryStream(P_0);
		Recovered_04_0043_Name.Upload(source, P_1);
		return true;
	}
	catch (Exception)
	{
		throw new ApplicationException("Error Upload Resource File");
	}
}
