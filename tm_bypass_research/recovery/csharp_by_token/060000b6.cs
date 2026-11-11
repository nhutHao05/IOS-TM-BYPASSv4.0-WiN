// Recovered from method token 0x060000b6; analyst names; not the original source.
using System.IO;
using System.Runtime.CompilerServices;
using Claunia.PropertyList;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00b6_Name()
{
	NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
	try
	{
		nSDictionary.Remove("kPostponementTicket");
	}
	catch
	{
	}
	nSDictionary.Add("kPostponementTicket", new NSDictionary
	{
		{ "ActivationState", "Activated" },
		{ "ActivationTicket", Recovered_04_005f_Name },
		{ "ActivityURL", "https://albert.apple.com/deviceservices/activity" },
		{ "PhoneNumberNotificationURL", "https://albert.apple.com/deviceservices/phoneHome" }
	});
	PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "com.apple.commcenter.device_specific_nobackup.plist"));
}
