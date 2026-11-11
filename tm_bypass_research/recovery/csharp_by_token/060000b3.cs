// Recovered from method token 0x060000b3; analyst names; not the original source.
using System.IO;

public void Recovered_06_00b3_Name(string P_0, string P_1)
{
	Stream stream = File.Open(P_0, FileMode.Open);
	Stream stream2 = stream;
	Recovered_04_0043_Name.Upload(stream2, P_1);
	stream2.Close();
}
