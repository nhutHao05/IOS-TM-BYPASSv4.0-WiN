// Recovered from method token 0x06000041; analyst names; not the original source.
using System;
using System.Threading.Tasks;
using System.Windows.Forms;

[STAThread]
private static void MainRecovered()
{
	AntiAnalysisMonitorRecovered Recovered_04_002e_Name = new AntiAnalysisMonitorRecovered();
	Task.Run(delegate
	{
		Recovered_04_002e_Name.StartAntiAnalysisMonitor();
	});
	Application.EnableVisualStyles();
	Application.SetCompatibleTextRenderingDefault(defaultValue: false);
	Application.Run(new MainFormRecovered());
}
