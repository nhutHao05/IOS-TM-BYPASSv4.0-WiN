// Recovered from method token 0x06000129; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_0129_Name(object P_0, EventArgs P_1)
{
	Recovered_06_0126_Name();
	Control.CheckForIllegalCrossThreadCalls = false;
	Recovered_06_0127_Name();
	try
	{
		Recovered_04_00aa_Name.Text = Recovered_06_0124_Name();
		string text = Recovered_06_0128_Name();
		text = text.ToString().Replace("\n", "").Replace("\r", "")
			.Replace("\t", "");
		switch (text)
		{
		case "AUTHORIZED":
			if (!Recovered_04_008f_Name)
			{
				DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
				deviceOperationsRecovered.Recovered_06_0076_Name();
			}
			goto default;
		default:
			if (text == "AUTHORIZED" && Recovered_04_008f_Name)
			{
				DeviceOperationsRecovered deviceOperationsRecovered2 = new DeviceOperationsRecovered();
				deviceOperationsRecovered2.Recovered_06_0076_Name();
			}
			break;
		case "NOT_AUTHORIZED":
			MessageBox.Show("Sorry Your iDevice Serial Not Registered", "Check Serial", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00fc_Name(0, "Not Authorized Serial");
			Process.Start("https://iservicevn.com/buy.php");
			break;
		case "CONECTION_ERROR":
			MessageBox.Show("Unlock your iDevice and Press Trust!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00fc_Name(0, "DEVICE NOT PAIRED");
			Recovered_04_00c0_Name.Enabled = true;
			break;
		}
	}
	catch (Exception value)
	{
		Console.WriteLine(value);
		MessageBox.Show("Please Re Open Tool and Click USB Patch Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
	finally
	{
		Recovered_06_0125_Name();
	}
}
