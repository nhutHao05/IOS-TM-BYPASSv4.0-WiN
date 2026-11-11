// Recovered from method token 0x06000012; analyst names; not the original source.
internal uint Recovered_06_0012_Name(Recovered_02_0004_TypeName rangeDecoder)
{
	uint num = (rangeDecoder.Recovered_04_0009_Name >> 11) * Recovered_04_0005_Name;
	if (rangeDecoder.Recovered_04_0008_Name < num)
	{
		rangeDecoder.Recovered_04_0009_Name = num;
		Recovered_04_0005_Name += 2048 - Recovered_04_0005_Name >> 5;
		if (rangeDecoder.Recovered_04_0009_Name < 16777216)
		{
			rangeDecoder.Recovered_04_0008_Name = (rangeDecoder.Recovered_04_0008_Name << 8) | (byte)rangeDecoder.Recovered_04_000a_Name.ReadByte();
			rangeDecoder.Recovered_04_0009_Name <<= 8;
		}
		return 0u;
	}
	rangeDecoder.Recovered_04_0009_Name -= num;
	rangeDecoder.Recovered_04_0008_Name -= num;
	Recovered_04_0005_Name -= Recovered_04_0005_Name >> 5;
	if (rangeDecoder.Recovered_04_0009_Name < 16777216)
	{
		rangeDecoder.Recovered_04_0008_Name = (rangeDecoder.Recovered_04_0008_Name << 8) | (byte)rangeDecoder.Recovered_04_000a_Name.ReadByte();
		rangeDecoder.Recovered_04_0009_Name <<= 8;
	}
	return 1u;
}
