// Export pseudocode from an unpacked snapshot, without executing the target.
// Import thunks are named from independent Unicorn emulation results.
// @category Research.Recovery
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;

public class RecoverNative extends GhidraScript {
    private final DataType ptr = new PointerDataType(VoidDataType.dataType);
    private final DataType str = new PointerDataType(CharDataType.dataType);
    private final DataType integer = IntegerDataType.dataType;
    private final DataType u64 = UnsignedLongLongDataType.dataType;
    private Address address(String value) {
        return toAddr(Long.parseUnsignedLong(value.replace("0x", ""), 16));
    }
    private void signature(Function f, String name) throws Exception {
        DataType result = null;
        DataType[] args = null;
        switch (name) {
            case "plist_new_dict": case "plist_new_array":
                result=ptr; args=new DataType[]{}; break;
            case "plist_new_string": result=ptr; args=new DataType[]{str}; break;
            case "plist_new_bool": result=ptr; args=new DataType[]{CharDataType.dataType}; break;
            case "plist_new_uint": result=ptr; args=new DataType[]{u64}; break;
            case "plist_dict_get_item": result=ptr; args=new DataType[]{ptr,str}; break;
            case "plist_dict_set_item": result=VoidDataType.dataType; args=new DataType[]{ptr,str,ptr}; break;
            case "plist_dict_remove_item": result=VoidDataType.dataType; args=new DataType[]{ptr,str}; break;
            case "plist_array_append_item": result=VoidDataType.dataType; args=new DataType[]{ptr,ptr}; break;
            case "plist_array_get_item": result=ptr; args=new DataType[]{ptr,integer}; break;
            case "plist_array_get_size": case "plist_get_node_type": result=integer; args=new DataType[]{ptr}; break;
            case "plist_get_string_val": case "plist_get_uint_val": case "plist_get_bool_val":
                result=VoidDataType.dataType; args=new DataType[]{ptr,ptr}; break;
            case "plist_to_xml": case "plist_to_bin":
                result=VoidDataType.dataType; args=new DataType[]{ptr,ptr,ptr}; break;
            case "plist_from_xml": case "plist_from_bin":
                result=VoidDataType.dataType; args=new DataType[]{str,integer,ptr}; break;
            case "plist_free": case "free": result=VoidDataType.dataType; args=new DataType[]{ptr}; break;
            case "malloc": result=ptr; args=new DataType[]{u64}; break;
            case "realloc": result=ptr; args=new DataType[]{ptr,u64}; break;
            case "calloc": result=ptr; args=new DataType[]{u64,u64}; break;
            case "strdup": case "_strdup": case "getenv": result=str; args=new DataType[]{str}; break;
            case "strlen": result=u64; args=new DataType[]{str}; break;
            case "strcmp": case "strcasecmp": result=integer; args=new DataType[]{str,str}; break;
            case "fopen": result=ptr; args=new DataType[]{str,str}; break;
            case "fclose": result=integer; args=new DataType[]{ptr}; break;
            case "fread": case "fwrite": result=u64; args=new DataType[]{ptr,u64,u64,ptr}; break;
            case "fseek": result=integer; args=new DataType[]{ptr,integer,integer}; break;
            case "ftell": result=integer; args=new DataType[]{ptr}; break;
            case "printf": result=integer; args=new DataType[]{str}; break;
            case "CreateDirectoryA": result=integer; args=new DataType[]{str,ptr}; break;
            case "GetLastError": result=integer; args=new DataType[]{}; break;
            case "mobilebackup2_send_request": result=integer; args=new DataType[]{ptr,str,str,str,ptr}; break;
            case "mobilebackup2_receive_message": result=integer; args=new DataType[]{ptr,ptr,ptr}; break;
            case "mobilebackup2_send_status_response": result=integer; args=new DataType[]{ptr,integer,str,ptr}; break;
            case "mobilebackup2_client_new": result=integer; args=new DataType[]{ptr,ptr,ptr}; break;
            case "mobilebackup2_version_exchange": result=integer; args=new DataType[]{ptr,ptr,CharDataType.dataType,ptr}; break;
            case "lockdownd_client_new_with_handshake": result=integer; args=new DataType[]{ptr,ptr,str}; break;
            case "lockdownd_start_service_with_escrow_bag": result=integer; args=new DataType[]{ptr,str,ptr}; break;
            case "lockdownd_start_service": result=integer; args=new DataType[]{ptr,str,ptr}; break;
            case "lockdownd_get_value": result=integer; args=new DataType[]{ptr,str,str,ptr}; break;
            case "idevice_get_device_list": case "idevice_get_udid":
                result=integer; args=new DataType[]{ptr,ptr}; break;
            case "idevice_new": result=integer; args=new DataType[]{ptr,str}; break;
            case "idevice_free": case "mobilebackup2_client_free": case "afc_client_free":
            case "lockdownd_client_free": case "np_client_free":
                result=integer; args=new DataType[]{ptr}; break;
            case "afc_file_open": result=integer; args=new DataType[]{ptr,str,u64,ptr}; break;
            case "afc_file_lock": result=integer; args=new DataType[]{ptr,u64,u64}; break;
            case "afc_file_close": result=integer; args=new DataType[]{ptr,u64}; break;
        }
        if (args==null) return;
        f.setCallingConvention(currentProgram.getCompilerSpec().getDefaultCallingConvention().getName());
        f.setReturnType(result, SourceType.USER_DEFINED);
        List<Parameter> params=new ArrayList<>();
        for(int i=0;i<args.length;i++) params.add(new ParameterImpl("arg"+i,args[i],currentProgram));
        f.replaceParameters(params,Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.USER_DEFINED);
        if(name.equals("printf"))f.setVarArgs(true);
    }
    public void run() throws Exception {
        String[] a=getScriptArgs();
        MemoryBlock codeBlock=currentProgram.getMemory().getBlock(".text");
        if(codeBlock==null)throw new IllegalStateException("Missing .text block");
        AddressSet text=new AddressSet(codeBlock.getStart(),codeBlock.getEnd());
        FunctionManager fm=currentProgram.getFunctionManager();
        ExternalManager em=currentProgram.getExternalManager();
        int names=0;
        for(String line:Files.readAllLines(Path.of(a[0]))) {
            String[] cols=line.split("\t"); if(cols.length!=3)continue;
            String[] symbol=cols[2].split("!",2);
            Address callsite=address(cols[0]),stub=address(cols[1]);
            ExternalLocation ext=em.getUniqueExternalLocation(symbol[0],symbol[1]);
            if(ext==null)ext=em.addExtFunction(symbol[0],symbol[1],null,SourceType.USER_DEFINED);
            Function target=ext.getFunction(); if(target==null)target=ext.createFunction();
            signature(target,symbol[1]);
            Function thunk=fm.getFunctionAt(stub);
            if(thunk==null)thunk=fm.createFunction("api_"+symbol[1].replaceAll("[^A-Za-z0-9_]","_")+"_"+stub,
                stub,new AddressSet(stub),SourceType.USER_DEFINED);
            thunk.setThunkedFunction(target);
            setPreComment(callsite,"Recovered VMProtect thunk: "+cols[2]+"; offline emulation evidence.");
            names++;
        }
        Map<Address,AddressSet> bodies=new TreeMap<>();
        for(String line:Files.readAllLines(Path.of(a[1]))) {
            String[] cols=line.split("\t");Address owner=address(cols[0]),start=address(cols[1]),end=address(cols[2]).subtract(1);
            new DisassembleCommand(start,text,true).applyTo(currentProgram,monitor);
            bodies.computeIfAbsent(owner,k->new AddressSet()).add(start,end);
        }
        for(Map.Entry<Address,AddressSet> entry:bodies.entrySet()) {
            Address start=entry.getKey();
            if(fm.getFunctionAt(start)==null)fm.createFunction("native_"+start,start,entry.getValue(),SourceType.USER_DEFINED);
        }
        Map<Long,String> namesByAddress=Map.ofEntries(
            Map.entry(0x140001230L,"FormatByteCountRecovered"),
            Map.entry(0x140001500L,"PrintMessageRecovered"),
            Map.entry(0x140001a80L,"HandleNotificationRecovered"),
            Map.entry(0x140002080L,"BuildBackupInfoPlistRecovered"),
            Map.entry(0x140002b10L,"CheckFinishedSnapshotRecovered"),
            Map.entry(0x140002c00L,"PostSyncNotificationRecovered"),
            Map.entry(0x140002ce0L,"LogDeviceLinkOperationRecovered"),
            Map.entry(0x140002dc0L,"SendBackupFileRecovered"),
            Map.entry(0x140003210L,"ReceiveFilenameRecovered"),
            Map.entry(0x140003360L,"ReceiveBackupFilesRecovered"),
            Map.entry(0x140003a70L,"BuildDirectoryListingRecovered"),
            Map.entry(0x140004070L,"RunBackupRestoreRecovered"));
        for(Map.Entry<Long,String> entry:namesByAddress.entrySet()) {
            Function f=fm.getFunctionAt(toAddr(entry.getKey()));
            if(f!=null)f.setName(entry.getValue(),SourceType.USER_DEFINED);
        }
        if(a.length>3) {
            for(String line:Files.readAllLines(Path.of(a[3]))) {
                String[] cols=line.split("\t");
                Function f=fm.getFunctionAt(address(cols[0]));
                if(f!=null) {
                    f.setName(cols[1]+"_Recovered",SourceType.USER_DEFINED);
                    if(cols.length>2 && cols[2].equals("virtualized"))
                        f.setComment("Only the VM entry is recovered here; the VM body remains protected.");
                }
            }
        }
        Function print=fm.getFunctionAt(toAddr(0x140001500L));if(print!=null)signature(print,"printf");
        Function main=fm.getFunctionAt(toAddr(0x140004070L));if(main!=null)main.setReturnType(integer,SourceType.USER_DEFINED);
        // MSVC's cookie-check leaf preserves RAX. Inline its real instructions
        // so the decompiler does not replace main's exit code with a fictitious return.
        Function cookie=fm.getFunctionAt(toAddr(0x140005da0L));
        if(cookie!=null) {
            cookie.setName("CheckSecurityCookieRecovered",SourceType.USER_DEFINED);
            cookie.setReturnType(VoidDataType.dataType,SourceType.USER_DEFINED);
            cookie.replaceParameters(List.of(new ParameterImpl("cookie",u64,currentProgram)),
                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.USER_DEFINED);
            cookie.setInline(true);
        }
        MemoryBlock data=currentProgram.getMemory().getBlock(".rdata");
        if(data!=null) {
            byte[] bytes=new byte[(int)data.getSize()];currentProgram.getMemory().getBytes(data.getStart(),bytes);
            for(int i=0;i<bytes.length;i++) {
                int j=i;while(j<bytes.length && ((bytes[j]>=32 && bytes[j]<127) || bytes[j]==9 || bytes[j]==10 || bytes[j]==13))j++;
                if(j-i>=4 && j<bytes.length && bytes[j]==0) {
                    try { createAsciiString(data.getStart().add(i),j-i+1); } catch(Exception ignored) {}
                }
                if(j>i)i=j;
            }
        }
        DecompInterface decompiler=new DecompInterface();
        decompiler.openProgram(currentProgram);
        int ok=0,failed=0;
        Path out=Path.of(a[2]);Files.createDirectories(out);
        try(PrintWriter manifest=new PrintWriter(Files.newBufferedWriter(out.resolve("coverage.tsv")))) {
            for(Function function:fm.getFunctions(true)) {
                if(!text.contains(function.getEntryPoint()))continue;
                DecompileResults result=decompiler.decompileFunction(function,20,monitor);
                String name=function.getEntryPoint().toString();
                if(result.decompileCompleted()) {
                    String source="/* Analyst pseudocode from an unpacked memory snapshot.\n * Not original source; API names come from emulated thunks.\n */\n"+result.getDecompiledFunction().getC();
                    Files.writeString(out.resolve(name+".c"),source);ok++;
                    manifest.println(name+"\tOK\t"+function.getName());
                } else {
                    Files.writeString(out.resolve(name+".error"),result.getErrorMessage());failed++;
                    manifest.println(name+"\tFAILED\t"+function.getName());
                }
            }
        }
        decompiler.dispose();
        println("NATIVE_RECOVERY calls_named="+names+" functions_exported="+ok+" failed="+failed);
    }
}
