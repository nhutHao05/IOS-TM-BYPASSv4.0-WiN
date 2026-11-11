// Recovered from method token 0x0600000a; analyst names; not the original source.
using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Text;

internal static - Recovered_06_000a_Name<->(int id)
{
	if (Assembly.GetExecutingAssembly().Equals(Assembly.GetCallingAssembly()))
	{
		id = (id * -1227899163) ^ 0x166BC73B;
		int num = id >>> 30;
		id = (id & 0x3FFFFFFF) << 2;
		switch (num)
		{
		case 1:
		{
			int count = Recovered_04_0001_Name[id] | (Recovered_04_0001_Name[id + 1] << 8) | (Recovered_04_0001_Name[id + 2] << 16) | (Recovered_04_0001_Name[id + 3] << 24);
			return (-)(object)string.Intern(Encoding.UTF8.GetString(Recovered_04_0001_Name, id + 4, count));
		}
		case 2:
		{
			-[] array2 = new -[1];
			Buffer.BlockCopy(Recovered_04_0001_Name, id, array2, 0, System.Runtime.CompilerServices.Unsafe.SizeOf<->());
			return array2[0];
		}
		case 3:
		{
			int num2 = Recovered_04_0001_Name[id] | (Recovered_04_0001_Name[id + 1] << 8) | (Recovered_04_0001_Name[id + 2] << 16) | (Recovered_04_0001_Name[id + 3] << 24);
			int length = Recovered_04_0001_Name[id + 4] | (Recovered_04_0001_Name[id + 5] << 8) | (Recovered_04_0001_Name[id + 6] << 16) | (Recovered_04_0001_Name[id + 7] << 24);
			Array array = Array.CreateInstance(typeof(-).GetElementType(), length);
			Buffer.BlockCopy(Recovered_04_0001_Name, id + 8, array, 0, num2 - 4);
			return (-)(object)array;
		}
		default:
			return default(-);
		}
	}
	return default(-);
}
