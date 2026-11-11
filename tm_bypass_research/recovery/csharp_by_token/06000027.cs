// Recovered from method token 0x06000027; analyst names; not the original source.
internal uint Recovered_06_0027_Name(Recovered_02_0004_TypeName rangeDecoder, uint posState)
{
	if (Recovered_04_001f_Name.Recovered_06_0012_Name(rangeDecoder) == 0)
	{
		return Recovered_04_001d_Name[posState].Recovered_06_0015_Name(rangeDecoder);
	}
	uint num = 8u;
	if (Recovered_04_0020_Name.Recovered_06_0012_Name(rangeDecoder) == 0)
	{
		return num + Recovered_04_001e_Name[posState].Recovered_06_0015_Name(rangeDecoder);
	}
	num += 8;
	return num + Recovered_04_0021_Name.Recovered_06_0015_Name(rangeDecoder);
}
