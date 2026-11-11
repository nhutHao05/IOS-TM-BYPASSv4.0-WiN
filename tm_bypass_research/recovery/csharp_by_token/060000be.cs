// Recovered from method token 0x060000be; analyst names; not the original source.
using System.Runtime.CompilerServices;
using Claunia.PropertyList;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_00be_Name(NSDictionary P_0, string P_1, int P_2 = 4)
{
	P_0.TryGetValue(P_1, out var value);
	return Recovered_06_00bf_Name(value.ToXmlPropertyList().ToString(), P_2).Replace("\n", "").Replace("\r", "").Replace("</data>", "")
		.Replace("</plist>", "")
		.Replace("</string>", "")
		.Replace("<string>", "")
		.Trim();
}
