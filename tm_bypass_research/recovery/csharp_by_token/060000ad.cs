// Recovered from method token 0x060000ad; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00ad_Name()
{
	try
	{
		ExecuteSshCommand("snappy -f / -r `snappy -f / -l | sed -n 2p` -t orig-fs");
	}
	catch (Exception)
	{
	}
}
