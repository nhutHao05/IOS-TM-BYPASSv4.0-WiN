// Recovered from method token 0x060000bf; analyst names; not the original source.
using System;
using System.Linq;

public string Recovered_06_00bf_Name(string P_0, int P_1)
{
	return P_0.Split(Environment.NewLine.ToCharArray(), P_1 + 1).Skip(P_1).FirstOrDefault();
}
