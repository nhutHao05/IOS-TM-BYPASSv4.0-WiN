// Recovered from method token 0x06000039; analyst names; not the original source.
internal byte Recovered_06_0039_Name(uint distance)
{
	uint num = Recovered_04_0029_Name - distance - 1;
	if (num >= Recovered_04_002c_Name)
	{
		num += Recovered_04_002c_Name;
	}
	return Recovered_04_0028_Name[num];
}
