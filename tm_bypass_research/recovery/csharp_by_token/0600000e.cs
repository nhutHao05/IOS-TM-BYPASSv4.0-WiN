// Recovered from method token 0x0600000e; analyst names; not the original source.
using System;
using System.Reflection;

internal static Assembly Recovered_06_000e_Name(object sender, ResolveEventArgs args)
{
	if (Recovered_04_0003_Name.FullName == args.Name)
	{
		return Recovered_04_0003_Name;
	}
	return null;
}
