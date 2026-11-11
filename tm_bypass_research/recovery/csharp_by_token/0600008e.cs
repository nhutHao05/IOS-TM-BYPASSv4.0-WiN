// Recovered from method token 0x0600008e; analyst names; not the original source.
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_008e_Name()
{
	try
	{
		List<string> list = null;
		string result = ExecuteSshCommand("ls /System/Library/PrivateFrameworks/SystemStatusServer.framework").Result;
		char[] array = new char[1];
		array[0] = '\n';
		list = result.Split(array).ToList();
		foreach (string item in list)
		{
			if (item.Contains("lproj"))
			{
				UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0018_Name, "/System/Library/PrivateFrameworks/SystemStatusServer.framework/" + item + "/SystemStatusServer.strings");
			}
		}
		ExecuteSshCommand("chmod 755 /System/Library/PrivateFrameworks/SystemStatusServer.framework");
	}
	catch
	{
	}
}
