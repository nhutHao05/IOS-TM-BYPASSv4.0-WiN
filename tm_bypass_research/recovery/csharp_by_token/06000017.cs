// Recovered from method token 0x06000017; analyst names; not the original source.
internal static uint Recovered_06_0017_Name(Recovered_02_0002_TypeName[] Models, uint startIndex, Recovered_02_0004_TypeName rangeDecoder, int NumBitLevels)
{
	uint num = 1u;
	uint num2 = 0u;
	for (int i = 0; i < NumBitLevels; i++)
	{
		uint num3 = Models[startIndex + num].Recovered_06_0012_Name(rangeDecoder);
		num <<= 1;
		num += num3;
		num2 |= num3 << i;
	}
	return num2;
}
