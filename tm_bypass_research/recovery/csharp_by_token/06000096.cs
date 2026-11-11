// Recovered from method token 0x06000096; analyst names; not the original source.
using System.Runtime.CompilerServices;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0096_Name()
{
	SshCommand sshCommand = ExecuteSshCommand("find /private/var/containers/Data/System/ -iname 'internal'");
	Recovered_04_0047_Name = sshCommand.Result.Replace("Library/internal", "").Replace("\n", "").Replace("//", "/");
	Recovered_04_0048_Name = Recovered_04_0047_Name + "Library/internal/";
	Recovered_04_0049_Name = Recovered_04_0047_Name + "Library/activation_records/";
	Recovered_04_004a_Name = "/var/mobile/Library/Preferences/";
	Recovered_04_004b_Name = "/var/wireless/Library/Preferences/";
	Recovered_04_004c_Name = "/var/root/Library/Lockdown/";
	Recovered_04_0050_Name = Recovered_04_0048_Name + "data_ark.plist";
	Recovered_04_004d_Name = Recovered_04_0049_Name + "activation_record.plist";
	Recovered_04_0051_Name = Recovered_04_004a_Name + "com.apple.purplebuddy.plist";
	Recovered_04_004e_Name = Recovered_04_004b_Name + "com.apple.commcenter.device_specific_nobackup.plist";
	Recovered_04_004f_Name = Recovered_04_004c_Name + "data_ark.plist";
}
