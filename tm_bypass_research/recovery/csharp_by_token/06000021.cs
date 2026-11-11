// Recovered from method token 0x06000021; analyst names; not the original source.
using System.IO;

internal void Recovered_06_0021_Name(Stream inStream, Stream outStream)
{
	Recovered_04_0016_Name.Recovered_06_0018_Name(inStream);
	Recovered_04_0013_Name.Recovered_06_0034_Name(outStream, Recovered_04_0018_Name);
	for (uint num = 0u; num < 12; num++)
	{
		for (uint num2 = 0u; num2 <= Recovered_04_001c_Name; num2++)
		{
			uint num3 = (num << 4) + num2;
			Recovered_04_000b_Name[num3].Recovered_06_0011_Name();
			Recovered_04_000c_Name[num3].Recovered_06_0011_Name();
		}
		Recovered_04_000d_Name[num].Recovered_06_0011_Name();
		Recovered_04_000e_Name[num].Recovered_06_0011_Name();
		Recovered_04_000f_Name[num].Recovered_06_0011_Name();
		Recovered_04_0010_Name[num].Recovered_06_0011_Name();
	}
	Recovered_04_0012_Name.Recovered_06_002a_Name();
	for (uint num = 0u; num < 4; num++)
	{
		Recovered_04_0015_Name[num].Recovered_06_0014_Name();
	}
	for (uint num = 0u; num < 114; num++)
	{
		Recovered_04_0014_Name[num].Recovered_06_0011_Name();
	}
	Recovered_04_0011_Name.Recovered_06_0026_Name();
	Recovered_04_0017_Name.Recovered_06_0026_Name();
	Recovered_04_001b_Name.Recovered_06_0014_Name();
}
