// Recovered from method token 0x06000090; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void UpdateProgress(int P_0, string P_1 = "")
{
	MainFormRecovered Recovered_04_006d_Name = (MainFormRecovered)Application.OpenForms["MainForm"];
	Recovered_04_006d_Name.Invoke((MethodInvoker)delegate
	{
		Recovered_04_006d_Name.Recovered_06_00fc_Name(P_0, P_0.ToString());
	});
	if (P_1 == "")
	{
		P_0.ToString();
	}
	else
	{
		P_1 = P_0 + " >>> " + P_1;
	}
	Console.WriteLine(P_1);
}
