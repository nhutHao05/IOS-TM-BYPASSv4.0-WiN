// Recovered from method token 0x060000ab; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
private void Recovered_06_00ab_Name()
{
	Recovered_06_00b3_Name(Recovered_04_0054_Name + "plutil_iphone", "/usr/bin/plutil");
	ExecuteSshCommand("chflags -R nouchg " + Recovered_04_0050_Name);
	ExecuteSshCommand("chflags -R nouchg " + Recovered_04_004f_Name);
	ExecuteSshCommand("chmod 755 /usr/bin/plutil");
	UpdateProgress(2);
	ExecuteSshCommand("plutil -key ActivationState -remove " + Recovered_04_0050_Name);
	ExecuteSshCommand("plutil -key -ActivationState -remove " + Recovered_04_0050_Name);
	ExecuteSshCommand("plutil -key -UCRTOOBForbidden -remove " + Recovered_04_0050_Name);
	ExecuteSshCommand("plutil -key ActivationState -string Activated " + Recovered_04_0050_Name);
	ExecuteSshCommand("chflags uchg " + Recovered_04_0050_Name);
	ExecuteSshCommand("cp " + Recovered_04_0050_Name + " " + Recovered_04_004f_Name);
	ExecuteSshCommand("chflags uchg " + Recovered_04_004f_Name);
}
