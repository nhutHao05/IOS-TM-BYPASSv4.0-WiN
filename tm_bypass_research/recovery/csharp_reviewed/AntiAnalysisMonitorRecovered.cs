using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;

internal sealed class AntiAnalysisMonitorRecovered
{
	[DllImport("kernel32.dll", EntryPoint = "CheckRemoteDebuggerPresent", ExactSpelling = true, SetLastError = true)]
	private static extern bool CheckRemoteDebuggerPresentRecovered(IntPtr P_0, ref bool P_1);

	internal void StartAntiAnalysisMonitor()
	{
		new Thread(AntiAnalysisMonitorLoop).Start(Thread.CurrentThread);
	}

	[MethodImpl(MethodImplOptions.NoInlining)]
	internal void AntiAnalysisMonitorLoop(object P_0)
	{
		string[] array = new string[96]
		{
			"codecracker", "x32dbg", "x64dbg", "charles", "dnspy", "simpleassembly", "peek", "httpanalyzer", "wireshark", "devirt",
			"logger", "usbtrace", "usbmonitor", "serialmonitor", "ilspy", "charlesproxy", "fiddler", "extremedumper", "megadumper", "x64netdumper",
			"dumper", "dump", "ollydbg ", "softice", "dotpeek", "cheat engine", "cheatengine", "scylla", "scylla_x64", "scylla_x86",
			"protection_id", "reshacker", "ImportREC", "de4dot", "disassembly", "Import reconstructor", "debug", "debugger", "httpdebug", "httpdebug",
			"immunitydebugger", "immunity", "debug", "petool", "petools", "PE Tools", "ida", "ida64", "idag", "idag64",
			"idaw", "idaw64", "idaq", "idaq64", "idau", "idau64", "idag", "idaq", "windbg", "[CPU",
			"simpleassembly", "postman", "softice", "jetbrains", "Resource Monitor", "Resource", "Resource and Performancer Monitor", "Suspend Process", "processhacker", "Process Hacker",
			"perfmon", "valgrind", "SIMMON", "Rational Purify", "Memcheck", "Disassembler", "parasoft", "Dr. Memory", "WinHex", "Analyze It",
			"Hook Analyzer", "Process Explorer", "procmon64", "scylla", "de4dotmodded", "protection_id", "x96dbg", "process hacker", "process monitor", "qt5core",
			"dbgclr", "hxd", "import reconstructor", "Trw2000", "Winpdb", "procdump"
		};
		while (true)
		{
			try
			{
				if (!DeviceStateRecovered.DiagnosticMode)
				{
					if (Debugger.IsAttached)
					{
						Process.GetCurrentProcess().Kill();
					}
					bool flag = false;
					CheckRemoteDebuggerPresentRecovered(Process.GetCurrentProcess().Handle, ref flag);
					if (flag)
					{
						Process.GetCurrentProcess().Kill();
					}
				}
				Process[] processes = Process.GetProcesses();
				foreach (Process process in processes)
				{
					if (process == Process.GetCurrentProcess())
					{
						continue;
					}
					for (int j = 0; j < array.Length; j++)
					{
						int id = Process.GetCurrentProcess().Id;
						if (process.ProcessName.ToLower().Contains(array[j]) && !DeviceStateRecovered.DiagnosticMode)
						{
							Process.GetCurrentProcess().Kill();
						}
						if (process.MainWindowTitle.ToLower().Contains(array[j]) && !DeviceStateRecovered.DiagnosticMode)
						{
							Process.GetCurrentProcess().Kill();
						}
					}
				}
			}
			catch (Exception)
			{
			}
			Thread.Sleep(1000);
		}
	}
}
