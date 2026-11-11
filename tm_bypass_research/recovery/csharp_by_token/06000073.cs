// Recovered from method token 0x06000073; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0073_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		ConnectSshOverUsb();
		MountDeviceFilesystem();
		string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
		string text = "http://iservicevn.com/idvbackup/" + deviceSerialNumber + ".tgz";
		if (Recovered_06_00c9_Name(text))
		{
			MessageBox.Show("iDevice Already Backup on Server", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			return;
		}
		Directory.CreateDirectory(Recovered_04_0055_Name + deviceSerialNumber);
		Directory.CreateDirectory(Recovered_04_0055_Name + deviceSerialNumber + "/FairPlay/");
		Directory.CreateDirectory(Recovered_04_0055_Name + deviceSerialNumber + "/Lockdown/");
		string text2 = "";
		SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
		text2 = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
		Recovered_04_0043_Name.Download(text2 + "Library/internal/data_ark.plist", new FileInfo(Recovered_04_0055_Name + deviceSerialNumber + "/data_ark.plist"));
		Recovered_04_0043_Name.Download(text2 + "Library/activation_records/activation_record.plist", new FileInfo(Recovered_04_0055_Name + deviceSerialNumber + "/activation_record.plist"));
		Recovered_04_0043_Name.Download("/private/var/mobile/Library/FairPlay", new DirectoryInfo(Recovered_04_0055_Name + deviceSerialNumber + "/FairPlay/"));
		Recovered_04_0043_Name.Download("/var/root/Library/Lockdown", new DirectoryInfo(Recovered_04_0055_Name + deviceSerialNumber + "/Lockdown/"));
		Recovered_04_0043_Name.Download("/private/var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist", new FileInfo(Recovered_04_0055_Name + deviceSerialNumber + "/com.apple.commcenter.device_specific_nobackup.plist"));
		Recovered_04_0043_Name.Download("/var/mobile/Library/Preferences/com.apple.purplebuddy.plist", new FileInfo(Recovered_04_0055_Name + deviceSerialNumber + "/com.apple.purplebuddy.plist"));
		Recovered_04_0043_Name.Download("/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem", new FileInfo(Recovered_04_0055_Name + deviceSerialNumber + "/RaptorActivation.pem"));
		string text3 = deviceSerialNumber + ".tgz";
		string text4 = Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber + ".tgz";
		string text5 = Recovered_04_0055_Name + deviceSerialNumber;
		Recovered_06_00ba_Name(text5, text4, text3);
		if (Directory.Exists(Recovered_04_0055_Name))
		{
			Directory.Delete(Recovered_04_0055_Name, recursive: true);
		}
		Recovered_06_0099_Name();
		Recovered_06_00c8_Name();
		Recovered_06_00c1_Name();
	}
	catch (Exception)
	{
	}
}
