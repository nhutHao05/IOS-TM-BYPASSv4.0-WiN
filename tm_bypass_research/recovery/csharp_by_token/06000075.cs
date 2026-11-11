// Recovered from method token 0x06000075; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0075_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		UpdateProgress(10);
		if (MessageBox.Show("Are you Sure want Erase Keep Same iOS?\nFor A11 CPU iOS 14.x Passcode/Disabled ONLY!", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
		{
			ConnectSshOverUsb();
			UpdateProgress(20);
			Recovered_06_00b2_Name();
			UpdateProgress(30);
			ExecuteSshCommand("snappy -f / -r orig-fs -x");
			UpdateProgress(40);
			ExecuteSshCommand("launchctl unload -F /System/Library/LaunchDaemons/*");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.CommCenterRootHelper.plist");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.CommCenterMobileHelper.plist");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.devicedataresetd.plist");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.backboardd.plist");
			ExecuteSshCommand("launchctl load -w -F /System/Library/LaunchDaemons/com.apple.runningboardd.plist");
			MountDeviceFilesystem();
			UpdateProgress(50);
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000a_Name, "/usr/bin/eraser");
			UpdateProgress(60);
			ExecuteSshCommand("chmod -R 755 /usr/bin/eraser");
			ExecuteSshCommand("/usr/bin/eraser -command da7e6b6d2c20eb316c093 & rm /usr/bin/eraser");
			UpdateProgress(70);
			ExecuteSshCommand("killall -9 SpringBoard mobileactivationd");
			UpdateProgress(80);
			Recovered_06_00b2_Name();
			UpdateProgress(90);
			ExecuteSshCommand("/usr/bin/eraser -command da7e6b6d2c20eb316c093 && rm /usr/bin/eraser");
			UpdateProgress(100);
			MessageBox.Show("Your iDevice Successfully Erasing... !\nIf stuck, Manually Reboot, Erasing will Continue...", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
		}
		else
		{
			UpdateProgress(100);
			MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
		}
	}
	catch (Exception)
	{
		MessageBox.Show("Please Re Open Tool and Click Erase Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
	}
}
