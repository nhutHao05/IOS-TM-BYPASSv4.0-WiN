// Recovered from method token 0x060000df; analyst names; not the original source.
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using Renci.SshNet;

[MethodImpl(MethodImplOptions.NoInlining)]
internal string Recovered_06_00df_Name(string P_0)
{
	if (!Recovered_04_009f_Name.IsConnected)
	{
		try
		{
			Recovered_04_009f_Name.Connect();
		}
		catch
		{
			MessageBox.Show("Cannot Connected to Your iDevice! \nPlease Re Open Tool and Try Again!", "Connection to iDevice lost.", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			return "XD";
		}
	}
	SshCommand sshCommand = Recovered_04_009f_Name.CreateCommand(P_0);
	string result;
	try
	{
		sshCommand.Execute();
		result = sshCommand.Result;
	}
	catch
	{
		Recovered_04_009f_Name.Disconnect();
		result = "XD";
	}
	return result;
}
