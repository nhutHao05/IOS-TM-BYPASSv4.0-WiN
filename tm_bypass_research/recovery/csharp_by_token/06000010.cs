// Recovered from method token 0x06000010; analyst names; not the original source.
using System;
using System.Reflection;
using System.Runtime.InteropServices;

internal unsafe static void Recovered_06_0010_Name()
{
	Module module = typeof(global::<Module>).Module;
	string fullyQualifiedName = module.FullyQualifiedName;
	bool flag = fullyQualifiedName.Length > 0 && fullyQualifiedName[0] == '<';
	byte* ptr = (byte*)(void*)Marshal.GetHINSTANCE(module);
	byte* num = ptr + (uint)((int*)ptr)[15];
	ushort num2 = ((ushort*)num)[3];
	ushort num3 = ((ushort*)num)[10];
	uint* ptr2 = null;
	uint num4 = 0u;
	uint* ptr3 = (uint*)(num + 24 + (int)num3);
	uint num5 = 65208925u;
	uint num6 = 789691915u;
	uint num7 = 2264432977u;
	uint num8 = 1160778982u;
	for (int i = 0; i < num2; i++)
	{
		switch (*(ptr3++) * *(ptr3++))
		{
		case 2431012394u:
			ptr2 = (uint*)(ptr + (flag ? ptr3[3] : ptr3[1]));
			num4 = (flag ? ptr3[2] : (*ptr3)) >> 2;
			break;
		default:
		{
			uint* ptr4 = (uint*)(ptr + (flag ? ptr3[3] : ptr3[1]));
			uint num9 = ptr3[2] >> 2;
			for (uint num10 = 0u; num10 < num9; num10++)
			{
				uint num11 = (num5 ^ *(ptr4++)) + num6 + num7 * num8;
				num5 = num6;
				num6 = num7;
				num6 = num8;
				num8 = num11;
			}
			break;
		}
		case 0u:
			break;
		}
		ptr3 += 8;
	}
	uint[] array = new uint[16];
	uint[] array2 = new uint[16];
	for (int j = 0; j < 16; j++)
	{
		array[j] = num8;
		array2[j] = num6;
		num5 = (num6 >> 5) | (num6 << 27);
		num6 = (num7 >> 3) | (num7 << 29);
		num7 = (num8 >> 7) | (num8 << 25);
		num8 = (num5 >> 11) | (num5 << 21);
	}
	array[0] = array[0] ^ array2[0];
	array[1] = array[1] * array2[1];
	array[2] = array[2] + array2[2];
	array[3] = array[3] ^ array2[3];
	array[4] = array[4] * array2[4];
	array[5] = array[5] + array2[5];
	array[6] = array[6] ^ array2[6];
	array[7] = array[7] * array2[7];
	array[8] = array[8] + array2[8];
	array[9] = array[9] ^ array2[9];
	array[10] = array[10] * array2[10];
	array[11] = array[11] + array2[11];
	array[12] = array[12] ^ array2[12];
	array[13] = array[13] * array2[13];
	array[14] = array[14] + array2[14];
	array[15] = array[15] ^ array2[15];
	uint lpflOldProtect = 64u;
	Recovered_06_000f_Name((IntPtr)ptr2, num4 << 2, lpflOldProtect, out lpflOldProtect);
	if (lpflOldProtect != 64)
	{
		uint num12 = 0u;
		for (uint num13 = 0u; num13 < num4; num13++)
		{
			*ptr2 ^= array[num12 & 0xF];
			array[num12 & 0xF] = (array[num12 & 0xF] ^ *(ptr2++)) + 1035675673;
			num12++;
		}
	}
}
