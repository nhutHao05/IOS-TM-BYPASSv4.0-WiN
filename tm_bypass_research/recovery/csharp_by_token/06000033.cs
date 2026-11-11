// Recovered from method token 0x06000033; analyst names; not the original source.
internal void Recovered_06_0033_Name(uint windowSize)
{
	if (Recovered_04_002c_Name != windowSize)
	{
		Recovered_04_0028_Name = new byte[windowSize];
	}
	Recovered_04_002c_Name = windowSize;
	Recovered_04_0029_Name = 0u;
	Recovered_04_002b_Name = 0u;
}
