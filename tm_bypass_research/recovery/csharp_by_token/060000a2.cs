// Recovered from method token 0x060000a2; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void MountDeviceFilesystem()
{
	ExecuteSshCommand("mount -o rw,union,update /");
	ExecuteSshCommand("echo \"\" >> /.mount_rw");
}
