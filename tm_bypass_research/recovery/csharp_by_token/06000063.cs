// Recovered from method token 0x06000063; analyst names; not the original source.
using System.IO;

public static void DeleteMdmWorkingDirectory()
{
	if (Directory.Exists(Recovered_04_0067_Name))
	{
		Directory.Delete(Recovered_04_0067_Name, recursive: true);
	}
}
