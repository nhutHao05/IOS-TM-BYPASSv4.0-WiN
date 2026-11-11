// Recovered from method token 0x06000092; analyst names; not the original source.
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void EnsureDevicePairing()
{
	while (!Recovered_06_0093_Name("pair"))
	{
		MessageBox.Show("Unlock Your iDevice and press Trust", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
	}
}
