// Recovered from method token 0x06000087; analyst names; not the original source.
using System.IO;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0087_Name()
{
	Recovered_06_0091_Name(Recovered_04_004d_Name, Recovered_04_0053_Name + "activation_record.plist");
	Recovered_06_0091_Name(Recovered_04_004e_Name, Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist");
	Recovered_06_0091_Name(Recovered_04_0050_Name, Recovered_04_0053_Name + "data_ark.plist");
	Recovered_04_0043_Name.Download("/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem", new FileInfo(Recovered_04_0053_Name + "/RaptorActivation.pem"));
}
