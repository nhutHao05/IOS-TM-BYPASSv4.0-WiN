// Recovered from method token 0x060000e6; analyst names; not the original source.
using System.Runtime.CompilerServices;
using LibUsbDotNet.DeviceNotify;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00e6_Name(object P_0, DeviceNotifyEventArgs P_1)
{
	if (!(P_1.EventType.ToString() == "DeviceRemoveComplete"))
	{
		Recovered_04_00ad_Name.Text = "iDevice Information";
		Recovered_04_00a3_Name.Visible = false;
		Recovered_04_00a4_Name.Visible = true;
		Recovered_06_00e4_Name();
	}
}
