// Recovered from method token 0x060000c9; analyst names; not the original source.
using System.Net;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public bool Recovered_06_00c9_Name(string P_0)
{
	bool result = true;
	WebRequest webRequest = WebRequest.Create(P_0);
	webRequest.Timeout = 1200;
	webRequest.Method = "HEAD";
	try
	{
		webRequest.GetResponse();
	}
	catch
	{
		result = false;
	}
	return result;
}
