// Recovered from method token 0x060000ba; analyst names; not the original source.
using System.IO;
using System.Runtime.CompilerServices;
using ICSharpCode.SharpZipLib.GZip;
using ICSharpCode.SharpZipLib.Tar;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00ba_Name(string P_0, string P_1, string P_2)
{
	if (!P_1.EndsWith(".tgz"))
	{
		P_1 += ".tgz";
	}
	using FileStream baseOutputStream = File.Create(Path.Combine(P_2, P_1));
	using GZipOutputStream outputStream = new GZipOutputStream(baseOutputStream);
	using TarArchive tarArchive = TarArchive.CreateOutputTarArchive(outputStream);
	Recovered_06_00bb_Name(tarArchive, P_0, true);
}
