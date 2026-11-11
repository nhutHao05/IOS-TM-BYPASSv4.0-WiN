// Recovered from method token 0x06000061; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public void RunMdmOverSsh_Unreferenced()
{
	try
	{
		Recovered_04_0063_Name = 1;
		UpdateProgress(5);
		try
		{
			EnsureDevicePairing();
			UpdateProgress(10);
			ConnectSshOverUsb();
			UpdateProgress(20);
			MountDeviceFilesystem();
			UpdateProgress(30);
			ExecuteSshCommand("rm -rf /var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/*");
			UpdateProgress(60);
			ExecuteSshCommand("killall backboardd && sleep 7");
			UpdateProgress(80);
			UploadResourceViaScp(ApplicationResourcesRecovered.MdmConfigurationTemplate, "/var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/CloudConfigurationDetails.plist");
			UpdateProgress(84);
			ExecuteSshCommand("chflags uchg /var/containers/Shared/SystemGroup/systemgroup.com.apple.configurationprofiles/Library/ConfigurationProfiles/CloudConfigurationDetails.plist");
			UpdateProgress(90);
			ExecuteSshCommand("killall backboardd");
			UpdateProgress(96);
			UpdateProgress(100);
		}
		catch (Exception ex)
		{
			Recovered_06_006e_Name(ex);
			return;
		}
		Recovered_02_0010_TypeName recovered_02_0010_TypeName = new Recovered_02_0010_TypeName();
		recovered_02_0010_TypeName.ShowDialog();
	}
	catch (Exception ex2)
	{
		Recovered_06_006e_Name(ex2);
	}
}
