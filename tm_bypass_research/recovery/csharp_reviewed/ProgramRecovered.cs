using System;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using System.Windows.Forms;

internal static class ProgramRecovered
{
	[CompilerGenerated]
	private sealed class Recovered_02_000e_TypeName
	{
		public AntiAnalysisMonitorRecovered Recovered_04_002e_Name;

		internal void Recovered_06_0043_Name()
		{
			Recovered_04_002e_Name.StartAntiAnalysisMonitor();
		}
	}

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
}
