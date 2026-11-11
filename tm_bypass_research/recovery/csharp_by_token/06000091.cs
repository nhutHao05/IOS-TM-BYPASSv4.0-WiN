// Recovered from method token 0x06000091; analyst names; not the original source.
using System;
using System.IO;

public void Recovered_06_0091_Name(string P_0 = "", string P_1 = "")
{
	Stream stream = File.Create(P_1);
	Stream stream2 = stream;
	try
	{
		Recovered_04_0043_Name.Download(P_0, stream2);
	}
	catch (Exception value)
	{
		Console.WriteLine(value);
		throw;
	}
	stream2.Close();
}
