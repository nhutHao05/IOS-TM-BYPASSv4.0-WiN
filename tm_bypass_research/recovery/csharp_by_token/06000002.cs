// Recovered from method token 0x06000002; analyst names; not the original source.
using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
private static void Recovered_06_0002_Name()
{
	Type typeFromHandle = typeof(Environment);
	Type[] array = new Type[1];
	array[0] = typeof(string);
	MethodInfo method = typeFromHandle.GetMethod("GetEnvironmentVariable", array);
	if ((object)method != null)
	{
		object[] array2 = new object[1];
		array2[0] = "COR_ENABLE_PROFILING";
		if ("1".Equals(method.Invoke(null, array2)))
		{
			Environment.FailFast(null);
		}
	}
	Thread thread = new Thread(Recovered_06_0003_Name);
	thread.IsBackground = true;
	thread.Start(null);
}
