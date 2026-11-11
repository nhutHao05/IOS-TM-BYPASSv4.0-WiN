// Recovered from method token 0x060000de; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00de_Name()
{
	try
	{
		Recovered_06_00e5_Name();
		if (!Recovered_04_0094_Name)
		{
			string text = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
			string text2 = Recovered_06_00e0_Name(text, "-s");
			if (!text2.StartsWith("ERROR: "))
			{
				Recovered_06_00dc_Name(text2);
				DeviceStateRecovered.DeviceUDID = Recovered_04_0093_Name;
				Recovered_04_00b1_Name.Text = DeviceStateRecovered.DeviceUDID;
				Recovered_04_00ac_Name.Text = Recovered_04_0096_Name;
				Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
			}
			string text3 = Recovered_06_00df_Name("/usr/libexec/just4fun " + Recovered_04_0093_Name);
		}
	}
	catch
	{
	}
}
