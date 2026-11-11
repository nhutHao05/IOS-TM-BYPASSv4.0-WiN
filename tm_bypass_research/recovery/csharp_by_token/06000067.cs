// Recovered from method token 0x06000067; analyst names; not the original source.
using System.IO;
using System.IO.Compression;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
private void ExtractMdmToolsArchive()
{
	File.WriteAllBytes(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip", ApplicationResourcesRecovered.MdmToolsZip);
	ZipFile.ExtractToDirectory(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip", TemporaryDirectory + "ikey");
	File.Delete(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip");
}
