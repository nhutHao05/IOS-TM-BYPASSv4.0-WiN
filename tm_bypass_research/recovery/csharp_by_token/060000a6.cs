// Recovered from method token 0x060000a6; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00a6_Name()
{
	ExecuteSshCommand("rm " + Recovered_04_0056_Name);
	string[] array = new string[6];
	array[0] = "mkdir ";
	array[1] = Recovered_04_0056_Name;
	array[2] = " && chown -R mobile:mobile ";
	array[3] = Recovered_04_0056_Name;
	array[4] = " && chmod -R 755 ";
	array[5] = Recovered_04_0056_Name;
	ExecuteSshCommand(string.Concat(array));
	UpdateProgress(58);
	Recovered_06_00ac_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", 2);
	ExecuteSshCommand("chflags nouchg " + Recovered_04_004e_Name + " && mkdir -p " + Recovered_04_004b_Name);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", Recovered_04_0056_Name + "/Route_CommCe.plist");
	UpdateProgress(59);
	ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/Route_CommCe.plist " + Recovered_04_004e_Name);
	string[] array2 = new string[6];
	array2[0] = "chown root:mobile ";
	array2[1] = Recovered_04_004e_Name;
	array2[2] = " && chmod 555 ";
	array2[3] = Recovered_04_004e_Name;
	array2[4] = " && chflags uchg ";
	array2[5] = Recovered_04_004e_Name;
	ExecuteSshCommand(string.Concat(array2));
	UpdateProgress(60);
	ExecuteSshCommand("mkdir -p " + Recovered_04_0049_Name + " && chmod 775 " + Recovered_04_0049_Name);
	Recovered_06_00ac_Name(Recovered_04_0053_Name + "activation_record.plist", 2);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "activation_record.plist", Recovered_04_0056_Name + "/Route_ActRec.plist");
	string[] array3 = new string[6];
	array3[0] = "mv -f ";
	array3[1] = Recovered_04_0056_Name;
	array3[2] = "/Route_ActRec.plist ";
	array3[3] = Recovered_04_004d_Name;
	array3[4] = " && chflags uchg ";
	array3[5] = Recovered_04_004d_Name;
	ExecuteSshCommand(string.Concat(array3));
	UpdateProgress(62);
	Recovered_06_00ac_Name(Recovered_04_0053_Name + "data_ark.plist", 2);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "data_ark.plist", Recovered_04_0056_Name + "/Route_DataArk.plist");
	UpdateProgress(64);
	string[] array4 = new string[12];
	array4[0] = "cp -f ";
	array4[1] = Recovered_04_0056_Name;
	array4[2] = "/Route_DataArk.plist ";
	array4[3] = Recovered_04_0050_Name;
	array4[4] = " && mv -f ";
	array4[5] = Recovered_04_0056_Name;
	array4[6] = "/Route_DataArk.plist ";
	array4[7] = Recovered_04_004f_Name;
	array4[8] = " && chflags uchg ";
	array4[9] = Recovered_04_0050_Name;
	array4[10] = " && chflags uchg ";
	array4[11] = Recovered_04_004f_Name;
	ExecuteSshCommand(string.Concat(array4));
}
