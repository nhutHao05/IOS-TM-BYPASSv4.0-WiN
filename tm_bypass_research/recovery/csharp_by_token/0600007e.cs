// Recovered from method token 0x0600007e; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_007e_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		ConnectSshOverUsb();
		UpdateProgress(2);
		MountDeviceFilesystem();
		UpdateProgress(3);
		string deviceProductVersion = DeviceStateRecovered.DeviceProductVersion;
		if (deviceProductVersion.Contains("12"))
		{
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/i12update", "/System/Library/PrivateFrameworks/PreferencesUI.framework/General.plist");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/i12erase", "/System/Library/PrivateFrameworks/PreferencesUI.framework/Reset.plist");
			ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/PreferencesUI.framework/General.plist");
			ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/PreferencesUI.framework/Reset.plist");
			ExecuteSshCommand("killall -9 backboardd");
		}
		else
		{
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/i13update", "/System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/General.plist");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/i13erase", "/System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/Reset.plist");
			ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/General.plist");
			ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/Reset.plist");
			ExecuteSshCommand("killall -9 backboardd");
		}
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist");
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.OTACrashCopier.plist");
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.mobile.softwareupdated.plist");
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.OTATaskingAgent.plist");
		ExecuteSshCommand("launchctl unload -w /System/Library/LaunchDaemons/com.apple.OTATaskingAgent.plist");
		ExecuteSshCommand("mount -o rw,union,update /");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/bebeo", "/tmp/bebeo.tar");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/lzma", "/sbin/lzma");
		ExecuteSshCommand("chmod 755 /sbin/lzma");
		ExecuteSshCommand("lzma -d -v /tmp/bebeo.tar");
		ExecuteSshCommand("tar -C / -xvf /tmp/bebeo.tar  rm -r /tmp/bebeo.tar");
		ExecuteSshCommand("chmod 755 /usr/libexec/substrate  /usr/libexec/substrate");
		ExecuteSshCommand("chmod 755 /usr/libexec/substrated  /usr/libexec/substrated");
		ExecuteSshCommand("killall -9 backboardd");
		ExecuteSshCommand("chmod +x Library/MobileSubstrate/DynamicLibraries/MobileSafety.dylib");
		ExecuteSshCommand("chmod +x Library/MobileSubstrate/DynamicLibraries/OTADisabler.dylib");
		UpdateProgress(100);
		MessageBox.Show("Done!", "Info");
	}
	catch (Exception ex)
	{
		Console.WriteLine(ex.Message.ToString());
		MessageBox.Show("Error in Activation Process (3)" + ex.Message, "Error in Activation Process (3)", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
}
