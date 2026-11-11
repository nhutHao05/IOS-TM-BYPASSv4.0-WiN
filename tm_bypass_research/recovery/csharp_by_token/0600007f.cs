// Recovered from method token 0x0600007f; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_007f_Name()
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
		string text = Recovered_06_0083_Name();
		string text2 = "http://iservicevn.com/idvbackup/" + text + ".tgz";
		if (Recovered_06_00c9_Name(text2))
		{
			UpdateProgress(100);
			MessageBox.Show("iDevice Already Backup on Server", "iService VN");
			return;
		}
		Directory.CreateDirectory(Recovered_04_0055_Name + text);
		Directory.CreateDirectory(Recovered_04_0055_Name + text + "/FairPlay/");
		Directory.CreateDirectory(Recovered_04_0055_Name + text + "/Lockdown/");
		UpdateProgress(20);
		string text3 = "";
		SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
		text3 = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
		UpdateProgress(30);
		Recovered_04_0043_Name.Download(text3 + "Library/internal/data_ark.plist", new FileInfo(Recovered_04_0055_Name + text + "/data_ark.plist"));
		Recovered_04_0043_Name.Download(text3 + "Library/activation_records/activation_record.plist", new FileInfo(Recovered_04_0055_Name + text + "/activation_record.plist"));
		UpdateProgress(40);
		ExecuteSshCommand("chmod 755 /var/mobile/Library/FairPlay");
		ExecuteSshCommand("rm -Rf /var/mobile/Library/FairPlay/iTunes_Control/iTunes/IC-Info.sisv");
		Recovered_06_008f_Name();
		ExecuteSshCommand("uicache --all ");
		ExecuteSshCommand("killall -9 backboardd");
		UpdateProgress(50);
		Recovered_04_0043_Name.Download("/private/var/mobile/Library/FairPlay", new DirectoryInfo(Recovered_04_0055_Name + text + "/FairPlay/"));
		Recovered_04_0043_Name.Download("/var/root/Library/Lockdown", new DirectoryInfo(Recovered_04_0055_Name + text + "/Lockdown/"));
		Recovered_04_0043_Name.Download("/private/var/wireless/Library/Preferences/com.apple.commcenter.device_specific_nobackup.plist", new FileInfo(Recovered_04_0055_Name + text + "/com.apple.commcenter.device_specific_nobackup.plist"));
		Recovered_04_0043_Name.Download("/var/mobile/Library/Preferences/com.apple.purplebuddy.plist", new FileInfo(Recovered_04_0055_Name + text + "/com.apple.purplebuddy.plist"));
		UpdateProgress(60);
		Recovered_04_0043_Name.Download("/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem", new FileInfo(Recovered_04_0055_Name + text + "/RaptorActivation.pem"));
		UpdateProgress(65);
		string text4 = text + ".tgz";
		string text5 = Recovered_04_0054_Name + "/Backup/" + text + ".tgz";
		string text6 = Recovered_04_0055_Name + text;
		Recovered_06_00ba_Name(text6, text5, text4);
		UpdateProgress(80);
		if (Directory.Exists(Recovered_04_0055_Name))
		{
			Directory.Delete(Recovered_04_0055_Name, recursive: true);
		}
		Recovered_06_0099_Name();
		UpdateProgress(90);
		ExecuteSshCommand("rm -Rf /var/mobile/Library/FairPlay/iTunes_Control/iTunes/IC-Info.sisv");
		UpdateProgress(95);
		Recovered_06_00c8_Name();
		UpdateProgress(100);
		Recovered_02_000f_TypeName recovered_02_000f_TypeName = new Recovered_02_000f_TypeName();
		recovered_02_000f_TypeName.ShowDialog();
	}
	catch (Exception ex)
	{
		Console.WriteLine(ex.Message.ToString());
		MessageBox.Show("Error in Backup Process : " + ex.Message, "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		Recovered_06_00c8_Name();
	}
}
