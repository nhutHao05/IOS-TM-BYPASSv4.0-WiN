// Recovered from method token 0x06000085; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0085_Name()
{
	string[] array = new string[8];
	array[0] = "mkdir -p ";
	array[1] = Recovered_04_004b_Name;
	array[2] = " && mkdir -p ";
	array[3] = Recovered_04_0049_Name;
	array[4] = " && mkdir -p ";
	array[5] = Recovered_04_0048_Name;
	array[6] = " && mkdir -p ";
	array[7] = Recovered_04_004c_Name;
	ExecuteSshCommand(string.Concat(array));
}
