// Recovered from method token 0x060000c1; analyst names; not the original source.
using System.IO;
using System.Threading;

public void Recovered_06_00c1_Name()
{
	if (Directory.Exists(Recovered_04_0053_Name))
	{
		Directory.Delete(Recovered_04_0053_Name, recursive: true);
	}
	Thread.Sleep(600);
	Directory.CreateDirectory(Recovered_04_0053_Name);
}
