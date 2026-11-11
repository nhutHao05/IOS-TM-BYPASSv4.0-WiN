// Recovered from method token 0x060000d6; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Management;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public MainFormRecovered()
{
	Recovered_04_0080_Name = 22;
	Recovered_04_0089_Name = false;
	Recovered_04_008a_Name = false;
	Recovered_04_008b_Name = false;
	MdmOperationSelected = false;
	Recovered_04_008d_Name = false;
	Recovered_04_008e_Name = false;
	Recovered_04_0091_Name = "127.0.0.1";
	Recovered_04_0092_Name = "alpine";
	Recovered_04_0093_Name = "";
	Recovered_04_0096_Name = "";
	Recovered_04_0097_Name = "";
	Recovered_04_0098_Name = "";
	Recovered_04_0099_Name = "";
	Recovered_04_009a_Name = "";
	Recovered_04_009b_Name = null;
	Recovered_04_009c_Name = null;
	Recovered_04_009d_Name = 2222;
	Recovered_04_009e_Name = 44;
	Recovered_04_00a1_Name = null;
	base..ctor();
	string text = Recovered_06_010a_Name();
	if (text == "CONECTION_ERROR")
	{
		MessageBox.Show("Error Connecting to Internet", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		Recovered_06_00fc_Name(0, "NO INTERNET");
		Recovered_04_00b5_Name.Enabled = true;
		Recovered_04_00b6_Name.Enabled = true;
		Recovered_04_00bd_Name.Enabled = true;
		return;
	}
	if (DeviceStateRecovered.ToolVersion != text)
	{
		Recovered_02_0012_TypeName recovered_02_0012_TypeName = new Recovered_02_0012_TypeName();
		recovered_02_0012_TypeName.ShowDialog();
		string text2 = Recovered_06_010b_Name();
		if (text2 != "CONECTION_ERROR")
		{
			Process.Start(text2);
			Recovered_06_00d7_Name();
		}
		else
		{
			MessageBox.Show(this, "Please Visit https://iservicevn.com and Look for the Latest Version available", "Check Version", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00d7_Name();
		}
		Recovered_06_00fc_Name(0, "");
		return;
	}
	InitializeComponentRecovered();
	string query = "SELECT * FROM __InstanceCreationEvent WITHIN 2 WHERE TargetInstance ISA 'Win32_PnPEntity'";
	EventQuery query2 = new EventQuery(query);
	Recovered_04_0086_Name = new ManagementEventWatcher(new ManagementScope("root\\CIMV2")
	{
		Options = 
		{
			EnablePrivileges = true
		}
	}, query2);
	Recovered_02_0019_TypeName recovered_02_0019_TypeName = Recovered_06_00e2_Name;
	Recovered_04_0086_Name.EventArrived += recovered_02_0019_TypeName.Invoke;
	Recovered_04_0086_Name.Start();
	string query3 = "SELECT * FROM __InstanceDeletionEvent WITHIN 2 WHERE TargetInstance ISA 'Win32_PnPEntity'";
	EventQuery query4 = new EventQuery(query3);
	Recovered_04_0087_Name = new ManagementEventWatcher(new ManagementScope("root\\CIMV2")
	{
		Options = 
		{
			EnablePrivileges = true
		}
	}, query4);
	Recovered_04_0087_Name.EventArrived += Recovered_06_00e3_Name;
	Recovered_04_0087_Name.Start();
	try
	{
		Recovered_06_00d9_Name();
	}
	catch (Exception)
	{
		Recovered_06_00e4_Name();
	}
}
