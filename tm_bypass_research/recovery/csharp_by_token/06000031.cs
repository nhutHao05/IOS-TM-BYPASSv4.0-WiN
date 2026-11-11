// Recovered from method token 0x06000031; analyst names; not the original source.
internal byte Recovered_06_0031_Name(Recovered_02_0004_TypeName rangeDecoder)
{
	uint num = 1u;
	do
	{
		num = (num << 1) | Recovered_04_0027_Name[num].Recovered_06_0012_Name(rangeDecoder);
	}
	while (num < 256);
	return (byte)num;
}
