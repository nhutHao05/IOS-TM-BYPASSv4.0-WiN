// Recovered from method token 0x0600006b; analyst names; not the original source.
using System;
using System.IO;
using System.Net;
using System.Runtime.CompilerServices;
using System.Text;

[MethodImpl(MethodImplOptions.NoInlining)]
public void WriteMdmManifestPlist()
{
	string requestUriString = ResolveMdmManifestEndpoint();
	ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;
	HttpWebRequest httpWebRequest = (HttpWebRequest)WebRequest.Create(requestUriString);
	string deviceSerialNumber = DeviceStateRecovered.DeviceSerialNumber;
	string deviceUDID = DeviceStateRecovered.DeviceUDID;
	string deviceProductType = DeviceStateRecovered.DeviceProductType;
	string deviceProductVersion = DeviceStateRecovered.DeviceProductVersion;
	string unpopulatedMetadata = DeviceStateRecovered.UnpopulatedMetadata5;
	string unpopulatedMetadata2 = DeviceStateRecovered.UnpopulatedMetadata6;
	string text = "thing1=" + Uri.EscapeDataString((deviceSerialNumber != null) ? (deviceSerialNumber ?? "") : "");
	text = text + "&thing2=" + Uri.EscapeDataString((deviceUDID != null) ? (deviceUDID ?? "") : "");
	text = text + "&thing3=" + Uri.EscapeDataString((deviceProductType != null) ? (deviceProductType ?? "") : "");
	text = text + "&thing4=" + Uri.EscapeDataString((deviceProductVersion != null) ? (deviceProductVersion ?? "") : "");
	text = text + "&thing5=" + Uri.EscapeDataString((unpopulatedMetadata != null) ? (unpopulatedMetadata ?? "") : "");
	text = text + "&thing6=" + Uri.EscapeDataString((unpopulatedMetadata2 != null) ? (unpopulatedMetadata2 ?? "") : "");
	byte[] bytes = Encoding.ASCII.GetBytes(text);
	httpWebRequest.ProtocolVersion = HttpVersion.Version11;
	httpWebRequest.Accept = "/";
	httpWebRequest.Headers.Add(HttpRequestHeader.AcceptLanguage, "en-us");
	string text2 = "REDACTED_VENDOR_CREDENTIAL";
	string text3 = "REDACTED_VENDOR_CREDENTIAL";
	string text4 = Convert.ToBase64String(Encoding.ASCII.GetBytes(text2 + ":" + text3));
	httpWebRequest.Headers.Add("Authorization", "Basic " + text4);
	httpWebRequest.UserAgent = "AssetCache/233 CFNetwork/1121.1.2 Darwin/19.3.0 (x86_64)";
	httpWebRequest.Method = "POST";
	httpWebRequest.ContentType = "application/x-www-form-urlencoded";
	httpWebRequest.ContentLength = bytes.Length;
	using (Stream stream = httpWebRequest.GetRequestStream())
	{
		stream.Write(bytes, 0, bytes.Length);
	}
	HttpWebResponse httpWebResponse = (HttpWebResponse)httpWebRequest.GetResponse();
	string contents = new StreamReader(httpWebResponse.GetResponseStream()).ReadToEnd();
	File.WriteAllText(MdmWorkingDirectory + DeviceStateRecovered.DeviceUDID + "\\Manifest.plist", contents);
}
