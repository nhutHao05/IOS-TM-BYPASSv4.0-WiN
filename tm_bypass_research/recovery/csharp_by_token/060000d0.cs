// Recovered from method token 0x060000d0; analyst names; not the original source.
using System.Threading;

internal void StartAntiAnalysisMonitor()
{
	new Thread(AntiAnalysisMonitorLoop).Start(Thread.CurrentThread);
}
