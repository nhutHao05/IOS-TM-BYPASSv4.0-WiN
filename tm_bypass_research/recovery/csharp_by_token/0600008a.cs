// Recovered from method token 0x0600008a; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_008a_Name()
{
	try
	{
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist && launchctl unload -w /System/Library/LaunchDaemons/com.apple.OTACrashCopier.plist && launchctl unload -w /System/Library/LaunchDaemons/com.apple.mobile.softwareupdated.plist && launchctl unload -w /System/Library/LaunchDaemons/com.apple.OTATaskingAgent.plist");
		ExecuteSshCommand("rm -rf /System/Library/LaunchDaemons/com.apple.softwareupdateservicesd.plist && rm -rf /System/Library/LaunchDaemons/com.apple.mobile.softwareupdated.plist &&  rm -rf /System/Library/LaunchDaemons/com.apple.mobile.obliteration &&  rm -rf /System/Library/LaunchDaemons/com.apple.OTATaskingAgent");
	}
	catch (Exception ex)
	{
		Console.WriteLine("Failed to Disable OTA: " + ex.Message);
	}
}
