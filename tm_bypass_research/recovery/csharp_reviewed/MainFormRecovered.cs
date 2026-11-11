using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Text;
using System.IO;
using System.Management;
using System.Net;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using LibUsbDotNet.DeviceNotify;
using Renci.SshNet;
using Siticone.UI.WinForms;
using Siticone.UI.WinForms.Enums;

public class MainFormRecovered : Form
{
	public delegate void Recovered_02_0019_TypeName(object sender, EventArrivedEventArgs e);

	[Serializable]
	[CompilerGenerated]
	private sealed class Recovered_02_001a_TypeName
	{
		public static readonly Recovered_02_001a_TypeName _003C_003E9 = new Recovered_02_001a_TypeName();

		public static Action _003C_003E9__107_0;

		internal void Recovered_06_013d_Name()
		{
			Clipboard.SetText(DeviceStateRecovered.DeviceSerialNumber);
		}
	}

	[CompilerGenerated]
	private sealed class Recovered_02_001b_TypeName
	{
		public Action Recovered_04_00cb_Name;

		public AutoResetEvent Recovered_04_00cc_Name;

		internal void Recovered_06_013f_Name()
		{
			Recovered_04_00cb_Name();
			Recovered_04_00cc_Name.Set();
		}
	}

	[CompilerGenerated]
	private static class Recovered_02_001c_TypeName
	{
		public static CallSite<Func<CallSite, object, object>> Recovered_04_00cd_Name;

		public static CallSite<Func<CallSite, Type, object, SolidBrush>> Recovered_04_00ce_Name;

		public static CallSite<Action<CallSite, object>> Recovered_04_00cf_Name;

		public static CallSite<Action<CallSite, object>> Recovered_04_00d0_Name;
	}

	public static string Recovered_04_007f_Name = Directory.GetCurrentDirectory();

	public int Recovered_04_0080_Name = 22;

	public const int Recovered_04_0081_Name = 161;

	public const int Recovered_04_0082_Name = 2;

	private static readonly string Recovered_04_0083_Name = Environment.NewLine;

	private const int Recovered_04_0084_Name = 65535;

	private const uint Recovered_04_0085_Name = 26u;

	private ManagementEventWatcher Recovered_04_0086_Name;

	private ManagementEventWatcher Recovered_04_0087_Name;

	private static int Recovered_04_0088_Name = 0;

	private bool Recovered_04_0089_Name = false;

	private bool Recovered_04_008a_Name = false;

	private bool Recovered_04_008b_Name = false;

	private bool MdmOperationSelected = false;

	private bool Recovered_04_008d_Name = false;

	private bool Recovered_04_008e_Name = false;

	public static bool Recovered_04_008f_Name = true;

	public static string Recovered_04_0090_Name = Recovered_04_007f_Name + "/vendor/";

	public string Recovered_04_0091_Name = "127.0.0.1";

	public string Recovered_04_0092_Name = "alpine";

	public string Recovered_04_0093_Name = "";

	private bool Recovered_04_0094_Name;

	public static IDeviceNotifier Recovered_04_0095_Name = DeviceNotifier.OpenDeviceNotifier();

	public string Recovered_04_0096_Name = "";

	public string Recovered_04_0097_Name = "";

	public string Recovered_04_0098_Name = "";

	public string Recovered_04_0099_Name = "";

	public string Recovered_04_009a_Name = "";

	private Process Recovered_04_009b_Name = null;

	private Process Recovered_04_009c_Name = null;

	public int Recovered_04_009d_Name = 2222;

	public int Recovered_04_009e_Name = 44;

	private SshClient Recovered_04_009f_Name;

	private ScpClient Recovered_04_00a0_Name;

	private IContainer Recovered_04_00a1_Name = null;

	private BackgroundWorker Recovered_04_00a2_Name;

	private PictureBox Recovered_04_00a3_Name;

	private Panel Recovered_04_00a4_Name;

	public Label Recovered_04_00a5_Name;

	private Label Recovered_04_00a6_Name;

	private Label Recovered_04_00a7_Name;

	private Label Recovered_04_00a8_Name;

	private Label Recovered_04_00a9_Name;

	private Label Recovered_04_00aa_Name;

	private Label Recovered_04_00ab_Name;

	private Label Recovered_04_00ac_Name;

	private Label Recovered_04_00ad_Name;

	private Panel Recovered_04_00ae_Name;

	private SiticoneControlBox Recovered_04_00af_Name;

	private SiticoneControlBox Recovered_04_00b0_Name;

	private Label Recovered_04_00b1_Name;

	private Label Recovered_04_00b2_Name;

	private SiticoneProgressBar Recovered_04_00b3_Name;

	private SiticoneGradientButton Recovered_04_00b4_Name;

	private SiticoneGradientButton Recovered_04_00b5_Name;

	private SiticoneGradientButton Recovered_04_00b6_Name;

	private SiticoneLabel Recovered_04_00b7_Name;

	private SiticonePictureBox Recovered_04_00b8_Name;

	private LinkLabel Recovered_04_00b9_Name;

	private PictureBox Recovered_04_00ba_Name;

	private LinkLabel Recovered_04_00bb_Name;

	private SiticoneGradientButton Recovered_04_00bc_Name;

	private SiticoneGradientButton Recovered_04_00bd_Name;

	private SiticoneGradientButton ButtonMdm;

	private SiticoneGradientButton Recovered_04_00bf_Name;

	private SiticoneGradientButton Recovered_04_00c0_Name;

	private Label Recovered_04_00c1_Name;

	private Label Recovered_04_00c2_Name;

	private Label Recovered_04_00c3_Name;

	private Label Recovered_04_00c4_Name;

	private SiticoneGradientButton Recovered_04_00c5_Name;

	private SiticoneGradientButton Recovered_04_00c6_Name;

	private SiticoneGradientButton Recovered_04_00c7_Name;

	private SiticoneGradientButton Recovered_04_00c8_Name;

	[DllImport("user32.dll", EntryPoint = "SendMessage")]
	public static extern int Recovered_06_00d3_Name(IntPtr P_0, int P_1, int P_2, int P_3);

	[DllImport("user32.dll", EntryPoint = "ReleaseCapture")]
	public static extern bool Recovered_06_00d4_Name();

	[DllImport("user32.dll", CharSet = CharSet.Auto, EntryPoint = "SendNotifyMessage", SetLastError = true)]
	private static extern bool Recovered_06_00d5_Name(IntPtr P_0, uint P_1, UIntPtr P_2, string P_3);

	[MethodImpl(MethodImplOptions.NoInlining)]
	public MainFormRecovered()
	{
		string text = Recovered_06_010a_Name();
		if (text == "CONECTION_ERROR")
		{
			MessageBox.Show("Error Connecting to Internet", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
			Recovered_06_00fc_Name(0, "NO INTERNET");
			Recovered_04_00b5_Name.Enabled = true;
			Recovered_04_00b6_Name.Enabled = true;
			Recovered_04_00bd_Name.Enabled = true;
			return;
		}
		if (DeviceStateRecovered.ToolVersion != text)
		{
			Recovered_02_0012_TypeName recovered_02_0012_TypeName = new Recovered_02_0012_TypeName();
			recovered_02_0012_TypeName.ShowDialog();
			string text2 = Recovered_06_010b_Name();
			if (text2 != "CONECTION_ERROR")
			{
				Process.Start(text2);
				Recovered_06_00d7_Name();
			}
			else
			{
				MessageBox.Show(this, "Please Visit https://iservicevn.com and Look for the Latest Version available", "Check Version", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				Recovered_06_00d7_Name();
			}
			Recovered_06_00fc_Name(0, "");
			return;
		}
		InitializeComponentRecovered();
		string query = "SELECT * FROM __InstanceCreationEvent WITHIN 2 WHERE TargetInstance ISA 'Win32_PnPEntity'";
		EventQuery query2 = new EventQuery(query);
		Recovered_04_0086_Name = new ManagementEventWatcher(new ManagementScope("root\\CIMV2")
		{
			Options = 
			{
				EnablePrivileges = true
			}
		}, query2);
		Recovered_02_0019_TypeName recovered_02_0019_TypeName = Recovered_06_00e2_Name;
		Recovered_04_0086_Name.EventArrived += recovered_02_0019_TypeName.Invoke;
		Recovered_04_0086_Name.Start();
		string query3 = "SELECT * FROM __InstanceDeletionEvent WITHIN 2 WHERE TargetInstance ISA 'Win32_PnPEntity'";
		EventQuery query4 = new EventQuery(query3);
		Recovered_04_0087_Name = new ManagementEventWatcher(new ManagementScope("root\\CIMV2")
		{
			Options = 
			{
				EnablePrivileges = true
			}
		}, query4);
		Recovered_04_0087_Name.EventArrived += Recovered_06_00e3_Name;
		Recovered_04_0087_Name.Start();
		try
		{
			Recovered_06_00d9_Name();
		}
		catch (Exception)
		{
			Recovered_06_00e4_Name();
		}
	}

	private void Recovered_06_00d7_Name()
	{
		try
		{
			Recovered_06_00e9_Name();
		}
		catch
		{
		}
		Environment.Exit(0);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00d8_Name()
	{
		Recovered_06_00f8_Name();
		Thread.Sleep(2000);
		using (Process process = new Process())
		{
			process.StartInfo.FileName = Recovered_04_007f_Name + "\\vendor\\iproxy.exe";
			process.StartInfo.Arguments = Recovered_04_0080_Name + " 44";
			process.StartInfo.UseShellExecute = false;
			process.StartInfo.RedirectStandardOutput = true;
			process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			process.StartInfo.CreateNoWindow = true;
			process.Start();
		}
		try
		{
			Recovered_06_00e1_Name();
		}
		catch
		{
		}
	}

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

	private void Recovered_06_00da_Name()
	{
		Recovered_04_00a4_Name.Visible = false;
		Recovered_04_0095_Name.OnDeviceNotify += Recovered_06_00e6_Name;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00db_Name()
	{
		MainFormRecovered mainFormRecovered = (MainFormRecovered)Application.OpenForms["MainForm"];
		Recovered_04_00a4_Name.Visible = true;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00dc_Name(string P_0)
	{
		string[] array = P_0.Split('\n');
		string[] array2 = array;
		for (int i = 0; i < array2.Length; i++)
		{
			string text = array2[i].Replace("\r", "");
			if (text.StartsWith("UniqueDeviceID: "))
			{
				string recovered_04_0093_Name = text.Replace("UniqueDeviceID: ", "");
				Recovered_04_0093_Name = recovered_04_0093_Name;
			}
			else if (text.StartsWith("ProductVersion: "))
			{
				string recovered_04_0096_Name = text.Replace("ProductVersion: ", "");
				Recovered_04_0096_Name = recovered_04_0096_Name;
			}
			else if (text.StartsWith("ProductType: "))
			{
				string recovered_04_0098_Name = text.Replace("ProductType: ", "");
				Recovered_04_0098_Name = recovered_04_0098_Name;
				DeviceStateRecovered.DeviceProductType = Recovered_04_0098_Name;
			}
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00dd_Name()
	{
		try
		{
			Recovered_06_00e1_Name();
			SshCommand sshCommand = Recovered_04_009f_Name.CreateCommand("mount -o rw,union,update /");
			IAsyncResult asyncResult = sshCommand.BeginExecute();
			while (!asyncResult.IsCompleted)
			{
				Thread.Sleep(2000);
			}
			sshCommand.EndExecute(asyncResult);
			string text = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
			string text2 = Recovered_06_00e0_Name(text, "-s");
			if (!text2.StartsWith("ERROR: "))
			{
			}
		}
		catch (Exception ex)
		{
			if (ex.Message.Contains("Wait Please"))
			{
			}
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00de_Name()
	{
		try
		{
			Recovered_06_00e5_Name();
			if (!Recovered_04_0094_Name)
			{
				string text = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
				string text2 = Recovered_06_00e0_Name(text, "-s");
				if (!text2.StartsWith("ERROR: "))
				{
					Recovered_06_00dc_Name(text2);
					DeviceStateRecovered.DeviceUDID = Recovered_04_0093_Name;
					Recovered_04_00b1_Name.Text = DeviceStateRecovered.DeviceUDID;
					Recovered_04_00ac_Name.Text = Recovered_04_0096_Name;
					Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
				}
				string text3 = Recovered_06_00df_Name("/usr/libexec/just4fun " + Recovered_04_0093_Name);
			}
		}
		catch
		{
		}
	}

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

	public string Recovered_06_00e0_Name(string P_0, string P_1)
	{
		Process process = new Process();
		process.StartInfo = new ProcessStartInfo
		{
			FileName = P_0,
			Arguments = P_1,
			UseShellExecute = false,
			RedirectStandardOutput = true,
			CreateNoWindow = true
		};
		process.Start();
		return process.StandardOutput.ReadToEnd();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00e1_Name()
	{
		AuthenticationMethod[] authenticationMethods = new AuthenticationMethod[1]
		{
			new PasswordAuthenticationMethod("root", Recovered_04_0092_Name)
		};
		ConnectionInfo connectionInfo = new ConnectionInfo(Recovered_04_0091_Name, Recovered_04_0080_Name, "root", authenticationMethods);
		connectionInfo.Timeout = TimeSpan.FromSeconds(20.0);
		Recovered_04_009f_Name = new SshClient(connectionInfo);
		Recovered_04_00a0_Name = new ScpClient(connectionInfo);
		if (!Recovered_04_009f_Name.IsConnected)
		{
			Recovered_04_009f_Name.Connect();
		}
		if (!Recovered_04_00a0_Name.IsConnected)
		{
			Recovered_04_00a0_Name.Connect();
		}
	}

	private void Recovered_06_00e2_Name(object P_0, EventArrivedEventArgs P_1)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		try
		{
			Recovered_06_00d9_Name();
		}
		catch (Exception)
		{
			Recovered_06_00e4_Name();
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00e3_Name(object P_0, EventArrivedEventArgs P_1)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		Control.CheckForIllegalCrossThreadCalls = false;
		PropertyData propertyData = P_1.NewEvent.Properties["TargetInstance"];
		ManagementBaseObject managementBaseObject = (ManagementBaseObject)propertyData.Value;
		string text = (string)managementBaseObject.Properties["Description"].Value;
		string text2 = (string)managementBaseObject.Properties["DeviceID"].Value;
		string text3 = (string)managementBaseObject.Properties["Status"].Value;
		if (text.Contains("Apple"))
		{
			Recovered_04_00ad_Name.Text = "Please connect a Jailbroken iDevice";
			Recovered_04_00a4_Name.Visible = false;
			Recovered_04_00a3_Name.Visible = true;
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00e4_Name()
	{
		if (!Recovered_06_00e5_Name())
		{
			Recovered_04_00ad_Name.Text = "Please connect a Jailbroken iDevice";
			Recovered_04_00a3_Name.Visible = true;
			Recovered_04_00a4_Name.Visible = false;
		}
		else
		{
			Recovered_04_00ad_Name.Text = "iDevice Information";
			Recovered_04_00a4_Name.Visible = true;
			Recovered_06_00e5_Name();
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private bool Recovered_06_00e5_Name(string P_0 = "")
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		Recovered_04_009c_Name = new Process();
		Recovered_04_009c_Name.StartInfo.FileName = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
		Recovered_04_009c_Name.StartInfo.Arguments = P_0;
		Recovered_04_009c_Name.StartInfo.UseShellExecute = false;
		Recovered_04_009c_Name.StartInfo.RedirectStandardOutput = true;
		Recovered_04_009c_Name.StartInfo.CreateNoWindow = true;
		Recovered_04_009c_Name.Start();
		DeviceStateRecovered.Recovered_04_007b_Name = false;
		DeviceStateRecovered.Recovered_04_007c_Name = false;
		DeviceStateRecovered.Recovered_04_007d_Name = false;
		int num = 0;
		while (!Recovered_04_009c_Name.StandardOutput.EndOfStream)
		{
			num++;
			string text = Recovered_04_009c_Name.StandardOutput.ReadLine();
			string text2 = text.Replace("\r", "");
			if (text2.StartsWith("UniqueDeviceID: "))
			{
				string text3 = text2.Replace("UniqueDeviceID: ", "");
				Recovered_04_00b1_Name.Text = text3;
				DeviceStateRecovered.DeviceUDID = text3;
			}
			else if (text2.StartsWith("ProductVersion: "))
			{
				string text4 = (Recovered_04_0096_Name = text2.Replace("ProductVersion: ", ""));
				Recovered_04_00ac_Name.Text = text4;
				DeviceStateRecovered.DeviceProductVersion = text4;
			}
			else if (text2.StartsWith("BuildVersion: "))
			{
				string recovered_04_0097_Name = text2.Replace("BuildVersion: ", "");
				Recovered_04_0097_Name = recovered_04_0097_Name;
			}
			else if (text2.StartsWith("DeviceName: "))
			{
				string text5 = text2.Replace("DeviceName: ", "");
			}
			else if (text2.StartsWith("ProductType: "))
			{
				string deviceProductType = (Recovered_04_0098_Name = text2.Replace("ProductType: ", ""));
				Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
				DeviceStateRecovered.DeviceProductType = deviceProductType;
			}
			else if (text2.StartsWith("DeviceClass: "))
			{
				string text6 = text2.Replace("DeviceClass: ", "");
			}
			else if (text2.StartsWith("DeviceColor: "))
			{
				string text7 = text2.Replace("DeviceColor: ", "");
			}
			else if (text2.StartsWith("HardwareModel: "))
			{
				string text8 = text2.Replace("HardwareModel: ", "");
			}
			else if (text2.StartsWith("ProductName: "))
			{
				string text9 = text2.Replace("ProductName: ", "").ToLower();
			}
			else if (text2.StartsWith("TelephonyCapability: "))
			{
				string text10 = text2.Replace("TelephonyCapability: ", "");
			}
			string[] array = text.Split(':');
			if (array[0] == "SerialNumber")
			{
				DeviceStateRecovered.DeviceSerialNumber = array[1].Trim();
				Recovered_04_00aa_Name.Text = array[1].Trim();
				DeviceStateRecovered.Recovered_04_007d_Name = true;
			}
			if (array[0] == "InternationalMobileEquipmentIdentity")
			{
				DeviceStateRecovered.DeviceIMEI = array[1].Trim();
				Recovered_04_00a5_Name.Text = array[1].Trim();
				DeviceStateRecovered.Recovered_04_007c_Name = true;
			}
			if (array[0] == "ActivationState")
			{
				DeviceStateRecovered.ActivationStatus = array[1].Trim();
				Recovered_04_00c3_Name.Text = array[1].Trim();
			}
			if (array[0] == "SIMStatus")
			{
				DeviceStateRecovered.Recovered_04_0072_Name = array[1].Trim();
				DeviceStateRecovered.Recovered_04_0073_Name = (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusReady") ^ (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusPINLocked");
			}
			if (text.Contains("MobileEquipmentIdentifier"))
			{
				DeviceStateRecovered.Recovered_04_007b_Name = true;
			}
			if (text.Contains("UniqueDeviceID"))
			{
				Recovered_04_00b1_Name.Text = array[1];
			}
		}
		if (!DeviceStateRecovered.Recovered_04_007b_Name && !DeviceStateRecovered.Recovered_04_007c_Name && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPhone")) && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPad")) && (!DeviceStateRecovered.Recovered_04_007d_Name || !Recovered_04_0098_Name.Contains("iPod")) && num <= 2)
		{
			Control.CheckForIllegalCrossThreadCalls = false;
			Recovered_04_009c_Name = new Process();
			Recovered_04_009c_Name.StartInfo.FileName = Environment.CurrentDirectory + "/vendor/ideviceinfo.exe";
			Recovered_04_009c_Name.StartInfo.Arguments = "-s";
			Recovered_04_009c_Name.StartInfo.UseShellExecute = false;
			Recovered_04_009c_Name.StartInfo.RedirectStandardOutput = true;
			Recovered_04_009c_Name.StartInfo.CreateNoWindow = true;
			Recovered_04_009c_Name.Start();
			DeviceStateRecovered.Recovered_04_007e_Name = false;
			int num2 = 0;
			while (!Recovered_04_009c_Name.StandardOutput.EndOfStream)
			{
				num2++;
				string text11 = Recovered_04_009c_Name.StandardOutput.ReadLine();
				string text12 = text11.Replace("\r", "");
				if (text12.StartsWith("UniqueDeviceID: "))
				{
					string text13 = text12.Replace("UniqueDeviceID: ", "");
					Recovered_04_00b1_Name.Text = text13;
					DeviceStateRecovered.Recovered_04_007e_Name = true;
				}
				else if (text12.StartsWith("ProductVersion: "))
				{
					string text14 = (Recovered_04_0096_Name = text12.Replace("ProductVersion: ", ""));
					Recovered_04_00ac_Name.Text = text14;
					DeviceStateRecovered.DeviceProductVersion = text14;
				}
				else if (text12.StartsWith("BuildVersion: "))
				{
					string recovered_04_0097_Name2 = text12.Replace("BuildVersion: ", "");
					Recovered_04_0097_Name = recovered_04_0097_Name2;
				}
				else if (text12.StartsWith("DeviceName: "))
				{
					string text15 = text12.Replace("DeviceName: ", "");
				}
				else if (text12.StartsWith("ProductType: "))
				{
					string recovered_04_0098_Name = text12.Replace("ProductType: ", "");
					Recovered_04_0098_Name = recovered_04_0098_Name;
					Recovered_04_00ab_Name.Text = Recovered_04_0098_Name;
				}
				else if (text12.StartsWith("DeviceClass: "))
				{
					string text16 = text12.Replace("DeviceClass: ", "");
				}
				else if (text12.StartsWith("DeviceColor: "))
				{
					string text17 = text12.Replace("DeviceColor: ", "");
				}
				else if (text12.StartsWith("HardwareModel: "))
				{
					string text18 = text12.Replace("HardwareModel: ", "");
				}
				else if (text12.StartsWith("ProductName: "))
				{
					string text19 = text12.Replace("ProductName: ", "").ToLower();
				}
				else if (text12.StartsWith("TelephonyCapability: "))
				{
					string text20 = text12.Replace("TelephonyCapability: ", "");
				}
				string[] array2 = text11.Split(':');
				if (array2[0] == "SerialNumber")
				{
					DeviceStateRecovered.DeviceSerialNumber = array2[1].Trim();
					Recovered_04_00aa_Name.Text = array2[1].Trim();
				}
				if (array2[0] == "InternationalMobileEquipmentIdentity")
				{
					DeviceStateRecovered.DeviceIMEI = array2[1].Trim();
					Recovered_04_00a5_Name.Text = array2[1].Trim();
				}
				if (array2[0] == "ActivationState")
				{
					DeviceStateRecovered.ActivationStatus = array2[1].Trim();
				}
				if (array2[0] == "SIMStatus")
				{
					DeviceStateRecovered.Recovered_04_0072_Name = array2[1].Trim();
					DeviceStateRecovered.Recovered_04_0073_Name = (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusReady") ^ (DeviceStateRecovered.Recovered_04_0072_Name == "kCTSIMSupportSIMStatusPINLocked");
				}
				if (text11.Contains("MobileEquipmentIdentifier"))
				{
				}
				if (text11.Contains("UniqueDeviceID"))
				{
					Recovered_04_00b1_Name.Text = array2[1];
				}
			}
			if (DeviceStateRecovered.Recovered_04_007e_Name)
			{
			}
			if (num2 <= 2)
			{
				return false;
			}
		}
		return true;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00e6_Name(object P_0, DeviceNotifyEventArgs P_1)
	{
		if (!(P_1.EventType.ToString() == "DeviceRemoveComplete"))
		{
			Recovered_04_00ad_Name.Text = "iDevice Information";
			Recovered_04_00a3_Name.Visible = false;
			Recovered_04_00a4_Name.Visible = true;
			Recovered_06_00e4_Name();
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00e7_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_0095_Name.OnDeviceNotify += Recovered_06_00e6_Name;
		string caption = "Double click to copy";
		new ToolTip().SetToolTip(Recovered_04_00a5_Name, caption);
		new ToolTip().SetToolTip(Recovered_04_00aa_Name, caption);
		new ToolTip().SetToolTip(Recovered_04_00b1_Name, caption);
		new ToolTip().SetToolTip(Recovered_04_00ab_Name, caption);
		new ToolTip().SetToolTip(Recovered_04_00ac_Name, caption);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void DispatchAuthorizedDeviceOperation(object P_0, DoWorkEventArgs P_1)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		try
		{
			Recovered_06_00e9_Name();
		}
		catch (Exception)
		{
		}
		try
		{
			string text = QuerySerialAuthorization();
			switch (text.ToString().Replace("\n", "").Replace("\r", "")
				.Replace("\t", ""))
			{
			case "CONECTION_ERROR":
				MessageBox.Show("Unlock your iDevice and Press Trust!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				Recovered_06_00fc_Name(0, "DEVICE NOT PAIRED");
				Recovered_04_00c0_Name.Enabled = true;
				return;
			case "NOT_AUTHORIZED":
				MessageBox.Show("Sorry Your iDevice Serial Not Registered", "Check Serial", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				Recovered_06_00fc_Name(0, "Not Authorized Serial");
				Process.Start("https://iservicevn.com/buy.php");
				return;
			case "AUTHORIZED":
				if (Recovered_04_008a_Name)
				{
					Recovered_06_00eb_Name();
				}
				else if (Recovered_04_008b_Name)
				{
					Recovered_06_00ed_Name();
				}
				else if (Recovered_04_008d_Name)
				{
					Recovered_06_00f1_Name();
				}
				else if (MdmOperationSelected)
				{
					StartMdmWorkflow();
				}
				else if (Recovered_04_0089_Name)
				{
					Recovered_06_00ea_Name();
				}
				else if (!DeviceStateRecovered.Recovered_04_007c_Name && !DeviceStateRecovered.Recovered_04_007b_Name && Recovered_04_0098_Name.Contains("iPhone"))
				{
					if (MessageBox.Show("Your iDevice BASEBAND BROKEN Can Bypass UNTETHERED ONLY !\nAre You Sure Want To Do That ?", "Check Your iPhone Informations!", MessageBoxButtons.YesNo) == DialogResult.Yes)
					{
						Recovered_06_00f1_Name();
					}
					else
					{
						MessageBox.Show("Process Cancelled by User", "iServices VN");
					}
				}
				else if (DeviceStateRecovered.DeviceProductType.StartsWith("iPhone6,") || DeviceStateRecovered.DeviceProductType.StartsWith("iPhone8,") || DeviceStateRecovered.DeviceProductType.StartsWith("iPad"))
				{
					Recovered_06_00ef_Name();
				}
				else if ((!DeviceStateRecovered.Recovered_04_007b_Name & DeviceStateRecovered.DeviceProductVersion.StartsWith("14.6")) || DeviceStateRecovered.DeviceProductVersion.StartsWith("14.7") || DeviceStateRecovered.DeviceProductVersion.StartsWith("14.8"))
				{
					if (MessageBox.Show("Your iOS 14.6 to 14.8.1 NOT supported Signal !\niDevice will Start Bypass without SimPin locked , Press YES\nIf You Sure want Use SimPin (No Battery Drain), Press NO", "Choose Services !!!", MessageBoxButtons.YesNo) == DialogResult.Yes)
					{
						Recovered_06_00f0_Name();
					}
					else
					{
						Recovered_06_00ee_Name();
					}
				}
				else if (!DeviceStateRecovered.Recovered_04_007b_Name)
				{
					Recovered_06_00ee_Name();
				}
				else
				{
					Recovered_06_00ef_Name();
				}
				break;
			}
			Recovered_06_00fc_Name(0, "EXITO");
		}
		catch (Exception value)
		{
			Recovered_06_00fc_Name(0, "ERROR");
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(value);
			}
			MessageBox.Show("Please Jailbreak with Checkra1n 0.12.4 and Try Again", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
		finally
		{
			Recovered_06_0125_Name();
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00e9_Name()
	{
		Process[] processesByName = Process.GetProcessesByName("iproxy");
		if (processesByName.Length >= 1)
		{
			Process[] array = processesByName;
			foreach (Process process in array)
			{
				process.Kill();
			}
			Recovered_04_009b_Name = null;
		}
	}

	public void Recovered_06_00ea_Name()
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_0080_Name();
	}

	public void Recovered_06_00eb_Name()
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_005e_Name();
	}

	public void Recovered_06_00ec_Name()
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_0060_Name();
	}

	public void Recovered_06_00ed_Name()
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_005f_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00ee_Name()
	{
		Invoke((MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
		{
			Recovered_04_00c0_Name.Text = "GSM with Signal Activating";
		}));
		Recovered_06_0126_Name();
		if (DeviceStateRecovered.Recovered_04_0073_Name)
		{
			MessageBox.Show("Please insert Sim card and Connect Wifi", "[IMPORTANT]", MessageBoxButtons.OKCancel, MessageBoxIcon.Exclamation);
		}
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_005b_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00ef_Name()
	{
		Invoke((MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
		{
			Recovered_04_00c0_Name.Text = "MEID No Signal Activating";
		}));
		Recovered_06_0126_Name();
		if (DeviceStateRecovered.Recovered_04_0073_Name)
		{
			MessageBox.Show("Please Remove Sim card and Connect Wifi", "[IMPORTANT]", MessageBoxButtons.OKCancel, MessageBoxIcon.Exclamation);
		}
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_005c_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00f0_Name()
	{
		Invoke((MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
		{
			Recovered_04_00c0_Name.Text = "GSM No Signal Activating";
		}));
		Recovered_06_0126_Name();
		if (DeviceStateRecovered.Recovered_04_0073_Name)
		{
			MessageBox.Show("Please Remove Sim card and Connect Wifi", "[IMPORTANT]", MessageBoxButtons.OKCancel, MessageBoxIcon.Exclamation);
		}
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_005d_Name();
	}

	public void Recovered_06_00f1_Name()
	{
		Invoke((MethodInvoker)([MethodImpl(MethodImplOptions.NoInlining)] () =>
		{
			Recovered_04_00c0_Name.Text = "BrokenBaseband Activating Untethered";
		}));
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_006c_Name();
	}

	public void StartMdmWorkflow()
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.RunMdmBackupRestore();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00f3_Name(int P_0, int P_1)
	{
		string text = Environment.CurrentDirectory + "/vendor/iproxy.exe";
		if ((Recovered_04_009b_Name == null && File.Exists(text)) || Recovered_04_009b_Name.HasExited)
		{
			Recovered_04_009b_Name = new Process();
			Recovered_04_009b_Name.StartInfo.FileName = text;
			Recovered_04_009b_Name.StartInfo.Arguments = P_0 + " " + P_1;
			Recovered_04_009b_Name.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
			Recovered_04_009b_Name.Start();
		}
		else if (File.Exists(text))
		{
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_00f4_Name()
	{
		string result = "";
		try
		{
			Recovered_06_00f5_Name(ApplicationResourcesRecovered.Recovered_17_0005_Name, "/usr/libexec/getserial");
			Recovered_06_00f6_Name("chmod 755 /usr/libexec/getserial");
			SshCommand sshCommand = Recovered_06_00f6_Name("/usr/libexec/getserial");
			result = sshCommand.Result.Replace("Serial:", "").Replace(" ", "").Trim();
		}
		catch (Exception ex)
		{
			File.WriteAllText("error.txt", ex.Message + "\n" + ex.StackTrace);
		}
		return result;
	}

	private void Recovered_06_00f5_Name(byte[] P_0, string P_1)
	{
		throw new NotImplementedException();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public SshCommand Recovered_06_00f6_Name(string P_0)
	{
		if (!Recovered_04_009f_Name.IsConnected)
		{
			Recovered_04_009f_Name.ConnectionInfo.Timeout = TimeSpan.FromSeconds(15.0);
			Recovered_04_009f_Name.Connect();
		}
		try
		{
			SshCommand sshCommand = Recovered_04_009f_Name.CreateCommand(P_0);
			sshCommand.CommandTimeout = TimeSpan.FromSeconds(30.0);
			sshCommand.Execute();
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine("=================");
				Console.WriteLine("Command Name = {0} " + sshCommand.CommandText);
				Console.WriteLine("Return Value = {0}", sshCommand.ExitStatus);
				Console.WriteLine("Error = {0}", sshCommand.Error);
				Console.WriteLine("Result = {0}", sshCommand.Result);
			}
			return sshCommand;
		}
		catch
		{
			if (!(P_0 == "ls") && !(P_0 == "uicache --all"))
			{
				if (DeviceStateRecovered.DiagnosticMode)
				{
					Console.WriteLine("SSH Error caused by:" + P_0);
				}
				else
				{
					Thread.Sleep(2000);
				}
				Recovered_06_00f7_Name();
				Recovered_06_00f6_Name(P_0);
			}
			return null;
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00f7_Name()
	{
		Recovered_06_00f8_Name();
		try
		{
			Process process = new Process
			{
				StartInfo = new ProcessStartInfo
				{
					FileName = Recovered_04_007f_Name + "\\vendor\\iproxy.exe",
					Arguments = Recovered_04_0080_Name + " 44",
					UseShellExecute = false,
					RedirectStandardOutput = true,
					CreateNoWindow = true
				}
			};
			process.Start();
		}
		catch (Win32Exception)
		{
			MessageBox.Show("iproxy not found");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00f8_Name()
	{
		Process[] processesByName = Process.GetProcessesByName("iproxy");
		foreach (Process process in processesByName)
		{
			process.Kill();
		}
		if (File.Exists("%USERPROFILE%\\.ssh\\known_hosts"))
		{
			File.Delete("%USERPROFILE%\\.ssh\\known_hosts");
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public void Recovered_06_00f9_Name(string P_0, int P_1, string P_2)
	{
		AuthenticationMethod[] authenticationMethods = new AuthenticationMethod[1]
		{
			new PasswordAuthenticationMethod("root", P_2)
		};
		ConnectionInfo connectionInfo = new ConnectionInfo(P_0, P_1, "root", authenticationMethods);
		SshClient sshClient = new SshClient(connectionInfo);
		sshClient.Connect();
		sshClient.Disconnect();
	}

	private void Recovered_06_00fa_Name(object P_0, ProgressChangedEventArgs P_1)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		Recovered_04_00b3_Name.Value = P_1.ProgressPercentage;
	}

	private void Recovered_06_00fb_Name(object P_0, RunWorkerCompletedEventArgs P_1)
	{
		Control.CheckForIllegalCrossThreadCalls = false;
		Recovered_04_00b3_Name.Value = 0;
	}

	public void Recovered_06_00fc_Name(int P_0, string P_1)
	{
		Recovered_04_00a2_Name.ReportProgress(P_0);
		if (DeviceStateRecovered.DiagnosticMode)
		{
			Console.WriteLine(P_1);
		}
	}

	private void Recovered_06_00fd_Name(object P_0, EventArgs P_1)
	{
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_00fe_Name(object P_0, PaintEventArgs P_1)
	{
		dynamic val = (Button)P_0;
		dynamic val2 = new SolidBrush(val.ForeColor);
		dynamic val3 = new StringFormat
		{
			Alignment = StringAlignment.Center,
			LineAlignment = StringAlignment.Center
		};
		val2._007CFN_002CxD_002Drg99n_0026_007Df_002A_007DPN1WV_002Fz4();
		val3._007CFN_002CxD_002Drg99n_0026_007Df_002A_007DPN1WV_002Fz4();
	}

	private void Recovered_06_00ff_Name(object P_0, EventArgs P_1)
	{
		try
		{
			if (Recovered_04_009b_Name != null)
			{
				Recovered_04_009b_Name.Kill();
				Recovered_04_009b_Name = null;
			}
			Recovered_06_00e9_Name();
		}
		catch (Exception)
		{
		}
		Environment.Exit(0);
	}

	private void Recovered_06_0100_Name(object P_0, EventArgs P_1)
	{
		base.WindowState = FormWindowState.Minimized;
	}

	private void Recovered_06_0101_Name(object P_0, EventArgs P_1)
	{
	}

	private void Recovered_06_0102_Name(object P_0, MouseEventArgs P_1)
	{
		if (P_1.Button == MouseButtons.Left)
		{
			Recovered_06_00d4_Name();
			Recovered_06_00d3_Name(base.Handle, 161, 2, 0);
		}
	}

	private void Recovered_06_0103_Name(object P_0, MouseEventArgs P_1)
	{
		if (P_1.Button == MouseButtons.Left)
		{
			Recovered_06_00d4_Name();
			Recovered_06_00d3_Name(base.Handle, 161, 2, 0);
		}
	}

	private void Recovered_06_0104_Name(object P_0, MouseEventArgs P_1)
	{
		if (P_1.Button == MouseButtons.Left)
		{
			Recovered_06_00d4_Name();
			Recovered_06_00d3_Name(base.Handle, 161, 2, 0);
		}
	}

	private void Recovered_06_0105_Name(object P_0, MouseEventArgs P_1)
	{
		if (P_1.Button == MouseButtons.Left)
		{
			Recovered_06_00d4_Name();
			Recovered_06_00d3_Name(base.Handle, 161, 2, 0);
		}
	}

	private string Recovered_06_0106_Name(string P_0)
	{
		return Encoding.UTF8.GetString(Convert.FromBase64String(P_0));
	}

	public static string Recovered_06_0107_Name(string P_0)
	{
		byte[] bytes = Encoding.UTF8.GetBytes(P_0);
		return Convert.ToBase64String(bytes);
	}

	private void Recovered_06_0108_Name(object P_0, MouseEventArgs P_1)
	{
		if (P_1.Button == MouseButtons.Left)
		{
			Recovered_06_00d4_Name();
			Recovered_06_00d3_Name(base.Handle, 161, 2, 0);
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string QuerySerialAuthorization()
	{
		try
		{
			string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
			string requestUriString = "http://iservicevn.com/tmgsm/checkSN.php?serialNumber=" + deviceSerialNumber;
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_010a_Name()
	{
		try
		{
			string requestUriString = "http://tm-bypass.iservicevn.com/version.php";
			HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
			httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
			httpWebRequest.Timeout = 12000;
			string result;
			using (HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse())
			{
				using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
				result = streamReader.ReadToEnd();
			}
			return result;
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_010b_Name()
	{
		try
		{
			return "https://iservicevn.com/";
		}
		catch (Exception ex)
		{
			if (DeviceStateRecovered.DiagnosticMode)
			{
				Console.WriteLine(ex.ToString());
			}
			return "CONECTION_ERROR";
		}
	}

	private static void Recovered_06_010c_Name(Action P_0)
	{
		AutoResetEvent Recovered_04_00cc_Name = new AutoResetEvent(initialState: false);
		Thread thread = new Thread((ThreadStart)delegate
		{
			P_0();
			Recovered_04_00cc_Name.Set();
		});
		thread.SetApartmentState(ApartmentState.STA);
		thread.Start();
		Recovered_04_00cc_Name.WaitOne();
	}

	private void Recovered_06_010d_Name(object P_0, EventArgs P_1)
	{
	}

	private void Recovered_06_010e_Name(object P_0, EventArgs P_1)
	{
	}

	private void Recovered_06_010f_Name(object P_0, EventArgs P_1)
	{
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00b4_Name.Enabled = false;
		});
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_0074_Name();
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00b4_Name.Enabled = true;
		});
	}

	public void Recovered_06_0110_Name(object P_0, EventArgs P_1)
	{
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00b5_Name.Enabled = false;
		});
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_007f_Name();
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00b5_Name.Enabled = true;
		});
	}

	private void Recovered_06_0111_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_0089_Name = true;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	private void Recovered_06_0112_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_008a_Name = true;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	private void Recovered_06_0113_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_008b_Name = true;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	private void Recovered_06_0114_Name(object P_0, EventArgs P_1)
	{
		Application.Restart();
	}

	private void Recovered_06_0115_Name(object P_0, PaintEventArgs P_1)
	{
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0116_Name(object P_0, EventArgs P_1)
	{
		Process.Start("https://iservicevn.com");
	}

	private void Recovered_06_0117_Name(object P_0, PaintEventArgs P_1)
	{
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0118_Name(object P_0, LinkLabelLinkClickedEventArgs P_1)
	{
		Process.Start("https://t.me/tmbypassgroup");
	}

	private void Recovered_06_0119_Name(object P_0, EventArgs P_1)
	{
		try
		{
			Recovered_06_00e9_Name();
		}
		catch (Exception)
		{
		}
		Environment.Exit(0);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_011a_Name(object P_0, EventArgs P_1)
	{
		Process.Start("https://iservicevn.com");
	}

	private void Recovered_06_011b_Name(object P_0, EventArgs P_1)
	{
		Recovered_06_010c_Name(delegate
		{
			Clipboard.SetText(DeviceStateRecovered.DeviceSerialNumber);
		});
	}

	private void OnMdmClick(object P_0, EventArgs P_1)
	{
		MdmOperationSelected = true;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	private void Recovered_06_011d_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_008d_Name = true;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	private void Recovered_06_011e_Name(object P_0, EventArgs P_1)
	{
		Recovered_04_008a_Name = false;
		Recovered_04_00a2_Name.RunWorkerAsync();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_011f_Name(object P_0, EventArgs P_1)
	{
		Process.Start("https://telegram.me/tuanraido");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0120_Name(object P_0, EventArgs P_1)
	{
		Process.Start("https://iservicevn.com");
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0121_Name(object P_0, EventArgs P_1)
	{
		Process.Start("https://iservicevn.com");
	}

	private void Recovered_06_0122_Name(object P_0, EventArgs P_1)
	{
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00c6_Name.Enabled = false;
		});
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_0075_Name();
		Invoke((MethodInvoker)delegate
		{
			Recovered_04_00c6_Name.Enabled = true;
		});
	}

	private void Recovered_06_0123_Name(object P_0, EventArgs P_1)
	{
		Recovered_06_0126_Name();
		DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
		deviceOperationsRecovered.Recovered_06_0077_Name();
		Recovered_06_0125_Name();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_0124_Name()
	{
		Recovered_06_00d8_Name();
		string result = "";
		try
		{
			string text = Recovered_06_00f6_Name("ioreg -l | grep IOPlatformSerialNumber --=never").Result.Replace("\"", "").Replace("\t", "").Replace(" ", "")
				.Replace("|IOPlatformSerialNumber=", "")
				.Trim();
			result = ((text.Length > 12) ? text.Remove(0, 13) : text);
		}
		catch
		{
		}
		return result;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0125_Name()
	{
		Recovered_04_00c0_Name.Enabled = true;
		Recovered_04_00b5_Name.Enabled = true;
		Recovered_04_00b6_Name.Enabled = true;
		Recovered_04_00bc_Name.Enabled = true;
		Recovered_04_00b4_Name.Enabled = true;
		Recovered_04_00c6_Name.Enabled = true;
		Recovered_04_00bf_Name.Enabled = true;
		ButtonMdm.Enabled = true;
		Recovered_04_00c8_Name.Enabled = true;
		Recovered_04_00c7_Name.Enabled = true;
		Recovered_04_00c5_Name.Enabled = true;
		Recovered_04_00c0_Name.Text = "iDEVICE ACTIVATE Auto Fix iServices";
	}

	private void Recovered_06_0126_Name()
	{
		Recovered_04_00c0_Name.Enabled = false;
		Recovered_04_00b5_Name.Enabled = false;
		Recovered_04_00b6_Name.Enabled = false;
		Recovered_04_00bc_Name.Enabled = false;
		Recovered_04_00b4_Name.Enabled = false;
		Recovered_04_00c6_Name.Enabled = false;
		Recovered_04_00bf_Name.Enabled = false;
		ButtonMdm.Enabled = false;
		Recovered_04_00c8_Name.Enabled = false;
		Recovered_04_00c7_Name.Enabled = false;
		Recovered_04_00c5_Name.Enabled = false;
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0127_Name()
	{
		string deviceUDID = DeviceStateRecovered.DeviceUDID;
		string contents = "@echo off\nECHO " + deviceUDID + " | vendor\\openssl.exe base64 -d | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A | vendor\\openssl.exe enc -aes-256-ecb -K 3731333437343337373732313741323534333241343632443441363134453634 | vendor\\openssl.exe base64 -A";
		File.WriteAllText(Recovered_04_0090_Name + "/utils/hash.cmd", contents);
		new Process();
		Process process = new Process();
		process.StartInfo = new ProcessStartInfo
		{
			FileName = Recovered_04_0090_Name + "/utils/hash.cmd",
			UseShellExecute = false,
			RedirectStandardOutput = true,
			CreateNoWindow = true
		};
		process.Start();
		string contents2 = process.StandardOutput.ReadToEnd();
		process.WaitForExit();
		File.WriteAllText(Recovered_04_0090_Name + "msys-core.dll", contents2);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	public string Recovered_06_0128_Name()
	{
		string text = Recovered_06_0124_Name();
		HttpWebRequest httpWebRequest = WebRequest.CreateHttp("http://iservicevn.com/tmgsm/checkSN.php?serialNumber=" + text);
		httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
		httpWebRequest.Timeout = 7000;
		using HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
		using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
		return streamReader.ReadToEnd();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void Recovered_06_0129_Name(object P_0, EventArgs P_1)
	{
		Recovered_06_0126_Name();
		Control.CheckForIllegalCrossThreadCalls = false;
		Recovered_06_0127_Name();
		try
		{
			Recovered_04_00aa_Name.Text = Recovered_06_0124_Name();
			string text = Recovered_06_0128_Name();
			text = text.ToString().Replace("\n", "").Replace("\r", "")
				.Replace("\t", "");
			switch (text)
			{
			case "AUTHORIZED":
				if (!Recovered_04_008f_Name)
				{
					DeviceOperationsRecovered deviceOperationsRecovered = new DeviceOperationsRecovered();
					deviceOperationsRecovered.Recovered_06_0076_Name();
				}
				goto default;
			default:
				if (text == "AUTHORIZED" && Recovered_04_008f_Name)
				{
					DeviceOperationsRecovered deviceOperationsRecovered2 = new DeviceOperationsRecovered();
					deviceOperationsRecovered2.Recovered_06_0076_Name();
				}
				break;
			case "NOT_AUTHORIZED":
				MessageBox.Show("Sorry Your iDevice Serial Not Registered", "Check Serial", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				Recovered_06_00fc_Name(0, "Not Authorized Serial");
				Process.Start("https://iservicevn.com/buy.php");
				break;
			case "CONECTION_ERROR":
				MessageBox.Show("Unlock your iDevice and Press Trust!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
				Recovered_06_00fc_Name(0, "DEVICE NOT PAIRED");
				Recovered_04_00c0_Name.Enabled = true;
				break;
			}
		}
		catch (Exception value)
		{
			Console.WriteLine(value);
			MessageBox.Show("Please Re Open Tool and Click USB Patch Again!", "iService VN", MessageBoxButtons.OK, MessageBoxIcon.Hand);
		}
		finally
		{
			Recovered_06_0125_Name();
		}
	}

	protected virtual void _007CFN_002CxD_002Drg99n_0026_007Df_002A_007DPN1WV_002Fz4(bool P_0)
	{
		if (P_0 && Recovered_04_00a1_Name != null)
		{
			Recovered_04_00a1_Name.Dispose();
		}
		Dispose(P_0);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	private void InitializeComponentRecovered()
	{
		ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(MainFormRecovered));
		Recovered_04_00a2_Name = new BackgroundWorker();
		Recovered_04_00a4_Name = new Panel();
		Recovered_04_00c8_Name = new SiticoneGradientButton();
		Recovered_04_00c7_Name = new SiticoneGradientButton();
		Recovered_04_00c6_Name = new SiticoneGradientButton();
		Recovered_04_00c5_Name = new SiticoneGradientButton();
		Recovered_04_00c2_Name = new Label();
		Recovered_04_00c3_Name = new Label();
		ButtonMdm = new SiticoneGradientButton();
		Recovered_04_00bf_Name = new SiticoneGradientButton();
		Recovered_04_00c0_Name = new SiticoneGradientButton();
		Recovered_04_00bd_Name = new SiticoneGradientButton();
		Recovered_04_00bc_Name = new SiticoneGradientButton();
		Recovered_04_00bb_Name = new LinkLabel();
		Recovered_04_00b9_Name = new LinkLabel();
		Recovered_04_00ba_Name = new PictureBox();
		Recovered_04_00b4_Name = new SiticoneGradientButton();
		Recovered_04_00b6_Name = new SiticoneGradientButton();
		Recovered_04_00b5_Name = new SiticoneGradientButton();
		Recovered_04_00b3_Name = new SiticoneProgressBar();
		Recovered_04_00ad_Name = new Label();
		Recovered_04_00a5_Name = new Label();
		Recovered_04_00a6_Name = new Label();
		Recovered_04_00a7_Name = new Label();
		Recovered_04_00a8_Name = new Label();
		Recovered_04_00b1_Name = new Label();
		Recovered_04_00b2_Name = new Label();
		Recovered_04_00a9_Name = new Label();
		Recovered_04_00aa_Name = new Label();
		Recovered_04_00ab_Name = new Label();
		Recovered_04_00ac_Name = new Label();
		Recovered_04_00ae_Name = new Panel();
		Recovered_04_00c4_Name = new Label();
		Recovered_04_00c1_Name = new Label();
		Recovered_04_00af_Name = new SiticoneControlBox();
		Recovered_04_00b0_Name = new SiticoneControlBox();
		Recovered_04_00b7_Name = new SiticoneLabel();
		Recovered_04_00b8_Name = new SiticonePictureBox();
		Recovered_04_00a3_Name = new PictureBox();
		Recovered_04_00a4_Name.SuspendLayout();
		((ISupportInitialize)Recovered_04_00ba_Name).BeginInit();
		Recovered_04_00ae_Name.SuspendLayout();
		((ISupportInitialize)Recovered_04_00b8_Name).BeginInit();
		((ISupportInitialize)Recovered_04_00a3_Name).BeginInit();
		SuspendLayout();
		Recovered_04_00a2_Name.WorkerReportsProgress = true;
		Recovered_04_00a2_Name.WorkerSupportsCancellation = true;
		Recovered_04_00a2_Name.DoWork += DispatchAuthorizedDeviceOperation;
		Recovered_04_00a2_Name.ProgressChanged += Recovered_06_00fa_Name;
		Recovered_04_00a2_Name.RunWorkerCompleted += Recovered_06_00fb_Name;
		Recovered_04_00a4_Name.BackColor = Color.Black;
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c8_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c7_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c6_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c5_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c2_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c3_Name);
		Recovered_04_00a4_Name.Controls.Add(ButtonMdm);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00bf_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00c0_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00bd_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00bc_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00bb_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b9_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00ba_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b4_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b6_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b5_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b3_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00ad_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00a5_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00a6_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00a7_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00a8_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b1_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00b2_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00a9_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00aa_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00ab_Name);
		Recovered_04_00a4_Name.Controls.Add(Recovered_04_00ac_Name);
		Recovered_04_00a4_Name.Font = new Font("Arial", 9f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a4_Name.Location = new Point(-1, 30);
		Recovered_04_00a4_Name.Name = "pnMain";
		Recovered_04_00a4_Name.Size = new Size(587, 327);
		Recovered_04_00a4_Name.TabIndex = 5;
		Recovered_04_00a4_Name.Visible = false;
		Recovered_04_00a4_Name.Paint += Recovered_06_0115_Name;
		Recovered_04_00c8_Name.BackColor = Color.Transparent;
		Recovered_04_00c8_Name.BorderRadius = 5;
		Recovered_04_00c8_Name.CheckedState.Parent = Recovered_04_00c8_Name;
		Recovered_04_00c8_Name.CustomImages.Parent = Recovered_04_00c8_Name;
		Recovered_04_00c8_Name.FillColor = Color.Gold;
		Recovered_04_00c8_Name.FillColor2 = Color.Red;
		Recovered_04_00c8_Name.Font = new Font("Segoe UI", 8.25f);
		Recovered_04_00c8_Name.ForeColor = Color.White;
		Recovered_04_00c8_Name.HoveredState.Parent = Recovered_04_00c8_Name;
		Recovered_04_00c8_Name.Location = new Point(442, 194);
		Recovered_04_00c8_Name.Name = "ButtonReadInfo";
		Recovered_04_00c8_Name.ShadowDecoration.Parent = Recovered_04_00c8_Name;
		Recovered_04_00c8_Name.Size = new Size(106, 25);
		Recovered_04_00c8_Name.TabIndex = 78;
		Recovered_04_00c8_Name.Text = "ID & Number";
		Recovered_04_00c8_Name.UseTransparentBackground = true;
		Recovered_04_00c8_Name.Click += Recovered_06_0123_Name;
		Recovered_04_00c7_Name.BorderRadius = 5;
		Recovered_04_00c7_Name.CheckedState.Parent = Recovered_04_00c7_Name;
		Recovered_04_00c7_Name.CustomImages.Parent = Recovered_04_00c7_Name;
		Recovered_04_00c7_Name.FillColor = Color.Gold;
		Recovered_04_00c7_Name.FillColor2 = Color.Red;
		Recovered_04_00c7_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00c7_Name.ForeColor = Color.White;
		Recovered_04_00c7_Name.HoveredState.Parent = Recovered_04_00c7_Name;
		Recovered_04_00c7_Name.Location = new Point(442, 163);
		Recovered_04_00c7_Name.Name = "ButtonUSBPatch";
		Recovered_04_00c7_Name.ShadowDecoration.Parent = Recovered_04_00c7_Name;
		Recovered_04_00c7_Name.Size = new Size(106, 25);
		Recovered_04_00c7_Name.TabIndex = 77;
		Recovered_04_00c7_Name.Text = "USB Patch";
		Recovered_04_00c7_Name.Click += Recovered_06_0129_Name;
		Recovered_04_00c6_Name.BackColor = Color.Transparent;
		Recovered_04_00c6_Name.BorderRadius = 5;
		Recovered_04_00c6_Name.CheckedState.Parent = Recovered_04_00c6_Name;
		Recovered_04_00c6_Name.CustomImages.Parent = Recovered_04_00c6_Name;
		Recovered_04_00c6_Name.FillColor = Color.Gold;
		Recovered_04_00c6_Name.FillColor2 = Color.Red;
		Recovered_04_00c6_Name.Font = new Font("Segoe UI", 8.25f);
		Recovered_04_00c6_Name.ForeColor = Color.White;
		Recovered_04_00c6_Name.HoveredState.Parent = Recovered_04_00c6_Name;
		Recovered_04_00c6_Name.Location = new Point(442, 256);
		Recovered_04_00c6_Name.Name = "ButtonDiagnostic";
		Recovered_04_00c6_Name.ShadowDecoration.Parent = Recovered_04_00c6_Name;
		Recovered_04_00c6_Name.Size = new Size(106, 25);
		Recovered_04_00c6_Name.TabIndex = 76;
		Recovered_04_00c6_Name.Text = "Diagnostic Eraser";
		Recovered_04_00c6_Name.UseTransparentBackground = true;
		Recovered_04_00c6_Name.Click += Recovered_06_0122_Name;
		Recovered_04_00c5_Name.BorderRadius = 5;
		Recovered_04_00c5_Name.CheckedState.Parent = Recovered_04_00c5_Name;
		Recovered_04_00c5_Name.CustomImages.Parent = Recovered_04_00c5_Name;
		Recovered_04_00c5_Name.FillColor = Color.Red;
		Recovered_04_00c5_Name.FillColor2 = Color.Gold;
		Recovered_04_00c5_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00c5_Name.ForeColor = Color.White;
		Recovered_04_00c5_Name.HoveredState.Parent = Recovered_04_00c5_Name;
		Recovered_04_00c5_Name.Location = new Point(167, 225);
		Recovered_04_00c5_Name.Margin = new Padding(2);
		Recovered_04_00c5_Name.Name = "ButtonCarrierUnlock";
		Recovered_04_00c5_Name.PressedColor = Color.FromArgb(94, 148, 255);
		Recovered_04_00c5_Name.ShadowDecoration.Parent = Recovered_04_00c5_Name;
		Recovered_04_00c5_Name.Size = new Size(123, 25);
		Recovered_04_00c5_Name.TabIndex = 75;
		Recovered_04_00c5_Name.Text = "OpenMenu FMI";
		Recovered_04_00c5_Name.Click += Recovered_06_0113_Name;
		Recovered_04_00c2_Name.AutoSize = true;
		Recovered_04_00c2_Name.BackColor = Color.Transparent;
		Recovered_04_00c2_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00c2_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00c2_Name.ForeColor = Color.White;
		Recovered_04_00c2_Name.Location = new Point(42, 87);
		Recovered_04_00c2_Name.Name = "label12";
		Recovered_04_00c2_Name.Size = new Size(42, 13);
		Recovered_04_00c2_Name.TabIndex = 74;
		Recovered_04_00c2_Name.Text = "Status:";
		Recovered_04_00c2_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00c3_Name.AutoSize = true;
		Recovered_04_00c3_Name.BackColor = Color.Transparent;
		Recovered_04_00c3_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00c3_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00c3_Name.ForeColor = Color.White;
		Recovered_04_00c3_Name.Location = new Point(93, 87);
		Recovered_04_00c3_Name.Name = "labelActivationState";
		Recovered_04_00c3_Name.Size = new Size(26, 13);
		Recovered_04_00c3_Name.TabIndex = 73;
		Recovered_04_00c3_Name.Text = "N/A";
		Recovered_04_00c3_Name.TextAlign = ContentAlignment.TopCenter;
		ButtonMdm.BorderRadius = 5;
		ButtonMdm.CheckedState.Parent = ButtonMdm;
		ButtonMdm.CustomImages.Parent = ButtonMdm;
		ButtonMdm.FillColor = Color.Red;
		ButtonMdm.FillColor2 = Color.Gold;
		ButtonMdm.Font = new Font("Segoe UI", 9f);
		ButtonMdm.ForeColor = Color.White;
		ButtonMdm.HoveredState.Parent = ButtonMdm;
		ButtonMdm.Location = new Point(40, 256);
		ButtonMdm.Margin = new Padding(2);
		ButtonMdm.Name = "ButtonMDM";
		ButtonMdm.PressedColor = Color.FromArgb(94, 148, 255);
		ButtonMdm.ShadowDecoration.Parent = ButtonMdm;
		ButtonMdm.Size = new Size(123, 25);
		ButtonMdm.TabIndex = 72;
		ButtonMdm.Text = "MDM iOS 9 -> 18";
		ButtonMdm.Click += OnMdmClick;
		Recovered_04_00bf_Name.BorderRadius = 5;
		Recovered_04_00bf_Name.CheckedState.Parent = Recovered_04_00bf_Name;
		Recovered_04_00bf_Name.CustomImages.Parent = Recovered_04_00bf_Name;
		Recovered_04_00bf_Name.FillColor = Color.Red;
		Recovered_04_00bf_Name.FillColor2 = Color.Gold;
		Recovered_04_00bf_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00bf_Name.ForeColor = Color.White;
		Recovered_04_00bf_Name.HoveredState.Parent = Recovered_04_00bf_Name;
		Recovered_04_00bf_Name.Location = new Point(167, 256);
		Recovered_04_00bf_Name.Margin = new Padding(2);
		Recovered_04_00bf_Name.Name = "ButtonBroken";
		Recovered_04_00bf_Name.PressedColor = Color.FromArgb(94, 148, 255);
		Recovered_04_00bf_Name.ShadowDecoration.Parent = Recovered_04_00bf_Name;
		Recovered_04_00bf_Name.Size = new Size(123, 25);
		Recovered_04_00bf_Name.TabIndex = 71;
		Recovered_04_00bf_Name.Text = "Broken Baseband";
		Recovered_04_00bf_Name.Click += Recovered_06_011d_Name;
		Recovered_04_00c0_Name.BorderRadius = 5;
		Recovered_04_00c0_Name.CheckedState.Parent = Recovered_04_00c0_Name;
		Recovered_04_00c0_Name.CustomImages.Parent = Recovered_04_00c0_Name;
		Recovered_04_00c0_Name.FillColor = Color.Red;
		Recovered_04_00c0_Name.FillColor2 = Color.Gold;
		Recovered_04_00c0_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00c0_Name.ForeColor = Color.White;
		Recovered_04_00c0_Name.HoveredState.Parent = Recovered_04_00c0_Name;
		Recovered_04_00c0_Name.Location = new Point(40, 180);
		Recovered_04_00c0_Name.Margin = new Padding(2);
		Recovered_04_00c0_Name.Name = "buttonBypass";
		Recovered_04_00c0_Name.PressedColor = Color.FromArgb(94, 148, 255);
		Recovered_04_00c0_Name.ShadowDecoration.Parent = Recovered_04_00c0_Name;
		Recovered_04_00c0_Name.Size = new Size(377, 39);
		Recovered_04_00c0_Name.TabIndex = 68;
		Recovered_04_00c0_Name.Text = "iDEVICE ACTIVATE Auto Fix iServices";
		Recovered_04_00c0_Name.Click += Recovered_06_011e_Name;
		Recovered_04_00bd_Name.BackColor = Color.Transparent;
		Recovered_04_00bd_Name.BorderColor = Color.Transparent;
		Recovered_04_00bd_Name.BorderRadius = 3;
		Recovered_04_00bd_Name.CheckedState.Parent = Recovered_04_00bd_Name;
		Recovered_04_00bd_Name.CustomImages.Parent = Recovered_04_00bd_Name;
		Recovered_04_00bd_Name.FillColor = Color.Transparent;
		Recovered_04_00bd_Name.FillColor2 = Color.Transparent;
		Recovered_04_00bd_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00bd_Name.ForeColor = Color.White;
		Recovered_04_00bd_Name.HoveredState.Parent = Recovered_04_00bd_Name;
		Recovered_04_00bd_Name.Image = (Image)componentResourceManager.GetObject("buttonCopySerial.Image");
		Recovered_04_00bd_Name.Location = new Point(227, 92);
		Recovered_04_00bd_Name.Margin = new Padding(2);
		Recovered_04_00bd_Name.Name = "buttonCopySerial";
		Recovered_04_00bd_Name.PressedColor = Color.FromArgb(94, 148, 255);
		Recovered_04_00bd_Name.ShadowDecoration.Parent = Recovered_04_00bd_Name;
		Recovered_04_00bd_Name.Size = new Size(37, 42);
		Recovered_04_00bd_Name.TabIndex = 70;
		Recovered_04_00bd_Name.Click += Recovered_06_011b_Name;
		Recovered_04_00bc_Name.BorderRadius = 5;
		Recovered_04_00bc_Name.CheckedState.Parent = Recovered_04_00bc_Name;
		Recovered_04_00bc_Name.CustomImages.Parent = Recovered_04_00bc_Name;
		Recovered_04_00bc_Name.FillColor = Color.Red;
		Recovered_04_00bc_Name.FillColor2 = Color.Gold;
		Recovered_04_00bc_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00bc_Name.ForeColor = Color.White;
		Recovered_04_00bc_Name.HoveredState.Parent = Recovered_04_00bc_Name;
		Recovered_04_00bc_Name.Location = new Point(40, 225);
		Recovered_04_00bc_Name.Margin = new Padding(2);
		Recovered_04_00bc_Name.Name = "ButtonFixiServices";
		Recovered_04_00bc_Name.PressedColor = Color.FromArgb(94, 148, 255);
		Recovered_04_00bc_Name.ShadowDecoration.Parent = Recovered_04_00bc_Name;
		Recovered_04_00bc_Name.Size = new Size(123, 25);
		Recovered_04_00bc_Name.TabIndex = 69;
		Recovered_04_00bc_Name.Text = "Fix iServices";
		Recovered_04_00bc_Name.Click += Recovered_06_0112_Name;
		Recovered_04_00bb_Name.AutoSize = true;
		Recovered_04_00bb_Name.BackColor = Color.Transparent;
		Recovered_04_00bb_Name.DisabledLinkColor = Color.White;
		Recovered_04_00bb_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00bb_Name.LinkColor = Color.White;
		Recovered_04_00bb_Name.Location = new Point(407, 115);
		Recovered_04_00bb_Name.Margin = new Padding(2, 0, 2, 0);
		Recovered_04_00bb_Name.Name = "linkLabel1";
		Recovered_04_00bb_Name.Size = new Size(123, 13);
		Recovered_04_00bb_Name.TabIndex = 68;
		Recovered_04_00bb_Name.TabStop = true;
		Recovered_04_00bb_Name.Text = "https://iservicevn.com";
		Recovered_04_00bb_Name.VisitedLinkColor = Color.Silver;
		Recovered_04_00bb_Name.LinkClicked += Recovered_06_011a_Name;
		Recovered_04_00b9_Name.AutoSize = true;
		Recovered_04_00b9_Name.BackColor = Color.Transparent;
		Recovered_04_00b9_Name.DisabledLinkColor = Color.White;
		Recovered_04_00b9_Name.Font = new Font("Segoe UI", 9f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00b9_Name.LinkColor = Color.White;
		Recovered_04_00b9_Name.Location = new Point(380, 128);
		Recovered_04_00b9_Name.Margin = new Padding(2, 0, 2, 0);
		Recovered_04_00b9_Name.Name = "linkLabelTwiter";
		Recovered_04_00b9_Name.Size = new Size(170, 15);
		Recovered_04_00b9_Name.TabIndex = 65;
		Recovered_04_00b9_Name.TabStop = true;
		Recovered_04_00b9_Name.Text = "Join Telegram Support Group";
		Recovered_04_00b9_Name.VisitedLinkColor = Color.Silver;
		Recovered_04_00b9_Name.LinkClicked += Recovered_06_0118_Name;
		Recovered_04_00ba_Name.BackColor = Color.Transparent;
		Recovered_04_00ba_Name.Image = (Image)componentResourceManager.GetObject("pictureBox4.Image");
		Recovered_04_00ba_Name.Location = new Point(378, 15);
		Recovered_04_00ba_Name.Margin = new Padding(2);
		Recovered_04_00ba_Name.Name = "pictureBox4";
		Recovered_04_00ba_Name.Size = new Size(174, 98);
		Recovered_04_00ba_Name.SizeMode = PictureBoxSizeMode.Zoom;
		Recovered_04_00ba_Name.TabIndex = 64;
		Recovered_04_00ba_Name.TabStop = false;
		Recovered_04_00ba_Name.Click += Recovered_06_0121_Name;
		Recovered_04_00b4_Name.BackColor = Color.Transparent;
		Recovered_04_00b4_Name.BorderRadius = 5;
		Recovered_04_00b4_Name.CheckedState.Parent = Recovered_04_00b4_Name;
		Recovered_04_00b4_Name.CustomImages.Parent = Recovered_04_00b4_Name;
		Recovered_04_00b4_Name.FillColor = Color.Gold;
		Recovered_04_00b4_Name.FillColor2 = Color.Red;
		Recovered_04_00b4_Name.Font = new Font("Segoe UI", 8.25f);
		Recovered_04_00b4_Name.ForeColor = Color.White;
		Recovered_04_00b4_Name.HoveredState.Parent = Recovered_04_00b4_Name;
		Recovered_04_00b4_Name.Location = new Point(442, 225);
		Recovered_04_00b4_Name.Name = "ButtonErase";
		Recovered_04_00b4_Name.ShadowDecoration.Parent = Recovered_04_00b4_Name;
		Recovered_04_00b4_Name.Size = new Size(106, 25);
		Recovered_04_00b4_Name.TabIndex = 8;
		Recovered_04_00b4_Name.Text = "Erase All Data  ";
		Recovered_04_00b4_Name.UseTransparentBackground = true;
		Recovered_04_00b4_Name.Click += Recovered_06_010f_Name;
		Recovered_04_00b6_Name.BorderRadius = 5;
		Recovered_04_00b6_Name.CheckedState.Parent = Recovered_04_00b6_Name;
		Recovered_04_00b6_Name.CustomImages.Parent = Recovered_04_00b6_Name;
		Recovered_04_00b6_Name.FillColor = Color.Gold;
		Recovered_04_00b6_Name.FillColor2 = Color.Red;
		Recovered_04_00b6_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00b6_Name.ForeColor = Color.White;
		Recovered_04_00b6_Name.HoveredState.Parent = Recovered_04_00b6_Name;
		Recovered_04_00b6_Name.Location = new Point(294, 256);
		Recovered_04_00b6_Name.Name = "ButtonActivate";
		Recovered_04_00b6_Name.ShadowDecoration.Parent = Recovered_04_00b6_Name;
		Recovered_04_00b6_Name.Size = new Size(123, 25);
		Recovered_04_00b6_Name.TabIndex = 11;
		Recovered_04_00b6_Name.Text = "ReActive iDevice";
		Recovered_04_00b6_Name.Click += Recovered_06_0111_Name;
		Recovered_04_00b5_Name.BorderRadius = 5;
		Recovered_04_00b5_Name.CheckedState.Parent = Recovered_04_00b5_Name;
		Recovered_04_00b5_Name.CustomImages.Parent = Recovered_04_00b5_Name;
		Recovered_04_00b5_Name.FillColor = Color.Gold;
		Recovered_04_00b5_Name.FillColor2 = Color.Red;
		Recovered_04_00b5_Name.Font = new Font("Segoe UI", 9f);
		Recovered_04_00b5_Name.ForeColor = Color.White;
		Recovered_04_00b5_Name.HoveredState.Parent = Recovered_04_00b5_Name;
		Recovered_04_00b5_Name.Location = new Point(294, 225);
		Recovered_04_00b5_Name.Name = "ButtonBackup";
		Recovered_04_00b5_Name.ShadowDecoration.Parent = Recovered_04_00b5_Name;
		Recovered_04_00b5_Name.Size = new Size(123, 25);
		Recovered_04_00b5_Name.TabIndex = 9;
		Recovered_04_00b5_Name.Text = "iDevice Backup";
		Recovered_04_00b5_Name.Click += Recovered_06_0110_Name;
		Recovered_04_00b3_Name.BorderRadius = 5;
		Recovered_04_00b3_Name.FillColor = Color.Gray;
		Recovered_04_00b3_Name.GradientMode = LinearGradientMode.Horizontal;
		Recovered_04_00b3_Name.Location = new Point(40, 294);
		Recovered_04_00b3_Name.Name = "progressBar1";
		Recovered_04_00b3_Name.ProgressColor = Color.Gold;
		Recovered_04_00b3_Name.ProgressColor2 = Color.Red;
		Recovered_04_00b3_Name.ShadowDecoration.Parent = Recovered_04_00b3_Name;
		Recovered_04_00b3_Name.Size = new Size(510, 12);
		Recovered_04_00b3_Name.TabIndex = 57;
		Recovered_04_00b3_Name.TextRenderingHint = TextRenderingHint.SystemDefault;
		Recovered_04_00ad_Name.AutoSize = true;
		Recovered_04_00ad_Name.BackColor = Color.Transparent;
		Recovered_04_00ad_Name.Font = new Font("Arial", 9.75f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00ad_Name.ForeColor = Color.White;
		Recovered_04_00ad_Name.Location = new Point(37, 19);
		Recovered_04_00ad_Name.Name = "lblStatus";
		Recovered_04_00ad_Name.Size = new Size(131, 16);
		Recovered_04_00ad_Name.TabIndex = 44;
		Recovered_04_00ad_Name.Text = "iDevice Information";
		Recovered_04_00a5_Name.AutoSize = true;
		Recovered_04_00a5_Name.BackColor = Color.Transparent;
		Recovered_04_00a5_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00a5_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a5_Name.ForeColor = Color.White;
		Recovered_04_00a5_Name.Location = new Point(79, 130);
		Recovered_04_00a5_Name.Name = "labelImei";
		Recovered_04_00a5_Name.Size = new Size(26, 13);
		Recovered_04_00a5_Name.TabIndex = 10;
		Recovered_04_00a5_Name.Text = "N/A";
		Recovered_04_00a5_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00a5_Name.Click += Recovered_06_010e_Name;
		Recovered_04_00a6_Name.AutoSize = true;
		Recovered_04_00a6_Name.BackColor = Color.Transparent;
		Recovered_04_00a6_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00a6_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a6_Name.ForeColor = Color.White;
		Recovered_04_00a6_Name.Location = new Point(41, 130);
		Recovered_04_00a6_Name.Name = "label3";
		Recovered_04_00a6_Name.Size = new Size(32, 13);
		Recovered_04_00a6_Name.TabIndex = 9;
		Recovered_04_00a6_Name.Text = "IMEI:";
		Recovered_04_00a6_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00a7_Name.AutoSize = true;
		Recovered_04_00a7_Name.BackColor = Color.Transparent;
		Recovered_04_00a7_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00a7_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a7_Name.ForeColor = Color.White;
		Recovered_04_00a7_Name.Location = new Point(41, 45);
		Recovered_04_00a7_Name.Name = "label6";
		Recovered_04_00a7_Name.Size = new Size(43, 13);
		Recovered_04_00a7_Name.TabIndex = 16;
		Recovered_04_00a7_Name.Text = "Model:";
		Recovered_04_00a7_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00a8_Name.AutoSize = true;
		Recovered_04_00a8_Name.BackColor = Color.Transparent;
		Recovered_04_00a8_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00a8_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a8_Name.ForeColor = Color.White;
		Recovered_04_00a8_Name.Location = new Point(41, 67);
		Recovered_04_00a8_Name.Name = "label5";
		Recovered_04_00a8_Name.Size = new Size(69, 13);
		Recovered_04_00a8_Name.TabIndex = 14;
		Recovered_04_00a8_Name.Text = "iOS Version:";
		Recovered_04_00a8_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00b1_Name.AutoSize = true;
		Recovered_04_00b1_Name.BackColor = Color.Transparent;
		Recovered_04_00b1_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00b1_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00b1_Name.ForeColor = Color.White;
		Recovered_04_00b1_Name.Location = new Point(84, 152);
		Recovered_04_00b1_Name.Name = "labelUDID";
		Recovered_04_00b1_Name.Size = new Size(26, 13);
		Recovered_04_00b1_Name.TabIndex = 13;
		Recovered_04_00b1_Name.Text = "N/A";
		Recovered_04_00b1_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00b2_Name.AutoSize = true;
		Recovered_04_00b2_Name.BackColor = Color.Transparent;
		Recovered_04_00b2_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00b2_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00b2_Name.ForeColor = Color.White;
		Recovered_04_00b2_Name.Location = new Point(41, 152);
		Recovered_04_00b2_Name.Name = "label4";
		Recovered_04_00b2_Name.Size = new Size(37, 13);
		Recovered_04_00b2_Name.TabIndex = 12;
		Recovered_04_00b2_Name.Text = "UDID:";
		Recovered_04_00b2_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00a9_Name.AutoSize = true;
		Recovered_04_00a9_Name.BackColor = Color.Transparent;
		Recovered_04_00a9_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00a9_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00a9_Name.ForeColor = Color.White;
		Recovered_04_00a9_Name.Location = new Point(42, 108);
		Recovered_04_00a9_Name.Name = "label2";
		Recovered_04_00a9_Name.Size = new Size(82, 13);
		Recovered_04_00a9_Name.TabIndex = 11;
		Recovered_04_00a9_Name.Text = "Serial Number:";
		Recovered_04_00a9_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00aa_Name.AutoSize = true;
		Recovered_04_00aa_Name.BackColor = Color.Transparent;
		Recovered_04_00aa_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00aa_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00aa_Name.ForeColor = Color.White;
		Recovered_04_00aa_Name.Location = new Point(130, 108);
		Recovered_04_00aa_Name.Name = "labelSerial";
		Recovered_04_00aa_Name.Size = new Size(26, 13);
		Recovered_04_00aa_Name.TabIndex = 8;
		Recovered_04_00aa_Name.Text = "N/A";
		Recovered_04_00aa_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00ab_Name.AutoSize = true;
		Recovered_04_00ab_Name.BackColor = Color.Transparent;
		Recovered_04_00ab_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00ab_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00ab_Name.ForeColor = Color.White;
		Recovered_04_00ab_Name.Location = new Point(90, 45);
		Recovered_04_00ab_Name.Name = "labelModel1";
		Recovered_04_00ab_Name.Size = new Size(26, 13);
		Recovered_04_00ab_Name.TabIndex = 17;
		Recovered_04_00ab_Name.Text = "N/A";
		Recovered_04_00ab_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00ac_Name.AutoSize = true;
		Recovered_04_00ac_Name.BackColor = Color.Transparent;
		Recovered_04_00ac_Name.FlatStyle = FlatStyle.Flat;
		Recovered_04_00ac_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
		Recovered_04_00ac_Name.ForeColor = Color.White;
		Recovered_04_00ac_Name.Location = new Point(116, 67);
		Recovered_04_00ac_Name.Name = "labelVersion";
		Recovered_04_00ac_Name.Size = new Size(29, 13);
		Recovered_04_00ac_Name.TabIndex = 15;
		Recovered_04_00ac_Name.Text = "N/A ";
		Recovered_04_00ac_Name.TextAlign = ContentAlignment.TopCenter;
		Recovered_04_00ae_Name.BackColor = Color.Black;
		Recovered_04_00ae_Name.Controls.Add(Recovered_04_00c4_Name);
		Recovered_04_00ae_Name.Controls.Add(Recovered_04_00c1_Name);
		Recovered_04_00ae_Name.Controls.Add(Recovered_04_00af_Name);
		Recovered_04_00ae_Name.Controls.Add(Recovered_04_00b0_Name);
		Recovered_04_00ae_Name.Location = new Point(-1, -3);
		Recovered_04_00ae_Name.Margin = new Padding(2);
		Recovered_04_00ae_Name.Name = "panel2";
		Recovered_04_00ae_Name.Size = new Size(590, 38);
		Recovered_04_00ae_Name.TabIndex = 23;
		Recovered_04_00ae_Name.Paint += Recovered_06_0117_Name;
		Recovered_04_00ae_Name.MouseDown += Recovered_06_0102_Name;
		Recovered_04_00c4_Name.AutoSize = true;
		Recovered_04_00c4_Name.Font = new Font("Segoe UI", 14.25f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00c4_Name.ForeColor = Color.White;
		Recovered_04_00c4_Name.Location = new Point(32, 10);
		Recovered_04_00c4_Name.Margin = new Padding(2, 0, 2, 0);
		Recovered_04_00c4_Name.Name = "ToolName";
		Recovered_04_00c4_Name.Size = new Size(161, 25);
		Recovered_04_00c4_Name.TabIndex = 68;
		Recovered_04_00c4_Name.Text = "TM-BYPASS v4.0";
		Recovered_04_00c4_Name.Click += Recovered_06_0120_Name;
		Recovered_04_00c1_Name.AutoSize = true;
		Recovered_04_00c1_Name.Font = new Font("Segoe UI", 8.25f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00c1_Name.ForeColor = Color.White;
		Recovered_04_00c1_Name.Location = new Point(422, 19);
		Recovered_04_00c1_Name.Margin = new Padding(2, 0, 2, 0);
		Recovered_04_00c1_Name.Name = "Developer";
		Recovered_04_00c1_Name.Size = new Size(86, 13);
		Recovered_04_00c1_Name.TabIndex = 63;
		Recovered_04_00c1_Name.Text = "© Tuấn Raido™";
		Recovered_04_00c1_Name.Click += Recovered_06_011f_Name;
		Recovered_04_00af_Name.Anchor = AnchorStyles.Top | AnchorStyles.Right;
		Recovered_04_00af_Name.BackColor = Color.Transparent;
		Recovered_04_00af_Name.ControlBoxType = ControlBoxType.MinimizeBox;
		Recovered_04_00af_Name.FillColor = Color.Transparent;
		Recovered_04_00af_Name.HoveredState.Parent = Recovered_04_00af_Name;
		Recovered_04_00af_Name.IconColor = Color.White;
		Recovered_04_00af_Name.Location = new Point(527, 3);
		Recovered_04_00af_Name.Name = "siticoneControlBox2";
		Recovered_04_00af_Name.ShadowDecoration.Parent = Recovered_04_00af_Name;
		Recovered_04_00af_Name.Size = new Size(23, 29);
		Recovered_04_00af_Name.TabIndex = 53;
		Recovered_04_00af_Name.Click += Recovered_06_010d_Name;
		Recovered_04_00b0_Name.Anchor = AnchorStyles.Top | AnchorStyles.Right;
		Recovered_04_00b0_Name.BackColor = Color.Transparent;
		Recovered_04_00b0_Name.FillColor = Color.Transparent;
		Recovered_04_00b0_Name.HoveredState.Parent = Recovered_04_00b0_Name;
		Recovered_04_00b0_Name.IconColor = Color.White;
		Recovered_04_00b0_Name.Location = new Point(552, 3);
		Recovered_04_00b0_Name.Name = "siticoneControlBox1";
		Recovered_04_00b0_Name.ShadowDecoration.Parent = Recovered_04_00b0_Name;
		Recovered_04_00b0_Name.Size = new Size(21, 29);
		Recovered_04_00b0_Name.TabIndex = 0;
		Recovered_04_00b0_Name.Click += Recovered_06_0119_Name;
		Recovered_04_00b7_Name.BackColor = Color.Black;
		Recovered_04_00b7_Name.Font = new Font("Comic Sans MS", 14.25f, FontStyle.Bold, GraphicsUnit.Point, 0);
		Recovered_04_00b7_Name.ForeColor = Color.White;
		Recovered_04_00b7_Name.Location = new Point(92, 289);
		Recovered_04_00b7_Name.Name = "siticoneLabel11";
		Recovered_04_00b7_Name.Size = new Size(398, 29);
		Recovered_04_00b7_Name.TabIndex = 61;
		Recovered_04_00b7_Name.Text = "Please Connect your iDevice to PC via USB";
		Recovered_04_00b8_Name.BackColor = Color.Black;
		Recovered_04_00b8_Name.Image = (Image)componentResourceManager.GetObject("siticonePictureBox2.Image");
		Recovered_04_00b8_Name.Location = new Point(89, 36);
		Recovered_04_00b8_Name.Name = "siticonePictureBox2";
		Recovered_04_00b8_Name.ShadowDecoration.Parent = Recovered_04_00b8_Name;
		Recovered_04_00b8_Name.Size = new Size(398, 253);
		Recovered_04_00b8_Name.SizeMode = PictureBoxSizeMode.Zoom;
		Recovered_04_00b8_Name.TabIndex = 62;
		Recovered_04_00b8_Name.TabStop = false;
		Recovered_04_00a3_Name.BackColor = Color.Black;
		Recovered_04_00a3_Name.Location = new Point(-1, 30);
		Recovered_04_00a3_Name.Margin = new Padding(2);
		Recovered_04_00a3_Name.Name = "pbWait";
		Recovered_04_00a3_Name.Size = new Size(590, 327);
		Recovered_04_00a3_Name.SizeMode = PictureBoxSizeMode.StretchImage;
		Recovered_04_00a3_Name.TabIndex = 26;
		Recovered_04_00a3_Name.TabStop = false;
		Recovered_04_00a3_Name.Click += Recovered_06_0101_Name;
		base.AutoScaleDimensions = new SizeF(96f, 96f);
		base.AutoScaleMode = AutoScaleMode.Dpi;
		BackColor = Color.FromArgb(50, 50, 50);
		base.ClientSize = new Size(584, 355);
		base.Controls.Add(Recovered_04_00a4_Name);
		base.Controls.Add(Recovered_04_00b8_Name);
		base.Controls.Add(Recovered_04_00b7_Name);
		base.Controls.Add(Recovered_04_00a3_Name);
		base.Controls.Add(Recovered_04_00ae_Name);
		base.FormBorderStyle = FormBorderStyle.None;
		base.Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
		base.ImeMode = ImeMode.Off;
		base.MaximizeBox = false;
		base.Name = "MainForm";
		base.StartPosition = FormStartPosition.CenterScreen;
		Text = "TM-BYPASS AIO | iService VN";
		base.Load += Recovered_06_00e7_Name;
		Recovered_04_00a4_Name.ResumeLayout(performLayout: false);
		Recovered_04_00a4_Name.PerformLayout();
		((ISupportInitialize)Recovered_04_00ba_Name).EndInit();
		Recovered_04_00ae_Name.ResumeLayout(performLayout: false);
		Recovered_04_00ae_Name.PerformLayout();
		((ISupportInitialize)Recovered_04_00b8_Name).EndInit();
		((ISupportInitialize)Recovered_04_00a3_Name).EndInit();
		ResumeLayout(performLayout: false);
		PerformLayout();
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	[CompilerGenerated]
	private void Recovered_06_012d_Name()
	{
		Recovered_04_00c0_Name.Text = "GSM with Signal Activating";
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	[CompilerGenerated]
	private void Recovered_06_012e_Name()
	{
		Recovered_04_00c0_Name.Text = "MEID No Signal Activating";
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	[CompilerGenerated]
	private void Recovered_06_012f_Name()
	{
		Recovered_04_00c0_Name.Text = "GSM No Signal Activating";
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	[CompilerGenerated]
	private void Recovered_06_0130_Name()
	{
		Recovered_04_00c0_Name.Text = "BrokenBaseband Activating Untethered";
	}

	[CompilerGenerated]
	private void Recovered_06_0131_Name()
	{
		Recovered_04_00b4_Name.Enabled = false;
	}

	[CompilerGenerated]
	private void Recovered_06_0132_Name()
	{
		Recovered_04_00b4_Name.Enabled = true;
	}

	[CompilerGenerated]
	private void Recovered_06_0133_Name()
	{
		Recovered_04_00b5_Name.Enabled = false;
	}

	[CompilerGenerated]
	private void Recovered_06_0134_Name()
	{
		Recovered_04_00b5_Name.Enabled = true;
	}

	[CompilerGenerated]
	private void Recovered_06_0135_Name()
	{
		Recovered_04_00c6_Name.Enabled = false;
	}

	[CompilerGenerated]
	private void Recovered_06_0136_Name()
	{
		Recovered_04_00c6_Name.Enabled = true;
	}
}
