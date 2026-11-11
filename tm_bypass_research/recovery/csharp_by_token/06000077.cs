// Recovered from method token 0x06000077; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0077_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		UpdateProgress(10);
		ConnectSshOverUsb();
		UpdateProgress(20);
		MountDeviceFilesystem();
		UpdateProgress(30);
		string text = Recovered_06_0083_Name();
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/lib.tar.gz", "/usr/libexec/lib.tar.gz");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/jlutil", "/usr/libexec/jlutil");
		Recovered_06_00b3_Name(Recovered_04_0054_Name + "/utils/mv", "/usr/libexec/imd");
		UpdateProgress(40);
		ExecuteSshCommand("chmod 777 /usr/libexec/lib.tar.gz");
		ExecuteSshCommand("chmod 777 /usr/libexec/jlutil");
		ExecuteSshCommand("chmod 777 /usr/libexec/imd");
		ExecuteSshCommand("cd /usr/libexec && tar -xf /usr/libexec/lib.tar.gz");
		UpdateProgress(50);
		Recovered_06_0078_Name();
		UpdateProgress(60);
		Recovered_06_007a_Name();
		UpdateProgress(70);
		UpdateProgress(100);
		string[] array = new string[6];
		array[0] = "Serial: ";
		array[1] = text;
		array[2] = "\n\n Account: ";
		array[3] = Recovered_04_005c_Name;
		array[4] = "\n Phone Number: ";
		array[5] = Recovered_04_005b_Name;
		MessageBox.Show(string.Concat(array), "Apple ID & Phone Number", MessageBoxButtons.OKCancel, MessageBoxIcon.Asterisk);
	}
	catch (Exception)
	{
		MessageBox.Show("Can Not Read Informations from iDevice", "Informations Not Found!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
}
