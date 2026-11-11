// Recovered from method token 0x06000122; analyst names; not the original source.
using System;
using System.Windows.Forms;

private void Recovered_06_0122_Name(object P_0, EventArgs P_1)
{
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00c6_Name.Enabled = false;
	});
	DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
	deviceOperationsRecovered.Recovered_06_0075_Name();
	Invoke((MethodInvoker)delegate
	{
		Recovered_04_00c6_Name.Enabled = true;
	});
}
