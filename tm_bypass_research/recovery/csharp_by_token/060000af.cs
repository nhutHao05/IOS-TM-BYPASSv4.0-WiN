// Recovered from method token 0x060000af; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00af_Name()
{
	ExecuteSshCommand("launchctl unload -F /System/Library/LaunchDaemons/* && launchctl load -w -F /System/Library/LaunchDaemons/*");
}
