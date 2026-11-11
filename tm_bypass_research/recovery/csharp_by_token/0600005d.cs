// Recovered from method token 0x0600005d; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Threading;

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
