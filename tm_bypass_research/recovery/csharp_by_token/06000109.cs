// Recovered from method token 0x06000109; analyst names; not the original source.
using System;
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;

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
