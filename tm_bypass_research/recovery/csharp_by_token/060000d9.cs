// Recovered from method token 0x060000d9; analyst names; not the original source.
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00d9_Name()
{
	try
	{
		Recovered_04_00a4_Name.Visible = true;
		Recovered_04_009e_Name = 44;
		Recovered_06_00f3_Name(Recovered_04_009d_Name, Recovered_04_009e_Name);
		Recovered_06_00f9_Name("127.0.0.1", Recovered_04_009d_Name, "alpine");
		DeviceStateRecovered.DeviceSerialNumber = Recovered_06_0124_Name();
		Recovered_04_00aa_Name.Text = DeviceStateRecovered.DeviceSerialNumber;
		Recovered_06_00de_Name();
	}
	catch
	{
		if (Interlocked.Exchange(ref Recovered_04_0088_Name, 1) == 0)
		{
			if (!Recovered_06_00e5_Name())
			{
				Recovered_06_00da_Name();
			}
			else
			{
				Recovered_06_00db_Name();
			}
		}
	}
}
