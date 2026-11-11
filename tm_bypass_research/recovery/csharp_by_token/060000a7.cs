// Recovered from method token 0x060000a7; analyst names; not the original source.
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00a7_Name()
{
	ExecuteSshCommand("rm -rf " + Recovered_04_0056_Name);
	ExecuteSshCommand("mkdir -p " + Recovered_04_0056_Name + " && chmod -R 755 " + Recovered_04_0056_Name);
	UpdateProgress(58);
	ExecuteSshCommand("mkdir -p " + Recovered_04_004b_Name + " && chmod 775 " + Recovered_04_004b_Name);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist", Recovered_04_0056_Name + "/Route_CommCe.plist");
	string[] array = new string[6];
	array[0] = "mv -f ";
	array[1] = Recovered_04_0056_Name;
	array[2] = "/Route_CommCe.plist ";
	array[3] = Recovered_04_004e_Name;
	array[4] = " && chflags uchg ";
	array[5] = Recovered_04_004e_Name;
	ExecuteSshCommand(string.Concat(array));
	ExecuteSshCommand("mkdir -p " + Recovered_04_0049_Name + " && chmod 775 " + Recovered_04_0049_Name);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "activation_record.plist", Recovered_04_0056_Name + "/Route_ActRec.plist");
	string[] array2 = new string[6];
	array2[0] = "mv -f ";
	array2[1] = Recovered_04_0056_Name;
	array2[2] = "/Route_ActRec.plist ";
	array2[3] = Recovered_04_004d_Name;
	array2[4] = " && chflags uchg ";
	array2[5] = Recovered_04_004d_Name;
	ExecuteSshCommand(string.Concat(array2));
	UpdateProgress(62);
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "data_ark.plist", Recovered_04_0056_Name + "/Route_DataArk.plist");
	UpdateProgress(64);
	string[] array3 = new string[12];
	array3[0] = "cp -f ";
	array3[1] = Recovered_04_0056_Name;
	array3[2] = "/Route_DataArk.plist ";
	array3[3] = Recovered_04_0050_Name;
	array3[4] = " && mv -f ";
	array3[5] = Recovered_04_0056_Name;
	array3[6] = "/Route_DataArk.plist ";
	array3[7] = Recovered_04_004f_Name;
	array3[8] = " && chflags uchg ";
	array3[9] = Recovered_04_0050_Name;
	array3[10] = " && chflags uchg ";
	array3[11] = Recovered_04_004f_Name;
	ExecuteSshCommand(string.Concat(array3));
	Recovered_06_00b3_Name(Recovered_04_0053_Name + "RaptorActivation.pem", Recovered_04_0056_Name + "/RaptorActivation.pem");
	ExecuteSshCommand("mv -f " + Recovered_04_0056_Name + "/RaptorActivation.pem/System/Library/PrivateFrameworks/MobileActivation.framework/Support/Certificates/RaptorActivation.pem");
}
