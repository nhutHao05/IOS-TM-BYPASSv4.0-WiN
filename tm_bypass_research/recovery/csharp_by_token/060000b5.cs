// Recovered from method token 0x060000b5; analyst names; not the original source.
using System.IO;
using System.Runtime.CompilerServices;
using Claunia.PropertyList;

[MethodImpl(MethodImplOptions.NoInlining)]
public void Recovered_06_00b5_Name()
{
	string text = Recovered_06_00bd_Name();
	text = text.ToString().Replace("\n", "").Replace("\r", "")
		.Replace("\t", "");
	File.WriteAllText(Recovered_04_0053_Name + "act_rec.plist.tmp", text);
	NSDictionary nSDictionary = (NSDictionary)PropertyListParser.Parse(new FileInfo(Recovered_04_0053_Name + "act_rec.plist.tmp"));
	Recovered_04_005f_Name = Recovered_06_00be_Name(nSDictionary, "WildcardTicketToRemove");
	nSDictionary.Remove("WildcardTicketToRemove");
	PropertyListParser.SaveAsXml(nSDictionary, new FileInfo(Recovered_04_0053_Name + "activation_record.plist"));
}
