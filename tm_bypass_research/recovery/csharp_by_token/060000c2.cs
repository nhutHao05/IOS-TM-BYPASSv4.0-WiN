// Recovered from method token 0x060000c2; analyst names; not the original source.
using System;
using System.IO;
using System.Threading;

public void Recovered_06_00c2_Name()
{
	try
	{
		if (Directory.Exists(Recovered_04_0057_Name))
		{
			Directory.Delete(Recovered_04_0057_Name, recursive: true);
		}
		Thread.Sleep(1000);
		Directory.CreateDirectory(Recovered_04_0057_Name);
	}
	catch (Exception)
	{
	}
}
