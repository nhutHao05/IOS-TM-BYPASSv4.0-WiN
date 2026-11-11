// Recovered from method token 0x0600001b; analyst names; not the original source.
internal uint Recovered_06_001b_Name(int numTotalBits)
{
	uint num = Recovered_04_0009_Name;
	uint num2 = Recovered_04_0008_Name;
	uint num3 = 0u;
	for (int num4 = numTotalBits; num4 > 0; num4--)
	{
		num >>= 1;
		uint num5 = num2 - num >> 31;
		num2 -= num & (num5 - 1);
		num3 = (num3 << 1) | (1 - num5);
		if (num < 16777216)
		{
			num2 = (num2 << 8) | (byte)Recovered_04_000a_Name.ReadByte();
			num <<= 8;
		}
	}
	Recovered_04_0009_Name = num;
	Recovered_04_0008_Name = num2;
	return num3;
}
