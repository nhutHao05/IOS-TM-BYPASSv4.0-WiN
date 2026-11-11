// Recovered from method token 0x06000022; analyst names; not the original source.
using System.IO;

internal void Recovered_06_0022_Name(Stream inStream, Stream outStream, long inSize, long outSize)
{
	Recovered_06_0021_Name(inStream, outStream);
	Recovered_02_000a_TypeName recovered_02_000a_TypeName = default(Recovered_02_000a_TypeName);
	recovered_02_000a_TypeName.Recovered_06_003b_Name();
	uint num = 0u;
	uint num2 = 0u;
	uint num3 = 0u;
	uint num4 = 0u;
	ulong num5 = 0uL;
	if (num5 < (ulong)outSize)
	{
		Recovered_04_000b_Name[recovered_02_000a_TypeName.Recovered_04_002d_Name << 4].Recovered_06_0012_Name(Recovered_04_0016_Name);
		recovered_02_000a_TypeName.Recovered_06_003c_Name();
		byte b = Recovered_04_0012_Name.Recovered_06_002c_Name(Recovered_04_0016_Name, 0u, 0);
		Recovered_04_0013_Name.Recovered_06_0038_Name(b);
		num5++;
	}
	while (num5 < (ulong)outSize)
	{
		uint num6 = (uint)(int)num5 & Recovered_04_001c_Name;
		if (Recovered_04_000b_Name[(recovered_02_000a_TypeName.Recovered_04_002d_Name << 4) + num6].Recovered_06_0012_Name(Recovered_04_0016_Name) == 0)
		{
			byte prevByte = Recovered_04_0013_Name.Recovered_06_0039_Name(0u);
			byte b2 = (recovered_02_000a_TypeName.Recovered_06_0040_Name() ? Recovered_04_0012_Name.Recovered_06_002c_Name(Recovered_04_0016_Name, (uint)num5, prevByte) : Recovered_04_0012_Name.Recovered_06_002d_Name(Recovered_04_0016_Name, (uint)num5, prevByte, Recovered_04_0013_Name.Recovered_06_0039_Name(num)));
			Recovered_04_0013_Name.Recovered_06_0038_Name(b2);
			recovered_02_000a_TypeName.Recovered_06_003c_Name();
			num5++;
			continue;
		}
		uint num8;
		if (Recovered_04_000d_Name[recovered_02_000a_TypeName.Recovered_04_002d_Name].Recovered_06_0012_Name(Recovered_04_0016_Name) == 1)
		{
			if (Recovered_04_000e_Name[recovered_02_000a_TypeName.Recovered_04_002d_Name].Recovered_06_0012_Name(Recovered_04_0016_Name) == 0)
			{
				if (Recovered_04_000c_Name[(recovered_02_000a_TypeName.Recovered_04_002d_Name << 4) + num6].Recovered_06_0012_Name(Recovered_04_0016_Name) == 0)
				{
					recovered_02_000a_TypeName.Recovered_06_003f_Name();
					Recovered_04_0013_Name.Recovered_06_0038_Name(Recovered_04_0013_Name.Recovered_06_0039_Name(num));
					num5++;
					continue;
				}
			}
			else
			{
				uint num7;
				if (Recovered_04_000f_Name[recovered_02_000a_TypeName.Recovered_04_002d_Name].Recovered_06_0012_Name(Recovered_04_0016_Name) == 0)
				{
					num7 = num2;
				}
				else
				{
					if (Recovered_04_0010_Name[recovered_02_000a_TypeName.Recovered_04_002d_Name].Recovered_06_0012_Name(Recovered_04_0016_Name) == 0)
					{
						num7 = num3;
					}
					else
					{
						num7 = num4;
						num4 = num3;
					}
					num3 = num2;
				}
				num2 = num;
				num = num7;
			}
			num8 = Recovered_04_0017_Name.Recovered_06_0027_Name(Recovered_04_0016_Name, num6) + 2;
			recovered_02_000a_TypeName.Recovered_06_003e_Name();
		}
		else
		{
			num4 = num3;
			num3 = num2;
			num2 = num;
			num8 = 2 + Recovered_04_0011_Name.Recovered_06_0027_Name(Recovered_04_0016_Name, num6);
			recovered_02_000a_TypeName.Recovered_06_003d_Name();
			uint num9 = Recovered_04_0015_Name[Recovered_06_0024_Name(num8)].Recovered_06_0015_Name(Recovered_04_0016_Name);
			if (num9 >= 4)
			{
				int num10 = (int)((num9 >> 1) - 1);
				num = (2 | (num9 & 1)) << num10;
				if (num9 < 14)
				{
					num += Recovered_02_0003_TypeName.Recovered_06_0017_Name(Recovered_04_0014_Name, num - num9 - 1, Recovered_04_0016_Name, num10);
				}
				else
				{
					num += Recovered_04_0016_Name.Recovered_06_001b_Name(num10 - 4) << 4;
					num += Recovered_04_001b_Name.Recovered_06_0016_Name(Recovered_04_0016_Name);
				}
			}
			else
			{
				num = num9;
			}
		}
		if ((num >= num5 || num >= Recovered_04_001a_Name) && num == uint.MaxValue)
		{
			break;
		}
		Recovered_04_0013_Name.Recovered_06_0037_Name(num, num8);
		num5 += num8;
	}
	Recovered_04_0013_Name.Recovered_06_0036_Name();
	Recovered_04_0013_Name.Recovered_06_0035_Name();
	Recovered_04_0016_Name.Recovered_06_0019_Name();
}
