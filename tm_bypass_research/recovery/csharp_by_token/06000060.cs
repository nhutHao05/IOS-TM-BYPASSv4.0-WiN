// Recovered from method token 0x06000060; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0060_Name()
{
	try
	{
		Recovered_04_0063_Name = 1;
		UpdateProgress(5);
		try
		{
			Recovered_06_00c1_Name();
			EnsureDevicePairing();
			UpdateProgress(10);
			ConnectSshOverUsb();
			UpdateProgress(20);
			MountDeviceFilesystem();
			UpdateProgress(30);
			Recovered_06_00c0_Name();
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/uikit.tar", "/uikit.tar");
			ExecuteSshCommand("cd / && tar -xvf uikit.tar && chmod 755 /usr/bin/*");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/9A", "/tmp/boot.tar.lzma");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/BC", "/sbin/lzma");
			UpdateProgress(40);
			ExecuteSshCommand("chmod 755 /sbin/lzma");
			ExecuteSshCommand("lzma -d -v /tmp/boot.tar.lzma");
			ExecuteSshCommand("tar -C / -xvf /tmp/boot.tar && rm -r /tmp/boot.tar");
			ExecuteSshCommand("chmod 755 /usr/libexec/substrate && /usr/libexec/substrate");
			ExecuteSshCommand("chmod 755 /usr/libexec/substrated && /usr/libexec/substrated");
			ExecuteSshCommand("killall -9 backboardd");
			UpdateProgress(50);
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0015_Name, "/Library/MobileSubstrate/DynamicLibraries/simunlock.dylib");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0016_Name, "/Library/MobileSubstrate/DynamicLibraries/simunlock.plist");
			Recovered_06_00b3_Name(Recovered_04_0053_Name + "hash", "/tmp/rsim_simlock_hash");
			UpdateProgress(60);
			Recovered_06_00b4_Name();
			Recovered_06_00c1_Name();
			ExecuteSshCommand("killall -9 SpringBoard mobileactivationd");
			UpdateProgress(80);
			Recovered_06_0098_Name();
			ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries/simunlock.dylib && rm /Library/MobileSubstrate/DynamicLibraries/simunlock.plist");
			ExecuteSshCommand("rm -rf /tmp/rsim_simlock_hash");
			UpdateProgress(84);
			Recovered_06_00a5_Name();
			UpdateProgress(90);
			ExecuteSshCommand("killall -9 SpringBoard mobileactivationd");
			UpdateProgress(96);
			UpdateProgress(100);
		}
		catch (Exception ex)
		{
			Recovered_06_006e_Name(ex);
			return;
		}
		MessageBox.Show("Your Phone Successfully Carrier Unlocked !\nYou Can OTA UPDATE, But Can't Restore", "[Activation Successfully!]", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
	}
	catch (Exception ex2)
	{
		Recovered_06_006e_Name(ex2);
	}
}
