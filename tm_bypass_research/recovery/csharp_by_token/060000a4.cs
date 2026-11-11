// Recovered from method token 0x060000a4; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00a4_Name()
{
	ExecuteSshCommand("rm -f /usr/bin/ldrestart");
	ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib && rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
	ExecuteSshCommand("rm -rf /Library/MobileSubstrate/DynamicLibraries/");
	ExecuteSshCommand("rm -rf /Library/Frameworks/CydiaSubstrate.framework");
	ExecuteSshCommand("rm /Library/MobileSubstrate/MobileSubstrate.dylib");
	ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries && rm /Library/MobileSubstrate/ServerPlugins");
	ExecuteSshCommand("rm /usr/bin/cycc && rm /usr/bin/cynject");
	ExecuteSshCommand("rm /usr/include/substrate.h");
	ExecuteSshCommand("rm /usr/lib/cycript0.9/com/saurik/substrate/MS.cy");
	ExecuteSshCommand("rm -rf /usr/lib/substrate");
	ExecuteSshCommand("rm /usr/lib/libsubstrate.dylib");
	ExecuteSshCommand("rm /usr/libexec/substrate && rm /usr/libexec/substrated");
}
