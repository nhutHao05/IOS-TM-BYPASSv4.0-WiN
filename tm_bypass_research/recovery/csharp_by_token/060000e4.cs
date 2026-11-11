// Recovered from method token 0x060000e4; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00e4_Name()
{
	if (!Recovered_06_00e5_Name())
	{
		Recovered_04_00ad_Name.Text = "Please connect a Jailbroken iDevice";
		Recovered_04_00a3_Name.Visible = true;
		Recovered_04_00a4_Name.Visible = false;
	}
	else
	{
		Recovered_04_00ad_Name.Text = "iDevice Information";
		Recovered_04_00a4_Name.Visible = true;
		Recovered_06_00e5_Name();
	}
}
