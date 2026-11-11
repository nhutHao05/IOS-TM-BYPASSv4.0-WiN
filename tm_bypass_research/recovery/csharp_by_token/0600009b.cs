// Recovered from method token 0x0600009b; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_009b_Name()
{
	ExecuteSshCommand("chflags nouchg " + Recovered_04_004d_Name + " && rm " + Recovered_04_004d_Name);
	string[] array = new string[16];
	array[0] = "chflags nouchg ";
	array[1] = Recovered_04_004e_Name;
	array[2] = " && rm ";
	array[3] = Recovered_04_004e_Name;
	array[4] = " && chflags nouchg ";
	array[5] = Recovered_04_004f_Name;
	array[6] = " && rm ";
	array[7] = Recovered_04_004f_Name;
	array[8] = " && chflags nouchg ";
	array[9] = Recovered_04_0050_Name;
	array[10] = " && rm ";
	array[11] = Recovered_04_0050_Name;
	array[12] = " && chflags nouchg ";
	array[13] = Recovered_04_0051_Name;
	array[14] = " && rm ";
	array[15] = Recovered_04_0051_Name;
	ExecuteSshCommand(string.Concat(array));
}
