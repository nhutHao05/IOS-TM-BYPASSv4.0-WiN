// Recovered from method token 0x060000b8; analyst names; not the original source.
using System;
using System.IO;
using System.Runtime.CompilerServices;
using Claunia.PropertyList;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00b8_Name()
{
	NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "data_ark.plist"));
	try
	{
		nSDictionary.Remove("-UCRTOOBForbidden");
		nSDictionary.Remove("ActivationState");
		nSDictionary.Remove("-ActivationState");
		nSDictionary.Add("ActivationState", "Activated");
	}
	catch (Exception)
	{
	}
	PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "data_ark.plist"));
}
