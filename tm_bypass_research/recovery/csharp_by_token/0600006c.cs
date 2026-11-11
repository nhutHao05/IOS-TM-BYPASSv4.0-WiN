// Recovered from method token 0x0600006c; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_006c_Name()
{
	try
	{
		Recovered_04_0063_Name = 1;
		try
		{
			Recovered_06_00c1_Name();
			EnsureDevicePairing();
			UpdateProgress(1);
			ConnectSshOverUsb();
			UpdateProgress(2);
			MountDeviceFilesystem();
			UpdateProgress(3);
			ExecuteSshCommand("rm -rf /Library/MobileSubstrate/DynamicLibraries/");
			ExecuteSshCommand("rm -rf /Library/Frameworks/CydiaSubstrate.framework");
			ExecuteSshCommand("rm /Library/MobileSubstrate/MobileSubstrate.dylib");
			ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries");
			ExecuteSshCommand("rm /Library/MobileSubstrate/ServerPlugins");
			ExecuteSshCommand("rm /usr/bin/cycc");
			ExecuteSshCommand("rm /usr/bin/cynject");
			ExecuteSshCommand("rm /usr/include/substrate.h");
			ExecuteSshCommand("rm /usr/lib/cycript0.9/com/saurik/substrate/MS.cy");
			ExecuteSshCommand("rm -rf /usr/lib/substrate");
			ExecuteSshCommand("rm /usr/lib/libsubstrate.dylib");
			ExecuteSshCommand("rm /usr/libexec/substrate");
			ExecuteSshCommand("rm /usr/libexec/substrated");
			UpdateProgress(8);
			string text = "";
			SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
			text = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
			UpdateProgress(10);
			ExecuteSshCommand("chflags nouchg " + text + "Library/internal/data_ark.plist");
			ExecuteSshCommand("chflags nouchg " + text + "Library/activation_records/activation_record.plist");
			ExecuteSshCommand("chflags nouchg /var/mobile/Library/Preferences/com.apple.purplebuddy.plist");
			ExecuteSshCommand("chflags nouchg /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chflags nouchg /var/root/Library/Lockdown/data_ark.plist");
			ExecuteSshCommand("rm " + text + "Library/internal/data_ark.plist");
			ExecuteSshCommand("rm " + text + "Library/activation_records/activation_record.plist");
			ExecuteSshCommand("rm /var/mobile/Library/Preferences/com.apple.purplebuddy.plist");
			ExecuteSshCommand("rm /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("rm /var/root/Library/Lockdown/data_ark.plist");
			ExecuteSshCommand("launchctl unload -F /System/Library/LaunchDaemons/*");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/*");
			UpdateProgress(15);
			EnsureDevicePairing();
			ExecuteSshCommand("rm -r /System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
			UpdateProgress(18);
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/raptor", "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
			ExecuteSshCommand("snappy -f / -r `snappy -f / -l | sed -n 2p` -t orig-fs");
			UpdateProgress(20);
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/uikit.tar", "/uikit.tar");
			ExecuteSshCommand("cd / && tar -xvf uikit.tar && chmod 755 /usr/bin/*");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/9A", "/tmp/boot.tar.lzma");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/BC", "/sbin/lzma");
			ExecuteSshCommand("chmod 755 /sbin/lzma");
			ExecuteSshCommand("lzma -d -v /tmp/boot.tar.lzma");
			ExecuteSshCommand("tar -C / -xvf /tmp/boot.tar && rm -r /tmp/boot.tar");
			ExecuteSshCommand("chmod 755 /usr/libexec/substrate && /usr/libexec/substrate");
			ExecuteSshCommand("chmod 755 /usr/libexec/substrated && /usr/libexec/substrated");
			ExecuteSshCommand("killall -9 backboardd");
			UpdateProgress(30);
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/12", "/Library/MobileSubstrate/DynamicLibraries/untethered.dylib");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/34", "/Library/MobileSubstrate/DynamicLibraries/untethered.plist");
			ExecuteSshCommand("chmod +x /Library/MobileSubstrate/DynamicLibraries/untethered.dylib");
			ExecuteSshCommand("killall -9 SpringBoard mobileactivationd");
			Recovered_06_006d_Name();
			UpdateProgress(50);
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/activation_record.plist", "/var/mobile/Media/Downloads/activation_record.plist");
			ExecuteSshCommand("chflags nouchg /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/com.apple.commcenter.device_specific_nobackup.plist", "/var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chflags uchg /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chmod -R 755 /var/containers/Data/System");
			string text2 = "";
			SshCommand sshCommand2 = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
			text2 = sshCommand2.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
			UpdateProgress(60);
			ExecuteSshCommand("mkdir -p " + text2 + "Library/activation_records");
			ExecuteSshCommand("cp -r /var/mobile/Media/Downloads/activation_record.plist " + text2 + "Library/activation_records/activation_record.plist");
			ExecuteSshCommand("launchctl unload /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
			ExecuteSshCommand("launchctl load /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/56", "/Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/78", "/Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
			UpdateProgress(70);
			ExecuteSshCommand("chmod +x /Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib");
			ExecuteSshCommand("rm -r /Library/MobileSubstrate/DynamicLibraries/untethered.dylib");
			ExecuteSshCommand("rm -r /Library/MobileSubstrate/DynamicLibraries/untethered.plist");
			ExecuteSshCommand("rm -r /Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib");
			ExecuteSshCommand("rm -r /Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
			ExecuteSshCommand("rm -r /var/mobile/Library/Logs/mobileactivationd");
			Recovered_06_009e_Name();
			UpdateProgress(75);
			Recovered_06_0088_Name();
			UpdateProgress(80);
			Recovered_06_008a_Name();
			UpdateProgress(85);
			Recovered_06_008c_Name();
			UpdateProgress(90);
			Recovered_06_008d_Name();
			UpdateProgress(92);
			Recovered_06_008e_Name();
			UpdateProgress(94);
			ExecuteSshCommand("launchctl unload -F -w /System/Library/LaunchDaemons/com.apple.CommCenter.plist");
			UpdateProgress(96);
			Recovered_06_00a5_Name();
			UpdateProgress(98);
			Recovered_06_008f_Name();
			UpdateProgress(100);
		}
		catch (Exception ex)
		{
			Recovered_06_006e_Name(ex);
			return;
		}
		Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
		recovered_02_0010_TypeName.ShowDialog();
	}
	catch (Exception ex2)
	{
		Recovered_06_006e_Name(ex2);
	}
}
