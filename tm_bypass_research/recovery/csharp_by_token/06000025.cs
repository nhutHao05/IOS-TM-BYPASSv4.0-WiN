// Recovered from method token 0x06000025; analyst names; not the original source.
internal void Recovered_06_0025_Name(uint numPosStates)
{
	for (uint num = Recovered_04_0022_Name; num < numPosStates; num++)
	{
		Recovered_04_001d_Name[num] = new Recovered_02_0003_TypeName(3);
		Recovered_04_001e_Name[num] = new Recovered_02_0003_TypeName(3);
	}
	Recovered_04_0022_Name = numPosStates;
}
