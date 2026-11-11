// Recovered from method token 0x06000128; analyst names; not the original source.
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;

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
