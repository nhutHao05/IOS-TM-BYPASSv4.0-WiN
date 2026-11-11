// Recovered from method token 0x060000dc; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00dc_Name(string P_0)
{
	char[] array = new char[1];
	array[0] = '\n';
	string[] array2 = P_0.Split(array);
	string[] array3 = array2;
	for (int i = 0; i < array3.Length; i++)
	{
		string text = array3[i].Replace("\r", "");
		if (text.StartsWith("UniqueDeviceID: "))
		{
			string recovered_04_0093_Name = text.Replace("UniqueDeviceID: ", "");
			Recovered_04_0093_Name = recovered_04_0093_Name;
		}
		else if (text.StartsWith("ProductVersion: "))
		{
			string recovered_04_0096_Name = text.Replace("ProductVersion: ", "");
			Recovered_04_0096_Name = recovered_04_0096_Name;
		}
		else if (text.StartsWith("ProductType: "))
		{
			string recovered_04_0098_Name = text.Replace("ProductType: ", "");
			Recovered_04_0098_Name = recovered_04_0098_Name;
			DeviceStateRecovered.DeviceProductType = Recovered_04_0098_Name;
		}
	}
}
