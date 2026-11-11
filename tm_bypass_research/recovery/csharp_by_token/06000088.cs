// Recovered from method token 0x06000088; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0088_Name()
{
	try
	{
		if (DeviceStateRecovered.DeviceProductVersion.StartsWith("13.") || DeviceStateRecovered.DeviceProductVersion.StartsWith("14."))
		{
			ExecuteSshCommand("mkdir -p /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework && chmod -R 777 /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000c_Name, "/System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/General.plist");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000b_Name, "/System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/Reset.plist");
		}
		else
		{
			ExecuteSshCommand("mkdir -p /System/Library/PrivateFrameworks/PreferencesUI.framework && chmod -R 777 /System/Library/PrivateFrameworks/PreferencesUI.framework");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0009_Name, "/System/Library/PrivateFrameworks/PreferencesUI.framework/General.plist");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0008_Name, "/System/Library/PrivateFrameworks/PreferencesUI.framework/Reset.plist");
		}
	}
	catch (Exception ex)
	{
		Console.WriteLine("Error: " + ex.Message);
	}
}
