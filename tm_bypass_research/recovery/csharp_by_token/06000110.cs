// Recovered from method token 0x06000110; analyst names; not the original source.
using System;
using System.Windows.Forms;

public void Recovered_06_0110_Name(object P_0, EventArgs P_1)
{
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00b5_Name.Enabled = false;
	});
	DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
	deviceOperationsRecovered.Recovered_06_007f_Name();
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00b5_Name.Enabled = true;
	});
}
