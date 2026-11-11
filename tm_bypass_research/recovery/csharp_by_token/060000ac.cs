// Recovered from method token 0x060000ac; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_00ac_Name(string P_0, int P_1)
{
	try
	{
		Process process = new Process();
		ProcessStartInfo processStartInfo = new ProcessStartInfo();
		processStartInfo.WindowStyle = ProcessWindowStyle.Hidden;
		processStartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\win-plutil.exe";
		if (P_1 == 1)
		{
			string text = $"\"{P_0}\"";
			processStartInfo.Arguments = "-convert xml1 " + text;
			process.StartInfo = processStartInfo;
			process.Start();
			process.WaitForExit();
			return true;
		}
		string text2 = $"\"{P_0}\"";
		processStartInfo.Arguments = "-convert binary1 " + text2;
		process.StartInfo = processStartInfo;
		process.Start();
		process.WaitForExit();
		return true;
	}
	catch (Exception ex)
	{
		Console.WriteLine(ex.ToString());
		throw new ApplicationException("Error(5)" + P_0 + " " + P_1);
	}
}
