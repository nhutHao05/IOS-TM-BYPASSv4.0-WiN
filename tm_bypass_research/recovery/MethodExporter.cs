using System;
using System.IO;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using ICSharpCode.Decompiler;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.Metadata;

// Offline reader only. The target assembly is never loaded for execution.
internal static class MethodExporter
{
    static int Main(string[] args)
    {
        var settings = new DecompilerSettings {
            ThrowOnAssemblyResolveErrors = false,
            ArrayInitializers = false,
            UseDebugSymbols = false
        };
        var resolver = new UniversalAssemblyResolver(args[0], false, ".NETFramework,Version=v4.8");
        resolver.AddSearchDirectory(Path.Combine(Path.GetDirectoryName(Path.GetFullPath(args[0])), "references"));
        var decompiler = new CSharpDecompiler(args[0], resolver, settings);
        Directory.CreateDirectory(args[1]);
        using var file = File.OpenRead(args[0]);
        using var pe = new PEReader(file);
        var md = pe.GetMetadataReader();
        int failed = 0;
        foreach (var handle in md.MethodDefinitions)
        {
            int token = MetadataTokens.GetToken(handle);
            if (args.Length > 2 && token > Convert.ToInt32(args[2], 16)) continue;
            var method = md.GetMethodDefinition(handle);
            string filename = Path.Combine(args[1], token.ToString("x8") + ".cs");
            try
            {
                string source = decompiler.DecompileAsString(handle);
                File.WriteAllText(filename, "// Recovered from method token 0x" + token.ToString("x8") +
                    "; analyst names; not the original source.\n" + source);
                Console.WriteLine(token.ToString("x8") + " OK " + source.Length);
            }
            catch (Exception ex)
            {
                failed++;
                File.WriteAllText(filename + ".error", ex.ToString());
                Console.WriteLine(token.ToString("x8") + " FAILED " + ex.GetType().Name);
            }
        }
        return failed == 0 ? 0 : 1;
    }
}
