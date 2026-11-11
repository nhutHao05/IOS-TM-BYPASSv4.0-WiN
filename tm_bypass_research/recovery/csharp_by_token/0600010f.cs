// Recovered from method token 0x0600010f; analyst names; not the original source.
using System;
using System.Windows.Forms;

private void Recovered_06_010f_Name(object P_0, EventArgs P_1)
{
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00b4_Name.Enabled = false;
	});
	DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
	deviceOperationsRecovered.Recovered_06_0074_Name();
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00b4_Name.Enabled = true;
	});
}
