// Recovered from method token 0x060000e8; analyst names; not the original source.
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
private void DispatchAuthorizedDeviceOperation(object P_0, DoWorkEventArgs P_1)
{
	Control.CheckForIllegalCrossThreadCalls = false;
	try
	{
		Recovered_06_00e9_Name();
	}
	catch (Exception)
	{
	}
	try
	{
		string text = QuerySerialAuthorization();
		switch (text.ToString().Replace("\n", "").Replace("\r", "")
			.Replace("\t", ""))
		{
		case "CONECTION_ERROR":
			MessageBox.Show("Unlock your iDevice and Press Trust!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00fc_Name(0, "DEVICE NOT PAIRED");
			Recovered_04_00c0_Name.Enabled = true;
			return;
		case "NOT_AUTHORIZED":
			MessageBox.Show("Sorry Your iDevice Serial Not Registered", "Check Serial", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00fc_Name(0, "Not Authorized Serial");
			Process.Start("https://iservicevn.com/buy.php");
			return;
		case "AUTHORIZED":
			if (Recovered_04_008a_Name)
			{
				Recovered_06_00eb_Name();
			}
			else if (Recovered_04_008b_Name)
			{
				Recovered_06_00ed_Name();
			}
			else if (Recovered_04_008d_Name)
			{
				Recovered_06_00f1_Name();
			}
			else if (MdmOperationSelected)
			{
				StartMdmWorkflow();
			}
			else if (Recovered_04_0089_Name)
			{
				Recovered_06_00ea_Name();
			}
			else if (!DeviceStateRecovered.Recovered_04_007c_Name && !DeviceStateRecovered.Recovered_04_007b_Name && Recovered_04_0098_Name.Contains("iPhone"))
			{
				if (MessageBox.Show("Your iDevice BASEBAND BROKEN Can Bypass UNTETHERED ONLY !\nAre You Sure Want To Do That ?", "Check Your iPhone Informations!", MessageBoxButtons.YesNo) == DialogResult.Yes)
				{
					Recovered_06_00f1_Name();
				}
				else
				{
					MessageBox.Show("Process Cancelled by User", "iServices VN");
				}
			}
			else if (DeviceStateRecovered.DeviceProductType.StartsWith("iPhone6,") || DeviceStateRecovered.DeviceProductType.StartsWith("iPhone8,") || DeviceStateRecovered.DeviceProductType.StartsWith("iPad"))
			{
				Recovered_06_00ef_Name();
			}
			else if ((!DeviceStateRecovered.Recovered_04_007b_Name & DeviceStateRecovered.DeviceProductVersion.StartsWith("14.6")) || DeviceStateRecovered.DeviceProductVersion.StartsWith("14.7") || DeviceStateRecovered.DeviceProductVersion.StartsWith("14.8"))
			{
				if (MessageBox.Show("Your iOS 14.6 to 14.8.1 NOT supported Signal !\niDevice will Start Bypass without SimPin locked , Press YES\nIf You Sure want Use SimPin (No Battery Drain), Press NO", "Choose Services !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
				{
					Recovered_06_00f0_Name();
				}
				else
				{
					Recovered_06_00ee_Name();
				}
			}
			else if (!DeviceStateRecovered.Recovered_04_007b_Name)
			{
				Recovered_06_00ee_Name();
			}
			else
			{
				Recovered_06_00ef_Name();
			}
			break;
		}
		Recovered_06_00fc_Name(0, "EXITO");
	}
	catch (Exception value)
	{
		Recovered_06_00fc_Name(0, "ERROR");
		if (DeviceStateRecovered.DiagnosticMode)
		{
			Console.WriteLine(value);
		}
		MessageBox.Show("Please Jailbreak with Checkra1n 0.12.4 and Try Again", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
	finally
	{
		Recovered_06_0125_Name();
	}
}
