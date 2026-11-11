// Recovered from method token 0x060000c8; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00c8_Name()
{
	try
	{
		if (Directory.Exists(Recovered_04_0054_Name + "\\Backup\\"))
		{
			Directory.Delete(Recovered_04_0054_Name + "\\Backup\\", recursive: true);
		}
		Thread.Sleep(1000);
		Directory.CreateDirectory(Recovered_04_0054_Name + "\\Backup\\");
	}
	catch (Exception)
	{
	}
}
