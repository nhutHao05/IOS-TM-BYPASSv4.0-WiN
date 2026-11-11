// Recovered from method token 0x06000036; analyst names; not the original source.
internal void Recovered_06_0036_Name()
{
	uint num = Recovered_04_0029_Name - Recovered_04_002b_Name;
	if (num != 0)
	{
		Recovered_04_002a_Name.Write(Recovered_04_0028_Name, (int)Recovered_04_002b_Name, (int)num);
		if (Recovered_04_0029_Name >= Recovered_04_002c_Name)
		{
			Recovered_04_0029_Name = 0u;
		}
		Recovered_04_002b_Name = Recovered_04_0029_Name;
	}
}
