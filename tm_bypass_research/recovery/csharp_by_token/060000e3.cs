// Recovered from method token 0x060000e3; analyst names; not the original source.
using System.Management;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00e3_Name(object P_0, EventArrivedEventArgs P_1)
{
	Control.CheckForIllegalCrossThreadCalls = false;
	Control.CheckForIllegalCrossThreadCalls = false;
	PropertyData propertyData = P_1.NewEvent.Properties["TargetInstance"];
	ManagementBaseObject managementBaseObject = (ManagementBaseObject)propertyData.Value;
	string text = (string)managementBaseObject.Properties["Description"].Value;
	string text2 = (string)managementBaseObject.Properties["DeviceID"].Value;
	string text3 = (string)managementBaseObject.Properties["Status"].Value;
	if (text.Contains("Apple"))
	{
		Recovered_04_00ad_Name.Text = "Please connect a Jailbroken iDevice";
		Recovered_04_00a4_Name.Visible = false;
		Recovered_04_00a3_Name.Visible = true;
	}
}
