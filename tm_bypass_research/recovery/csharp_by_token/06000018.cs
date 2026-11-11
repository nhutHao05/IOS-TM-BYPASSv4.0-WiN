// Recovered from method token 0x06000018; analyst names; not the original source.
using System.IO;

internal void Recovered_06_0018_Name(Stream stream)
{
	Recovered_04_000a_Name = stream;
	Recovered_04_0008_Name = 0u;
	Recovered_04_0009_Name = uint.MaxValue;
	for (int i = 0; i < 5; i++)
	{
		Recovered_04_0008_Name = (Recovered_04_0008_Name << 8) | (byte)Recovered_04_000a_Name.ReadByte();
	}
}
