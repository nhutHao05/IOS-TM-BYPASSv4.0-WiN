// Recovered from method token 0x0600008f; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_008f_Name()
{
	UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000e_Name, "/usr/bin/ldrestart");
	if (!Recovered_04_0042_Name.IsConnected)
	{
		Recovered_04_0042_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
		Recovered_04_0042_Name.Connect();
	}
	try
	{
		Recovered_04_0042_Name.CreateCommand("chmod 755 /usr/bin/ldrestart && /usr/bin/ldrestart").Execute();
		Recovered_04_0042_Name.Disconnect();
	}
	catch (Exception)
	{
		if (File.Exists("%USERPROFILE%\\.ssh\\known_hosts"))
		{
			File.Delete("%USERPROFILE%\\.ssh\\known_hosts");
		}
	}
	Thread.Sleep(11000);
	ConnectSshOverUsb();
	Thread.Sleep(1000);
	MountDeviceFilesystem();
}
