// Recovered from method token 0x06000023; analyst names; not the original source.
internal void Recovered_06_0023_Name(byte[] properties)
{
	int lc = properties[0] % 9;
	int num = properties[0] / 9;
	int lp = num % 5;
	int pb = num / 5;
	uint num2 = 0u;
	for (int i = 0; i < 4; i++)
	{
		num2 += (uint)(properties[1 + i] << i * 8);
	}
	Recovered_06_001e_Name(num2);
	Recovered_06_001f_Name(lp, lc);
	Recovered_06_0020_Name(pb);
}
