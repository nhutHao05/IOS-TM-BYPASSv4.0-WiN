// Recovered from method token 0x06000124; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_0124_Name()
{
	Recovered_06_00d8_Name();
	string result = "";
	try
	{
		string text = Recovered_06_00f6_Name("ioreg -l | grep IOPlatformSerialNumber --=never").Result.Replace("\"", "").Replace("\t", "").Replace(" ", "")
			.Replace("|IOPlatformSerialNumber=", "")
			.Trim();
		result = ((text.Length > 12) ? text.Remove(0, 13) : text);
	}
	catch
	{
	}
	return result;
}
