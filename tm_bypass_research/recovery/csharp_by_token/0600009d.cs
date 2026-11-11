// Recovered from method token 0x0600009d; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_009d_Name()
{
	Recovered_06_009c_Name(Recovered_04_0068_Name, "/uikit.tar");
	ExecuteSshCommand("cd / && tar -xvf uikit.tar && chmod 755 /usr/bin/*");
	Recovered_06_009c_Name(Recovered_04_0069_Name, "/boot.tar.lzma");
	Recovered_06_009c_Name(Recovered_04_006a_Name, "/sbin/lzma");
	ExecuteSshCommand("chmod 777 /sbin/lzma");
	ExecuteSshCommand("lzma -d -v /boot.tar.lzma");
	ExecuteSshCommand("tar -C / -xvf /boot.tar && rm -r /boot.tar");
	ExecuteSshCommand("chmod +x /usr/libexec/substrate && /usr/libexec/substrate");
	ExecuteSshCommand("chmod +x /usr/libexec/substrated && /usr/libexec/substrated");
	ExecuteSshCommand("killall - 9 backboardd");
}
