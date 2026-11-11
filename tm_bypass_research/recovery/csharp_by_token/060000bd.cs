// Recovered from method token 0x060000bd; analyst names; not the original source.
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;

[MethodImpl(MethodImplOptions.NoInlining)]
public string Recovered_06_00bd_Name()
{
	string requestUriString = "http://iservicevn.com/tmgsm/getfilesact.php?serial=" + DeviceStateRecovered.DeviceSerialNumber;
	HttpWebRequest httpWebRequest = WebRequest.CreateHttp(requestUriString);
	httpWebRequest.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;
	httpWebRequest.Timeout = 18000;
	using HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
	using StreamReader streamReader = new StreamReader(httpWebResponse.GetResponseStream());
	return streamReader.ReadToEnd();
}
