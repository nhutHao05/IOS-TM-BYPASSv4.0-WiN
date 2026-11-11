// Recovered from method token 0x06000020; analyst names; not the original source.
internal void Recovered_06_0020_Name(int pb)
{
	uint num = (uint)(1 << pb);
	Recovered_04_0011_Name.Recovered_06_0025_Name(num);
	Recovered_04_0017_Name.Recovered_06_0025_Name(num);
	Recovered_04_001c_Name = num - 1;
}
