// Recovered from method token 0x06000076; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0076_Name()
{
	ConnectSshOverUsb();
	UpdateProgress(2);
	try
	{
		ExecuteSshCommand("mount -uw -o union /dev/disk0s1s1").Execute();
		UpdateProgress(5);
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/chflags", "/usr/bin/chflags");
		UpdateProgress(10);
		ExecuteSshCommand("chmod 755 chflags").Execute();
		UpdateProgress(15);
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/include/libap.c", "/tmp/aplsud1");
		UpdateProgress(20);
		ExecuteSshCommand("chmod +x /tmp/aplsud1").Execute();
		UpdateProgress(25);
		ExecuteSshCommand("tmp/aplsud1").Execute();
		UpdateProgress(30);
		ExecuteSshCommand("chflags -R nouchg /private/var/mobile/Library/UserConfigurationProfiles").Execute();
		UpdateProgress(35);
		ExecuteSshCommand("chflags -R nouchg /usr/share/firmware/wifi").Execute();
		ExecuteSshCommand("rm /private/var/mobile/Library/UserConfigurationProfiles/EffectiveUserSettings.plist").Execute();
		ExecuteSshCommand("rm /private/var/mobile/Library/UserConfigurationProfiles/PublicInfo/PublicEffectiveUserSettings.plist").Execute();
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/include/libals.cpp", "/usr/libexec/aplsud");
		UpdateProgress(40);
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/E.bin", "/u.bin");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/include/settings.h", "/private/var/mobile/Library/UserConfigurationProfiles/EffectiveUserSettings.plist");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/include/peus.h", "/private/var/mobile/Library/UserConfigurationProfiles/PublicInfo/PublicEffectiveUserSettings.plist");
		ExecuteSshCommand("chmod 755 /private/var/mobile/Library/UserConfigurationProfiles/EffectiveUserSettings.plist").Execute();
		UpdateProgress(45);
		ExecuteSshCommand("chmod 755 /private/var/mobile/Library/UserConfigurationProfiles/PublicInfo/PublicEffectiveUserSettings.plist").Execute();
		ExecuteSshCommand("chflags -R uchg /private/var/mobile/Library/UserConfigurationProfiles").Execute();
		ExecuteSshCommand("snappy -f / -r `snappy -f / -l | sed -n 2p` -t orig-fs").Execute();
		ExecuteSshCommand("tar -xvf /u.bin  -C /./").Execute();
		UpdateProgress(50);
		ExecuteSshCommand("cd /./ && chmod 777 ./usr/lib/libhistory.8.dylib ./usr/lib/libncurses.6.dylib ./usr/lib/libreadline.8.dylib ./sbin/launchctl ./bin/bash").Execute();
		ExecuteSshCommand("rm /u.bin").Execute();
		ExecuteSshCommand("rm -rf /private/etc/rc.d").Execute();
		ExecuteSshCommand("mkdir -p /private/etc/rc.d").Execute();
		UpdateProgress(60);
		ExecuteSshCommand("echo '#!/bin/bash' &>/private/etc/rc.d/substrate; echo '/sbin/launchctl load -w /./Library/LaunchDaemons/com.apple.aplsud.plist' >>/private/etc/rc.d/substrate; chmod +x /private/etc/rc.d/substrate").Execute();
		ExecuteSshCommand("chmod 777 /usr/libexec/aplsud").Execute();
		ExecuteSshCommand("rm -rf /tmp/aplsud1").Execute();
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/include/cpap.h", "/./Library/LaunchDaemons/com.apple.aplsud.plist");
		string contents = "@echo off\nvendor\\idevice_id.exe -l | vendor\\openssl.exe base64 -d | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A";
		File.WriteAllText(Recovered_04_0054_Name + "/utils/hash.cmd", contents);
		Process process = new Process();
		process.StartInfo = new ProcessStartInfo
		{
			FileName = Recovered_04_0054_Name + "/utils/hash.cmd",
			UseShellExecute = false,
			RedirectStandardOutput = true,
			CreateNoWindow = true
		};
		process.Start();
		StreamReader standardOutput = process.StandardOutput;
		string contents2 = standardOutput.ReadToEnd();
		process.WaitForExit();
		UpdateProgress(70);
		File.WriteAllText(Recovered_04_0054_Name + "/utils/hash.dll", contents2);
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/hash.dll", "/usr/share/firmware/wifi/DefaulPlatform.plist");
		UpdateProgress(80);
		ExecuteSshCommand("chflags uchg /usr/share/firmware/wifi/DefaulPlatform.plist").Execute();
		UpdateProgress(90);
		ExecuteSshCommand("/private/etc/rc.d/substrate").Execute();
		UpdateProgress(100);
		MessageBox.Show("Congratulations! iDevice Successfully USB Patched! \nNow You Can use Checkra1n 0.12.4 Jailbreak without USB Restricted!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
	}
	catch (Exception)
	{
		MessageBox.Show("Please Re Open Tool and Click USB Patch Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
}
