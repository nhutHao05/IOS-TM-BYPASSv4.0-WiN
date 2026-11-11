// Recovered from method token 0x0600005f; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

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
