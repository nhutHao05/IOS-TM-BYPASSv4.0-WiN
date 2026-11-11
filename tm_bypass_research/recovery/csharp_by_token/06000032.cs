// Recovered from method token 0x06000032; analyst names; not the original source.
internal byte Recovered_06_0032_Name(Recovered_02_0004_TypeName rangeDecoder, byte matchByte)
{
	uint num = 1u;
	do
	{
		uint num2 = (uint)((matchByte >> 7) & 1);
		matchByte <<= 1;
		uint num3 = Recovered_04_0027_Name[(1 + num2 << 8) + num].Recovered_06_0012_Name(rangeDecoder);
		num = (num << 1) | num3;
		if (num2 != num3)
		{
			while (num < 256)
			{
				num = (num << 1) | Recovered_04_0027_Name[num].Recovered_06_0012_Name(rangeDecoder);
			}
			break;
		}
	}
	while (num < 256);
	return (byte)num;
}
