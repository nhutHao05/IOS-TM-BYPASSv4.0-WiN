// Recovered from method token 0x06000005; analyst names; not the original source.
using System;
using System.Reflection;
using System.Runtime.InteropServices;

internal unsafe static void Recovered_06_0005_Name()
{
	Module module = typeof(global::<Module>).Module;
	byte* ptr = (byte*)(void*)Marshal.GetHINSTANCE(module);
	byte* ptr2 = ptr + 60;
	ptr2 = ptr + (uint)(*(int*)ptr2);
	ptr2 += 6;
	ushort num = *(ushort*)ptr2;
	ptr2 += 14;
	ushort num2 = *(ushort*)ptr2;
	ptr2 = ptr2 + 4 + (int)num2;
	byte* ptr3 = stackalloc byte[11];
	uint lpflOldProtect;
	if (module.FullyQualifiedName[0] != '<')
	{
		byte* ptr4 = ptr + (uint)(*((int*)ptr2 - 4));
		if (*((uint*)ptr2 - 30) != 0)
		{
			byte* ptr5 = ptr + (uint)(*((int*)ptr2 - 30));
			byte* ptr6 = ptr + (uint)(*(int*)ptr5);
			byte* ptr7 = ptr + (uint)((int*)ptr5)[3];
			byte* ptr8 = ptr + (uint)(*(int*)ptr6) + 2;
			Recovered_06_0004_Name(ptr7, 11, 64u, out lpflOldProtect);
			*(int*)ptr3 = 1818522734;
			((int*)ptr3)[1] = 1818504812;
			((short*)ptr3)[4] = 108;
			ptr3[10] = 0;
			for (int i = 0; i < 11; i++)
			{
				ptr7[i] = ptr3[i];
			}
			Recovered_06_0004_Name(ptr8, 11, 64u, out lpflOldProtect);
			*(int*)ptr3 = 1866691662;
			((int*)ptr3)[1] = 1852404846;
			((short*)ptr3)[4] = 25973;
			ptr3[10] = 0;
			for (int j = 0; j < 11; j++)
			{
				ptr8[j] = ptr3[j];
			}
		}
		for (int k = 0; k < num; k++)
		{
			Recovered_06_0004_Name(ptr2, 8, 64u, out lpflOldProtect);
			Marshal.Copy(new byte[8], 0, (IntPtr)ptr2, 8);
			ptr2 += 40;
		}
		Recovered_06_0004_Name(ptr4, 72, 64u, out lpflOldProtect);
		byte* ptr9 = ptr + (uint)((int*)ptr4)[2];
		*(int*)ptr4 = 0;
		((int*)ptr4)[1] = 0;
		((int*)ptr4)[2] = 0;
		((int*)ptr4)[3] = 0;
		Recovered_06_0004_Name(ptr9, 4, 64u, out lpflOldProtect);
		*(int*)ptr9 = 0;
		ptr9 += 12;
		ptr9 += (uint)(*(int*)ptr9);
		ptr9 = (byte*)(((long)ptr9 + 7L) & -4);
		ptr9 += 2;
		ushort num3 = *ptr9;
		ptr9 += 2;
		for (int l = 0; l < num3; l++)
		{
			Recovered_06_0004_Name(ptr9, 8, 64u, out lpflOldProtect);
			ptr9 += 4;
			ptr9 += 4;
			for (int m = 0; m < 8; m++)
			{
				Recovered_06_0004_Name(ptr9, 4, 64u, out lpflOldProtect);
				*ptr9 = 0;
				ptr9++;
				if (*ptr9 == 0)
				{
					ptr9 += 3;
					break;
				}
				*ptr9 = 0;
				ptr9++;
				if (*ptr9 == 0)
				{
					ptr9 += 2;
					break;
				}
				*ptr9 = 0;
				ptr9++;
				if (*ptr9 == 0)
				{
					ptr9++;
					break;
				}
				*ptr9 = 0;
				ptr9++;
			}
		}
		return;
	}
	uint num4 = *((uint*)ptr2 - 4);
	uint num5 = *((uint*)ptr2 - 30);
	uint[] array = new uint[num];
	uint[] array2 = new uint[num];
	uint[] array3 = new uint[num];
	for (int n = 0; n < num; n++)
	{
		Recovered_06_0004_Name(ptr2, 8, 64u, out lpflOldProtect);
		Marshal.Copy(new byte[8], 0, (IntPtr)ptr2, 8);
		array[n] = ((uint*)ptr2)[3];
		array2[n] = ((uint*)ptr2)[2];
		array3[n] = ((uint*)ptr2)[5];
		ptr2 += 40;
	}
	if (num5 != 0)
	{
		for (int num6 = 0; num6 < num; num6++)
		{
			if (array[num6] <= num5 && num5 < array[num6] + array2[num6])
			{
				num5 = num5 - array[num6] + array3[num6];
				break;
			}
		}
		byte* ptr10 = ptr + num5;
		uint num7 = *(uint*)ptr10;
		for (int num8 = 0; num8 < num; num8++)
		{
			if (array[num8] <= num7 && num7 < array[num8] + array2[num8])
			{
				num7 = num7 - array[num8] + array3[num8];
				break;
			}
		}
		byte* ptr11 = ptr + num7;
		uint num9 = ((uint*)ptr10)[3];
		for (int num10 = 0; num10 < num; num10++)
		{
			if (array[num10] <= num9 && num9 < array[num10] + array2[num10])
			{
				num9 = num9 - array[num10] + array3[num10];
				break;
			}
		}
		uint num11 = *(uint*)ptr11 + 2;
		for (int num12 = 0; num12 < num; num12++)
		{
			if (array[num12] <= num11 && num11 < array[num12] + array2[num12])
			{
				num11 = num11 - array[num12] + array3[num12];
				break;
			}
		}
		Recovered_06_0004_Name(ptr + num9, 11, 64u, out lpflOldProtect);
		*(int*)ptr3 = 1818522734;
		((int*)ptr3)[1] = 1818504812;
		((short*)ptr3)[4] = 108;
		ptr3[10] = 0;
		for (int num13 = 0; num13 < 11; num13++)
		{
			(ptr + num9)[num13] = ptr3[num13];
		}
		Recovered_06_0004_Name(ptr + num11, 11, 64u, out lpflOldProtect);
		*(int*)ptr3 = 1866691662;
		((int*)ptr3)[1] = 1852404846;
		((short*)ptr3)[4] = 25973;
		ptr3[10] = 0;
		for (int num14 = 0; num14 < 11; num14++)
		{
			(ptr + num11)[num14] = ptr3[num14];
		}
	}
	for (int num15 = 0; num15 < num; num15++)
	{
		if (array[num15] <= num4 && num4 < array[num15] + array2[num15])
		{
			num4 = num4 - array[num15] + array3[num15];
			break;
		}
	}
	byte* ptr12 = ptr + num4;
	Recovered_06_0004_Name(ptr12, 72, 64u, out lpflOldProtect);
	uint num16 = ((uint*)ptr12)[2];
	for (int num17 = 0; num17 < num; num17++)
	{
		if (array[num17] <= num16 && num16 < array[num17] + array2[num17])
		{
			num16 = num16 - array[num17] + array3[num17];
			break;
		}
	}
	*(int*)ptr12 = 0;
	((int*)ptr12)[1] = 0;
	((int*)ptr12)[2] = 0;
	((int*)ptr12)[3] = 0;
	byte* ptr13 = ptr + num16;
	Recovered_06_0004_Name(ptr13, 4, 64u, out lpflOldProtect);
	*(int*)ptr13 = 0;
	ptr13 += 12;
	ptr13 += (uint)(*(int*)ptr13);
	ptr13 = (byte*)(((long)ptr13 + 7L) & -4);
	ptr13 += 2;
	ushort num18 = *ptr13;
	ptr13 += 2;
	for (int num19 = 0; num19 < num18; num19++)
	{
		Recovered_06_0004_Name(ptr13, 8, 64u, out lpflOldProtect);
		ptr13 += 4;
		ptr13 += 4;
		for (int num20 = 0; num20 < 8; num20++)
		{
			Recovered_06_0004_Name(ptr13, 4, 64u, out lpflOldProtect);
			*ptr13 = 0;
			ptr13++;
			if (*ptr13 == 0)
			{
				ptr13 += 3;
				break;
			}
			*ptr13 = 0;
			ptr13++;
			if (*ptr13 == 0)
			{
				ptr13 += 2;
				break;
			}
			*ptr13 = 0;
			ptr13++;
			if (*ptr13 == 0)
			{
				ptr13++;
				break;
			}
			*ptr13 = 0;
			ptr13++;
		}
	}
}
