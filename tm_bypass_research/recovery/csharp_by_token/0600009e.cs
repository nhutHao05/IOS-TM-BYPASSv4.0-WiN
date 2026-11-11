// Recovered from method token 0x0600009e; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_009e_Name()
{
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0010_Name, "/sbin/lzma");
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000f_Name, "/lib.tar");
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0017_Name, "/foo.tar.lzma");
	ExecuteSshCommand("tar -xvf /lib.tar -C / && chmod 777 /sbin/lzma && lzma -d -v /foo.tar.lzma && tar -xvf /foo.tar -C /");
	ExecuteSshCommand("/usr/libexec/substrate");
	ExecuteSshCommand("rm /sbin/lzma && rm /lib.tar && rm /foo.tar && rm /foo.tar.lzma");
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0003_Name, "/Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib");
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0004_Name, "/Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
}
