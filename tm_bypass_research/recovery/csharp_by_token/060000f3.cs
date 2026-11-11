// Recovered from method token 0x060000f3; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00f3_Name(int P_0, int P_1)
{
	string text = Environment.CurrentDirectory + "/vendor/iproxy.exe";
	if ((Recovered_04_009b_Name == null && File.Exists(text)) || Recovered_04_009b_Name.HasExited)
	{
		Recovered_04_009b_Name = new Process();
		Recovered_04_009b_Name.StartInfo.FileName = text;
		Recovered_04_009b_Name.StartInfo.Arguments = P_0 + " " + P_1;
		Recovered_04_009b_Name.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		Recovered_04_009b_Name.Start();
	}
	else if (File.Exists(text))
	{
	}
}
