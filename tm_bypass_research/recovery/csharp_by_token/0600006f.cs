// Recovered from method token 0x0600006f; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_006f_Name(Exception P_0 = null)
{
	string text = "Activation error!";
	if (P_0 != null)
	{
		text = P_0.Message + P_0.StackTrace;
	}
	string text2 = "\n Please Fresh Restore your iDevice and Try Again !";
	try
	{
	}
	catch
	{
	}
	MessageBox.Show(text2, "iService VN!");
}
