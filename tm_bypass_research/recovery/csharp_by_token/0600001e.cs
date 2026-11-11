// Recovered from method token 0x0600001e; analyst names; not the original source.
using System;

internal void Recovered_06_001e_Name(uint dictionarySize)
{
	if (Recovered_04_0019_Name != dictionarySize)
	{
		Recovered_04_0019_Name = dictionarySize;
		Recovered_04_001a_Name = Math.Max(Recovered_04_0019_Name, 1u);
		uint windowSize = Math.Max(Recovered_04_001a_Name, 4096u);
		Recovered_04_0013_Name.Recovered_06_0033_Name(windowSize);
	}
}
