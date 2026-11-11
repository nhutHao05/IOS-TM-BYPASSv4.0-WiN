// Recovered from method token 0x06000037; analyst names; not the original source.
internal void Recovered_06_0037_Name(uint distance, uint len)
{
	uint num = Recovered_04_0029_Name - distance - 1;
	if (num >= Recovered_04_002c_Name)
	{
		num += Recovered_04_002c_Name;
	}
	while (len != 0)
	{
		if (num >= Recovered_04_002c_Name)
		{
			num = 0u;
		}
		Recovered_04_0028_Name[Recovered_04_0029_Name++] = Recovered_04_0028_Name[num++];
		if (Recovered_04_0029_Name >= Recovered_04_002c_Name)
		{
			Recovered_06_0036_Name();
		}
		len--;
	}
}
