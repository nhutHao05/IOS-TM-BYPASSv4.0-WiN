// Recovered from method token 0x060000bb; analyst names; not the original source.
using System.IO;
using ICSharpCode.SharpZipLib.Tar;

private void Recovered_06_00bb_Name(TarArchive P_0, string P_1, bool P_2)
{
	if (P_2)
	{
		string[] directories = Directory.GetDirectories(P_1);
		string[] array = directories;
		foreach (string text in array)
		{
			Recovered_06_00bb_Name(P_0, text, P_2);
		}
	}
	string[] files = Directory.GetFiles(P_1);
	string[] array2 = files;
	foreach (string fileName in array2)
	{
		TarEntry sourceEntry = TarEntry.CreateEntryFromFile(fileName);
		P_0.WriteEntry(sourceEntry, recurse: true);
	}
}
