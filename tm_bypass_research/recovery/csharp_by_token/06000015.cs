// Recovered from method token 0x06000015; analyst names; not the original source.
internal uint Recovered_06_0015_Name(Recovered_02_0004_TypeName rangeDecoder)
{
	uint num = 1u;
	for (int num2 = Recovered_04_0007_Name; num2 > 0; num2--)
	{
		num = (num << 1) + Recovered_04_0006_Name[num].Recovered_06_0012_Name(rangeDecoder);
	}
	return num - (uint)(1 << Recovered_04_0007_Name);
}
