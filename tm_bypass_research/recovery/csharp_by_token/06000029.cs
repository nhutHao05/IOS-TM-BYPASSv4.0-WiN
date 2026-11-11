// Recovered from method token 0x06000029; analyst names; not the original source.
internal void Recovered_06_0029_Name(int numPosBits, int numPrevBits)
{
	if (Recovered_04_0023_Name == null || Recovered_04_0025_Name != numPrevBits || Recovered_04_0024_Name != numPosBits)
	{
		Recovered_04_0024_Name = numPosBits;
		Recovered_04_0026_Name = (uint)((1 << numPosBits) - 1);
		Recovered_04_0025_Name = numPrevBits;
		uint num = (uint)(1 << Recovered_04_0025_Name + Recovered_04_0024_Name);
		Recovered_04_0023_Name = new Recovered_02_0008_TypeName[num];
		for (uint num2 = 0u; num2 < num; num2++)
		{
			Recovered_04_0023_Name[num2].Recovered_06_002f_Name();
		}
	}
}
