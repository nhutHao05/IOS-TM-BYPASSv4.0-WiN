// Recovered from method token 0x06000082; analyst names; not the original source.
using System;
using System.Text;

public string Recovered_06_0082_Name(string P_0, Encoding P_1)
{
	return string.IsNullOrEmpty(P_0) ? P_0 : Convert.ToBase64String(P_1.GetBytes(P_0));
}
