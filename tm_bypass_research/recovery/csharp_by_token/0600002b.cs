// Recovered from method token 0x0600002b; analyst names; not the original source.
internal uint Recovered_06_002b_Name(uint pos, byte prevByte)
{
	return ((pos & Recovered_04_0026_Name) << Recovered_04_0025_Name) + (uint)(prevByte >> 8 - Recovered_04_0025_Name);
}
