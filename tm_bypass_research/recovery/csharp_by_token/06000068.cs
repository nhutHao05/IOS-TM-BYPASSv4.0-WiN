// Recovered from method token 0x06000068; analyst names; not the original source.
using System.IO;
using System.IO.Compression;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void ExtractMdmBackupArchive()
{
	File.WriteAllBytes(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip", ApplicationResourcesRecovered.MdmBackupZip);
	ZipFile.ExtractToDirectory(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip", MdmWorkingDirectory + DeviceStateRecovered.DeviceUDID);
	File.Delete(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip");
}
