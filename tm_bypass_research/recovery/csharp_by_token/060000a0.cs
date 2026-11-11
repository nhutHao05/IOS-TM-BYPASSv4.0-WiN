// Recovered from method token 0x060000a0; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
public void ConnectSshOverUsb()
{
	while (true)
	{
		Recovered_06_0095_Name();
		Thread.Sleep(2000);
		using (Process process = new Process())
		{
			process.StartInfo.FileName = Recovered_04_0052_Name + "\\vendor\\iproxy.exe";
			process.StartInfo.Arguments = Recovered_04_0046_Name + " 44";
			process.StartInfo.UseShellExecute = false;
			process.StartInfo.RedirectStandardOutput = true;
			process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process.StartInfo.CreateNoWindow = true;
			process.Start();
		}
		try
		{
			AuthenticationMethod[] array = new AuthenticationMethod[1];
			array[0] = new PasswordAuthenticationMethod("root", Recovered_04_0045_Name);
			AuthenticationMethod[] authenticationMethods = array;
			ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0044_Name, Recovered_04_0046_Name, "root", authenticationMethods);
			connectionInfo.Timeout = TimeSpan.FromSeconds(300.0);
			Recovered_04_0042_Name = new SshClient(connectionInfo);
			Recovered_04_0042_Name.Connect();
		}
		catch
		{
			MessageBoxButtons buttons = MessageBoxButtons.YesNo;
			if (MessageBox.Show("SSH Connection Error. Please Jailbreak Again with Checkra1n 0.12.4!", "Warning!", buttons) == DialogResult.Yes)
			{
				continue;
			}
			throw new ApplicationException("Error SSH");
		}
		break;
	}
	Recovered_06_00a1_Name();
}
