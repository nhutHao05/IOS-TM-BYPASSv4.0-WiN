// Recovered from method token 0x060000bc; analyst names; not the original source.
using System.IO;
using ICSharpCode.SharpZipLib.GZip;
using ICSharpCode.SharpZipLib.Tar;

public void Recovered_06_00bc_Name(string P_0, string P_1)
{
	Stream stream = File.OpenRead(P_0);
	Stream stream2 = new GZipInputStream(stream);
	TarArchive tarArchive = TarArchive.CreateInputTarArchive(stream2);
	tarArchive.ExtractContents(P_1);
	tarArchive.Close();
	stream2.Close();
	stream.Close();
}
