// Recovered from method token 0x0600009a; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_009a_Name()
{
	ExecuteSshCommand("launchctl unload /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
	ExecuteSshCommand("launchctl load /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
}
