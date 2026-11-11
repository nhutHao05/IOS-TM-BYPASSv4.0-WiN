// Recovered from method token 0x060000e5; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
private bool Recovered_06_00e5_Name(string P_0 = "")
{
	Control.CheckForIllegalCrossThreadCalls = false;
	Recovered_04_009c_Name = new Process();
	Recovered_04_009c_Name.StartInfo.FileName = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
	Recovered_04_009c_Name.StartInfo.Arguments = P_0;
	Recovered_04_009c_Name.StartInfo.UseShellExecute = false;
	Recovered_04_009c_Name.StartInfo.RedirectStandardOutput = true;
	Recovered_04_009c_Name.StartInfo.CreateNoWindow = true;
	Recovered_04_009c_Name.Start();
	DeviceStateRecovered.Recovered_04_007b_Name = false;
	DeviceStateRecovered.Recovered_04_007c_Name = false;
	DeviceStateRecovered.Recovered_04_007d_Name = false;
	int num = 0;
	while (!Recovered_04_009c_Name.StandardOutput.EndOfStream)
	{
		num++;
		string text = Recovered_04_009c_Name.StandardOutput.ReadLine();
		string text2 = text.Replace("\r", "");
		if (text2.StartsWith("UniqueDeviceID: "))
		{
			string text3 = text2.Replace("UniqueDeviceID: ", "");
			Recovered_04_00b1_Name.Text = text3;
			DeviceStateRecovered.DeviceUDID = text3;
		}
		else if (text2.StartsWith("ProductVersion: "))
		{
			string text4 = (Recovered_04_0096_Name = text2.Replace("ProductVersion: ", ""));
			Recovered_04_00ac_Name.Text = text4;
			DeviceStateRecovered.DeviceProductVersion = text4;
		}
		else if (text2.StartsWith("BuildVersion: "))
		{
			string recovered_04_0097_Name = text2.Replace("BuildVersion: ", "");
			Recovered_04_0097_Name = recovered_04_0097_Name;
		}
		else if (text2.StartsWith("DeviceName: "))
		{
			string text5 = text2.Replace("DeviceName: ", "");
		}
		else if (text2.StartsWith("ProductType: "))
		{
			string deviceProductType = (Recovered_04_0098_Name = text2.Replace("ProductType: ", ""));
			Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
			DeviceStateRecovered.DeviceProductType = deviceProductType;
		}
		else if (text2.StartsWith("DeviceClass: "))
		{
			string text6 = text2.Replace("DeviceClass: ", "");
		}
		else if (text2.StartsWith("DeviceColor: "))
		{
			string text7 = text2.Replace("DeviceColor: ", "");
		}
		else if (text2.StartsWith("HardwareModel: "))
		{
			string text8 = text2.Replace("HardwareModel: ", "");
		}
		else if (text2.StartsWith("ProductName: "))
		{
			string text9 = text2.Replace("ProductName: ", "").ToLower();
		}
		else if (text2.StartsWith("TelephonyCapability: "))
		{
			string text10 = text2.Replace("TelephonyCapability: ", "");
		}
		char[] array = new char[1];
		array[0] = ':';
		string[] array2 = text.Split(array);
		if (array2[0] == "SerialNumber")
		{
			DeviceStateRecovered.DeviceSerialNumber = array2[1].Trim();
			Recovered_04_00aa_Name.Text = array2[1].Trim();
			DeviceStateRecovered.Recovered_04_007d_Name = true;
		}
		if (array2[0] == "InternationalMobileEquipmentIdentity")
		{
			DeviceStateRecovered.DeviceIMEI = array2[1].Trim();
			Recovered_04_00a5_Name.Text = array2[1].Trim();
			DeviceStateRecovered.Recovered_04_007c_Name = true;
		}
		if (array2[0] == "ActivationState")
		{
			DeviceStateRecovered.ActivationStatus = array2[1].Trim();
			Recovered_04_00c3_Name.Text = array2[1].Trim();
		}
		if (array2[0] == "SIMStatus")
		{
			DeviceStateRecovered.Recovered_04_0072_Name = array2[1].Trim();
			DeviceStateRecovered.Recovered_04_0073_Name = (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusReady") ^ (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusPINLocked");
		}
		if (text.Contains("MobileEquipmentIdentifier"))
		{
			DeviceStateRecovered.Recovered_04_007b_Name = true;
		}
		if (text.Contains("UniqueDeviceID"))
		{
			Recovered_04_00b1_Name.Text = array2[1];
		}
	}
	if (!DeviceStateRecovered.Recovered_04_007b_Name && !DeviceStateRecovered.Recovered_04_007c_Name && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPhone")) && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPad")) && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPod")) && num <= 2)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		Recovered_04_009c_Name = new Process();
		Recovered_04_009c_Name.StartInfo.FileName = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
		Recovered_04_009c_Name.StartInfo.Arguments = "-s";
		Recovered_04_009c_Name.StartInfo.UseShellExecute = false;
		Recovered_04_009c_Name.StartInfo.RedirectStandardOutput = true;
		Recovered_04_009c_Name.StartInfo.CreateNoWindow = true;
		Recovered_04_009c_Name.Start();
		DeviceStateRecovered.Recovered_04_007e_Name = false;
		int num2 = 0;
		while (!Recovered_04_009c_Name.StandardOutput.EndOfStream)
		{
			num2++;
			string text11 = Recovered_04_009c_Name.StandardOutput.ReadLine();
			string text12 = text11.Replace("\r", "");
			if (text12.StartsWith("UniqueDeviceID: "))
			{
				string text13 = text12.Replace("UniqueDeviceID: ", "");
				Recovered_04_00b1_Name.Text = text13;
				DeviceStateRecovered.Recovered_04_007e_Name = true;
			}
			else if (text12.StartsWith("ProductVersion: "))
			{
				string text14 = (Recovered_04_0096_Name = text12.Replace("ProductVersion: ", ""));
				Recovered_04_00ac_Name.Text = text14;
				DeviceStateRecovered.DeviceProductVersion = text14;
			}
			else if (text12.StartsWith("BuildVersion: "))
			{
				string recovered_04_0097_Name2 = text12.Replace("BuildVersion: ", "");
				Recovered_04_0097_Name = recovered_04_0097_Name2;
			}
			else if (text12.StartsWith("DeviceName: "))
			{
				string text15 = text12.Replace("DeviceName: ", "");
			}
			else if (text12.StartsWith("ProductType: "))
			{
				string recovered_04_0098_Name = text12.Replace("ProductType: ", "");
				Recovered_04_0098_Name = recovered_04_0098_Name;
				Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
			}
			else if (text12.StartsWith("DeviceClass: "))
			{
				string text16 = text12.Replace("DeviceClass: ", "");
			}
			else if (text12.StartsWith("DeviceColor: "))
			{
				string text17 = text12.Replace("DeviceColor: ", "");
			}
			else if (text12.StartsWith("HardwareModel: "))
			{
				string text18 = text12.Replace("HardwareModel: ", "");
			}
			else if (text12.StartsWith("ProductName: "))
			{
				string text19 = text12.Replace("ProductName: ", "").ToLower();
			}
			else if (text12.StartsWith("TelephonyCapability: "))
			{
				string text20 = text12.Replace("TelephonyCapability: ", "");
			}
			char[] array3 = new char[1];
			array3[0] = ':';
			string[] array4 = text11.Split(array3);
			if (array4[0] == "SerialNumber")
			{
				DeviceStateRecovered.DeviceSerialNumber = array4[1].Trim();
				Recovered_04_00aa_Name.Text = array4[1].Trim();
			}
			if (array4[0] == "InternationalMobileEquipmentIdentity")
			{
				DeviceStateRecovered.DeviceIMEI = array4[1].Trim();
				Recovered_04_00a5_Name.Text = array4[1].Trim();
			}
			if (array4[0] == "ActivationState")
			{
				DeviceStateRecovered.ActivationStatus = array4[1].Trim();
			}
			if (array4[0] == "SIMStatus")
			{
				DeviceStateRecovered.Recovered_04_0072_Name = array4[1].Trim();
				DeviceStateRecovered.Recovered_04_0073_Name = (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusReady") ^ (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusPINLocked");
			}
			if (text11.Contains("MobileEquipmentIdentifier"))
			{
			}
			if (text11.Contains("UniqueDeviceID"))
			{
				Recovered_04_00b1_Name.Text = array4[1];
			}
		}
		if (DeviceStateRecovered.Recovered_04_007e_Name)
		{
		}
		if (num2 <= 2)
		{
			return false;
		}
	}
	return true;
}
