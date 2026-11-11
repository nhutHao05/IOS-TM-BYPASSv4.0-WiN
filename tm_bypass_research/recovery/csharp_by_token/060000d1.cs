// Recovered from method token 0x060000d1; analyst names; not the original source.
using System;
using System.Diagnostics;
using System.Runtime.CompilerServices;
using System.Threading;

[MethodImpl(MethodImplOptions.NoInlining)]
internal void AntiAnalysisMonitorLoop(object P_0)
{
	string[] array = new string[96];
	array[0] = "codecracker";
	array[1] = "x32dbg";
	array[2] = "x64dbg";
	array[3] = "charles";
	array[4] = "dnspy";
	array[5] = "simpleassembly";
	array[6] = "peek";
	array[7] = "httpanalyzer";
	array[8] = "wireshark";
	array[9] = "devirt";
	array[10] = "logger";
	array[11] = "usbtrace";
	array[12] = "usbmonitor";
	array[13] = "serialmonitor";
	array[14] = "ilspy";
	array[15] = "charlesproxy";
	array[16] = "fiddler";
	array[17] = "extremedumper";
	array[18] = "megadumper";
	array[19] = "x64netdumper";
	array[20] = "dumper";
	array[21] = "dump";
	array[22] = "ollydbg ";
	array[23] = "softice";
	array[24] = "dotpeek";
	array[25] = "cheat engine";
	array[26] = "cheatengine";
	array[27] = "scylla";
	array[28] = "scylla_x64";
	array[29] = "scylla_x86";
	array[30] = "protection_id";
	array[31] = "reshacker";
	array[32] = "ImportREC";
	array[33] = "de4dot";
	array[34] = "disassembly";
	array[35] = "Import reconstructor";
	array[36] = "debug";
	array[37] = "debugger";
	array[38] = "httpdebug";
	array[39] = "httpdebug";
	array[40] = "immunitydebugger";
	array[41] = "immunity";
	array[42] = "debug";
	array[43] = "petool";
	array[44] = "petools";
	array[45] = "PE Tools";
	array[46] = "ida";
	array[47] = "ida64";
	array[48] = "idag";
	array[49] = "idag64";
	array[50] = "idaw";
	array[51] = "idaw64";
	array[52] = "idaq";
	array[53] = "idaq64";
	array[54] = "idau";
	array[55] = "idau64";
	array[56] = "idag";
	array[57] = "idaq";
	array[58] = "windbg";
	array[59] = "[CPU";
	array[60] = "simpleassembly";
	array[61] = "postman";
	array[62] = "softice";
	array[63] = "jetbrains";
	array[64] = "Resource Monitor";
	array[65] = "Resource";
	array[66] = "Resource and Performancer Monitor";
	array[67] = "Suspend Process";
	array[68] = "processhacker";
	array[69] = "Process Hacker";
	array[70] = "perfmon";
	array[71] = "valgrind";
	array[72] = "SIMMON";
	array[73] = "Rational Purify";
	array[74] = "Memcheck";
	array[75] = "Disassembler";
	array[76] = "parasoft";
	array[77] = "Dr. Memory";
	array[78] = "WinHex";
	array[79] = "Analyze It";
	array[80] = "Hook Analyzer";
	array[81] = "Process Explorer";
	array[82] = "procmon64";
	array[83] = "scylla";
	array[84] = "de4dotmodded";
	array[85] = "protection_id";
	array[86] = "x96dbg";
	array[87] = "process hacker";
	array[88] = "process monitor";
	array[89] = "qt5core";
	array[90] = "dbgclr";
	array[91] = "hxd";
	array[92] = "import reconstructor";
	array[93] = "Trw2000";
	array[94] = "Winpdb";
	array[95] = "procdump";
	string[] array2 = array;
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
				for (int j = 0; j < array2.Length; j++)
				{
					int id = Process.GetCurrentProcess().Id;
					if (process.ProcessName.ToLower().Contains(array2[j]) && !DeviceStateRecovered.DiagnosticMode)
					{
						Process.GetCurrentProcess().Kill();
					}
					if (process.MainWindowTitle.ToLower().Contains(array2[j]) && !DeviceStateRecovered.DiagnosticMode)
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
