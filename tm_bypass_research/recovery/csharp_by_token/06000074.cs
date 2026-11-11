// Recovered from method token 0x06000074; analyst names; not the original source.
using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_0074_Name()
{
	try
	{
		Recovered_06_00c1_Name();
		UpdateProgress(10);
		if (MessageBox.Show("Are you Sure want Erase All Data?", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
		{
			ConnectSshOverUsb();
			UpdateProgress(20);
			MountDeviceFilesystem();
			UpdateProgress(30);
			Recovered_06_007c_Name();
			UpdateProgress(40);
			ExecuteSshCommand("snappy -f / -r orig-fs -x");
			UpdateProgress(50);
			ExecuteSshCommand("launchctl load -w /System/Library/LaunchDaemons/com.apple.mobile.obliteration.plist");
			UpdateProgress(60);
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_000a_Name, "/usr/bin/eraser");
			UploadResourceViaScp(ApplicationResourcesRecovered.Recovered_17_0007_Name, "/bin/eraser");
			UpdateProgress(70);
			ExecuteSshCommand("chmod -R 755 /usr/bin/eraser");
			ExecuteSshCommand("chmod -R 755 /bin/eraser");
			UpdateProgress(90);
			if (MessageBox.Show("Your iDevice now is being Restore, OK?", "Warning !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
			{
				ExecuteSshCommand("eraser -command da7e6b6d2c20eb316c093 & rm /usr/bin/eraser");
				ExecuteSshCommand("eraser -command 8a5fbd968b4f16624ecb5713744028fefabe8a20de10dfc58c4ede37212ac3da & rm /bin/eraser");
				UpdateProgress(100);
				MessageBox.Show("Your iDevice Successfully Erasing... !", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			}
			else
			{
				UpdateProgress(100);
				MessageBox.Show("Process Cancelled by User", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
			}
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
