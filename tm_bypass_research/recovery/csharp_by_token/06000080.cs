// Recovered from method token 0x06000080; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0080_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		Recovered_06_00c8_Name();
		UpdateProgress(2);
		ConnectSshOverUsb();
		UpdateProgress(5);
		MountDeviceFilesystem();
		UpdateProgress(10);
		string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
		using (WebClient webClient = new WebClient())
		{
			webClient.DownloadFile("http://iservicevn.com/idvbackup/" + deviceSerialNumber + ".tgz", Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber + ".tgz");
		}
		UpdateProgress(20);
		if (File.Exists(Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber + ".tgz"))
		{
			if (Directory.Exists(Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber))
			{
				Directory.Delete(Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber, recursive: true);
			}
			string text = Recovered_04_0054_Name + "/Backup/" + deviceSerialNumber + ".tgz";
			string text2 = Recovered_04_0054_Name + "/Backup/";
			Recovered_06_00bc_Name(text, text2);
			UpdateProgress(30);
			string text3 = "";
			SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
			text3 = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
			UpdateProgress(40);
			ExecuteSshCommand("rm -rf /var/mobile/Media/Downloads/" + deviceSerialNumber);
			ExecuteSshCommand("rm -rf /var/mobile/Media/" + deviceSerialNumber);
			ExecuteSshCommand("mkdir /var/mobile/Media/Downloads/" + deviceSerialNumber);
			Recovered_04_0043_Name.Upload(new DirectoryInfo(Recovered_04_0054_Name + "/Backup/Command/Downloads/" + deviceSerialNumber), "/var/mobile/Media/Downloads/" + deviceSerialNumber);
			UpdateProgress(50);
			ExecuteSshCommand("mv -f /var/mobile/Media/Downloads/" + deviceSerialNumber + " /var/mobile/Media/" + deviceSerialNumber);
			ExecuteSshCommand("chown -R mobile:mobile /var/mobile/Media/" + deviceSerialNumber);
			ExecuteSshCommand("chmod -R 755 /var/mobile/Media/" + deviceSerialNumber);
			ExecuteSshCommand("chmod 644 /var/mobile/Media/" + deviceSerialNumber + "/activation_record.plist");
			ExecuteSshCommand("chmod 644 /var/mobile/Media/" + deviceSerialNumber + "/data_ark.plist");
			ExecuteSshCommand("chmod 644 /var/mobile/Media/" + deviceSerialNumber + "/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("killall backboardd");
			Thread.Sleep(6000);
			ExecuteSshCommand("mv -f /var/mobile/Media/" + deviceSerialNumber + "/FairPlay /var/mobile/Library/FairPlay");
			ExecuteSshCommand("chmod 755 /var/mobile/Library/FairPlay");
			UpdateProgress(55);
			ExecuteSshCommand("chflags nouchg " + text3 + "/Library/internal/data_ark.plist");
			string[] array = new string[5];
			array[0] = "mv -f /var/mobile/Media/";
			array[1] = deviceSerialNumber;
			array[2] = "/data_ark.plist ";
			array[3] = text3;
			array[4] = "/Library/internal/data_ark.plist";
			ExecuteSshCommand(string.Concat(array));
			ExecuteSshCommand("chmod 755 " + text3 + "/Library/internal/data_ark.plist");
			ExecuteSshCommand("chflags uchg " + text3 + "/Library/internal/data_ark.plist");
			ExecuteSshCommand("mkdir " + text3 + "/Library/activation_records");
			string[] array2 = new string[5];
			array2[0] = "mv -f /var/mobile/Media/";
			array2[1] = deviceSerialNumber;
			array2[2] = "/activation_record.plist ";
			array2[3] = text3;
			array2[4] = "/Library/activation_records/activation_record.plist";
			ExecuteSshCommand(string.Concat(array2));
			ExecuteSshCommand("chmod 755 " + text3 + "/Library/activation_records/activation_record.plist");
			ExecuteSshCommand("chflags uchg " + text3 + "/Library/activation_records/activation_record.plist");
			UpdateProgress(60);
			ExecuteSshCommand("chflags nouchg /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("mv -f /var/mobile/Media/" + deviceSerialNumber + "/com.apple.commcenter.device_specific_nobackup.plist /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chown root:mobile /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chmod 755 /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("chflags uchg /var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist");
			ExecuteSshCommand("launchctl unload /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
			ExecuteSshCommand("launchctl load /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
			UpdateProgress(65);
			if (File.Exists(Recovered_04_0054_Name + "/Backup/Command/Downloads/" + deviceSerialNumber + "/RaptorActivation.pem"))
			{
				ExecuteSshCommand("mv -f /var/mobile/Media/" + deviceSerialNumber + "/RaptorActivation.pem /System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
			}
			else
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0014_Name, "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
			}
			UpdateProgress(70);
			Recovered_06_009e_Name();
			UpdateProgress(80);
			Recovered_06_00ae_Name();
			UpdateProgress(81);
			Recovered_06_0088_Name();
			UpdateProgress(82);
			Recovered_06_008a_Name();
			UpdateProgress(84);
			Recovered_06_008c_Name();
			UpdateProgress(85);
			Recovered_06_008d_Name();
			UpdateProgress(86);
			Recovered_06_00ad_Name();
			UpdateProgress(88);
			Recovered_06_008f_Name();
			UpdateProgress(90);
			Recovered_06_00a5_Name();
			UpdateProgress(96);
			if (Directory.Exists(Environment.CurrentDirectory + "/ref/Backup/" + deviceSerialNumber))
			{
				Directory.Delete(Environment.CurrentDirectory + "/ref/Backup/" + deviceSerialNumber, recursive: true);
			}
			Recovered_06_00c8_Name();
			Recovered_06_008b_Name();
			UpdateProgress(100);
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
			Process.Start("https://iservicevn.com");
		}
		else
		{
			UpdateProgress(100);
			MessageBox.Show("Your Backup Not Found on Server!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}
	catch (Exception)
	{
		UpdateProgress(100);
		MessageBox.Show("iDevice ReActive Failed! Please Erase All Data and Try Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		Recovered_06_00c1_Name();
		Recovered_06_00c8_Name();
	}
}
