// Recovered from method token 0x06000006; analyst names; not the original source.
using System;
using System.IO;

internal static byte[] Recovered_06_0006_Name(byte[] data)
{
	MemoryStream memoryStream = new MemoryStream(data);
	Recovered_02_0005_TypeName recovered_02_0005_TypeName = new Recovered_02_0005_TypeName();
	byte[] array = new byte[5];
	for (int i = 0; i < 5; i += memoryStream.Read(array, i, 5 - i))
	{
	}
	recovered_02_0005_TypeName.Recovered_06_0023_Name(array);
	for (int i = 0; i < 4; i += memoryStream.Read(array, i, 4 - i))
	{
	}
	if (!BitConverter.IsLittleEndian)
	{
		Array.Reverse(array, 0, 4);
	}
	int num = BitConverter.ToInt32(array, 0);
	byte[] array2 = new byte[num];
	MemoryStream outStream = new MemoryStream(array2, writable: true);
	long inSize = memoryStream.Length - 5 - 4;
	recovered_02_0005_TypeName.Recovered_06_0022_Name(memoryStream, outStream, inSize, num);
	return array2;
}
