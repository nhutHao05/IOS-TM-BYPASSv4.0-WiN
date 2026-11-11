// Recovered from method token 0x0600001a; analyst names; not the original source.
internal void Recovered_06_001a_Name()
{
	while (Recovered_04_0009_Name < 16777216)
	{
		Recovered_04_0008_Name = (Recovered_04_0008_Name << 8) | (byte)Recovered_04_000a_Name.ReadByte();
		Recovered_04_0009_Name <<= 8;
	}
}
