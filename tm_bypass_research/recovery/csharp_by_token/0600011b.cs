// Recovered from method token 0x0600011b; analyst names; not the original source.
using System;
using System.Windows.Forms;

private void Recovered_06_011b_Name(object P_0, EventArgs P_1)
{
	Recovered_06_010c_Name(delegate
	{
		Clipboard.SetText(DeviceStateRecovered.DeviceSerialNumber);
	});
}
