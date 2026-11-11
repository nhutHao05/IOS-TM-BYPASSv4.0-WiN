// Recovered from method token 0x06000107; analyst names; not the original source.
using System;
using System.Text;

public static string Recovered_06_0107_Name(string P_0)
{
	byte[] bytes = Encoding.UTF8.GetBytes(P_0);
	return Convert.ToBase64String(bytes);
}
