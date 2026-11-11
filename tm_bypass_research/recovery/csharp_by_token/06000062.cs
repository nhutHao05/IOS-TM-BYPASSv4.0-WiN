// Recovered from method token 0x06000062; analyst names; not the original source.
using System;

public void RunMdmBackupRestore()
{
	try
	{
		Recovered_04_0063_Name = 1;
		UpdateProgress(5);
		try
		{
			EnsureDevicePairing();
			UpdateProgress(10);
			UpdateProgress(20);
			DeleteMdmWorkingDirectory();
			UpdateProgress(30);
			ExtractMdmToolsArchive();
			UpdateProgress(40);
			ExtractMdmBackupArchive();
			UpdateProgress(60);
			WriteMdmInfoPlist();
			UpdateProgress(80);
			WriteMdmManifestPlist();
			UpdateProgress(84);
			RunMdmSetupProcess();
			UpdateProgress(90);
			DeleteMdmWorkingDirectory();
			UpdateProgress(96);
			UpdateProgress(100);
		}
		catch (Exception ex)
		{
			Recovered_06_006f_Name(ex);
			return;
		}
		Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
		recovered_02_0010_TypeName.ShowDialog();
	}
	catch (Exception ex2)
	{
		Recovered_06_006f_Name(ex2);
	}
}
